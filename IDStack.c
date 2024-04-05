#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDStack.h"
#include "scanner.h"

static int MAXSTACK = 100;
void stackSet(sStack stack){
	stack.count = 0;
	stack.top = NULL;
}
void push(tToken tk, sStack* stack){
	int i;
	if(stack->count >= MAXSTACK){
		fprintf(stderr, "\nERROR: IDStack.c: push Stack overflow."
				"Stack has %d elements.\n", stack.size);
		exit()
	}
	eElement *element = (eElement*)malloc(sizeof(eElement));
	element->tk = tokenSetter(tk.ID, tk.tokenInstance, tk.row, tk.column);
	element->next = stack->top;
	stack->top = element;
	stack->count++;	
}
void pop(sStack* stack){
	if(stack->count < 1){
		fprintf(stderr, "\nERROR: IDStack.c: pop: Stack empty.\n"
		exit()
	}
	eElement* tempholder = stack->top;
	stack->top = tempholder->next;
	free(tempHolder)
	stack->size--;
}
//should not be invoked before stack initialized
int find(tToken tk, eElement* element){
	int pos;
	element = stack.top;
	for(pos = 0; pos < stack.size; pos++){
		if(!strcmp(tk.tokenInstance, element->tk.tokenInstance)){
			return(pos);
		}
	}
	return -1;
}
/*
			fprintf(stderr, "\nERROR: IDStack.c: searchVar: "
					"Variable of ID '%s' already defined"
					" in this scope.\n"
					": Initial definition on line %d at "
					"char %d\n"
					": Repeat definition on line "
					"%d at char %d."
					tk.tokenInstance, tk.row, tk.column,
					element->tk.row, element->tk.column);
*/
