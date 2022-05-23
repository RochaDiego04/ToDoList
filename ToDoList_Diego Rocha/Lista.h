#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include "Parametros.h"

using namespace std;

class Lista {
public:
	Parametros objetoParametro; //creamos un objeto para darselo a la lista
	int numeroDeTareaABuscar;
	int numeroDeTareaPosterior;
	list <Parametros> unaListita;
	list <Parametros>::iterator pos;
	list <Parametros>::iterator pos2;

	Lista();
	//inputs
	void setPosicionEnLista();
	void setPosicionPosteriorEnLista();
	void setParametrosDeLista();
	//métodos del menu
	void agregarEnLista();
	void eliminarDeLista();
	void comprobarExistencia();
	void visualizarElementos(list <Parametros> unaListita);
	void marcarComoCompletado();
	void DesmarcarComoCompletado();
	void agregarEnPosicionEspecifica();
	bool encontrarPosicionesDuplicadas();
};