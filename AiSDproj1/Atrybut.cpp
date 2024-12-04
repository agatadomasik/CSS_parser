#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Atrybut.h"

Atrybut::Atrybut(char* name, char* value) {
    prev = NULL;
    this->name = name;
    this->value = value;
    next = NULL;
}

Atrybut::Atrybut(Atrybut*& other) {
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

    if (other->value == NULL) {
        value = NULL;
    }
    else {
        value = new char[strlen(other->value) + 1];
        strcpy(value, other->value);
    }
}

Atrybut::~Atrybut() {
    //printf("DESTRUKTOR ATRYBUTU\n");
    //delete[] name;
    //delete[] value;
}

char* Atrybut::getName() {
    if (this == NULL) return NULL;
    else return name;
}

char* Atrybut::getValue() {
    if (this == NULL) return NULL;
    else return value;
}

bool equals(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return false;
    for (int i = 0; i < strlen(str1); i++)
        if (str1[i] != str2[i])return false;
    return true;
}

void Atrybut::addFirst(Atrybut*& firstNode, char* name, char* value)
{

    Atrybut* newNode = new Atrybut(name, value);
    newNode->next = firstNode;

    if (firstNode != NULL) {
        firstNode->prev = newNode;
    }

    firstNode = newNode;
}

void Atrybut::addLast(Atrybut*& firstNode, char* name, char* value)
{

    if (firstNode == NULL) {
        addFirst(firstNode, name, value);
        return;
    }

    Atrybut* newNode = new Atrybut(name, value);
    Atrybut* temp = firstNode;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Atrybut::removeFirst(Atrybut*& firstNode) {
    if (firstNode != NULL) {
        firstNode = firstNode->next;
    }
}

void Atrybut::removeLast(Atrybut*& firstNode) {
    if (firstNode != NULL || firstNode->next != NULL) {
        Atrybut* temp = firstNode;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp = NULL;
    }
}


//void Atrybut::removeByName(Atrybut*& head, char* str) {
//    Atrybut* current = head;
//    while (current != NULL && !equals(current->name, str)) {
//        current = current->next;
//    }
//    if (current == NULL) {
//        return; // Value not found in list
//    }
//    if (current->prev != NULL) {
//        current->prev->next = current->next;
//    }
//    else {
//        head = current->next;
//    }
//    if (current->next != NULL) {
//        current->next->prev = current->prev;
//    }
//    //delete current;
//}

//void Atrybut::removeByName(Atrybut*& firstNode, char* str) {
//    Atrybut* tmp = firstNode;
//    while (tmp!=NULL) {
//        if (equals(tmp->name, str)) {
//            printf("USUWAM\n");
//            if (tmp->prev != NULL)tmp->prev->next = tmp->next;
//            else firstNode = tmp->next;
//            if (tmp->next != NULL)tmp->next->prev = tmp->prev;
//            //delete tmp;
//            tmp = NULL;
//            //delete tmp;
//            break;
//        }
//        tmp = tmp->next;
//    }

    //else printf("NIE USUWAM\n");

    //printf("FIRSTNODE PRINTLIST: \n");
    //firstNode->printList(firstNode);
    //printf("TEMP PRINTLIST: \n");
    //tmp->printList(tmp);
    //firstNode = tmp;
//}

void Atrybut::removeByName(Atrybut*& firstNode, char* str) {
    Atrybut* tmp = firstNode;
    while (tmp != NULL) {
        if (equals(tmp->name, str)) {
            //printf("USUWAM\n");
            if (tmp->prev != NULL) tmp->prev->next = tmp->next;
            else firstNode = tmp->next;
            if (tmp->next != NULL) tmp->next->prev = tmp->prev;
            tmp = NULL;
            return;
        }
        //else printf("NIE USUWAM\n");
        tmp = tmp->next;
    }
}


//void Atrybut::removeByName(Atrybut*& head, char* str) {
//    // Start from the head of the list
//    Atrybut* current = head;
//
//    // Traverse the list until we find the node with the given value
//    while (current != NULL) {
//        if (equals(current->name,str)) {
//            // If this is the head of the list, update the head
//            if (current == head) {
//                head = current->next;
//            }
//
//            // Update the pointers of the neighboring nodes to skip over the current node
//            if (current->prev != NULL) {
//                current->prev->next = current->next;
//            }
//            if (current->next != NULL) {
//                current->next->prev = current->prev;
//            }
//
//            // Delete the current node
//            //delete current;
//            current = NULL;
//            return;
//        }
//        current = current->next;
//    }
//}



void Atrybut::replaceValue(Atrybut*& firstNode, char* str, char* newValue) {
    if (firstNode != NULL) {
        Atrybut* temp = firstNode;

        while (!equals(temp->name, str) && temp->next != NULL) {
            temp = temp->next;
        }
        if (equals(temp->name, str)) {
            temp->value = newValue;
        }
    }
}

void Atrybut::printList(Atrybut* firstNode)
{
    printf("Atrybuty: \n");
    Atrybut* temp = firstNode;
    while (temp != NULL) {
        printf("attName: %s attValue: %s \n", temp->name, temp->value);
        temp = temp->next;
    }
}

int Atrybut::getListLen(Atrybut* firstNode) {
    Atrybut* temp = firstNode;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Atrybut* Atrybut::GetFirst(Atrybut* firstNode) {
    if (firstNode == NULL) return NULL;
    return firstNode;
}

Atrybut* Atrybut::GetLast(Atrybut* firstNode) {
    if (firstNode == NULL) return NULL;
    Atrybut* tmp = firstNode;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

Atrybut* Atrybut::GetByName(Atrybut* firstNode, char* str) {
    if (firstNode == NULL) return NULL;
    Atrybut* tmp = firstNode;
    while (!equals(tmp->name, str) && tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (equals(tmp->name, str)) return tmp;
    else return NULL;
}

