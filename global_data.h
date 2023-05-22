#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct node {
	int digit;
	struct node* yes;
	struct node* no;
} node;
struct dataFromFile {
	int from, yes, no;
};

char questionsAndAnswers[301][100] = { "" };
struct dataFromFile gettedFrom[301];
void printEquivalent(int node) {
	printf(questionsAndAnswers[node]);
}

int maxNode = -1;


int counter;
