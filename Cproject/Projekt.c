#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct cvor* Pozicija;

typedef struct cvor
{
	int element;
	Pozicija next;
}Cvor;

void DodajCvor(Pozicija, int);

void UkloniCvor(Pozicija);

Pozicija AlocirajNoviElement();

void IspisListe(Pozicija);

int main()
{
	int broj;
	Pozicija head = NULL;
	head = (Pozicija)malloc(sizeof(Cvor));
	head->next = NULL;
	
	printf("Unesi broj: ");
	scanf("%d", &broj);
	

	return 0;
}

void DodajCvor(Pozicija head, int broj)
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

void IspisListe(Pozicija head)
{
	head = head->next;
	while (head->next != NULL)
	{
		printf("%d  ", head->element);
		head = head->next;
	}
	printf("%d  ", head->element);
}