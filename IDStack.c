#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDStack.h"
#include "scanner.h"

static int MAXSTACK = 127;
static sStack stack;
void stackSet(){
	stack.size = 0;
	stack.top = NULL;
}
void push(tToken tk){
	int i;
	if(stack.size > MAXSTACK){
		fprintf(stderr, "\nERROR: IDStack.c: push Stack overflow."
				"Stack has %d elements.\n", stack.size);
		exit()
	}
	eElement *element = (eElement*)malloc(sizeof(eElement));
	element->tk = tokenSetter(tk.ID, tk.tokenInstance, tk.row, tk.column);
	element->next = stack.top;
	stack.top = element;
	stack.size++;	
}
void pop(){
	if(stack.size < 1){
		fprintf(stderr, "\nERROR: IDStack.c: pop: Stack empty.\n"
		exit()
	}
	eElement* tempholder = stack.top;
	stack.top = tempholder->next;
	free(tempHolder)
	stack.size--;
}
void search(tToken tk, int){
	int pos;	//position in stack
	eElement* element = stack.top
	
	for(pos = 0; pos < stack.size; pos++){
		if(strcmp(tk.tokenInstance, element->tk.instance == 0){}
		element = element->next;
	}
	
}
