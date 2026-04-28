#include <iostream>
#include "arbol.h"

using namespace std;

int main() {
    ArbolBST arbol;
    int op;

    do {
        cout << "\n===== SISTEMA BST EMPRESA =====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Buscar empleado\n";
        cout << "3. Mostrar raiz\n";
        cout << "4. Recorrido Inorden\n";
        cout << "5. Recorrido Preorden\n";
        cout << "6. Recorrido Postorden\n";
        cout << "7. Mostrar altura\n";
        cout << "8. Mostrar nodos hoja\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";

        cin >> op;

        switch (op) {
            case 1: {
                Empleado e;
                cout << "Ingrese codigo: ";
                cin >> e.codigo;
                cin.ignore();

                cout << "Ingrese nombre: ";
                getline(cin, e.nombre);

                cout << "Ingrese cargo: ";
                getline(cin, e.cargo);

                arbol.insertarEmpleado(e);
                cout << "Empleado registrado correctamente.\n";
                break;
            }

            case 2: {
                int c;
                cout << "Ingrese codigo a buscar: ";
                cin >> c;
                arbol.buscarEmpleado(c);
                break;
            }

            case 3:
                arbol.mostrarRaiz();
                break;

            case 4:
                arbol.mostrarInorden();
                break;

            case 5:
                arbol.mostrarPreorden();
                break;

            case 6:
                arbol.mostrarPostorden();
                break;

            case 7:
                arbol.mostrarAltura();
                break;

            case 8:
                arbol.mostrarHojas();
                break;
        }

    } while (op != 0);

    return 0;
}