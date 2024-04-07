#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDStack.h"
#include "scanner.h"
#ifndef IDSTACK_C
#define IDSTACK_C
static const int MAXSTACK = 100;
static sStack stack = {.count = 0, .top = NULL};
void push(Ttoken* tk){
	if(stack.count >= MAXSTACK){
		fprintf(stderr, "\nERROR: IDStack.c: push Stack overflow."
				"Stack has %d elements.\n", stack.count);
		exit(-1);
	}
	eElement *element = (eElement*)malloc(sizeof(eElement));
	element->tk = tokenSetter(tk->ID, tk->tokenInstance, tk->row, tk->column);
	element->next = stack.top;
	stack.top = element;
	stack.count++;	
}
void pop(){
	if(stack.count < 1){
		fprintf(stderr, "\nERROR: IDStack.c: pop: Stack empty.\n");
		exit(-1);
	}
	eElement* tempholder = stack.top;
	stack.top = tempholder->next;
	free(tempholder);
	stack.count--;
}
//should not be invoked before stack initialized
int find(Ttoken* tk, int* row, int* col){
	eElement* element = (eElement*)malloc(sizeof(eElement));
	int pos;
	element = stack.top;
/*	if(element != NULL){
		int i;
		element->tk.ID = stack.top->tk.ID;
		for(i = 0; i < strlen(stack.top->tk.tokenInstance); i++){
			element->tk.tokenInstance[i] = stack.top->tk.tokenInstance[i];
		}
		int r = stack.top->tk.row;
		element->tk.row = r;
		element->tk.column =  stack.top->tk.column;
	}*/
	if(element != NULL){
		*row = stack.top->tk.row;
		*col = stack.top->tk.column;
	}
	for(pos = 0; pos < stack.count; pos++){
		if(strcmp(tk->tokenInstance, element->tk.tokenInstance)==0){
			return(pos);
		}
		element = element->next;
		if(element != NULL){
			*row = element->tk.row;
			*col = element->tk.column;
		}
	}
	return -1;
}
#endif
