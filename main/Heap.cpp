#include "Heap.h"
#include <algorithm>
#include <iostream>

// Retorna el índice del padre del nodo en el índice i.
int Heap::parent(int i) { 
    return (i - 1) >> 1; 
} 

// Retorna el índice del hijo izquierdo del nodo en el índice i.
int Heap::left(int i) { 
    return (i << 1) + 1; 
}  

// Retorna el índice del hijo derecho del nodo en el índice i.
int Heap::right(int i) { return (i << 1) + 2; } 

// Verifica si la cadena dada es numérica.
bool Heap::isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

// Compara dos cadenas. Si ambas son numéricas, las compara como números.
int Heap::compareElements(const std::string& a, const std::string& b) {
    if (isNumeric(a) && isNumeric(b)) {
        return std::stoi(a) - std::stoi(b);
    }
    return a.compare(b);
}

// Corrige el montón hacia arriba, empezando por el índice dado.
void Heap::heapifyUp(int i) {
    // Si el nodo actual es mayor que su padre, se intercambian.
    while (i != 0 && compareElements(heap[parent(i)].getData(), heap[i].getData()) < 0) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i); // Sube al nodo padre.
    }
}

// Corrige el montón hacia abajo, empezando por el índice dado.
void Heap::heapifyDown(int i) {
    int l = left(i); // Hijo izquierdo.
    int r = right(i); // Hijo derecho.
    int largest = i;

    // Selecciona el nodo mayor entre el nodo actual y su hijo izquierdo.
    if (l < heap.size() && compareElements(heap[l].getData(), heap[i].getData()) > 0) {
        largest = l;
    }

    // Compara el nodo mayor anterior con el hijo derecho.
    if (r < heap.size() && compareElements(heap[r].getData(), heap[largest].getData()) > 0) {
        largest = r;
    }

    // Si el nodo actual no es el mayor, se intercambia con el mayor de sus hijos.
    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapifyDown(largest); // Continúa corrigiendo hacia abajo.
    }
}

// Métodos públicos:

// Inserta un nuevo elemento al montón.
void Heap::insert(const Element& elem) {
    heap.push_back(elem);
    int index = heap.size() - 1; 
    heapifyUp(index); // Corrige el montón hacia arriba.
}

// Verifica si un elemento específico está en el montón.
bool Heap::member(const Element& elem) {
    for (const auto& item : heap) {
        if (item.getData() == elem.getData()) {
            return true;
        }
    }
    return false;
}

// Elimina un elemento específico del montón.
void Heap::deleteKey(const Element& elem) {
    int index = -1;
    // Busca el elemento en el montón.
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i].getData() == elem.getData()) {
            index = i;
            break;
        }
    }
    // Si no se encuentra, lanza una excepción.
    if (index == -1) {
        throw std::runtime_error("Key not found");
    }

    // Reemplaza el elemento con el último elemento del montón y lo elimina.
    heap[index] = heap.back();
    heap.pop_back();

    heapifyDown(index); // Corrige el montón hacia abajo.
}

// Imprime los elementos del montón.
void Heap::print() {
    for (const auto& item : heap) {
        std::cout << item.getData() << " ";
    }
    std::cout << std::endl;
}
