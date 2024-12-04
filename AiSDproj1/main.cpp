#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Atrybut.h"
#include "Selektor.h"
#include "Sekcja.h"
#include "Blok.h"

bool section_end = false;
bool command_section = false;
bool end = false;

int actual_len(char* str) {
    //printf("1");
    int len = strlen(str);
    int i = 0;
    int j = len - 1;
    //printf("2");

    while (isspace(str[i])) {
        i++;
    }

    while (j >= i && isspace(str[j])) {
        j--;
    }
    //printf("4");
    return j - i + 1;
}

int actual_len_front(char* str) {
    if (str == NULL)return 0;
    //int len = strlen(str);
    //while (len > 0 && isspace(str[len - 1])) {
    //    len--;
    //}
    //return len;
    while (isspace(*str)) {
        str++;
    }
    return strlen(str);
}

int count_char(char* str, char c) {
    int cnt = 0;
    while (*str != '\0') {
        if (*str == c) cnt++;
        str++;
    }
    return cnt;
}

bool equals(char* str, const char* command) {
    if (str == NULL)return false;
    if (strlen(str) != strlen(command)) return false;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] != command[i])return false;
    return true;
}

bool is_number(char* str) {
    if (str[0] >= '0' && str[0] <= '9') return true;
    return false;
}

int to_number(char* str) {
    int n = 0;
    while (*str != '\0') {
        n = n * 10 + (*str - 48);
        str++;
    }
    return n;
}



//char* substr(const char* str, int start, int length) {
//    int strLength = 0;
//    while (str[strLength] != '\0') {
//        strLength++;
//    }
//    if (start >= strLength) {
//        return NULL;
//    }
//    if (start + length > strLength) {
//        length = strLength - start;
//    }
//    char* substr = new char[length + 1];
//    int i;
//    for (i = 0; i < length; i++) {
//        substr[i] = str[start + i];
//    }
//    substr[length] = '\0';
//    return substr;
//}

void test_char(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%i. char: %c int: %i\n", i, str[i], str[i]);
    }
}

void skip_char(int n) {
    for (int i = 0; i < n; i++) {
        char c = getchar();
    }
}

char* read_until(char stop_char) {
    char* str = new char[1];
    int c;
    int i = 0;

    while ((c = getchar()) && c != stop_char) {
        if (c == EOF) {

            end = true;
            exit(0);
        }
        if (c == '}') {
            section_end = true;
            break;
        }
        if (command_section == false && c == '?') {
            command_section = true;
            skip_char(4);
            break;
        }
        str[i++] = (char)c;
        char* temp = new char[i + 1];
        for (int j = 0; j < i; j++) {
            temp[j] = str[j];
        }
        //delete[] str;
        str = temp;
        //if (equals(str, "????")) break;
        //delete[] temp;
    }

    str[i] = 0;

    return str;
}


char* read_until(char stop_char, Blok* head) {
    char* str = new char[1];
    int c;
    int i = 0;

    while ((c = getchar()) && c != stop_char) {
        if (c == '}') {
            section_end = true;
            break;
        }
        if (command_section == false && c == '?') {
            command_section = true;
            skip_char(4);
            break;
        }

        if (c == EOF) {
            str[i] = 0;
            if (equals(str, "?")) printf("? == %i", head->liczbaSekcji(head));
            end = true;
            exit(0);
        }

        str[i++] = (char)c;
        char* temp = new char[i + 1];
        for (int j = 0; j < i; j++) {
            temp[j] = str[j];
        }
        //delete[] str;
        str = temp;
        //if (equals(str, "????")) break;
        //delete[] temp;
    }

    str[i] = 0;

    return str;
}

//char* read_until(char stop_char) {
//    const int BUFFER_SIZE = 1024;
//    char* str = new char[BUFFER_SIZE];
//    int i = 0;
//
//    char buffer[BUFFER_SIZE];
//    int n = 0;
//    while (n < BUFFER_SIZE - 1) {
//        int c = getchar();
//        if (c == EOF) {
//            end = true;
//            exit(0);
//        }
//        if (c == '}') {
//            section_end = true;
//            break;
//        }
//        if (command_section == false && c == '?') {
//            command_section = true;
//            skip_char(4);
//            break;
//        }
//        if (c == stop_char) {
//            break;
//        }
//        buffer[n++] = (char)c;
//    }
//    buffer[n] = 0;
//
//    int len = strlen(buffer);
//    if (len > BUFFER_SIZE - 1) {
//        len = BUFFER_SIZE - 1;
//    }
//    memcpy(str, buffer, len);
//    str[len] = 0;
//
//    return str;
//}


char* substr_until(char* str, int start, char stop_char) {
    while (isspace(*str)) {
        str++;
    }
    str += start;

    int len = 0;
    while (str[len] != stop_char && str[len] != 0) {
        len++;
    }

    char* substr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        substr[i] = str[i];
    }
    substr[len] = 0;

    return substr;
}

char* substr_until(char* str, int start, char stop_char1, char stop_char2) {
    while (str != NULL && isspace(*str)) {
        str++;
    }

    str += start;

    int len = 0;

    while (str[len] != 0 && str[len] != stop_char2 && str[len] != stop_char1) {
        len++;
    }
    if (len <= 0)return NULL;
    while (isspace(str[len - 1])) len--;
    if (len <= 0)return NULL;

    char* substr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        substr[i] = str[i];
    }
    substr[len] = 0;

    return substr;
}


char* substr_until(char* str, int start) {
    if (str == NULL) return NULL;
    while (isspace(*str)) {
        str++;
    }
    str += start;

    if (*str < 33)str++;

    int len = 0;
    while (str[len] != 0) {
        len++;
    }

    char* substr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        substr[i] = str[i];
    }
    substr[len] = 0;

    return substr;
}


void sel(char* str, Selektor*& selektory) {
    //printf("PRZED PETLA\n");
    char* selName = NULL;
    if (actual_len_front(str) <= 0) {
        //printf("PUSTY SELEKTOR\n");
        //printf("LIST LEN: %i\n", selektory->getListLen(selektory));
        selektory->addLast(selektory, selName);
        //printf("LIST LEN: %i\n", selektory->getListLen(selektory));
    }
    //if (selName == NULL) printf("NULL\n");
    int start = 0;
    //printf("strlen %i\n", strlen(str));
    //printf("ACTUAL LEN %i\n", actual_len_front(str));
    while (start < actual_len_front(str)) {
        //printf("POCZATEK PETLI\n");
        selName = substr_until(str, start, ',', '{');
        //printf("SELNAME->%s<-\n", selName);
        if (selName == NULL) printf("NULL\n");
        //printf("PO SUBSTR\n");
        //printf("start %i\n", start);


        if (selektory->GetByName(selektory, selName) == NULL) selektory->addLast(selektory, selName);


        //printf("PO IF\n");
        start += strlen(selName) + 2;
        //printf("next start %i\n", start);
        //delete[] selName;
    }
    //printf("HALO\n");
}

void att(char* str, Atrybut*& atrybuty, Selektor*& selektory) {
    while (section_end == false) {
        str = read_until(';');
        //printf("line->%s\n", str);
        char* attName = substr_until(str, 0, ':');
        char* attValue = substr_until(str, strlen(attName) + 1);
        if (section_end == false) {
            //printf("attName->%s\n", attName);
            //printf("attValue->%s\n", attValue);
            if (atrybuty->GetByName(atrybuty, attName) == NULL) atrybuty->addLast(atrybuty, attName, attValue);
            else atrybuty->replaceValue(atrybuty, attName, attValue);

            //atrybuty->addLast(atrybuty, attName, attValue);
            //delete[] attName;
            //delete[] attValue;
        }
    }
    section_end = false;
}


void com1(Blok* head, char** com) {
    //printf("com1\n");
    int i = to_number(com[0]);
    int temp = head->getSekcjaByIndex(head, i)->getSelektory()->getListLen(head->getSekcjaByIndex(head, i)->getSelektory());
    //head->getSekcjaByIndex(head, i).print();
    if(temp>0)printf("%i,S,? == %i\n", i, temp);
    if (temp == -1)printf("%i,S,? == 0\n", i);
}

void com2(Blok* head, char** com) {
    //printf("com2\n");
    int i = to_number(com[0]);
    int temp = head->getSekcjaByIndex(head, i)->getAtrybuty()->getListLen(head->getSekcjaByIndex(head, i)->getAtrybuty());
    //head->getSekcjaByIndex(head, i).getAtrybuty()->printList(head->getSekcjaByIndex(head, i).getAtrybuty());
    if (temp > 0)printf("%i,A,? == %i\n", i, temp);
}

void com3(Blok* head, char** com) {
    //printf("com3\n");
    int i = to_number(com[0]);
    int j = to_number(com[2]);
    char* temp = head->getSekcjaByIndex(head, i)->getSelektory()->GetByIndex(head->getSekcjaByIndex(head, i)->getSelektory(), j - 1)->getName();
    if (temp != NULL) printf("%i,S,%i == %s\n", i, j, temp);
}

void com4(Blok* head, char** com) {
    //printf("com4\n");
    int i = to_number(com[0]);
    char* n = com[2];
    char* temp = head->getSekcjaByIndex(head, i)->getAtrybuty()->GetByName(head->getSekcjaByIndex(head, i)->getAtrybuty(), n)->getValue();
    if (temp != NULL) printf("%i,A,%s == %s\n", i, n, temp);
}

void com5(Blok* head, char** com) {
    char* n = com[0];
    int i = head->attNameNum(head, n);
    printf("%s,A,? == %i\n", n, i);
}

void com6(Blok* head, char** com) {
    char* z = com[0];
    int i = head->selNameNum(head, z);
    printf("%s,S,? == %i\n", z, i);
}

void com7(Blok* head, char** com) {
    char* z = com[0];
    char* n = com[2];
    if(head->function(head, z, n)!=NULL)printf("%s,E,%s == %s\n", z, n, head->function(head, z, n));
}

void com8(Blok* head, char** com) {
    int i = to_number(com[0]);
    Atrybut* temp = head->getSekcjaByIndex(head, i)->getAtrybuty();
    if (temp->getListLen(temp) != 0) {
        //head->getSekcjaByIndex(head, i).print();
        head->deleteSekcjaByIndex(head, i);
        printf("%i,D,* == deleted\n", i);
    }
    //head->getSekcjaByIndex(head, i).print();
}

void com9(Blok* head, char** com) {
    int i = to_number(com[0]);
    char* n = com[2];
    //printf("NAME->%s<-", n);
    Atrybut* temp = head->getSekcjaByIndex(head, i)->getAtrybuty();
    //head->getSekcjaByIndex(head, i).getAtrybuty()->removeByName(head->getSekcjaByIndex(head, i).getAtrybuty(), n);
    //printf("DLUGOSC LISTY ATRYBUTOW: %i\n", temp->getListLen(temp));
    if (temp->getListLen(temp) != 0) {
        //temp->printList(temp);
        if (temp->GetByName(temp, n) != NULL) printf("%i,D,%s == deleted\n", i, n);
        temp->removeByName(temp, n);
        //printf("DLUGOSC LISTY ATRYBUTOW: %i\n", temp->getListLen(temp));
        //temp->printList(temp);
        if (temp->getListLen(temp) == 0) {
            head->deleteSekcjaByIndex(head, i);
            //printf("USUWAM PUSTA SEKCJE\n");
        }
    }
}

int main() {
    Blok* head = NULL;
    int pom = 0;
    while (!end) {
        char* str;
        //Sekcja* sekcje = NULL;
        do {
            //printf("CSS READING\n");
            Selektor* selektory = NULL;
            Atrybut* atrybuty = NULL;
            str = read_until('{');
            if (end)break;
            //printf("HALO\n");
            //printf("line->%s\n", str);
            if (!command_section) {
                //printf("HALO\n");
                sel(str, selektory);
                //printf("HALO\n");
                att(str, atrybuty, selektory);
                //printf("SELEKTOR O INDEKSIE 1: %s\n", selektory->GetByIndex(selektory, 1)->getName());
                //const char* a = "width";
                //char* b = strdup(a);
                //printf("WARTOSC ATRYBUTU O NAZWIE 'WIDTH': %s\n", atrybuty->GetByName(atrybuty, b)->getValue());
                //selektory->printList(selektory);
                //atrybuty->printList(atrybuty);

                Sekcja* s = new Sekcja(selektory, atrybuty);


                //s->print();


                head->addSekcja(head, s);


                //head->printList(head);
                //printf("LICZBA WEZLOW: %i\n", head->getListLen(head));
                //printf("LICZBA SEKCJI: %i\n", s->getCnt());
                //printf("TAKEN: %i", head->getTaken(head));
            }
        } while (!command_section);

        //head->getSekcjaByIndex(head, 0);
        //head->getSekcjaByIndex(head, 1).print();
        //head->getSekcjaByIndex(head, 2).print();
        //head->getSekcjaByIndex(head, 3).print();
        //head->getSekcjaByIndex(head, 4).print();
        //head->getSekcjaByIndex(head, 5).print();
        //head->getSekcjaByIndex(head, 6).print();
        //head->getSekcjaByIndex(head, 7).print();

        while (command_section) {
            //printf("COMMAND SECTION\n");
            char c;
            char* str = read_until('\n',head);


            //printf("Wczytany tekst: %s\n", str);
            if (str != NULL) {

                if (/*equals(str, "****\n") ||*/ equals(str, "****")) {
                    command_section = false;
                    break;
                }
                if (equals(str, "?\n") || equals(str, "?")) printf("? == %i\n", head->liczbaSekcji(head));
                if (actual_len_front(str) > 2 && count_char(str, ',') == 2) {
                    char** com = new char* [3];
                    int start = 0;
                    int k = 0;
                    while (start < actual_len_front(str)) {
                        char* tmp = substr_until(str, start, ',', '\n');
                        com[k] = tmp;
                        //printf("com->%s\n", com[k]);
                        //if (is_number(com)) printf("LICZBA\n");
                        //else printf("TEKST\n");
                        start += strlen(tmp) + 1;
                        k++;
                    }


                    //i,S,?
                    if (is_number(com[0]) && com[1][0] == 'S' && com[2][0] == '?') com1(head, com);
                    //i,A,?
                    else if (is_number(com[0]) && com[1][0] == 'A' && com[2][0] == '?') com2(head, com);
                    //i,S,j
                    else if (is_number(com[0]) && com[1][0] == 'S' && is_number(com[2])) com3(head, com);
                    //i,A,n
                    else if (is_number(com[0]) && com[1][0] == 'A' && !is_number(com[2])) com4(head, com);
                    //n,A,?
                    else if (!is_number(com[0]) && com[1][0] == 'A' && com[2][0] == '?') com5(head, com);
                    //z,S,?
                    else if (!is_number(com[0]) && com[1][0] == 'S' && com[2][0] == '?') com6(head, com);

                    else if (!is_number(com[0]) && com[1][0] == 'E' && !is_number(com[2])) com7(head, com);

                    else if (is_number(com[0]) && com[1][0] == 'D' && com[2][0] == '*') com8(head, com);

                    else if (is_number(com[0]) && com[1][0] == 'D' && !is_number(com[2])) com9(head, com);
                }

            }

        }
        //head->getSekcjaByIndex(head, 1).print();
        //head->getSekcjaByIndex(head, 2).print();
        //head->getSekcjaByIndex(head, 3).print();
    }
    return 0;
}