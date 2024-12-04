#pragma once
#include <stdio.h>
#include "Atrybut.h"

class Selektor {
private:
    Selektor* prev;
    char* name;
    Selektor* next;

public:
    Selektor(char* str);
    Selektor(Selektor*& other);
    ~Selektor();
    char* getName() const;
    void addFirst(Selektor*& firstNode, char* name);
    void addLast(Selektor*& firstNode, char* name);
    void removeFirst(Selektor*& firstNode);
    void removeLast(Selektor*& firstNode);
    void printList(Selektor* firstNode);
    int getListLen(Selektor* firstNode);
    Selektor* GetFirst(Selektor* firstNode);
    Selektor* GetLast(Selektor* firstNode);
    Selektor* GetByIndex(Selektor* firstNode, int i);
    Selektor* GetByName(Selektor* firstNode, char* str);
};


