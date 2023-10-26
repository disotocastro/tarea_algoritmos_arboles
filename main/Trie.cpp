#include "Trie.h"  // Incluye el archivo de encabezado Trie.h

using std::string, std::cout, std::shared_ptr, std::endl;  // Usa ciertos elementos del espacio de nombres estándar

// Constructor de TrieNode (nodo del Trie)
TrieNode::TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = shared_ptr<TrieNode>();
    }
    isWord = false;  // Inicializa isWord como falso
}

// Constructor de Trie
Trie::Trie() {
    root = shared_ptr<TrieNode>(new TrieNode());
    Total_words = 0;  // Inicializa el contador de palabras como cero
}

// Convierte un carácter en un índice (0-25) usando 'a' como base
int Trie::i2c(char c) {
    return static_cast<int>(c - 'a');
}

// Inserta una palabra en el Trie
void Trie::insert_word(string& trieString) {
    shared_ptr<TrieNode> current = root;
    for (int i = 0; i < trieString.size(); i++) {
        if (current->children[i2c(trieString[i])] == shared_ptr<TrieNode>(nullptr)) {
            current->children[i2c(trieString[i])] = shared_ptr<TrieNode>(new TrieNode());
        }
        current = (current->children[i2c(trieString[i])]);
    }
    current->isWord = true;  // Marca la última letra de la palabra como una palabra completa
}

// Busca una palabra en el Trie
bool Trie::search_word(string& trieString) {
    shared_ptr<TrieNode> current = root;
    for (int i = 0; i < trieString.size(); i++) {
        if (current->children[i2c(trieString[i])] == shared_ptr<TrieNode>(nullptr)) {
            return false;  // La palabra no está en el Trie
        }
        current = current->children[i2c(trieString[i])];
    }
    return current->isWord;  // Devuelve verdadero si se encuentra una palabra completa
}

// Elimina una palabra del Trie
bool Trie::del(string& trieString, shared_ptr<TrieNode>& checkout) {
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
    if (del(part, checkout->children[i2c(trieString[0])])) {
        if (is_empty(checkout->children[i2c(trieString[0])])) {
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

// Inicia la eliminación de una palabra del Trie
bool Trie::delete_word(string& trieString) {
    if (del(trieString, root)) {
        return true;
    }
    return false;
}

bool Trie::member(std::string &trieString) {
    shared_ptr<TrieNode> current = root;

    for (int i = 0; i < trieString.size(); i++) {
        if (current->children[i2c(trieString[i])] == shared_ptr<TrieNode>(nullptr)) {
            return false;  // No es parte
        }
        current = current->children[i2c(trieString[i])];
    }

    return true;  // Si es
}

// Comprueba si un nodo Trie está vacío (sin hijos ni palabras completas)
bool Trie::is_empty(shared_ptr<TrieNode> check) const {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (check->children[i] != nullptr || check->isWord == true) {
            return false;
        }
    }
    return true;
}

// Imprime todas las palabras almacenadas en el Trie
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
