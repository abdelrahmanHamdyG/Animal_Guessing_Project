#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "global_data.h"

void traverse(node* head, node** copy);

void validateTheOutput(node* head, node** copy) {
	printf("did I get it right? \n");
	char answer[110];
	fgets(answer, 80, stdin);
	if (answer[0] == 'y' || answer[0] == 'Y') {
		printf("Thank you\n");
		printf("Do you want to play again?\n");
		char ans[10];
		scanf("%s", ans);

		if (strcmp(ans, "yes") == 0 || ans[0] == 'y' || ans[0] == 'Y' || strcmp(ans, "Yes") == 0) {
			traverse(*copy, copy);
			return;
		}

	}
	else {

		// you will need to scan a question and correct answer from the user and assign their numbers to nOfQuestion 
		//  and nOfAnswer 
		// instead of reading integers
		// æáÇÒã ÇÑÞÇãåã Êßæä ÌÏíÏå  , ÑÞã ããíÒ ãÔ ãÍÌæÒ ãä ÓÊÑíäÌ ÊÇäí 
		printf("Enter the Question\n");
		char nOfQuestion[100];
		char nOfAnswer[100];
		fgets(nOfQuestion, 80, stdin);
		printf("Enter the animal you was thinking of \n");
		fgets(nOfAnswer, 80, stdin);
		//scanf("%d", &nOfAnswer);
		node* newYes = (struct node*)malloc(sizeof(struct node));
		node* newNo = (struct node*)malloc(sizeof(struct node));
		int temp = head->digit;
		head->digit = ++maxNode;
		strcpy(questionsAndAnswers[maxNode], nOfQuestion);
		newYes->digit = ++maxNode;
		strcpy(questionsAndAnswers[maxNode], nOfAnswer);
		newYes->yes = NULL;
		newYes->no = NULL;
		newNo->digit = temp;
		newNo->yes = NULL;
		newNo->no = NULL;
		head->yes = newYes;
		head->no = newNo;
		printf("Thank You!\n");
		printf("Do you want to play again?\n");


		char hh[10];

		scanf("%s", hh);
		if (strcmp(hh, "yes") == 0 || hh[0] == 'y' || hh[0] == 'Y' || strcmp(hh, "Yes") == 0) {
			traverse(*copy, copy);
			return;
		}
		//store(*copy, copy);
		//store2();

	}
}
void traverse(node* head, node** copy) {
	node* temp = head;
	if (temp == NULL) {
		printf("NULL\n");

		int answer;
		scanf("%d", &answer);

		if (answer == 1) {
			printf("%d", temp->yes->digit);
			printEquivalent(temp->yes->digit);
			validateTheOutput(temp->yes, copy);
		}
		else {
			printf("%d", temp->no->digit);
			printEquivalent(temp->no->digit);
			validateTheOutput(temp->no, copy);
		}
	}
	//printf("%d\n", temp->digit);
	printEquivalent(temp->digit);
	if (temp->yes == NULL && temp->no == NULL) validateTheOutput(temp, copy);
	else {
		//int answer;
		//scanf("%d", &answer);
		char answer[110];
		fgets(answer, 80, stdin);
		if (!strcmp(answer, "\n")) {
			fgets(answer, 80, stdin);
		}

		if (strcmp(answer, "yes") == 0 || answer[0] == 'y' || answer[0] == 'Y' || strcmp(answer, "Yes") == 0)
			traverse(temp->yes, copy);
		else traverse(temp->no, copy);
	}
}
