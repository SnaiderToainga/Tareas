#include <iostream>
#include <algorithm>
#include "arbol.h"

using namespace std;

Nodo::Nodo(Empleado emp) {
    dato = emp;
    izquierdo = nullptr;
    derecho = nullptr;
}

ArbolBST::ArbolBST() {
    raiz = nullptr;
}

Nodo* ArbolBST::insertar(Nodo* nodo, Empleado emp) {
    if (!nodo) return new Nodo(emp);

    if (emp.codigo < nodo->dato.codigo)
        nodo->izquierdo = insertar(nodo->izquierdo, emp);
    else if (emp.codigo > nodo->dato.codigo)
        nodo->derecho = insertar(nodo->derecho, emp);
    else
        cout << "Codigo ya existe\n";

    return nodo;
}

Nodo* ArbolBST::buscar(Nodo* nodo, int codigo) {
    if (!nodo || nodo->dato.codigo == codigo) return nodo;

    if (codigo < nodo->dato.codigo)
        return buscar(nodo->izquierdo, codigo);
    else
        return buscar(nodo->derecho, codigo);
}

void ArbolBST::mostrar(Nodo* nodo) {
    cout << "Codigo: " << nodo->dato.codigo
         << " | Nombre: " << nodo->dato.nombre
         << " | Cargo: " << nodo->dato.cargo << endl;
}

void ArbolBST::inorden(Nodo* nodo) {
    if (nodo) {
        inorden(nodo->izquierdo);
        mostrar(nodo);
        inorden(nodo->derecho);
    }
}

void ArbolBST::preorden(Nodo* nodo) {
    if (nodo) {
        mostrar(nodo);
        preorden(nodo->izquierdo);
        preorden(nodo->derecho);
    }
}

void ArbolBST::postorden(Nodo* nodo) {
    if (nodo) {
        postorden(nodo->izquierdo);
        postorden(nodo->derecho);
        mostrar(nodo);
    }
}

int ArbolBST::altura(Nodo* nodo) {
    if (!nodo) return 0;
    return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
}

void ArbolBST::hojas(Nodo* nodo) {
    if (nodo) {
        if (!nodo->izquierdo && !nodo->derecho)
            mostrar(nodo);
        hojas(nodo->izquierdo);
        hojas(nodo->derecho);
    }
}

void ArbolBST::insertarEmpleado(Empleado emp) {
    raiz = insertar(raiz, emp);
}

void ArbolBST::buscarEmpleado(int codigo) {
    Nodo* r = buscar(raiz, codigo);
    if (r) {
        cout << "\nEmpleado encontrado:\n";
        mostrar(r);
    } else {
        cout << "\nNo encontrado\n";
    }
}

void ArbolBST::mostrarRaiz() {
    if (raiz) {
        cout << "\nRaiz:\n";
        mostrar(raiz);
    }
}

void ArbolBST::mostrarInorden() {
    cout << "\nInorden:\n";
    inorden(raiz);
}

void ArbolBST::mostrarPreorden() {
    cout << "\nPreorden:\n";
    preorden(raiz);
}

void ArbolBST::mostrarPostorden() {
    cout << "\nPostorden:\n";
    postorden(raiz);
}

void ArbolBST::mostrarAltura() {
    cout << "\nAltura: " << altura(raiz) << endl;
}

void ArbolBST::mostrarHojas() {
    cout << "\nHojas:\n";
    hojas(raiz);
}