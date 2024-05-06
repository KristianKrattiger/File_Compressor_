#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <functional>

// Forward declaration of HuffmanNode
struct HuffmanNode;

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
