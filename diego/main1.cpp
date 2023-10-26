#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>


class MaxHeap {
private:
    std::vector<std::string> heap;

  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }


void heapifyUp(int i) {
    while (i != 0 && heap[parent(i)] < heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void heapifyDown(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap.size() && heap[l] > heap[i]) {
        largest = l;
    }

    if (r < heap.size() && heap[r] > heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapifyDown(largest);
    }
}

public:

  void insert(const std::string& key) {
      heap.push_back(key);
      int index = heap.size() - 1;
      heapifyUp(index);
  }

  void insert(int key) {
    insert(std::to_string(key));
  }

    bool member(const std::string& key) {
        for (const auto& item : heap) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }

    bool member(int key) {
        return member(std::to_string(key));
    }

    void deleteKey(const std::string& key) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw std::runtime_error("Key not found");
        }

        heap[index] = heap.back();
        heap.pop_back();

        heapifyDown(index);
    }

    void deleteKey(int key) {
        deleteKey(std::to_string(key));
    }

    void print() {
        for (const auto& item : heap) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    void displayTree() {
    if (heap.empty()) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }

    int n = heap.size();

    // Calculate the height of the heap.
    int height = log2(n) + 1;

    int levelStart = 0; // starting index for the current level
    for (int i = 0; i < height; ++i) {
        int levelEnd = std::min((levelStart + pow(2, i) - 1), (double)n - 1);  // ending index for the current level

        // Print nodes at the current level.
        for (int j = levelStart; j <= levelEnd; ++j) {
            std::cout << heap[j] << " ";
        }

        std::cout << std::endl;  // line break for the next level

        levelStart = levelEnd + 1;  // update the starting index for the next level
    }
}

};


int main() {
    MaxHeap heap;

    heap.insert("10");
    heap.insert("1");
    heap.insert("2");
    heap.insert("3");
    heap.insert("4");
    heap.insert("5");
    heap.insert("6");
    heap.insert("7");
    heap.insert("8");
    heap.insert("9");


    // heap.insert("apple");
    // heap.insert("banana");

    heap.print();  // Expect something like: 20 banana 15 10 5 apple
    heap.displayTree();

    // std::cout << heap.member(10) << std::endl;    // 1 (true)
    // std::cout << heap.member("apple") << std::endl; // 1 (true)
    // std::cout << heap.member("cherry") << std::endl; // 0 (false)

    // heap.deleteKey(5);
    // heap.deleteKey("banana");

    // heap.print();  // Expect something like: 20 apple 15 10

    return 0;
}