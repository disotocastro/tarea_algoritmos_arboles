#include <iostream>
#include <vector>


using std::string, std::cout, std::vector, std::endl;

class Heap{
private:
    int size{};
    vector<int>vect = {-1}; // Valor random
    int parent(int i);
    int left_child(int i);
    int right_child(int i);

public:
    bool is_empty() const;
    int get_Max() const;
    void insert_item(int value);
    void shift_down(int i);
    void shift_up(int i);
    int extract_max();
};


//g++ -o main main.cpp Trie.cpp Heap.cpp