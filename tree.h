#ifndef TREE_H_
#define TREE_H_
#include "node.h"
#include <stdio.h>
#include <string.h>
//list of token and nonterminal names for reference


struct node* newTermNode(Ttoken* tk); // Allocate memory for new node
struct node* newNode(char* nonTerms); // Allocate memory for new node

void printPreOrder(struct node* dataNode, int depth);
void deleteTree(struct node* dataNode);
void statSem(node *dataNode, int* IDCount);
void preStat(node *dataNode, int* IDCount);
void chkNode(node* dataNode, int* IDCount);

#endif
