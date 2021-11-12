#include "Recepteur.h"

using namespace std;

Recepteur::Recepteur() : evt(NULL)
{
	buffer = new List<string>();
}

void Recepteur::capter() {
	evt = &Emetteur::diffuser;			//on recup la diffusion

	string messageRecep = (*evt)();

	buffer->addEnd(messageRecep);
}


void Recepteur::ecouter()
{
	cout << "Recepteur : ";

	if (buffer->size() > 0) {
		cout << buffer->get(0) << endl;
		buffer->deleteBegin();
	}
	else cout << "Le buffer est vide";
}

Recepteur::~Recepteur() {
	delete buffer;
}

