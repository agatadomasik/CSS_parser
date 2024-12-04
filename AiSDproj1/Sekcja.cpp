#include <stdio.h>
#include <string.h>
#include "Sekcja.h"
#include "Selektor.h"
#include "Atrybut.h"

Sekcja::Sekcja() {
    //prev = NULL;
    atrybuty = NULL;
    selektory = NULL;
    //next = NULL;
}

int Sekcja::cnt = 0;

Sekcja::Sekcja(Selektor*& selektory, Atrybut*& atrybuty) {
    this->atrybuty = new Atrybut(atrybuty);
    this->selektory = new Selektor(selektory);
    //cnt++;
}

Sekcja::Sekcja(Sekcja*& other) {
    //printf("COPY CONSTRUCTOR SEKCJA\n");
    this->atrybuty = new Atrybut(other->atrybuty);
    this->selektory = new Selektor(other->selektory);
    cnt++;
}

Sekcja::~Sekcja() {
    //atrybuty->~Atrybut();
    //selektory->~Selektor();
    //delete[] atrybuty;
    //delete[] selektory;
}

int Sekcja::getCnt() const {
    return cnt;
}

Selektor* Sekcja::getSelektory() const {
    if (this!=NULL) return selektory;
    return NULL;
}

Atrybut* Sekcja::getAtrybuty() const {
    if (this!=NULL) return atrybuty;
    return NULL;
}

void Sekcja::print() const {
    if (this != NULL) {
        printf("Sekcja: \n");
        selektory->printList(selektory);
        atrybuty->printList(atrybuty);
    }
}

bool Sekcja::findSelName(char* str) {
    if (selektory->GetByName(selektory, str) != NULL) return true;
    return false;
}

bool Sekcja::findAttName(char* str) {
    if (atrybuty->GetByName(atrybuty, str) != NULL) return true;
    return false;
}

void Sekcja::deleteSekcja() {
    //printf("USUWAM\n");
    atrybuty = NULL;
    selektory = NULL;
}
