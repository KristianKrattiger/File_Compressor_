#include "MinHeap.h"
#include <algorithm>

struct HuffmanNode{
    char character;
    unsigned frequency = 0;
    HuffmanNode *lLink, *rLink;

    HuffmanNode(char ch, unsigned freq)
        : character(ch), frequency(freq), lLink(nullptr), rLink(nullptr) {}
};

//ensures the integrity of the min-ordered heap
bool HuffmanCompare::operator()(HuffmanNode* l, HuffmanNode* r){
    return l->frequency > r->frequency;
}

void MinHeap::insert(HuffmanNode* node){
    heap.push_back(node); //insert into bottom
    std::push_heap(heap.begin(), heap.end(), HuffmanCompare()); //maintain heap properties
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