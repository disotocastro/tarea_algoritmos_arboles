#ifndef HEAP_H
#define HEAP_H

#include "Element.h"
#include <vector>
#include <string>

class Heap {
private:
    std::vector<Element> heap;

    int parent(int i);
    int left(int i);
    int right(int i);
    bool isNumeric(const std::string& str);
    int compareElements(const std::string& a, const std::string& b);
    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    void insert(const Element& elem);
    bool member(const Element& elem);
    void deleteKey(const Element& elem);
    void print();
};

#endif
