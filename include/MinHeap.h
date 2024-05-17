#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <functional>

// Forward declaration of HuffmanNode
struct HuffmanNode {
    char data; // Data stored in the node
    unsigned frequency; // Frequency of the data
    HuffmanNode* left; // Pointer to the left child
    HuffmanNode* right; // Pointer to the right child

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparator for the MinHeap
struct HuffmanCompare {
    bool operator()(HuffmanNode* l, HuffmanNode* r);
};

class MinHeap {
public:
    MinHeap() = default; // Default constructor
    void insert(HuffmanNode* node); // Insert a node into the heap
    HuffmanNode* extractMin(); // Extract the node with the smallest frequency
    bool isEmpty() const; // Check if the heap is empty

private:
    std::vector<HuffmanNode*> heap; // Vector to store heap elements
};

#endif // MINHEAP_H
