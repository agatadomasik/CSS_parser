#include <stdio.h>
#include "Blok.h"

//CSS::CSS() {
//	prev = NULL;
//	sekcje = new Sekcja[T];
//	next = NULL;
//}



int Blok::taken = 0;
int Blok::deleted = 0;

Blok::Blok(Sekcja*& s) {
	prev = NULL;
	T = 8;
	sekcje = new Sekcja[T];
	sekcje[0] = s;
	next = NULL;
}

Blok::~Blok() {
	//sekcje->~Sekcja();
	delete[] sekcje;
}

int Blok::getListLen(Blok* firstNode) {
	Blok* temp = firstNode;
	int cnt = 0;
	while (temp != NULL) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

int Blok::getTaken(Blok*& firstNode) {
	return taken;
}

int Blok::liczbaSekcji(Blok*& firstNode) {
	if (this != NULL) return (firstNode->getListLen(firstNode) - 1) * T + firstNode->getTaken(firstNode) - deleted;
	//int cnt = 0;
	//Blok* temp = firstNode;
	//if (this != NULL) {
	//	while (temp != NULL) {
	//		//cnt += temp->getTaken(temp);
	//		//cnt -= temp->deleted;
	//		//for (int i = 0; i < T; i++) {
	//		//	if (temp->sekcje[i].getAtrybuty() != NULL) cnt++;
	//		//}
	//		temp = temp->next;
	//	}
	//	return cnt;
	//}
	return 0;
}

void Blok::addFirst(Blok*& firstNode, Sekcja*& s) {
	Blok* newNode = new Blok(s);
	newNode->next = firstNode;

	if (firstNode != NULL) {
		firstNode->prev = newNode;
	}
	firstNode = newNode;
}

void Blok::addLast(Blok*& firstNode, Sekcja*& s)
{
	//printf("TWORZE NOWY WEZEL\n");
	if (firstNode == NULL) {
		addFirst(firstNode, s);
		return;
	}

	Blok* newNode = new Blok(s);
	Blok* temp = firstNode;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void Blok::addSekcja(Blok*& firstNode, Sekcja*& s) {
	Blok* temp = firstNode;
	while (temp!= NULL && temp->next != NULL) {
		temp = temp->next;
	}
	if (temp != NULL && temp->taken < T) {
		//printf("DODAJE SEKCJE DO SEKCJE[%i]\n", s->getCnt() % T);
		//s->print();
		temp->sekcje[(s->getCnt()-1) % T] = s;
		temp->taken++;
	}
	else {
		addLast(firstNode, s);
		temp->taken = 1;
		//deleted = 0;
	}
}


Blok* Blok::getBlokByIndex(Blok* firstNode, int i) {
	if (firstNode == NULL) return NULL;
	int j = 0;
	Blok* tmp = firstNode;
	while (j < i && tmp->next != NULL) {
		tmp = tmp->next;
		j++;
	}
	if (j == i) return tmp;
	else return NULL;
}

Sekcja* Blok::getSekcjaByIndex(Blok* firstNode, int i) {
	//Blok* temp = firstNode->getBlokByIndex(firstNode, i / T);
	//if (temp!=NULL) return (temp->sekcje[i % T]);
	//printf("I: %i\n", i);
	//else return NULL;
	int cnt = 0;
	Blok* temp = firstNode;
	//temp->sekcje[0].print();
	if (this != NULL) {
		while (temp != NULL) {
			//cnt += temp->taken;
			//cnt -= temp->deleted;
			for (int j = 0; j < T; j++) {
				//printf("SRAKA %i\n", i);
				if (temp->sekcje[j].getAtrybuty() != NULL) cnt++;
				//printf("CNT: %i\n", cnt);
				//printf("J: %i\n", j);
				//temp->sekcje[j].print();
				//if (temp->sekcje[j].getAtrybuty() != NULL) temp->sekcje[j].getAtrybuty()->printList(temp->sekcje[j].getAtrybuty());
				if (cnt == i) {
					//temp->sekcje[j].print();
					return &(temp->sekcje[j]);
				}
			}
			temp = temp->next;
		}
	}
	return NULL;
}

void Blok::deleteSekcjaByIndex(Blok*& firstNode, int i) {
	//Blok* temp = firstNode->getBlokByIndex(firstNode, i / T);
	//if (temp != NULL) {
	//	temp->sekcje[i % T].deleteSekcja();
	//	deleted++;
	//	//printf("USUWAM\n");
	//}
	//Sekcja* tmp = &(firstNode->getSekcjaByIndex(firstNode, i));
	//tmp = new Sekcja();
	//else return NULL;

	//*firstNode->getSekcjaByIndex(firstNode, i).selektory=NULL;
	//*firstNode->getSekcjaByIndex(firstNode, i).atrybuty=NULL;
	////firstNode->getSekcjaByIndex(firstNode, i) = new Sekcja();
	////firstNode->sekcje[2].deleteSekcja();

	int k = 0;
	Blok* temp = firstNode;
	if (this != NULL) {
		while (temp != NULL) {
			//cnt += temp->taken;
			//cnt -= temp->deleted;
			for (int j = 0; j < T; j++) {
				//printf("SRAKA %i\n", i);
				if (temp->sekcje[j].getAtrybuty() != NULL) k++;
				//if (temp->sekcje[j].getAtrybuty() != NULL) temp->sekcje[j].getAtrybuty()->printList(temp->sekcje[j].getAtrybuty());
				if (k == i) temp->sekcje[j].deleteSekcja();
			}
			temp = temp->next;
		}
	}


	deleted++;
}

int Blok::selNameNum(Blok* firstNode, char* str) {
	Blok* temp = firstNode;
	int cnt = 0;
	while (temp != NULL) {
		for (int i = 0; i < T; i++) {
			if (temp->sekcje[i].findSelName(str)) cnt++;
		}
		temp = temp->next;
	}
	return cnt;
}

int Blok::attNameNum(Blok* firstNode, char* str) {
	int j = 0;
	Blok* temp = firstNode;
	int k = 0;
	while (temp != NULL) {
		//printf("Blok %i\n", j);
		for (int i = 0; i < T; i++) {
			//printf("Sekcja %i ", i);
			if (temp->sekcje[i].findAttName(str)) {
				//printf("jest\n");
				//sekcje[i].print();
				k++;
			}
			//else printf("nie ma\n");
		}
		temp = temp->next;
		j++;
	}
	return k;
}



char* Blok::function(Blok* firstNode, char* z, char* n) {
	Blok* temp = firstNode;
	Sekcja s;
	int cnt = 0;
	while (temp != NULL) {
		for (int i = 0; i < T; i++) {
			if (temp->sekcje[i].findSelName(z)) {
				s = temp->sekcje[i];
				//printf("\nJEST\n");
				//temp->sekcje[i].print();
			}
			else {
				//printf("\nNIE MA:\n");
				//temp->sekcje[i].print();
			}
		}
		temp = temp->next;
	}
	
	return s.getAtrybuty()->GetByName(s.getAtrybuty(), n)->getValue();
	//return NULL;
}


void Blok::printList(Blok* firstNode) {
	int i = 0;
		printf("Blok %i:\n",i);
		Blok* temp = firstNode;
		while (temp != NULL) {
			for (int j=0; j < T; j++) {
				printf("sekcja %i\n", j);
				temp->sekcje[j].print();
			}
			temp = temp->next;
			i++;
		}
	
}