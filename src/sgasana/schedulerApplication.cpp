/* 


   schedulerApplication.cpp - application file for a program named scheduler
   =====================================================================

   This program is for a scheduler that should help you prioritize the tasks to do.
   Being someone with difficulty working in order and having problems meeting deadlines i had
   and idea of creating a program that would help me schedule the tasks i have to do by the deadline
   and the the difficulty in task.
   -i couldn't find a mathematical framework to quantify the level of difficulty so i created a scale 
   from 0-10(subjective scale) and i wrote them to the file.
   -i only put in the input file tasks id's and the actual task name is in a different file but below you
   can see what it looks like.
  
   Input
   -----
    i want to do these things for school this week:

	1. i want to complete an assignment for graphs in datastructure(by wednesday)
	2. i want to complete  nlp assignment 1(5 april sunday)
	3. i want to finish assignment on economics 6(i have got to learn the math behind game theory)(31 tuesday)
	4. i have to understand nlp concepts(the videos of this week and next week(logistic regression,neural networks,analysis of n-grams and tp-idp))(monday 24)
	5.economics business plan research(23 april)
	6. I want to email david ross to know if i can propose and teamwork on our project(friday)
	7. i want to finish IT innovation's homework(by tuesday)
	8. nlp project code(by wednesday 6am)

   - a text file of numbers representing tasks id, their deadlines countdown in days and their relative
   level of difficulty.
   task id | the number identifying each task
   deadline| if the deadline is in 5days its columns will be 5
   difficulty| here its all about subjectively


   Output
   ------

   - the tasks to do ordered by how hard they are and how urgent they are
 

   Sample Input
   ------------
   1
	1 6 10
	2 10 9
	3 5 8
	4 4 8
	5 28 10
	6 1 5
	7 5 8
	8 6 8
	-1
   


   Sample Output
   -------------
	You have to perform your tasks in this order
	task id |deadline|difficulty
	----------------
	6       1       5
	4       4       8
	3       5       8
	7       5       8
	1       6       10
	8       6       8
	2       10      9
	5       28      10


  
   Author
   ------

   Sammy Gasana, Carnegie Mellon University Africa
   27/03/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/
 
#include "shedulerInterface.h"

int main() {
  
   FILE *fp_in, *fp_out;

   if ((fp_in = fopen("../data/input_schedule.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
     prompt_and_exit(1);
   }
   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
     prompt_and_exit(1);
   }

   int number_of_test_cases,s=0;
   int task_id, deadline,difficulty,test_check;
   int i,j;
   int task_count;
   int count=0;
   struct task_structure task[MAX_NUMBER_OF_POINTS];
   struct task_structure temp;
   
   
   printf("You have to perform your tasks in this order\n");
   fscanf(fp_in, "%d", &number_of_test_cases);
	
   for(i=0;i<number_of_test_cases;i++){ //
	  fscanf(fp_in,"%d %d %d", &task_id, &deadline, &difficulty);//read the 3 variables from it
	  

	   while(task_id>0){//as long as the time isnt negative proceed
		   task_count = store_task(task, task_id, deadline, difficulty);// it takes the task array,t deadline y then sets the counter locid and vartohelpus to 0 then if our time isnt 0 our taskid is 1 then our array structure is gonna take the values inputed from the files including t,deadline,y and id then our counter increment by 1, in case we get to the point where t is negative our vartohelpus will save the task counter which is 1
		   fscanf(fp_in,"%d	%d %d", &task_id, &deadline, &difficulty);
	   }
	  
	   decrementing_insertion_sort(task,task_count,3,count);//key = difficulty
	   insertion_sort(task, task_count, 2,count);//key=deadline
	   printf("%s |%s|%s\n", "task id","deadline", "difficulty");
	   printf(" ----------------\n");
	   for(j = count; j<task_count;j++){
		  printf("%d	%d	%d\n", task[j].task_id,task[j].deadline, task[j].difficulty);
		  fprintf(fp_out,"%d	%d	%d\n", task[j].task_id,task[j].deadline, task[j].difficulty);
	   }
	   fprintf(fp_out," ----------------\n");
	   printf(" ----------------\n");
	   count = task_count;
	   task_count = 0;
   }
   fclose(fp_in);
   fclose(fp_out);
   prompt_and_exit(0);
}
