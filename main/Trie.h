#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <memory>
#include <string>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    std::shared_ptr<TrieNode> children[ALPHABET_SIZE];
    bool isWord;

    TrieNode();
};

class Trie {
private:
    int Total_words;
    bool del(std::string& trieString, std::shared_ptr<TrieNode>& checkout);
    bool is_empty(std::shared_ptr<TrieNode> check) const;

public:
    std::shared_ptr<TrieNode> root;
    Trie();

    int i2c(char c);
    void insert_word(std::string& trieString);
    bool search_word(std::string& trieString);
    bool delete_word(std::string& trieString);
    bool member(std::string& trieString);
    void print_trie(std::shared_ptr<TrieNode> node, std::string word);

};


#endif
