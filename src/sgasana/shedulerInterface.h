/* 

    shedulerInterface.h - interface file for a program named example
   ======================================================
*/
 
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>


#define MAX_NUMBER_OF_POINTS 1000 // or some other limit 

/* function prototypes go here */
struct task_structure {
int task_id;
int   deadline;
int   difficulty;
};

void selectionSort(struct task_structure task[] , int n,char key);
void prompt_and_exit(int status);
void insertion_sort(struct task_structure task[], int n, int key,int start);
int store_task(struct task_structure task[], int task_id, int deadline, int y);
void print_message_to_file(FILE *fp, char message[]);
void decrementing_insertion_sort(struct task_structure task[], int n, int key,int end);
