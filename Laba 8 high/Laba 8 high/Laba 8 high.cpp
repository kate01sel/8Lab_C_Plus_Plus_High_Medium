#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Word
{
	char word;
	struct Word *next = NULL;
};
struct Word *head = NULL;
struct Word*savehead = NULL;

void push();
void pop();
void proverka();
char posl[20] = { '(',')','(',')','[',']','[','[',']',']','[',']','[',']','(',')' };
int i;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1)
	{
		int action = 0;
		setlocale(LC_ALL, "Russian");
		cout <<"Ваша последовательнось скобок: \t" << posl << endl;
		cout <<"1. Ввод последовательности открывающихся скобок" << endl;
		cout <<"2. Вывод" <<endl;
		cout <<"3. Проверка на правильность" << endl;
		cout <<"0. Выход" << endl;
		cout <<"Ваш Выбор: " << endl;
		cin >> action;

		if (action == 0)
		{
			system("CLS");//Очистка экрана
			break;
		}

		if (action == 1)
		{
			system("CLS");
			push();
			system("CLS");
			continue;
		}

		if (action == 2)
		{
			system("CLS");
			pop();
			system("pause");
			system("CLS");
			continue;
		}

		if (action == 3)
		{
			proverka();
			system("CLS");
			continue;
		}
	}
	return 0;
}

void push()
{
	for (i = 0; i < strlen(posl); i++)
	{
		if (posl[i] == '(' || posl[i] == '[' || posl[i] == '{')
		{
			savehead = new Word();
			savehead->next = head;
			head = savehead;
			savehead = NULL;
			head->word = posl[i];
		}
	}
	system("pause");
}

void pop()
{
	cout << "Ваша последовательность: \n";
	for (savehead = head; savehead != NULL; savehead = savehead->next)
		cout << savehead->word << " ";

}

void proverka()
{
	for (i = strlen(posl) - 1; i >0; i--)
	{
		//cout «"head "« head->word « endl « "posl " « posl [i]«endl;
		if (posl[i] == ')' || posl[i] == ']' || posl[i] == '}')
		{
			if (head->word == '(' && posl[i] == ')')
			{
				head = head->next;
				continue;
			}
			else if (head->word == '[' && posl[i] == ']')
			{
				head = head->next;
				continue;
			}
			else if (head->word == '{' && posl[i] == '}')
			{
				head = head->next;
				continue;
			}
			else
			{
				cout << "Ваша последовательность не являеться правильной!" << endl;
				break;
			}

		}
	}
	system("pause");
}