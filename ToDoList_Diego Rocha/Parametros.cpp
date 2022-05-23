#include "Parametros.h"

Parametros::Parametros() {
	numDeTarea = 0;
	unaTarea = " ";
	completado = " ";
}

void Parametros::setNumDeTarea() {
	cin >> numDeTarea;
}

void Parametros::setUnaTarea() {
	cin.ignore();
	getline(cin, unaTarea);
}

