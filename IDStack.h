#ifndef VARSTACK_H
#define VARSTACK_H
#include "token.h"

typedef struct eElement{
	tToken tk;
	struct element *next;
}eElement;
typedef struct sStack{
	int count;
	eElement* top;
}sStack;
void push(tToken);
void pop();
void searchvar(tToken);
void search(tToken);
