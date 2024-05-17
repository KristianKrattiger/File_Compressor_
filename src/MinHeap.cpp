#include "MinHeap.h"
#include <algorithm>
#include <iostream>

//ensures the integrity of the min-ordered heap
bool HuffmanCompare::operator()(HuffmanNode* l, HuffmanNode* r){
    return l->frequency < r->frequency;
}

void MinHeap::insert(HuffmanNode* node){
    heap.push_back(node); //insert into bottom
    std::push_heap(heap.begin(), heap.end(), HuffmanCompare()); //maintain heap properties
}

void MinHeap::print(){
    for (HuffmanNode* node : heap){
        std::cout << "Character: " << node->data
                  << ", Frequency: " << node->frequency << std::endl;
    }
}


HuffmanNode* MinHeap::extractMin() {
    std::pop_heap(heap.begin(), heap.end(), HuffmanCompare()); // Move smallest to end
    HuffmanNode* minNode = heap.back(); // Get the smallest
    heap.pop_back(); // Remove it from the vector
    return minNode;
}

bool MinHeap::isEmpty() const {
    return heap.empty();
}