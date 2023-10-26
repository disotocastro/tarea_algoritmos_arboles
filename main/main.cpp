// g++ main.cpp Heap.cpp Element.cpp Trie.cpp -o main

#include "Heap.h"
#include "Element.h"
#include "Trie.h"
#include <iostream>
#include <memory>
#include <cctype>  // para usar 'tolower'
#include <algorithm>  // para usar 'transform'

using std::string, std::cout, std::shared_ptr, std::endl;

void BinaryHeap(){
    bool execute = true;
    int option;
    Heap heap;
    string data;
    string word_trie;
    while (execute) {
        std::cout << "Choose an action for your Heap: " << std::endl;
        std::cout << "1. Insert Element" << std::endl;
        std::cout << "2. Search for an Element" << std::endl;
        std::cout << "3. Delete an Element" << std::endl;
        std::cout << "4. Print All Elements in Heap" << std::endl;
        std::cout << "5. Member" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "--->: ";
        std::cin >> option;

        Element elem; 

        switch (option) {
            case 1:
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                elem = Element(data);
                heap.insert(elem);
                std::cout << "Data inserted successfully!" << std::endl;
                break;

            case 2:
                std::cout << "Enter the data to search: ";
                std::cin >> data;
                elem = Element(data);
                if (heap.member(elem)) {
                    std::cout << "Data found in the Heap." << std::endl;
                } else {
                    std::cout << "Data not found in the Heap." << std::endl;
                }
                break;

            case 3:
                std::cout << "Enter the data to delete: ";
                std::cin >> data;
                elem = Element(data);
                try {
                    heap.deleteKey(elem);
                    std::cout << "Data deleted successfully." << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;

            case 4:
                std::cout << "Data in the Heap:" << std::endl;
                heap.print();
                break;
            case 5:
                std::cout << "Enter the word_trie you want to check: ";
                std::cin >> word_trie;

                if (heap.member(word_trie)) {
                    std::cout << word_trie << " is a member of the heap." << std::endl;
                } else {
                    std::cout << word_trie << " is not a member of the heap." << std::endl;
                }
                break;
            case 6:
                execute = false;
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid option, please choose again." << std::endl;
                break;
        }
    }
}

void TriePointers(){
    bool execute = true;
    int option;
    shared_ptr<Trie> myTrie(new Trie());
    string word;
    string word_member;

    while (execute) {
        std::cout << "Choose an action for your Trie: " << std::endl;
        std::cout << "1. Insert Word" << std::endl;
        std::cout << "2. Search Word" << std::endl;
        std::cout << "3. Delete Word" << std::endl;
        std::cout << "4. Print All Words in Trie" << std::endl;
        std::cout << "5. Member" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "--->: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter the word to insert: ";
                std::cin >> word;
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                myTrie->insert_word(word);
                std::cout << "Word inserted successfully!" << std::endl;
                break;

            case 2:
                std::cout << "Enter the word to search: ";
                std::cin >> word;
                if (myTrie->search_word(word)) {
                    std::cout << "Word found in the Trie." << std::endl;
                } else {
                    std::cout << "Word not found in the Trie." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter the word to delete: ";
                std::cin >> word;
                if (myTrie->delete_word(word)) {
                    std::cout << "Word deleted successfully." << std::endl;
                } else {
                    std::cout << "Word not found in the Trie." << std::endl;
                }
                break;
            case 4:
                std::cout << "Words in the Trie: " << std::endl;
                myTrie->print_trie(myTrie->root, "");
                break;
            case 5:
                std::cout << "Enter the word_trie you want to check: ";
                std::cin >> word_member;
                myTrie->member(word_member);
                if (myTrie->member(word_member)) {
                    cout << word_member << " is a prefix in the Trie." << endl;
                } else {
                    cout << word_member << " is not a prefix in the Trie." << endl;
                }
                break;

            case 6:
                execute = false;
                std::cout << "Exiting..." << std::endl;
                break;

            default:
                std::cout << "Invalid option, please choose again." << std::endl;
                break;
        }
    }
}

int main() {
    bool execute = true;
    int option;
    int size;

    while (execute){
        cout << "Choose a data structure for your dictionary: " << endl;
        cout << "1. Binary Search Tree Pointers" << endl;
        cout << "2. Binary Search Tree Vector Heap" << endl;
        cout << "3. Trie Pointers" << endl;
        cout << "4. Trie Array" << endl;
        cout << "5. Exit" << endl;
        cout << "--->: ";
        cin >> option;
        switch (option) {
        case 1:
            cout << "Binary Search Tree Pointers" << endl;
            cin >> size;
            cout << endl;
            // ABB Punteros
            
            break;
        case 2:
            cout << "Binary Search Tree Vector Heap" << endl;
            BinaryHeap();
            break;
        case 3:
            cout << "Trie Pointers" << endl;
            TriePointers();
            break;
        case 4:
            cout << "Trie Array" << endl;
            // Trie Array
            break;
        case 5:
            execute = false;
            cout << "EXIT" << endl;
            break;
        }
    }
}