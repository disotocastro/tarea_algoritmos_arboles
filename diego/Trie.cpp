#include "Trie.h"
using std::string, std::cout, std::shared_ptr, std::endl;

TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = shared_ptr<TrieNode>();
    }
    isWord = false;
}

Trie::Trie() {
    root = shared_ptr<TrieNode>(new TrieNode());
    Total_words = 0;
}

int Trie::i2c(char c) {
    return static_cast<int>(c - 'a');
}

void Trie::insert_word(string& trieString) {
    shared_ptr<TrieNode> current = root;
    for (int i = 0; i < trieString.size(); i++) {
        if (current->children[i2c(trieString[i])] == shared_ptr<TrieNode>(nullptr)) {
            current->children[i2c(trieString[i])] = shared_ptr<TrieNode>(new TrieNode());
        }
        current = (current->children[i2c(trieString[i])]);
    }
    current->isWord = true;
}

bool Trie::search_word(string& trieString) {
    shared_ptr<TrieNode> current = root;
    for (int i = 0; i < trieString.size(); i++) {
        if (current->children[i2c(trieString[i])] == shared_ptr<TrieNode>(nullptr)) {
            return false;
        }
        current = current->children[i2c(trieString[i])];
    }
    if (current->isWord == true) {
        return true;
    }
    return false;
}

bool Trie::Partdelete(string& trieString, shared_ptr<TrieNode>& checkout) {
    if (checkout == nullptr) {
        return false;
    }
    if (trieString.size() == 0) {
        if (checkout->isWord == true) {
            checkout->isWord = false;
            return true;
        }
        return false;
    }
    string part = trieString.substr(1);
    if (Partdelete(part, checkout->children[i2c(trieString[0])])) {
        if (isEmptyNode(checkout->children[i2c(trieString[0])])) {
            checkout->children[i2c(trieString[0])].reset();
            checkout->children[i2c(trieString[0])] = nullptr;
            return true;
        }
        else
            return true;
    }
    else
        return false;
    return false;
}

bool Trie::delete_word(string& trieString) {
    if (Partdelete(trieString, root)) {
        return true;
    }
    return false;
}

bool Trie::isEmptyNode(shared_ptr<TrieNode> check) const {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (check->children[i] != nullptr || check->isWord == true) {
            return false;
        }
    }
    return true;
}

void Trie::print_trie(std::shared_ptr<TrieNode> node, std::string word) {
    if (node == nullptr) {
        return;
    }

    if (node->isWord) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != nullptr) {
            print_trie(node->children[i], word + static_cast<char>('a' + i));
        }
    }
}
