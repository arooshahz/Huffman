#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H
#include "QObject"
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

class Huffman : public QObject {
    class Compare {
    public:
        bool operator()(Node *l, Node *r) {
            return (l->freq > r->freq);
        }
    };

private:
    vector<Node *> arr;
    fstream inFile, outFile;
    basic_string<char> outFileName;
    basic_string<char> inFileName;

    Node *root;

    priority_queue<Node *, vector<Node *>, Compare> minHeap;

public:


    // Constructor
    Huffman(QString inFileName, QString outFileName);

    ~Huffman();

    void compress();

    void decompress();

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


};

#endif // HUFFMAN_HUFFMAN_H
