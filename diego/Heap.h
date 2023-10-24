#include <iostream>
#include <vector>

using std::string, std::cout, std::vector, std::endl;

class Heap{
private:
    int size{};
    vector<int>vect = {-1}; // Valor random
    int parent(int i);
    int left_child(int i) const;
    int right_child(int i) const;

public:
    bool is_empty() const;
    int get_Max() const;
    void insert_item(int value);
    void shift_down(int i);
    void shift_up(int i);
    int extract_max();
    void print_heap(int i, int depth) const;
    // void print_heap_array() const;
    void print_heap_array() const;
    

    

};


//g++ -o main main.cpp Trie.cpp Heap.cpp