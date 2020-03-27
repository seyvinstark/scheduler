/* 
  schedulerImplementation.cpp - implementation file for a program named example
   ============================================================================

   Author
   ------

   Sammy Gasana, Carnegie Mellon University Africa
   27/03/2019

*/

 
 
#include "shedulerInterface.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}

int store_task(struct task_structure task[],int task_id, int deadline, int difficulty){
	 /* this is just a stub */  
	static int task_ids=0;
	static int task_counter=0;

	task[task_counter].task_id = task_id;//array task_id=task_id
	task[task_counter].deadline = deadline; //array deadline=deadline
	task[task_counter].difficulty = difficulty;
		
	return task_counter = task_counter+1;// eventually, return where we are in our array 
};


//insertion(stable)
void insertion_sort(struct task_structure task[], int n, int key,int start)
{ 
	int i,j;
	struct  task_structure temp;

	if(key==1){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].task_id < task[j-1].task_id))
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
		}
	}
	else if(key==2){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].deadline < task[j-1].deadline))
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
	}
	}
	else if(key==3){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].difficulty < task[j-1].difficulty))
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
	}
	}
}
void decrementing_insertion_sort(struct task_structure task[], int n, int key,int start)
{ 
	int i,j;
	struct  task_structure temp;

	if(key==1){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].task_id > task[j-1].task_id))//j=2 --->9 and task2 less task1 
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
		}
	}
	else if(key==2){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].deadline > task[j-1].deadline))
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
	}
	}
	else if(key==3){
		for (i=start + 1; i<n; i++) {
		j=i;
		while ((j>start) && (task[j].difficulty > task[j-1].difficulty))
		{ 
			temp = task[j-1]; // swap 
			task[j-1] = task[j];
			task[j] = temp;
			j = j-1;
		}
	}
	}
}