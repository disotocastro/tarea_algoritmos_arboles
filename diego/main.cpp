#include <iostream>
#include "Trie.h"

using std::string, std::cout, std::shared_ptr, std::endl;

int main() {
    std::shared_ptr<Trie> myTrie(new Trie());

    std::string word1 = "geeksfor";
    std::string word2 = "geeksforgeeks";
    std::string word3 = "nothing";
    std::string word4 = "geeksf";
    std::string word5 = "geeksfor";



    myTrie->insertWord(word1);
    myTrie->insertWord(word2);
    myTrie->insertWord(word3);
    myTrie->insertWord(word4);
    myTrie->insertWord(word5);


    // Imprime todas las palabras en el Trie
    myTrie->printTrie(myTrie->root, "");

    return 0;
}