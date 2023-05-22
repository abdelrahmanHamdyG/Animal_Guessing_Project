#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "global_data.h"
#include "data.h"
#include"game.h"

int main() {
	counter = 0;
	getData();
	node* head = NULL;
	recurseOnData(0, &head);
	traverse(head, &head);
	store(head, &head);
	store2();

}