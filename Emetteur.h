#pragma once
#include <string>
#include <iostream>

class Emetteur
{
public:
	Emetteur();
	static void signal(std::string message);
	static std::string diffuser();

private:
	static std::string message;
};

