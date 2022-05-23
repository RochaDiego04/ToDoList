#include "Lista.h"

Lista::Lista() {
	list<Parametros> unaListita;
	list<Parametros>::iterator pos = unaListita.begin(); //se inicia el iterador al comienzo de la lista
	list<Parametros>::iterator pos2 = unaListita.begin();
	numeroDeTareaABuscar = 0;
	numeroDeTareaPosterior = 0;
}

void Lista::setPosicionEnLista() { 
	cout << "Escribe el numero de la tarea" << endl;
	cin >> numeroDeTareaABuscar;
}

void Lista::setPosicionPosteriorEnLista() { 
	cout << "Antes de cual tarea deseas agregar?" << endl;
	cin >> numeroDeTareaPosterior;
}

void Lista::setParametrosDeLista() {
	cout << "Que numero de tarea deseas agregar?\n";
	objetoParametro.setNumDeTarea();
	cout << "Que tarea deseas agregar?\n";
	objetoParametro.setUnaTarea();
	objetoParametro.completado = " ";
}

void Lista::agregarEnLista() {
	setParametrosDeLista(); //Ingresar num de tarea y la tarea 
	encontrarPosicionesDuplicadas();	
	while (encontrarPosicionesDuplicadas() == true) {	//si hay posiciones duplicadas
		cout << "La posicion se encuentra en la lista, intente con otra" << endl;
		setParametrosDeLista();	//vuelve a pedir parametros
		encontrarPosicionesDuplicadas();  //vuelve a buscar si hay una posicion duplicada
	}
	unaListita.emplace_back(objetoParametro);
	system("cls");
}

void Lista::eliminarDeLista() {
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {
		if (pos->numDeTarea == numeroDeTareaABuscar) { //cuando sea diferente de la ultima posicion
			pos = unaListita.erase(pos); /*si solo eliminamos pos, valdrá null y dará un error al regresar al ciclo for
										 por esto se pone pos = ...*/
			break;
		}

	}
	system("cls");
}

void Lista::comprobarExistencia() {
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {
		if (pos->numDeTarea == numeroDeTareaABuscar) {
			cout << "El elemento se encuentra en la lista" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Lista::visualizarElementos(list <Parametros> unaListita) {
	cout << "\t___--'ELEMENTOS DE LA LISTA'--___" << endl;
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {
		cout << pos->numDeTarea << ". " << pos->unaTarea << "\t" << pos->completado << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Lista::marcarComoCompletado() {
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {	//Hacer un refresh de la tarea que se le indique, agregando el "completado"
		if (pos->numDeTarea == numeroDeTareaABuscar) {
			objetoParametro.numDeTarea = pos->numDeTarea; /*Asignamos los valores de la posicion al objeto*/
			objetoParametro.unaTarea = pos->unaTarea;
			objetoParametro.completado = "\tCOMPLETADO";
			pos = unaListita.erase(pos);		//Ya que guardamos los valores en objeto parámetro, los eliminamos de la posicion
			unaListita.insert(pos, objetoParametro);	//Volvemos a insertar los valores de objeto Parámetro, pero con el string de "completado"
			system("cls");
			break;
		}
	}
	system("cls");
}

void Lista::DesmarcarComoCompletado() {
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {	//Hacer un refresh de la tarea que se le indique, agregando el " "
		if (pos->numDeTarea == numeroDeTareaABuscar) {
			objetoParametro.numDeTarea = pos->numDeTarea; /*Asignamos los valores de la posicion al objeto*/
			objetoParametro.unaTarea = pos->unaTarea;
			objetoParametro.completado = " ";
			pos = unaListita.erase(pos);		//Ya que guardamos los valores en objeto parámetro, los eliminamos de la posicion
			unaListita.insert(pos, objetoParametro);	//Volvemos a insertar los valores de objeto Parámetro, pero con el string de " " sustituyendo el "completado"
			system("cls");
			break;
		}
	}
	system("cls");
}

void Lista::agregarEnPosicionEspecifica() {
	for (pos = unaListita.begin(); pos != unaListita.end(); pos++) {
		if (pos->numDeTarea == numeroDeTareaPosterior && pos != unaListita.end()) {
			setParametrosDeLista();
			encontrarPosicionesDuplicadas();
			while (encontrarPosicionesDuplicadas() == true) {
				cout << "La posicion se encuentra en la lista, intente con otra" << endl;
				setParametrosDeLista();
				encontrarPosicionesDuplicadas();
			}
			unaListita.insert(pos, objetoParametro);
		}
	}
	system("cls");
}

bool Lista::encontrarPosicionesDuplicadas() {	//Usamos otro iterador para que no ocurra un choque con el iterador de agregarEnPosicionEspecifica()
	for (pos2 = unaListita.begin(); pos2 != unaListita.end(); pos2++) {
		if (objetoParametro.numDeTarea == pos2->numDeTarea) {
			return true;
		}
	}
	return false;
}


