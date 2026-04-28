#ifndef ARBOL_H
#define ARBOL_H

#include <string>
using namespace std;

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp);
};

class ArbolBST {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo*, Empleado);
    Nodo* buscar(Nodo*, int);

    void inorden(Nodo*);
    void preorden(Nodo*);
    void postorden(Nodo*);
    int altura(Nodo*);
    void hojas(Nodo*);
    void mostrar(Nodo*);

public:
    ArbolBST();

    void insertarEmpleado(Empleado);
    void buscarEmpleado(int);
    void mostrarRaiz();

    void mostrarInorden();
    void mostrarPreorden();
    void mostrarPostorden();
    void mostrarAltura();
    void mostrarHojas();
};

#endif