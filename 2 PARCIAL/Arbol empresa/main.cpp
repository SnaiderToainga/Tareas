#include <iostream>
#include "arbol.h"

using namespace std;

int main() {
    ArbolBST arbol;
    int op;

    do {
        cout << "\n==== MENU BST EMPRESA ====\n";
        cout << "1. Insertar\n2. Buscar\n3. Raiz\n4. Inorden\n5. Preorden\n6. Postorden\n7. Altura\n8. Hojas\n0. Salir\n";
        cin >> op;

        if (op == 1) {
            Empleado e;
            cout << "Codigo: "; cin >> e.codigo;
            cin.ignore();
            cout << "Nombre: "; getline(cin, e.nombre);
            cout << "Cargo: "; getline(cin, e.cargo);
            arbol.insertarEmpleado(e);
        }
        else if (op == 2) {
            int c;
            cout << "Codigo: "; cin >> c;
            arbol.buscarEmpleado(c);
        }
        else if (op == 3) arbol.mostrarRaiz();
        else if (op == 4) arbol.mostrarInorden();
        else if (op == 5) arbol.mostrarPreorden();
        else if (op == 6) arbol.mostrarPostorden();
        else if (op == 7) arbol.mostrarAltura();
        else if (op == 8) arbol.mostrarHojas();

    } while (op != 0);

    return 0;
}