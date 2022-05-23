#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class Parametros {
public:
	string unaTarea;
	int numDeTarea;
	string completado;
	Parametros();
	void setNumDeTarea();
	void setUnaTarea();
};