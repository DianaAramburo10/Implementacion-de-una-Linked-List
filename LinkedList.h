#pragma once
#include <iostream>

class LinkedList {
private:
    // Nodo interno: guarda el dato y el puntero al siguiente
    struct Node {
        int data;
        Node* next;  //puntero al siguiente nodo de la lista.
        explicit Node(int value, Node* nxt = nullptr) : data(value), next(nxt) {}
    };

    Node* head;          // inicio de la lista (nullptr si está vacía)
    std::size_t size_;   //cantidad de elementos (apoyo para validaciones)

public:
    // Constructor: inicia lista vacía
    LinkedList();

    //Se declara el destructor
    ~LinkedList();

    //Inserciones
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(std::size_t pos, int value); // 0..size_ permitido

    // Eliminación por valor (primera ocurrencia)
    bool deleteValue(int value);

    // Búsqueda
    bool search(int value) const;

    // Mostrar elementos en orden
    void display() const;

    // Utilidades (opcionales para pruebas)
    bool empty() const { return head == nullptr; }  //Devuelve true si la lista está vacía
    std::size_t size() const { return size_; } //Devuelve cuántos elementos hay en la lista, leyendo el contador interno size_

private:
    // libera toda la memoria de la lista
    void clear();
};
