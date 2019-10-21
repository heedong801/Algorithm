#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED 0
#define BLACK 1
typedef struct node
{
	int key;
	int color;
	struct node *left, *right, *pa;
}node;

node *head;
node *tail;
node *p;
node *NIL;

void left_rotate(node *x);
void right_rotate(node *x);
int RB_insertfix(node*);
int RB_insert(node*, int data);

int DataNum;