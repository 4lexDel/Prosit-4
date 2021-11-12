#include "Emetteur.h"
#include "Recepteur.h"

using namespace std;

string Emetteur::message = "";

Emetteur::Emetteur()
{

}

void Emetteur::signal(std::string message) {
	Emetteur::message = message;
}


string Emetteur::diffuser() {
	cout << "Emetteur : " << message << endl;
	return message;
	//return NULL;
}
