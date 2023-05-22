#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "global_data.h"

void store2() {
	FILE* ptr;
	ptr = fopen("data.txt", "a");
	fprintf(ptr, "%c", '*');
	fprintf(ptr, "%c", '\n');
	for (int i = 0; i < 300; i++) {
		if (strcmp(questionsAndAnswers[i], "") != 0)
		{
			fprintf(ptr, "%d", i);
			fprintf(ptr, "%s", questionsAndAnswers[i]);
		}
	}
}
void store(node* temp, node** copy) {
	static int flag = 1;
	if (flag) {
		FILE* ptr;
		ptr = fopen("data.txt", "w");
		fprintf(ptr, "%d ", temp->digit);
		fprintf(ptr, "%d ", temp->yes->digit);
		fprintf(ptr, "%d\n", temp->no->digit);
		flag--;
		store(temp->yes, copy);
		store(temp->no, copy);
	}
	else {
		FILE* ptr;
		ptr = fopen("data.txt", "a");
		if (temp->yes != NULL && temp->no != NULL) {
			fprintf(ptr, "%d ", temp->digit);
			fprintf(ptr, "%d ", temp->yes->digit);
			fprintf(ptr, "%d\n", temp->no->digit);
			store(temp->yes, copy);
			store(temp->no, copy);
		}
	}
}
void getdata2() {
	FILE* file;
	char c[100];
	file = fopen("data.txt", "r");
	char x = '0';
	while (true) {
		x = fgetc(file);
		if (x == '*')
			break;
	}
	while (!feof(file))
	{
		int y;
		if (!fscanf(file, "%d", &y))
			break;
		fgets(c, 80, file);
		strcpy(questionsAndAnswers[y], c);
	}
}
void getData() {
	FILE* ptr;
	ptr = fopen("data.txt", "r+");
	int from, yes, no;
	while (!feof(ptr)) {
		if (!fscanf(ptr, "%d", &from))
			break;
		fscanf(ptr, "%d", &yes);
		fscanf(ptr, "%d", &no);
		struct dataFromFile d;
		d.from = from;
		d.yes = yes;
		d.no = no;
		if (d.from > maxNode)
			maxNode = d.from;

		if (d.yes > maxNode)
			maxNode = d.yes;

		if (d.no > maxNode)
			maxNode = d.no;

		gettedFrom[counter] = d;
		counter++;
	}
	getdata2();
}
void recurseOnData(int j, node** head) {
	struct dataFromFile s = gettedFrom[j];
	if (*head == NULL) *head = (struct node*)malloc(sizeof(struct node));
	(*head)->digit = s.from;
	node* yes = (struct node*)malloc(sizeof(struct node));
	node* no = (struct node*)malloc(sizeof(struct node));
	yes->digit = s.yes;
	no->digit = s.no;
	yes->yes = NULL;
	yes->no = NULL;
	no->no = NULL;
	no->yes = NULL;
	(*head)->yes = yes;
	(*head)->no = no;
	for (int i = 0; i < counter; i++) {
		if (gettedFrom[i].from == s.yes) recurseOnData(i, &((*head)->yes));
		if (gettedFrom[i].from == s.no) recurseOnData(i, &((*head)->no));
	}
}


