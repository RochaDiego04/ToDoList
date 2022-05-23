#pragma once
#include <iostream>
#include <cstdlib>
#include "Lista.h"
using namespace std;


class Menu {
public:
	int option;
	Lista* listita;

	Menu();
	void run();
	void mostrarOpcionesMenu();
	void setOption();
	void createList();
};