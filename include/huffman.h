#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <functional>
#include <map>
#include <fstream>

// Forward declaration of HuffmanNode
class HuffmanNode {
private:
    char data; // Data stored in the node
    unsigned frequency; // Frequency of the data
    HuffmanNode* left; // Pointer to the left child
    HuffmanNode* right; // Pointer to the right child
public:    
    HuffmanNode() : data('\0'), frequency(0), left(nullptr), right(nullptr) {} // Default constructor
    HuffmanNode(char data, unsigned frequency) : data(data), 
                frequency(frequency), left(nullptr), right(nullptr) {} //leaf node constructor
    HuffmanNode(HuffmanNode* left, HuffmanNode* right) : data('\0'), 
                frequency(left->frequency + right->frequency), left(left), right(right) {} //internal node constructor
    HuffmanNode(const HuffmanNode& other) : data(other.data), frequency(other.frequency), left(other.left), right(other.right) {} // Copy constructor

    HuffmanNode& buildHuffmanTree(std::map<char, unsigned>& frequency_map); 

    HuffmanNode& operator=(HuffmanNode&& other) { // Move assignment operator
        if (this != &other) {
            data = other.data;
            frequency = other.frequency;
            left = other.left;
            right = other.right;
            other.left = nullptr;
            other.right = nullptr;
        }
        return *this;
    } 

    HuffmanNode& operator=(HuffmanNode& other) { // Copy assignment operator
        if (this != &other) {
            data = other.data;
            frequency = other.frequency;
            left = other.left;
            right = other.right;
        }
        return *this;
    } 

    ~HuffmanNode() {
        delete left;
        delete right;
    }

    HuffmanNode* getLeft();
    HuffmanNode* getRight();
    char getData();
    unsigned getFrequency(); 

    //print the tree
    void printTree(HuffmanNode* root);

    // Comparator for the MinHeap
    struct HuffmanCompare {
        bool operator()(HuffmanNode* l, HuffmanNode* r);
    };

    // encoding the Huffman tree
    void encode(const std::string& code, std::map<char, std::string>& HuffmanCode);

    // decode the Huffman tree
    void decode(HuffmanNode* huffmanPtr, std::ifstream& infile, std::ofstream& outfile);
};

class MinHeap {
public:
    MinHeap() = default; // Default constructor
    MinHeap(const MinHeap& other) : heap(other.heap) {} // Copy constructor
    MinHeap(MinHeap&& other) : heap(std::move(other.heap)) {} // Move constructor
    MinHeap& operator=(const MinHeap& other) { // Copy assignment operator
        if (this != &other) {
            heap = other.heap;
        }
        return *this;
    }
    MinHeap& operator=(MinHeap&& other) { // Move assignment operator
        if (this != &other) {
            heap = std::move(other.heap);
        }
        return *this;
    }
    ~MinHeap() {
        for (HuffmanNode* node : heap) {
            delete node;
        }
    }
    void insert(HuffmanNode* node); // Insert a node into the heap
    void print(); // Print the Heap
    HuffmanNode* extractMin(); // Extract the node with the smallest frequency
    bool isEmpty() const; // Check if the heap is empty
    int size() const; // Return the size of the heap
private:
    std::vector<HuffmanNode*> heap; // Vector to store heap elements
};

#endif //   HUFFMAN_H
