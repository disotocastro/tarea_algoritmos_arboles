#include <iostream>
#include "Trie.h"
#include "Heap.h"

using std::string, std::cout, std::shared_ptr, std::endl;

int main() {
    // shared_ptr<Trie> myTrie(new Trie());
    // string word1 = "geeksfor";
    // string word2 = "geeksforgeeks";
    // string word3 = "nothing";
    // string word4 = "geeksf";
    // string word5 = "geeksfor";



    // myTrie->insertWord(word1);
    // myTrie->insertWord(word2);
    // myTrie->insertWord(word3);
    // myTrie->insertWord(word4);
    // myTrie->insertWord(word5);


    // // Imprime todas las palabras en el Trie
    // myTrie->printTrie(myTrie->root, "");




    Heap* myHeap = new Heap();
    if (myHeap->is_empty())
    {
        std::cout << "Corrent anwser" << std::endl;
    }else{
        std::cout << "No funciona" << std::endl;
    }

    myHeap->insert_item(10);
    myHeap->insert_item(120);
    myHeap->insert_item(1000);
    myHeap->insert_item(130);
    myHeap->insert_item(110);
    myHeap->insert_item(40);
    myHeap->insert_item(34);
    myHeap->insert_item(41);
    myHeap->insert_item(5);

    myHeap->print_heap_array();

    return 0;
}



//g++ -o main main.cpp Trie.cpp Heap.cpp