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
    HuffmanNode(HuffmanNode* left, HuffmanNode* right) : data('\0'), 
                frequency(left->frequency + right->frequency), left(left), right(right) {}
};

// Comparator for the MinHeap
struct HuffmanCompare {
    bool operator()(HuffmanNode* l, HuffmanNode* r);
};

// encoding the Huffman tree
void encode(HuffmanNode* root, std::string code, std::unordered_map<char, std::string>& HuffmanCode);

class MinHeap {
public:
    MinHeap() = default; // Default constructor
    void insert(HuffmanNode* node); // Insert a node into the heap
    void print(); // Print the Heap
    HuffmanNode* extractMin(); // Extract the node with the smallest frequency
    bool isEmpty() const; // Check if the heap is empty
    int size() const; // Return the size of the heap
private:
    std::vector<HuffmanNode*> heap; // Vector to store heap elements
};

#endif // MINHEAP_H
