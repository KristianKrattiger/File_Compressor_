/**
 * @file huffman.cpp
 * @brief Implementation of the MinHeap class and the HuffmanNode class.
 *
 * This file contains the implementation of the MinHeap class, which represents a min-heap data structure,
 * and the HuffmanNode class, which represents a node in a Huffman tree.
 * The MinHeap class is used to store HuffmanNode objects and perform operations such as insertion, extraction,
 * and checking if the heap is empty.
 * The HuffmanNode class represents a node in a Huffman tree and contains methods for getting the left and right
 * child nodes, getting the data and frequency of the node, printing the tree, encoding and decoding the data,
 * and assigning binary codes to characters.
 *
 * @author [Kristian Krattiger]
 */
#include "huffman.h"
#include <algorithm>
#include <iostream>


// Ensures the integrity of the min-ordered heap
bool HuffmanNode::HuffmanCompare::operator()(HuffmanNode* l, HuffmanNode* r) {
    return l->getFrequency() > r->getFrequency();
}


// Getters for HuffmanNode class
HuffmanNode* HuffmanNode::getLeft() {
    return left;
}


HuffmanNode* HuffmanNode::getRight() {
    return right;
}


char HuffmanNode::getData() {
    return data;
}


unsigned HuffmanNode::getFrequency() {
    return frequency;
}


// Print the Huffman tree
void HuffmanNode::printTree(HuffmanNode* root) {
    if (!root) {
        return;
    }
    std::cout << "Character: " << root->getData() << ", Frequency: " << root->getFrequency() << std::endl;
    printTree(root->getLeft());
    printTree(root->getRight());
}


// Recursively traverse the tree and assign a binary code to each character
void HuffmanNode::encode(const std::string& code, std::map<char, std::string>& HuffmanCode) {
    HuffmanNode* huffmanPtr = this;
    if (!huffmanPtr) {
        return;
    }
    if (!huffmanPtr->getLeft() && !huffmanPtr->getRight()) {
        std::cout << "Assigning " << huffmanPtr->getData() << " the code " << code << "\n";
        HuffmanCode[huffmanPtr->getData()] = code;
    }
    if (huffmanPtr->getLeft()) {
        std::cout << "Going left\n";
        huffmanPtr->getLeft()->encode(code + "0", HuffmanCode);
    }
    if (huffmanPtr->getRight()) {
        std::cout << "Going right\n";
        huffmanPtr->getRight()->encode(code + "1", HuffmanCode);
    }
}


// Traverse the tree and decode the binary code to the original string
void HuffmanNode::decode(HuffmanNode* huffmanPtr, std::ifstream& infile, std::ofstream& outfile) {
    char bit;
    while (true) {
        if (!infile.get(bit)) {
            if (infile.eof()) {
                std::cout << "Reached end of file.\n";
            } else {
                std::cerr << "Error reading from file.\n";
            }
            break;
        }
        std::cout << "Read bit: " << bit << std::endl;  // Debug: what bit did we read?


        if (bit == '0') {
            std::cout << "Going left\n";
            huffmanPtr = huffmanPtr->getLeft();
        } else if (bit == '1') {
            std::cout << "Going right\n";
            huffmanPtr = huffmanPtr->getRight();
        } else {
            std::cerr << "Invalid character in file: " << bit << std::endl;
            continue;
        }


        if (!huffmanPtr->getLeft() && !huffmanPtr->getRight()) {
            std::cout << "Writing " << huffmanPtr->getData() << " to file\n";
            outfile << huffmanPtr->getData();
            huffmanPtr = this;  // Assuming 'root' is a pointer to the root of your Huffman tree
        }
    }
}


// Insert a HuffmanNode into the min-heap
void MinHeap::insert(HuffmanNode* node) {
    heap.push_back(node); // Insert into bottom
    std::push_heap(heap.begin(), heap.end(), HuffmanNode::HuffmanCompare()); // Maintain heap properties
}


// Print the contents of the min-heap
void MinHeap::print() {
    for (HuffmanNode* node : heap) {
        std::cout << "Character: " << node->getData()
                  << ", Frequency: " << node->getFrequency() << std::endl;
    }
}


// Extract the minimum element from the min-heap
HuffmanNode* MinHeap::extractMin() {
    if (heap.empty()) {
        return nullptr; // Handle the case where the heap is empty
    }


    std::pop_heap(heap.begin(), heap.end(), HuffmanNode::HuffmanCompare()); // Move smallest to end
    HuffmanNode* minNode = heap.back(); // Get the smallest element


    heap.pop_back(); // Remove it from the vector
    return minNode;
}


// Check if the min-heap is empty
bool MinHeap::isEmpty() const {
    return heap.empty();
}


// Get the size of the min-heap
int MinHeap::size() const {
    return heap.size();
}
