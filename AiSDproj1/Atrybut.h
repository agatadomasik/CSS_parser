#pragma once
#include <stdio.h>

class Atrybut {
private:
    Atrybut* prev;
    char* name;
    char* value;
    Atrybut* next;
public:
    Atrybut(char* name, char* value);
    Atrybut(Atrybut*& other);
    ~Atrybut();
    char* getName();
    char* getValue();
    void addFirst(Atrybut*& firstNode, char* name, char* value);
    void addLast(Atrybut*& firstNode, char* name, char* value);
    void removeFirst(Atrybut*& firstNode);
    void removeLast(Atrybut*& firstNode);
    void removeByName(Atrybut*& firstNode, char* str);
    void replaceValue(Atrybut*& firstNode, char* str, char* newValue);
    //void removeByName(Atrybut*& firstNode, char* str);
    void printList(Atrybut* firstNode);
    int getListLen(Atrybut* firstNode);
    Atrybut* GetFirst(Atrybut* firstNode);
    Atrybut* GetLast(Atrybut* firstNode);
    Atrybut* GetByName(Atrybut* firstNode, char* str);

};



