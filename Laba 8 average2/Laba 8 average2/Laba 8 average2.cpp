#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct stack
{
	int number;
	struct stack *next = NULL;

};
struct stack *head = NULL;
struct stack *savehead = NULL;

int create();
void push();
void pop();

int main()
{
	create();
	 push();
	 pop();
	return 0;
}
int create()
{
	head = new stack();
	if (head == NULL)
		return 0;
	head->next = NULL;
}
void push()
{
	int N;
	cout << "N: ";
	cin >> N;
	int i;
	for (i = 0; i<N; i++) {
		savehead = new stack();
		savehead->next = head;
		head = savehead;
		savehead = NULL;
		cin >> head->number;
	}
}
void pop()
{
	for (savehead = head; savehead != NULL; savehead = savehead->next)
	{
		cout << savehead->number << endl;
	}
}