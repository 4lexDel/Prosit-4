#pragma once
#include "Emetteur.h"
#include "List.h"
#include <iostream>
#include <string>

typedef std::string (*pf)(void);

class Recepteur
{
public:
	Recepteur();
	void capter();
	void ecouter();
	~Recepteur();
	

private:
	List<std::string> *buffer;
	pf evt;						//point d'acces aux données emetteur
};

