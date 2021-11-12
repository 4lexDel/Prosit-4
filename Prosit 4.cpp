// Prosit 4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Emetteur.h"
#include "Recepteur.h"

#include "List.h"

using namespace std;

int main()
{
    cout << "-------------------Prosit 4-------------------" << endl << endl;

    Emetteur *em1 = new Emetteur();
    Recepteur *rec1 = new Recepteur();


    em1->signal("Coucou ");
	rec1->capter();

	em1->signal("c'est ");
	rec1->capter();

	em1->signal("la radio !");
	rec1->capter();

	cout << endl;

	rec1->ecouter();
	rec1->ecouter();
	rec1->ecouter();
	rec1->ecouter();

	delete em1, rec1;

	cout << endl << endl;

	/*cout << "-------------------Test list-------------------" << endl << endl;


	List<int> *list1 = new List<int>();

	list1->addEnd(14);
	list1->addEnd(71);
	list1->addEnd(58);
	list1->addEnd(95);
	list1->addEnd(54);
	list1->addEnd(24);
	list1->addEnd(18);
	list1->addEnd(36);

	list1->addBegin(2);
	list1->addBegin(1);

	list1->add(3, 2);

	cout << "Taille de la liste : " << list1->size() << endl;
	list1->add(666, 3);
	for (size_t i = 0; i < list1->size(); i++)
	{
		cout << list1->get(i) << "-";
	}
	cout << endl;
	list1->display();

	list1->clear();

	list1->display();
	cout << "Taille de la liste : " << list1->size() << endl;

	/*List<string>* list2 = new List<string>();

	list2->addEnd("Bonjour ");
	list2->addEnd("a ");
	list2->addEnd("tous ");
	list2->addEnd("les ");
	list2->addEnd("amis !");

	list2->display();*/
}






















/*
//Programmation evt*****************************************************
#include <iostream>
using namespace std;

typedef void (*evt)(const char*);
evt e;

class REC
{
public:
	static void ecoute(const char*);
};
void REC::ecoute(const char* message)
{
	std::cout << message << std::endl;
}

class EM
{
public:
	void signal(const char*);
};
void EM::signal(const char* message)
{
	e = &REC::ecoute;
	e(message);
}

int main()
{
	EM emission;
	emission.signal("Salut");
}*/