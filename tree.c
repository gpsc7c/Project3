/*
 * tree.h
 *
 *  Created on: Jan 20, 2024
 *      Author: Greg
 */
#ifndef TREE_H_
#define TREE_H_
#include "node.h"
#include <stdio.h>
#include <string.h>
char nonterms[28][11] = {"TERMINAL", "<program>", "<func>", "<block>", "<vars>", "<facvars>", "<expr>", "<N>", "<N1>", "<A>", "<M>", "<R>", "<stats>", "<mStat>", "<stat>", "<in>", "<out>", "<if>", "<pick>", "<pickbody>", "<loop1>", "<loop2>", "<assign>", "<RBracket>", "<RTriplet>", "<R0>", "<label>", "<goto>"};
char* tokenNames[43] = {"IDTK", "INTTK", "ASSIGNTK", "GREATTK", "LESSTK", "ISEQUALTK", "NOTEQUALTK", "COLONTK", "COLONEQLTK", "PLUS", "MINUSTK", "MULTIPLYTK", "DIVIDETK", "EXPONTK", "DOTTK", "OPENPARENTK", "CLOSEPARENTK", "COMMATK", "OPENCURLTK", "CLOSECURLTK", "SEMICOLONTK", "OPENSQUARETK", "CLOSESQUARETK", "ORTK", "ANDTK", "STARTTK", "STOPTK", "WHILETK", "REPEATTK", "UNTILTK", "LABELTK", "RETURNTK", "CINTK", "COUTTK", "TAPETK", "JUMPTK", "IFTK", "THENTK", "PICKTK", "CREATETK", "SETTK", "FUNCTK", "EOFTK"};

struct node* newTermNode(Ttoken* tk){ // Allocate memory for new node
    	 node* nNode
        	= (struct node*)malloc(sizeof(node));
	int i;
	int j;
	nNode->tk = (Ttoken*)malloc(sizeof(Ttoken));
    	//assign title
    	nNode->tk->ID = tk->ID;
	for(j = 0; j < 9; j++){
    		nNode->tk->tokenInstance[j] = tk->tokenInstance[j];
	}
    	nNode->tk->row = tk->row;
    	nNode->tk->column = tk->column;
	
	for(i = 0; i < strlen(nonterms[0]); i++){
    		nNode->tTitle.nonterm[i] = nonterms[0][i];
	}
	for(; i <=10; i++){
    		nNode->tTitle.nonterm[10] = '\0';
	}


    	//initialize children as NULL
	nNode->one = NULL;
    	nNode->two = NULL;
    	nNode->three = NULL;
	nNode->four = NULL;
    	return nNode;
}
struct node* newNode(char* nonTerms){ // Allocate memory for new node
    	node* nNode
        	= (struct node*)malloc(sizeof(struct node));
	int i;
    	//assign title
    	nNode->tk = NULL;
	for(i = 0; i < 10; i++){
    		nNode->tTitle.nonterm[i] = nonTerms[i];
	}
    	nNode->tTitle.nonterm[10] = '\0';
    	//initialize children as NULL
	nNode->one = NULL;
    	nNode->two = NULL;
    	nNode->three = NULL;
	nNode->four = NULL;
    	return nNode;
}
void printPreOrder(struct node* dataNode, int depth){
	
	if(dataNode == NULL){
		return;
	}
	int i;	
	for(i = 0; i < depth; i++){
		fprintf(stdout, " |");
	}
	if(dataNode->tk != NULL){
		fprintf(stdout, " \\-%s: %s at depth %d\n", dataNode->tTitle.nonterm, tokenNames[dataNode->tk->ID], depth);
	}
	else{
		fprintf(stdout, " \\-%s at depth %d\n", dataNode->tTitle.nonterm, depth);
	}
	printPreOrder(dataNode->one, depth+1);
	printPreOrder(dataNode->two, depth+1);
	printPreOrder(dataNode->three, depth+1);
	printPreOrder(dataNode->four, depth+1);
}
void preorderStatSem(node* dataNode, int varCount){
	if


}
void deleteTree(struct node* dataNode){
	if(dataNode == NULL){
		fprintf(stderr, "\nERROR: tree.h: deleteTree: tree does not exist\n"); 
		return;
	}
	if(dataNode->one != NULL){
		deleteTree(dataNode->one);
	}
	if(dataNode->two != NULL){
		deleteTree(dataNode->two);
	}
	if(dataNode->three != NULL){
		deleteTree(dataNode->three);
	}
	if(dataNode->four != NULL){
		deleteTree(dataNode->four);
	}
	free(dataNode->tTitle.nonterm);
	if(dataNode->tk != NULL){
		free(dataNode->tk->tokenInstance);
		free(dataNode->tk);
	}
	free(dataNode);
}
void statSem(node* dataNode, int* IDCount){
	if(dataNode != NULL){
		if(!strcmp(dataNode->tTitle, nonterms[1]) || !strcmp(dataNode->tTitle, nonterms[3])){
			int i;
			int *IDCount = (int*) malloc(sizeof(int));
			*IDCount = 0;
			
			preStat(dataNode, IDCount);
			for( i = 0; i < *IDCount; i++){
				pop();
			}
			free(IDCount);
		}
		else{
			preStat(dataNode, IDCount);
		}
	}
}

void preStat(node *dataNode, int* IDCount){
	chkNode(dataNode, IDCount);
	statSem(dataNode->one, IDCount);
	statSem(dataNode->two, IDCount);
	statSem(dataNode->three, IDCount);
	statSem(dataNode->four, IDCount);

}

void chkNode(node* dataNode, int* IDCount){
	eElement* element = (eElement*)malloc(sizeof(eElement));
	if(*IDCount > 0 && (strcmp(dataNode->tTitle, nonterms[5]) || strcmp(dataNode->tTitle, nonterms[2]))){
		if(dataNode->two->tk->ID == IDTK){
			int dist = find(dataNode->tk, element);
			if( dist != -1 && *IDCount - dist != 0){
				fprintf(stderr, "\nERROR: IDStack.c: searchVar:"
					" Variable of ID '%s' already defined"
					" in this scope.\n"
					": Initial definition on line %d at "
					"char %d\n"
					": Repeat definition on line "
					"%d at char %d."
					tk.tokenInstance, tk.row, tk.column,
					element->tk.row, element->tk.column);
					exit();	
			}
			push(dataNode->two->tk);
		}
	}
	else if(strcmp(dataNode->tTitle, nonterms[11])||strcmp(dataNode->tTitle, nonterms[22])||strcmp(dataNode->tTitle, nonterms[15])||strcmp(dataNode->tTitle, nonterms[26])||strcmp(dataNode->tTitle, nonterms[27])){
		int dist;
		if(dataNode->one->tk != NULL){
			dist = find(dataNode->one->tk, element);
			
		}
		else {
			dist = find(dataNode->two->tk, element);
		}
		if(dist == -1){
			fprintf(stderr, "\nERROR: tree.c: chkNode: Identifier "
					"%s on line %d at char %d has not been"
					" Initialized!\n", 
					element->tk.tokenInstance, 
					element->tk.row, element->tk.column);
			exit(); 
		}
	}

}
#endif
