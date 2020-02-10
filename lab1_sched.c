/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32167365	 
*	    Student name : 양준호
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
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

void push(struct Queue *q[], char *name, int arrive, int time)
{

	strcpy(q[0]->p[q[0]->front]->name, name);
	q[0]->p[q[0]->front]->arrive = arrive;
	q[0]->p[q[0]->front]->time = time;
	q[0]->p[q[0]->front]->pr = 0; //priority = 0;

	q[0]->front--;
}

void pop(struct Queue *q[], int i)//i is queue's index
{
	if (i == N_Q - 1) {
		if (q[i]->p[q[i]->rear]->time == 0) {
			q[i]->rear--;
		}
		else {
			q[i]->p[q[i]->front] = q[i]->p[q[i]->rear];
			q[i]->rear--;
			q[i]->front--;
		}
	}
	else if (q[i]->p[q[i]->rear]->time == 0) {//task의 time이 0인 경우
		q[i]->rear--;
	}
	else {//task의 time이 0이 아닌경우
		q[i + 1]->p[q[i + 1]->front] = q[i]->p[q[i]->rear];
		q[i]->rear--;
		q[i + 1]->front--;
	}
}

void print(struct Queue *q[])
{
	for (int i = q[0]->front + 1; i <= q[0]->rear; i++) {
		printf("name: %s, arrive: %d, time: %d \n", q[0]->p[i]->name, q[0]->p[i]->arrive, q[0]->p[i]->time);
		puts("");
	}
}

void quickSort(struct Queue *arr[], int left, int right) // left = 0, right = n - 1
{
	int i = left, j = right;
	struct Process *pivot = arr[0]->p[(left + right) / 2]; // pivot은 배열의 중간인덱스에 위치한 값
	struct Process *swap;

	do
	{
		while (arr[0]->p[i]->arrive > pivot->arrive) // 좌측 인덱스 값이 기준값보다 작으면 인덱스 증가
			i++;
		while (arr[0]->p[j]->arrive < pivot->arrive) // 우측 인덱스 값이 기준값보다 크면 인덱스 감소
			j--;
		if (i <= j) /* 좌측 인덱스가 우측 인덱스 보다 작으면
					   좌측 인덱스 값이 우측 인덱스 값 보다 크다는 얘기므로 스왑연산함*/
		{
			swap = arr[0]->p[i];
			arr[0]->p[i] = arr[0]->p[j];
			arr[0]->p[j] = swap;
			i++;
			j--;
		}
	} while (i < j); // 위와 같은 작업은 좌측 인덱스가 우측인덱스보다 작으면 계속 반복함.

	/* recursion */
	if (left < j) /* 위의 do while을 통해 기준값 중심으로
					 작은 수는 좌측에 몰아넣고, 큰 수는 우측에 몰아넣었으므로
					 기준값 중심으로 배열을 두개로 나누어 재귀함수를 취하여
					 정렬을 하도록 한다.*/
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}

void alphabetSort(struct Queue *arr[], int left, int right) // left = 0, right = n - 1
{
	int i = left, j = right;
	struct Process *pivot = arr[0]->p[(left + right) / 2]; // pivot은 배열의 중간인덱스에 위치한 값
	struct Process *swap;

	do
	{
		while (strcmp(arr[0]->p[i]->name, pivot->name) > 0) 
			i++;
		while (strcmp(arr[0]->p[j]->name, pivot->name) < 0) 
			j--;
		if (i <= j) /* 좌측 인덱스가 우측 인덱스 보다 작으면
					   좌측 인덱스 값이 우측 인덱스 값 보다 크다는 얘기므로 스왑연산함*/
		{
			swap = arr[0]->p[i];
			arr[0]->p[i] = arr[0]->p[j];
			arr[0]->p[j] = swap;
			i++;
			j--;
		}
	} while (i < j); // 위와 같은 작업은 좌측 인덱스가 우측인덱스보다 작으면 계속 반복함.

	/* recursion */
	if (left < j) /* 위의 do while을 통해 기준값 중심으로
					 작은 수는 좌측에 몰아넣고, 큰 수는 우측에 몰아넣었으므로
					 기준값 중심으로 배열을 두개로 나누어 재귀함수를 취하여
					 정렬을 하도록 한다.*/
		alphabetSort(arr, left, j);

	if (i < right)
		alphabetSort(arr, i, right);
}

void menu(struct Queue *q[], int *arr_size)
{
	int ch; //ch is channel
	char name[N_SIZE];
	int arrive;
	int time;

	do {
		printf("\n\n Queue:\n1. Insert\n2. Print\n0. Exit\n");
		printf("Enter Choice 0-1? : ");

		scanf("%d", &ch);

		switch (ch) {
			case 1:
				printf("Enter name: ");
				scanf("%s", name);
				printf("Enter arrive: ");
				scanf("%d", &arrive);
				printf("Enter time: ");
				scanf("%d", &time);

				push(q, name, arrive, time);

				*arr_size += 1;

				break;
			case 2:
				print(q);
				break;
		}
	} while (ch != 0);

	quickSort(q, q[0]->front + 1, q[0]->rear);
	//alphabetSort(q, q[0]->front + 1, q[0]->rear);
}

void initialize(struct Queue *q[])
{
	for (int i = 0; i < N_Q; i++) {
		q[i] = malloc(sizeof(struct Queue));
		for (int j = 0; j < SIZE; j++)
			q[i]->p[j] = malloc(sizeof(struct Process));
	}
	for (int i = 0; i < N_Q; i++) {
		q[i]->rear = q[i]->front = SIZE - 1;
		for (int j = 0; j < SIZE; j++) {//큐 사이즈(numbers of raw) 만큼 반복
			q[i]->p[j]->arrive = 99; //arrive을 모두 99로 초기화
		}
	}
}

void freeQ(struct Queue *q[])
{
	for (int i = 0; i < N_Q-1; i++) {
		for (int j = 0; j < SIZE; j++){
			free(q[i]->p[j]);
		}
		free(q[i]);
	}
}

void painting(struct Queue *q[], char **arr, int idx, int *i/*i is time slice*/)
{
	arr[q[idx]->p[q[idx]->rear]->no][*i] = '#';
}

void cpu(struct Queue *q[], char **arr, int idx, int *i, int mode)
{
	if(mode == 1){
		if(q[idx]->p[q[idx]->rear]->time == 0)
			return;
		//if((*i + 1)%5 == 0){
		//	*i += 1; return;}
		q[idx]->p[q[idx]->rear]->time--;
		painting(q, arr, idx, i);
		*i += 1;
	}else if(mode == 2){
		switch(idx)
		{
			case 0:
				if(q[idx]->p[q[idx]->rear]->time == 0)
					break;
				//if((*i + 1)%5 == 0){
				//	*i+=1; break;}
				q[idx]->p[q[idx]->rear]->time--;
				painting(q, arr, idx, i);
				*i += 1;
				break;
			case 1:	
				for(int k = 0; k < 2*idx; k++){
					if(q[idx]->p[q[idx]->rear]->time == 0)
						break;
					if((*i + 1)%5 == 0)
						break;
					q[idx]->p[q[idx]->rear]->time--;
					painting(q, arr, idx, i);
					*i+=1;
				}
				break;
			case 2:
				for(int k = 0; k < 2*idx; k++){
					if(q[idx]->p[q[idx]->rear]->time == 0)
						break;
					if((*i + 1)%5 == 0)
						break;
					q[idx]->p[q[idx]->rear]->time--;
					painting(q, arr, idx, i);
					*i+=1;
				}
				break;
		}
	}else{
		printf("Wrong mode\n");
		exit(0);
	}
}

//when the time flow 5*x, initialize queue
void initialize_queue(struct Queue *q[], int *idx)
{
	q[0]->rear = SIZE - 1; //q rear 초기화
	for(int k = 1; k < N_Q; k++){
		q[k]->rear = SIZE - 1;
		q[k]->front = SIZE - 1;
	}
	*idx = 0; //큐 인덱스 초기화
}

void schedule(struct Queue *q[], char **arr, int t_time, int mode, int init)
{
	int idx = 0; //queue's index ex) first lv queue's idx is 0 

	for (int i = 0; i < t_time; i += SLICE) { //arr[i]의 마지막은 NULL
	
		if(init == 5 && (i+1) % 5 == 0) //시간 5가 지날 때 마다 큐 초기화
			initialize_queue(q, &idx);
		
		//in the first queue if there is a empty space, rear--
		if(i+1 >= 5 && idx == 0 && q[0]->p[q[0]->rear]->time == 0){
			do{
				if(q[0]->rear == q[0]->front)
					break;
				q[0]->rear--;
			}while(q[0]->p[q[0]->rear]->time == 0);
		}

		if (q[idx]->rear == q[idx]->front) { //해당 큐에 아무것도 없을 때
		    bool empty = true; // checks whether whole queue is empty
			for(int h = idx + 1; h < N_Q; h++){
				if(q[h]->rear != q[h]->front)
					empty = false;
			}
			if(empty == true)
				break; //if the whole queue is empty, then break the loop
			
			if(idx + 1 < N_Q)
				idx++;
		}
		if (i < q[idx]->p[q[idx]->rear]->arrive) { //해당 시간에 큐에 task가 아직 도착하지 않은경우
			bool decrease = false;
			for (int j = idx + 1; j < N_Q; j++) { //이미 존재하는 아래 큐에 있는 task를 검색
			//	printf("time is %d, under the queue\n", i);
				if (q[j]->p[q[j]->rear]->arrive <= i && q[j]->p[q[j]->rear]->time > 0) { //아래 큐에 이미 도착한 task가 있다면
					decrease = true;
					cpu(q, arr, j, &i, mode); //cpu에서 수행 
					pop(q, j); break;
				}
			}

			if(decrease == true)
				i--;
			
			if(i >= q[idx]->p[q[idx]->rear]->arrive) //if time is 0 & there's no task do not decrease i
				i--;
		}
		else if (idx == 0 && q[idx]->p[q[idx]->rear]->arrive == q[idx]->p[q[idx]->rear - 1]->arrive) {
			//도착시간이 같은 task가 여러개인 경우
			int left = 0; //현재 task와arrive가 같은것 중 가장 좌측에 있는것의 인덱스
			for (int j = q[idx]->rear - 1; ; j--) {
				if (q[idx]->p[q[idx]->rear]->arrive != q[idx]->p[j]->arrive) {
					//i를 좌측으로 arrive가 같지 않은것이 나올때까지 옮김
					break;
				}
				left = j;
			}
			alphabetSort(q, left, q[idx]->rear); //alphabet sorting
			for (int j = q[idx]->rear; j >= left; j--) {
				
				cpu(q, arr, idx, &i, mode);
				pop(q, idx);
			}
			i--;
		}
		else if (idx == 0 && q[idx]->rear == SIZE - 1 && q[idx]->p[q[idx]->rear - 1]->arrive > i) {//첫번째 큐이고, 아직 프로세스가 하나밖에 없을때
			
			for (int j = i; j < q[idx]->p[q[idx]->rear - 1]->arrive; j++) {
				if (q[idx]->p[q[idx]->rear]->time == 0)
					break;
				cpu(q, arr, idx, &i, mode);
			}
			i--;//어차피 for문에서 i를 또 증가시킬것이므로 감소시켜줌
			pop(q, idx);
		}
		else { //해당 시간에 큐에 task가 있는 경우
			cpu(q, arr, idx, &i, mode); //해당 task time 줄임
			pop(q, idx); //그리고 우선순위 낮춤
			i--;
		}
	}
}

int total_time(struct Queue *q[])
{
	int t_time = 10;
	for (int i = q[0]->front + 1; i <= q[0]->rear; i++)
		t_time += q[0]->p[i]->time;
	t_time += q[0]->p[q[0]->rear]->arrive;

	return t_time;
}

char **allocate(struct Queue *q[], int t_time, int arr_size)
{
	char **arr = malloc(sizeof(char *) * arr_size);
	for (int i = 0; i < arr_size; i++)
		arr[i] = malloc(sizeof(char) * (t_time + 1));

	for (int i = 0; i < arr_size; i++) { //공백으로 채움
		memset(arr[i], ' ', t_time);
	}

	return arr;
}

void numbering(struct Queue *q[])
{
	int n = 0;
	for (int i = q[0]->rear; i > q[0]->front; i--) {
		q[0]->p[i]->no = n++;
	}
}

void visualize(char **savename, char **arr, int t_time, int arr_size)
{
	printf("     ");
	for (int i = 0; i < t_time; i++) {
		if ( i >= 30)
			printf("%d", i - 30);
		else if (i >= 20)
			printf("%d", i - 20);
		else if (i >= 10)
			printf("%d", i - 10);
		else
			printf("%d", i);
	}puts("");

	for (int i = 0; i < arr_size; i++) {
		printf("%-5s", savename[i]);
		for (int j = 0; j < t_time; j++)
			printf("%c", arr[i][j]);
		puts("");
	}
}


