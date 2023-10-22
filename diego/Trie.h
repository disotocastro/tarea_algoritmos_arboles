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

public:
    std::shared_ptr<TrieNode> root;
    Trie();

    int i2c(char c);
    void insertWord(std::string& trieString);
    bool searchWord(std::string& trieString);
    bool deleteWord(std::string& trieString);
    void printTrie(std::shared_ptr<TrieNode> node, std::string word);
private:
    bool Partdelete(std::string& trieString, std::shared_ptr<TrieNode>& checkout);
    bool isEmptyNode(std::shared_ptr<TrieNode> check) const;
};

#endif
