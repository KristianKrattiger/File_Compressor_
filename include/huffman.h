#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <functional>
#include <map>
#include <fstream>

// Forward declaration of HuffmanNode
/**
 * @brief Represents a node in the Huffman tree.
 */
class HuffmanNode {
private:
    char data; ///< Data stored in the node
    unsigned frequency; ///< Frequency of the data
    HuffmanNode* left; ///< Pointer to the left child
    HuffmanNode* right; ///< Pointer to the right child

public:
    /**
     * @brief Default constructor.
     */
    HuffmanNode() : data('\0'), frequency(0), left(nullptr), right(nullptr) {}

    /**
     * @brief Leaf node constructor.
     * @param data The data stored in the node.
     * @param frequency The frequency of the data.
     */
    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

    /**
     * @brief Internal node constructor.
     * @param left Pointer to the left child.
     * @param right Pointer to the right child.
     */
    HuffmanNode(HuffmanNode* left, HuffmanNode* right) : data('\0'), frequency(left->frequency + right->frequency), left(left), right(right) {}

    /**
     * @brief Copy constructor.
     * @param other The HuffmanNode object to copy from.
     */
    HuffmanNode(const HuffmanNode& other) : data(other.data), frequency(other.frequency), left(other.left), right(other.right) {}

    /**
     * @brief Build the Huffman tree based on the frequency map.
     * @param frequency_map The frequency map of characters.
     * @return Reference to the HuffmanNode object.
     */
    HuffmanNode& buildHuffmanTree(std::map<char, unsigned>& frequency_map);

    /**
     * @brief Move assignment operator.
     * @param other The HuffmanNode object to move from.
     * @return Reference to the HuffmanNode object.
     */
    HuffmanNode& operator=(HuffmanNode&& other) {
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

    /**
     * @brief Copy assignment operator.
     * @param other The HuffmanNode object to copy from.
     * @return Reference to the HuffmanNode object.
     */
    HuffmanNode& operator=(HuffmanNode& other) {
        if (this != &other) {
            data = other.data;
            frequency = other.frequency;
            left = other.left;
            right = other.right;
        }
        return *this;
    }

    /**
     * @brief Destructor.
     */
    ~HuffmanNode() {
        delete left;
        delete right;
    }

    /**
     * @brief Get the left child of the node.
     * @return Pointer to the left child.
     */
    HuffmanNode* getLeft();

    /**
     * @brief Get the right child of the node.
     * @return Pointer to the right child.
     */
    HuffmanNode* getRight();

    /**
     * @brief Get the data stored in the node.
     * @return The data stored in the node.
     */
    char getData();

    /**
     * @brief Get the frequency of the data.
     * @return The frequency of the data.
     */
    unsigned getFrequency();

    /**
     * @brief Print the Huffman tree.
     * @param root Pointer to the root of the tree.
     */
    void printTree(HuffmanNode* root);

    /**
     * @brief Comparator for the MinHeap.
     */
    struct HuffmanCompare {
        /**
         * @brief Compare two HuffmanNode objects.
         * @param l The left HuffmanNode object.
         * @param r The right HuffmanNode object.
         * @return True if the frequency of the left node is greater than the frequency of the right node, false otherwise.
         */
        bool operator()(HuffmanNode* l, HuffmanNode* r);
    };

    /**
     * @brief Encode the Huffman tree.
     * @param code The current code being generated.
     * @param HuffmanCode The map to store the Huffman codes.
     */
    void encode(const std::string& code, std::map<char, std::string>& HuffmanCode);

    /**
     * @brief Decode the Huffman tree.
     * @param huffmanPtr Pointer to the Huffman tree.
     * @param infile Input file stream.
     * @param outfile Output file stream.
     */
    void decode(HuffmanNode* huffmanPtr, std::ifstream& infile, std::ofstream& outfile);
};

class MinHeap {
public:
    // Default constructor
    MinHeap() = default;

    // Copy constructor
    MinHeap(const MinHeap& other) : heap(other.heap) {}

    // Move constructor
    MinHeap(MinHeap&& other) : heap(std::move(other.heap)) {}

    // Copy assignment operator
    MinHeap& operator=(const MinHeap& other) {
        if (this != &other) {
            heap = other.heap;
        }
        return *this;
    }

    // Move assignment operator
    MinHeap& operator=(MinHeap&& other) {
        if (this != &other) {
            heap = std::move(other.heap);
        }
        return *this;
    }

    // Destructor
    ~MinHeap() {
        for (HuffmanNode* node : heap) {
            delete node;
        }
    }

    // Insert a node into the heap
    void insert(HuffmanNode* node);

    // Print the Heap
    void print();

    // Extract the node with the smallest frequency
    HuffmanNode* extractMin();

    // Check if the heap is empty
    bool isEmpty() const;

    // Return the size of the heap
    int size() const;

private:
    std::vector<HuffmanNode*> heap; // Vector to store heap elements
};

#endif // HUFFMAN_H
