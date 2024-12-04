#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Selektor.h"

Selektor::Selektor(char* str) {
    prev = NULL;
    name = str;
    next = NULL;
}

Selektor::Selektor(Selektor*& other) {
    //printf("COPY CONSTRUCTOR\n");
    prev = other->prev;
    next = other->next;

    if (other->name == NULL) {
        name = NULL;
    }
    else {
        name = new char[strlen(other->name) + 1];
        strcpy(name, other->name);
    }
}

Selektor::~Selektor() {
    //delete[] name;
}

char* Selektor::getName() const {
    if (this == NULL) return NULL;
    else return name;
}

void Selektor::addFirst(Selektor*& firstNode, char* name) {
    Selektor* newNode = new Selektor(name);
    newNode->next = firstNode;

    if (firstNode != NULL) {
        firstNode->prev = newNode;
    }
    firstNode = newNode;
}

void Selektor::addLast(Selektor*& firstNode, char* name)
{

    if (firstNode == NULL) {
        addFirst(firstNode, name);
        return;
    }

    Selektor* newNode = new Selektor(name);
    Selektor* temp = firstNode;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Selektor::removeFirst(Selektor*& firstNode) {
    if (firstNode != NULL) {
        firstNode = firstNode->next;
    }
}

void Selektor::removeLast(Selektor*& firstNode) {
    if (firstNode != NULL || firstNode->next != NULL) {
        Selektor* temp = firstNode;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp = NULL;
    }
}

void Selektor::printList(Selektor* firstNode)
{
    printf("Selektory: \n");
    Selektor* temp = firstNode;
    while (temp != NULL) {
        printf("selName: %s\n", temp->name);
        temp = temp->next;
    }
}

int Selektor::getListLen(Selektor* firstNode) {
    Selektor* temp = firstNode;
    int cnt = 0;
    while (temp != NULL) {
        //temp->printList(temp);
        if (temp->getName() == NULL)return -1;
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Selektor* Selektor::GetFirst(Selektor* firstNode) {
    if (firstNode == NULL) return NULL;
    return firstNode;
}

Selektor* Selektor::GetLast(Selektor* firstNode) {
    if (firstNode == NULL) return NULL;
    Selektor* tmp = firstNode;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

Selektor* Selektor::GetByIndex(Selektor* firstNode, int i) {
    if (firstNode == NULL) return NULL;
    int j = 0;
    Selektor* tmp = firstNode;
    while (j < i && tmp->next != NULL) {
        tmp = tmp->next;
        j++;
    }
    if (j == i) return tmp;
    else return NULL;
}

bool equal(char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL)return false;
    if (strlen(str1) != strlen(str2)) return false;
    for (int i = 0; i < strlen(str1); i++)
        if (str1[i] != str2[i])return false;
    return true;
}

Selektor* Selektor::GetByName(Selektor* firstNode, char* str) {
    if (firstNode == NULL) return NULL;
    Selektor* tmp = firstNode;
    while (!equal(tmp->name, str) && tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (equal(tmp->name, str)) return tmp;
    else return NULL;
}