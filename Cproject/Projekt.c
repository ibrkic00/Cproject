#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct cvor* Pozicija;

typedef struct cvor
{
	long element;
	Pozicija next;
}Cvor;

bool isNum(char);

long kalkulator(long, long, char);

void Push(Pozicija, long);

long Pop(Pozicija);

Pozicija AlocirajNoviElement();

int main()
{
	char postfix[20];
	long op1, op2;
	long rezultat;
	FILE* datoteka;
	Pozicija head = NULL;
	head = (Pozicija)malloc(sizeof(Cvor));
	head->next = NULL;
	
	datoteka = fopen("postfix.txt", "r");

	while (!feof(datoteka))
	{
		fscanf(datoteka, "%s", postfix);

		if (isNum(postfix[0]))
			Push(head, atoi(postfix));
		
		else
		{
			op1 = Pop(head);
			op2 = Pop(head);
			Push(head, kalkulator(op1, op2, postfix[0]));
		}
	}
	
	rezultat = Pop(head);

	printf("%d", rezultat);

	fclose(datoteka);
	

	return 0;
}

void Push(Pozicija head, long broj)
{
	Pozicija noviCvor = AlocirajNoviElement();
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = noviCvor;
	noviCvor->next = NULL;
	noviCvor->element = broj;
}

Pozicija AlocirajNoviElement()
{
	Pozicija novi;
	novi = (Pozicija)malloc(sizeof(Cvor));
	return novi;
}



long Pop(Pozicija head)
{
	Pozicija pom;
	long op;
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	op = head->next->element;
	free(head->next);
	head->next = NULL;
	return op;
}

bool isNum(char simbol)
{
	return (simbol >= '0' && simbol <= '9');
}

long kalkulator(long op1, long op2, char znak)
{
	switch (znak)
	{
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1 * op2;
		break;
	case '/':
		return op1 / op2;
		break;
	default:
		return -2;
		break;
	}
}