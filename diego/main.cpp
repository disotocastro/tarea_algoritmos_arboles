#include <iostream>
#include <string>
#include "Trie.h"
#include "Element.h"
#include "Heap.h"

using std::string, std::cout, std::shared_ptr, std::endl;

int main() {
    shared_ptr<Trie> myTrie(new Trie());
    string word1 = "geeksfor";
    string word2 = "geeksforgeeks";
    string word3 = "nothing";
    string word4 = "geeksf";
    string word5 = "geeksfor";



    myTrie->insert_word(word1);
    myTrie->insert_word(word2);
    myTrie->insert_word(word3);
    myTrie->insert_word(word4);
    myTrie->insert_word(word5);


    // Imprime todas las palabras en el Trie
    myTrie->print_trie(myTrie->root, "");

    return 0;
}

//g++ -o main main.cpp Trie.cpp Heap.cpp