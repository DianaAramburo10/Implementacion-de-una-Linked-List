#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;

    std::cout << "Estado inicial \n";
    list.display();

    //Insertar varios elementos en diferentes posiciones
    std::cout << "\nInserciones básicas \n";
    list.insertAtBeginning(10);     // [10]
    list.display();

    list.insertAtEnd(30);           // [10, 30]
    list.display();

    list.insertAtPosition(1, 20);   // [10, 20, 30]
    list.display();

    list.insertAtPosition(0, 5);    // [5, 10, 20, 30]
    list.display();

    list.insertAtPosition(list.size(), 40); // al final = [5, 10, 20, 30, 40]
    list.display();

    //Posición fuera de rango
    std::cout << "\n Intento de inserción fuera de rango (pos=10) \n";
    list.insertAtPosition(10, 99);  // error controlado
    list.display();
 
    //Buscar elementos existentes y no existentes
    std::cout << "\nBúsquedas \n";
    std::cout << "search(20): " << std::boolalpha << list.search(20) << "\n"; // true
    std::cout << "search(99): " << std::boolalpha << list.search(99) << "\n"; // false

    //Eliminar nodos y mostrar antes/después

    std::cout << "\nEliminaciones \n";
    std::cout << "Antes de eliminar 5 (head):\n";
    list.display();
    std::cout << "deleteValue(5):  " << list.deleteValue(5) << "\n";   // elimina head
    list.display();

    std::cout << "Antes de eliminar 40 (tail):\n";
    list.display();
    std::cout << "deleteValue(40): " << list.deleteValue(40) << "\n"; // elimina tail
    list.display();

    std::cout << "Eliminar un elemento intermedio (20):\n";
    list.display();
    std::cout << "deleteValue(20): " << list.deleteValue(20) << "\n"; // intermedio
    list.display();

    std::cout << "Intentar eliminar inexistente (999):\n";
    std::cout << "deleteValue(999): " << list.deleteValue(999) << "\n";
    list.display();

    //Verificar que la lista se actualiza correctamente
    std::cout << "\nVerificación final\n";
    std::cout << "empty(): " << list.empty() << ", size(): " << list.size() << "\n";
    list.display();

    // Limpieza automática al terminar (destructor)
    return 0;
}