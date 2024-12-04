#pragma once
#include "Sekcja.h"



class Blok {
private:
	Blok* prev;
	Sekcja* sekcje;
	static int taken;
	static int deleted;
	int T;
	Blok* next;

public:
	//CSS();
	Blok(Sekcja*& s);
	~Blok();
	void addSekcja(Blok*& firstNode, Sekcja*& s);
	void addFirst(Blok*& firstNode, Sekcja*& s);
	void addLast(Blok*& firstNode, Sekcja*& s);
	int getListLen(Blok* firstNode);
	int getTaken(Blok*& firstNode);
	int liczbaSekcji(Blok*& firstNode);
	Sekcja* getSekcja(Blok* firstNode, int i);
	Blok* getBlokByIndex(Blok* firstNode, int i);
	Sekcja* getSekcjaByIndex(Blok* firstNode, int i);
	int selNameNum(Blok* firstNode, char* str);
	int attNameNum(Blok* firstNode, char* str);
	char* function(Blok* firstNode, char* z, char* n);
	void deleteSekcjaByIndex(Blok*& firstNode, int i);
	void printList(Blok* firstNode);
};