#include <iostream>
#include <vector>

using std::string, std::cout, std::vector, std::endl;

class Heap{
private:
    int size{};
    vector<string> vect = {""}; // Valor random
    int parent(int i);
    int left_child(int i) const;
    int right_child(int i) const;

public:
    bool is_empty() const;
    string get_Max() const;
    void insert_item(string value);
    void shift_down(int i);
    void shift_up(int i);
    string extract_max();
    void print_heap_array() const;
    bool member(const string& value) const;

};


//g++ -o main main.cpp Trie.cpp Heap.cpp