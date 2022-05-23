#include "Menu.h"


Menu::Menu() {
	option = 0;
	listita = nullptr;
}

void Menu::run() {
	while (option != 9) {
		mostrarOpcionesMenu();
		setOption();
		createList();
	}
}

void Menu::mostrarOpcionesMenu() {
	cout << "\t___--'MENU'--___" << endl;
	cout << "1. Crear una nueva lista" << endl;
	cout << "2. Agregar tareas a la lista" << endl;
	cout << "3. Comprobar si existe la tarea en la lista" << endl;
	cout << "4. Borrar una tarea de la lista" << endl;
	cout << "5. Visualizar lista" << endl;
	cout << "6. Marcar como completado" << endl;
	cout << "7. Desmarcar como completado" << endl;
	cout << "8. Agregar tarea antes de posicion especifica" << endl;
	cout << "9. Salir del menu" << endl;
}

void Menu::setOption() {
	cout << "\nYour option-> ";
	cin >> option;
	if (option < 0 || option > 9) {
		cout << "Escribe una opcion del menu" << endl;
		setOption();
	}
}

void Menu::createList() {
	system("cls");

	switch (option){
	case 1:	
		listita = new Lista;
		break;
	case 2: 
		listita->agregarEnLista();
		break;
	case 3:
		listita->setPosicionEnLista();
		listita->comprobarExistencia();
		break;
	case 4:
		listita->setPosicionEnLista();
		listita->eliminarDeLista(); 
		break;
	case 5:
		listita->visualizarElementos(listita->unaListita); /*el objeto listita le manda una lista
														   llamada "unaListita" como parametro para poder imprimirla*/
		break;
	case 6:
		listita->setPosicionEnLista();
		listita->marcarComoCompletado();
		break;
	case 7:
		listita->setPosicionEnLista();
		listita->DesmarcarComoCompletado();
		break;
	case 8:
		listita->setPosicionPosteriorEnLista(); //saber antes de que tarea ingresar la nueva tarea
		listita->agregarEnPosicionEspecifica(); //se agrega la tarea antes de la seleccionada arriba
		break;
	}
}