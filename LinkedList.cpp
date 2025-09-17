#include "LinkedList.h"
#include <cerrno>

//Constructor
LinkedList::LinkedList() : head(nullptr), size_(0) {
    // Lista vacía: head = nullptr, size_ = 0
}

//Destructor 
LinkedList::~LinkedList() {
    clear();
}

//Libera todos los nodos
void LinkedList::clear() {  //Define el método clear()
    Node* cur = head; //Crea un puntero cur que empieza en el primer nodo (head)
    while (cur) { //Bucle que se ejecuta mientras quede algún nodo por borrar).
        Node* nxt = cur->next;  //Guarda en nxt la dirección del siguiente nodo
        delete cur; //Libera (destruye) el nodo actual apuntado por cur
        cur = nxt; //Avanza el cursor al siguiente nodo
    }
    head = nullptr; //Deja el puntero de inicio en nullptr para indicar que la lista está vacía.
    size_ = 0; //resetea el contador
}

//Inserciones

/**
 insertAtBeginning(value): Crea un nuevo nodo y lo pone al inicio.
 - Caso base: si está vacía, head pasa a ser el nuevo nodo.
 - Si no, el nuevo nodo apunta al head actual y se vuelve el nuevo head.
 Complejidad O(1).
 */
void LinkedList::insertAtBeginning(int value) {
    Node* n = new Node(value, head);
    head = n;
    ++size_;
}

/**
 insertAtEnd(value): Inserta al final recorriendo hasta encontrar el último nodo (next == nullptr).
 - Caso base: si está vacía, equivale a insertar al inicio.
 Complejidad O(n) por el recorrido.
 */
void LinkedList::insertAtEnd(int value) {
    Node* n = new Node(value, nullptr);
    if (!head) {
        head = n;
        ++size_;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    ++size_;
}

/**
insertAtPosition(pos, value): Inserta en una posición 0..size_ (0 = inicio, size_ = final).
 - Si pos > size_, se reporta error y no inserta.
 - Si pos == 0, usa insertAtBeginning.
 - Si pos == size_, usa insertAtEnd.
 - En caso general, avanza hasta (pos-1) y re-enlaza.
 Complejidad O(n) por recorrido.
 */
void LinkedList::insertAtPosition(std::size_t pos, int value) {
    if (pos > size_) {
        std::cerr << "[Error] insertAtPosition: posición fuera de rango (pos=" 
                  << pos << ", size=" << size_ << ")\n";
        return;
    }
    if (pos == 0) { insertAtBeginning(value); return; }
    if (pos == size_) { insertAtEnd(value); return; }

    Node* cur = head;
    for (std::size_t i = 0; i < pos - 1; ++i) cur = cur->next;

    Node* n = new Node(value, cur->next);
    cur->next = n;
    ++size_;
}

//Eliminación

/**
 deleteValue(value): Elimina la PRIMERA ocurrencia de 'value'.
 - Caso base: lista vacía -> false.
 - Si el head contiene el valor, se elimina el head y se re-enlaza.
 - En otro caso, se recorre con (prev, cur) hasta encontrarlo.
 - Maneja eliminar el último nodo (tail lógico) porque cur->next puede ser nullptr.
 Retorna true si eliminó; false si no encontró el valor.
 Complejidad O(n).
 */
bool LinkedList::deleteValue(int value) {
    if (!head) return false;

    // Eliminar en la cabeza
    if (head->data == value) {
        Node* old = head;
        head = head->next;
        delete old;
        --size_;
        return true;
    }

    // Caso general
    Node* prev = head;
    Node* cur = head->next;
    while (cur) {
        if (cur->data == value) {
            prev->next = cur->next; // re-enlaza, funciona también si cur es último
            delete cur;
            --size_;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    // No se encontró el valor
    return false;
}

//Búsqueda

/**
 search(value): Recorre la lista comparando cada dato.
 Retorna true al encontrar la primera coincidencia, false si no existe.
 Complejidad O(n).
 */
bool LinkedList::search(int value) const {
    Node* cur = head;
    while (cur) {
        if (cur->data == value) return true;
        cur = cur->next;
    }
    return false;
}

//Mostrar
/**
 display():Imprime los elementos en orden, formateados como: [size=N]  a -> b -> c -> nullptr
Útil para visualizar el estado actual de la lista.
 */
void LinkedList::display() const {
    std::cout << "[size=" << size_ << "]  ";
    Node* cur = head;
    while (cur) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "nullptr\n";
}
