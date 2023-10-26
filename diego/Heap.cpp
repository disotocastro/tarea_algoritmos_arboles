#include "Heap.h"
#include <vector>
#include <iostream>

int Heap::parent(int i) {
    return i >> 1; // i/2, bitwise porque son más rápidas
}

int Heap::left_child(int i) const {
    return i << 1; // i*2
}

int Heap::right_child(int i) const {
    return (i << 1) + 1; // i*2 + 1
}

bool Heap::is_empty() const {
    return size == 0; // Si está vacío, retorna 1.
}

string Heap::get_Max() const {
    return vect[1];
}

void Heap::insert_item(string value) {
    if (size + 1 >= vect.size()) {
        vect.push_back(""); // Enviamos un placeholder = ""
    }
    vect[++size] = value;
    shift_up(size);
}

void Heap::shift_up(int i) {
    if (i > size) {
        return;
    }

    if (i == 1) {
        return;
    }

    // Intercambia los valores, el mayor lo envía hacia arriba con el swap
    if (vect[i] > vect[parent(i)]) {
        std::swap(vect[parent(i)], vect[i]);
    }

    shift_up(parent(i));
}

void Heap::shift_down(int i) {
    if (i > size) {
        return;
    }

    int max_index = i;
    int left = left_child(i);
    int right = right_child(i);

    if (left <= size && vect[i] < vect[left]) {
        max_index = left;
    }

    if (right <= size && vect[max_index] < vect[right]) {
        max_index = right;
    }

    if (max_index != i) {
        std::swap(vect[i], vect[max_index]);
        shift_down(max_index);
    }
}

string Heap::extract_max() {
    string max_str = vect[1];
    std::swap(vect[1], vect[size--]); // size = último número
    shift_down(1);
    return max_str;
}

void Heap::print_heap_array() const {
    if (size == 0) {
        std::cout << "El heap está vacío." << std::endl;
        return;
    }

    int level = 0;
    int level_nodes = 1;
    int nodes_printed = 0;

    for (int i = 1; i <= size; i++) {
        if (nodes_printed == level_nodes) {
            // Cambio de nivel
            std::cout << std::endl;
            level++;
            level_nodes *= 2;
            nodes_printed = 0;
        }

        std::cout << vect[i] << "  ";  // Imprimimos el nodo
        nodes_printed++;
    }

    std::cout << std::endl;
}


bool Heap::member(const string& value) const {
    for (int i = 1; i <= size; i++) {
        if (vect[i] == value) {
            return true;
        }
    }
    return false;
}