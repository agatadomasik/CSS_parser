#pragma once
#include <stdio.h>
#include <string.h>
#include "Selektor.h"
#include "Atrybut.h"

class Sekcja {
private:
    Selektor* selektory;
    Atrybut* atrybuty;
    static int cnt;
public:
    Sekcja();
    Sekcja(Selektor*& selektory, Atrybut*& atrybuty);
    Sekcja(Sekcja*& other);
    ~Sekcja();
    int getCnt() const;
    void print() const;
    void deleteSekcja();
    Selektor* getSelektory() const;
    Atrybut* getAtrybuty() const;
    bool findSelName(char* str);
    bool findAttName(char* str);
};