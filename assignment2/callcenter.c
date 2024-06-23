/*********************************************************************** 
** Program Filename: callcenter
** Author: Troy Diaz
** Date: 04/28/2024
** Description: A program to simulate a call center. Utilizes ADTs - stack
and queue. Program provides various options to - recieve a call, answer a call, 
print out number of calls answered/print out number of calls to be answered and their
respective call information. 
** Input: User input of caller's name, call reason, options 1-5
** Output: Adding information to stack/queue, display information of call
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

/********************************************************************* 
** Function: print_options
** Description: Prints call center options
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void print_options();

/********************************************************************* 
** Function: get_option_choice
** Description: Gets user's option choice and returns choice
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int get_option_choice();

/********************************************************************* 
** Function: run_program
** Description: Runs call center, quits program if user enters 5. 
** Parameters: struct queue* queue, struct stack* stack
** Pre-Conditions: pointer to queue and stack
** Post-Conditions: none
*********************************************************************/
void run_program(struct queue* queue, struct stack* stack);

/********************************************************************* 
** Function: receive_call
** Description: Allocating memory to new call, passing in pointer to new value
into enqueue and updating id number based on queue size
** Parameters: struct queue* queue
** Pre-Conditions: pointer to queue
** Post-Conditions: none
*********************************************************************/
void receive_call(struct queue* queue);

/********************************************************************* 
** Function: answer_a_call
** Description: Checks if there are calls to be answered. If there is, 
create a new pointer to removed value at queue, then push it onto stack, and 
display removed call info
** Parameters: struct queue* queue, struct stack* stack
** Pre-Conditions: pointer to queue and stack
** Post-Conditions: none
*********************************************************************/
void answer_a_call(struct queue* queue, struct stack* stack);

/********************************************************************* 
** Function: display_stack
** Description: Checks number of calls answered and prints out last call's 
information.
** Parameters: struct stack* stack
** Pre-Conditions: pointer to stack
** Post-Conditions: none
*********************************************************************/
void display_stack(struct stack* stack);

/********************************************************************* 
** Function: display_queue
** Description: Checks number of calls to be answered and prints out
last call's information.
** Parameters: struct queue* queue
** Pre-Conditions: pointer to queue
** Post-Conditions: none
*********************************************************************/
void display_queue(struct queue* queue);

struct callcenter{
	struct stack* stack;
	struct queue* queue;
};

struct call{
	int id;
	char caller_name[256];
	char caller_reason[256];
	
};

int main(int argc, char *argv[]) {
	
	// Allocating memory to queue and stack
	struct queue* queue = queue_create();
	struct stack* stack = stack_create();

	// Passing in pointers to queue and stack to program
	run_program(queue, stack);

	// Freeing memory from queue and stack
	queue_free(queue);
	stack_free(stack);

	// make call* tmp = pop stack ez

	// End program
	return 0;
}

void print_options(){
	// Printing out call center options

	printf("\n");
	printf("1. Receive a new call\n");
	printf("2. Answer a call\n");
	printf("3. Current state of the stack - answered calls\n");
	printf("4. Current state of the queue - calls to be answered\n");
	printf("5. Quit\n");

	printf("Choose an option: ");
}

int get_option_choice(){
	int choice = 0;
	print_options();
	scanf("%d", &choice);

	// Returning user choice
	return choice;
}

void run_program(struct queue* queue, struct stack* stack){
	printf("\n");
	printf("Welcome to the Call Center!");
	printf("\n");

	int choice = 0;
	while (choice != 5){
		choice = get_option_choice();

		if (choice == 1){
			receive_call(queue);
		}
		else if (choice == 2){
			answer_a_call(queue, stack);
		}
		else if (choice == 3){
			display_stack(stack);
		}
		else if (choice == 4){
			display_queue(queue);
		}
	}

	printf("\n");
	printf("Bye!\n");
	
	return;
}

void receive_call(struct queue* queue){
	// Allocating memory to a new call
	struct call* new_call = malloc(sizeof(struct call));
	
	printf("\n");

	// Storing caller name and reason into new call
	printf("Enter caller's name: ");
	scanf("%s", new_call->caller_name);
	printf("Enter call reason: ");
	scanf("%s", new_call->caller_reason);

	// Pass in pointer to new call enqueue
	queue_enqueue(queue, new_call);

	// Updating id number based on queue size
	new_call->id = get_queue_size(queue);

	printf("\n");
	printf("The call has been successfully added to the queue!\n");

	return;
}

void answer_a_call(struct queue* queue, struct stack* stack){
	printf("\n");

	// If there are no more calls
	if(queue_isempty(queue)){
		printf("No more calls need to be answered at the moment!\n");
		return;
	}

	// If there is a call to be answered
	else{
		// Create new pointer to removed value at queue
		struct call* removed_call = queue_dequeue(queue);

		// Push removed value onto stack
		stack_push(stack, removed_call);

		printf("The following call has been answered and added to the stack!\n");
		printf("\n");

		// Display information of removed call
		printf("Call ID: %d\n", removed_call->id);
		printf("Caller's name: %s\n", removed_call->caller_name);
		printf("Call reason: %s\n", removed_call->caller_reason);
	}

	return;
}

void display_stack(struct stack* stack){
	printf("\n");

	// Size of stack
	printf("Number of calls answered: %d\n", get_stack_size(stack));

	// Create pointer to top of stack value
	struct call* call = stack_top(stack);

	if(!stack_isempty(stack)){
		printf("Details of the last call answered:\n");
		printf("\n");

		// Displays information of last call
		printf("Call ID: %d\n", call->id);
		printf("Caller's name: %s\n", call->caller_name);
		printf("Call reason: %s\n", call->caller_reason);
	}
	
	return;
}

void display_queue(struct queue* queue){
	printf("\n");

	// Size of queue
	printf("Number of calls to be answered: %d\n", get_queue_size(queue));

	// Create pointer to front queue value
	struct call* call = queue_front(queue);

	if(!queue_isempty(queue)){
		printf("Details of the last call answered:\n");
		printf("\n");

		// Displays information of last call
		printf("Call ID: %d\n", call->id);
		printf("Caller's name: %s\n", call->caller_name);
		printf("Call reason: %s\n", call->caller_reason);
	}

	return;
}