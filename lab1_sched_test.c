/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32167365	
*	    Student name : 양준호
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm test code.
*
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>
#include <stdbool.h>

#include "lab1_sched_types.h"

/*
 * you need to implement scheduler simlator test code.
 *
 */

int main(int argc, char *argv[]){

	int arr_size = 0; //프로세스 개수 저장할 변수
	
	int mode = 0; //아래 큐로 내려갈수록 time slice를 길게줄것인가를 선택하는 변수 
	printf("select mode\n\nmode = 1, time slice is 1\nmode = 2, time slice is 2^lev\nmode : ");
	scanf("%d", &mode);
	int t_time = 0;

	char yesNo[3] = { 0, };
	int init = 0;
	printf("\n\n시간이 5만큼 지날 때 마다 큐를 초기화 할 것인가? (y/n) ");
	scanf("%s", yesNo);
	if(strcmp(yesNo, "y") == 0){
		init = 5;
		printf("yes\n");
	}else{
		printf("no\n");
	}

	struct Queue *q[N_Q];
	struct Process *p[SIZE];

	initialize(q);

	menu(q, &arr_size);
	numbering(q);

	t_time = total_time(q);

	char **arr = allocate(q, t_time, arr_size);
	char **savename = malloc(sizeof(char*)*arr_size); // 각 task 이름 저장할 문자열 
	for (int i = 0; i < arr_size; i++) { // arr_size는 task 갯수
		savename[i] = malloc(sizeof(char) * sizeof(q[0]->p[0]->name));
	}

	int j = 0;
	for (int i = q[0]->rear; i > q[0]->front; i--) {
		strncpy(savename[j++], q[0]->p[i]->name, sizeof(q[0]->p[i]->name));
	}

	for (int i = q[0]->front + 1; i <= q[0]->rear; i++) {
		printf("name: %s, arrive: %d, time: %d, number: %d \n", q[0]->p[i]->name, q[0]->p[i]->arrive, q[0]->p[i]->time, q[0]->p[i]->no);
		puts("");
	}

	//////////////////////////0203
	printf("\nbefore scheduling\n");
	/////////////////////////0203
	schedule(q, arr, t_time, mode, init);
	visualize(savename, arr, t_time, arr_size);

	//free all of things
	//freeQ(q);
	for (int i = 0; i < arr_size; i++) {
		free(arr[i]);
	}
	free(arr);

	for (int i = 0; i < arr_size; i++) {
		free(savename[i]);
	}
	free(savename);

	return 0;
}

