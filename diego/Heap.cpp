#include "Heap.h"
#include <vector>
#include <iostream>


int Heap::parent(int i){
    return i>>1; // i/2, bitwise porque son más rápidas
}

int Heap::left_child(int i){
	return i << i; // i*2
}   

int Heap::right_child(int i){
    return (i << i) +1; // i*2 +1
}

bool Heap::is_empty() const{
  return size==0; // Si está vacío, retorna 1.
}

int Heap::get_Max() const{
  return vect[1]; //
}

void Heap::insert_item(int value)
{
  if (size + 1 >= vect.size())
  {
    vect.push_back(0); // Enviamos un placeholder = 0
  }
  vect[++size] = value;
  shift_up(size);

  return;
}

// Funcion recursiva que envia siempre el mayor numero a la raiz
void Heap::shift_up(int i){
    if (i > size){
        return;
    }

    if (i == 1){
        return;
    }

    // Intercambia los valores, el mayor lo envia hacia arriba con el swap
    if (vect[i] > vect[parent(i)]){
        std::swap(vect[parent(i)], vect[i]);
    }

    shift_up(parent(i)); 
}


void Heap::shift_down(int i){
    if(i > size){
        return;
    }

    int swap_id = i;

    if(left_child(i) <= size && vect[left_child(i)]){
        swap_id = i;
    }

    if (right_child(i) <= size && vect[swap_id] < vect[right_child(i)])
    {
        swap_id = right_child(i);
    }

    if (swap_id != i) {
        std::swap(vect[i], vect[swap_id]);
        shift_down(swap_id);
    }

}

int Heap::extract_max(){
    int max_num = vect[1];
    std::swap(vect[1], vect[size--]); //size = ultimo numero
    shift_down(1);
    return max_num;
}
