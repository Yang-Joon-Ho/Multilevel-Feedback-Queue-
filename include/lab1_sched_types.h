/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 
*	    Student name : 
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H

#define SLICE 1 //time slice
#define SIZE 20 //size of queue
#define N_SIZE 20 //size of process' name
#define N_Q 3 // number of queue

struct Process { //프로세스 구조체
	char name[N_SIZE];//프로세스 이름
	int arrive;//도착시간
	int time;//할당받은 시간
	int pr; //우선순위
	int no; //시각화 할 때 쓰는 인덱스 
};

struct Queue {//큐 구조체
	struct Process *p[SIZE];//프로세스 
	int front;
	int rear;
};

void push(struct Queue *q[], char *name, int arrive, int time);
void pop(struct Queue *q[], int i);//i is queue's index
void print(struct Queue *q[]);
void quickSort(struct Queue *arr[], int left, int right); // left = 0, right = n - 1
void alphabetSort(struct Queue *arr[], int left, int right); // left = 0, right = n - 1
void menu(struct Queue *q[], int *arr_size);
void initialize(struct Queue *q[]);
void freeQ(struct Queue *q[]);
void painting(struct Queue *q[], char **arr, int idx, int *i/*i is time slice*/);
void cpu(struct Queue *q[], char **arr, int idx, int *i, int mode);
void schedule(struct Queue *q[], char **arr, int t_time, int mode, int init);
int total_time(struct Queue *q[]);
char **allocate(struct Queue *q[], int t_time, int arr_size);
void numbering(struct Queue *q[]);
void visualize(char **savename, char **arr, int t_time, int arr_size);
void initialize_queue(struct Queue *q[], int *idx);


/*
 * You need to Declare functions in  here
 */


#endif /* LAB1_HEADER_H*/



