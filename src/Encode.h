#ifndef HUFFMAN_ENCODE_H
#define HUFFMAN_ENCODE_H

#include <fstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Huffman Tree Nodes
struct Node {
    char data;
    unsigned int freq;
    string code;
    Node *left, *right;
    Node() {
        left = right = NULL;
    }
};

class Encode {
private:
    vector<Node *> arr;
    fstream inFile, outFile;
    string inFileName, outFileName;
    Node *root;
    class Compare {
    public:
        bool operator()(Node *l, Node *r) {
            return (l->freq > r->freq);
        }
    };
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // vector of tree nodes: {characters ascii code, it's frequency}
    void createArray();

    // traversing the tree to generate huffman code for each character
    void traverseTree(Node *, string);

    int binaryToDecimal(string);
    string decimalToBinary(int);

    // rebuilding the huffman tree for decoding the file
    void buildTree(char, string &);

    void createMinHeap();

    // creating the huffman tree
    void createTree();

    // generating huffman codes
    void createCodes();
    void saveEncodedFile();
    void saveDecodedFile();

    // reading the file to rebuild the huffman tree
    void getTree();

public:
    // Constructor
    Encode(string inFileName, string outFileName) {
        this->inFileName = inFileName;
        this->outFileName = outFileName;
        createArray();
    }
    void compress();
    void decompress();
};

#endif // HUFFMAN_ENCODE_H
