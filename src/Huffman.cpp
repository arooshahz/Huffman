#include "Huffman.h"
#include "views/loadingBar.h"
#include <QFileDialog>

using namespace std;

Huffman::Huffman(QString inFileName, QString outFileName) {


    this->inFileName = inFileName.toStdString();
    this->outFileName = outFileName.toStdString();
    createArray();

}

Huffman::~Huffman() {
    delete root;
    qDeleteAll(arr);

}

void Huffman::compress() {
    createMinHeap();
    createTree();
    createCodes();
    saveEncodedFile();
}

void Huffman::decompress() {
    getTree();
    saveDecodedFile();
}


void Huffman::createArray() {
    for (int i = 0; i < 128; i++) {
        arr.push_back(new Node());
        arr[i]->data = i, arr[i]->freq = 0;
    }
}

void Huffman::traverseTree(Node *v, string str) {
    // Check if this node is a leaf or not
    if (v->left == NULL and v->right == NULL) {
        v->code = str;
        return;
    }
    traverseTree(v->left, str + '0');
    traverseTree(v->right, str + '1');
}

int Huffman::binaryToDecimal(string str) {
    int ret = 0;
    for (auto c: str)
        ret = ret * 2 + (c - '0');
    return ret;
}

string Huffman::decimalToBinary(int num) {
    string temp = "", ret = "";
    while (num)
        temp += (num % 2 + '0'),
                num /= 2;
    ret.append(8 - temp.length(), '0');
    for (int i = temp.length() - 1; i >= 0; i--)
        ret += temp[i];
    return ret;
}

void Huffman::buildTree(char data, string &path) {
    Node *curr = root;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '0') {
            if (curr->left == NULL)
                curr->left = new Node();
            curr = curr->left;
        } else if (path[i] == '1') {
            if (curr->right == NULL)
                curr->right = new Node();
            curr = curr->right;
        }
    }
    curr->data = data;
}

void Huffman::createMinHeap() {
    char c;
    inFile.open(inFileName, ios::in);
    inFile.get(c);
    //counting the frequency of characters that have appeared in the input file
    while (!inFile.eof()) {
        arr[c]->freq++;
        inFile.get(c);
    }
    inFile.close();

    // pushing nodes into the priority queue
    for (int i = 0; i < 128; i++)
        if (arr[i]->freq > 0)
            minHeap.push(arr[i]);
}

void Huffman::createTree() {
    Node *left, *right;
    priority_queue<Node *, vector<Node *>, Compare> temp(minHeap);
    while (temp.size() != 1) {
        left = temp.top();
        temp.pop();

        right = temp.top();
        temp.pop();

        root = new Node();
        root->freq = left->freq + right->freq;

        root->left = left;
        root->right = right;
        temp.push(root);
    }
}

void Huffman::createCodes() {
    //Start the encoding process with traversing the Huffman Tree
    traverseTree(root, "");
}

void Huffman::saveEncodedFile() {
    inFile.open(inFileName, ios::in);
    outFile.open(outFileName, ios::out | ios::binary);
    string in = "", s = "";
    char c;

    // Saving the data we need from the Huffman tree
    in += (char) minHeap.size();
    priority_queue<Node *, vector<Node *>, Compare> temp(minHeap);
    while (!temp.empty()) {
        Node *curr = temp.top();
        in += curr->data;

        //128 binary bits representing code of curr->data
        s.assign(127 - curr->code.length(), '0');
        s += '1';
        s += curr->code;

        //Converting 128-bit number to 16 * 8-bit binary codes
        in += (char) binaryToDecimal(s.substr(0, 8));
        for (int i = 0; i < 15; i++) {
            //removing first 8 elements of s:
            s = s.substr(8);
            //converting first 8 elements of s into a decimal number
            in += (char) binaryToDecimal(s.substr(0, 8));
        }
        temp.pop();
    }
    s.clear();

    //Saving codes in the input file
    inFile.get(c);
    while (!inFile.eof()) {
        s += arr[c]->code;
        while (s.length() > 8) {
            in += (char) binaryToDecimal(s.substr(0, 8));
            s = s.substr(8);
        }
        inFile.get(c);
    }

    int countZeroes = 8 - s.length();
    if (s.length() < 8)
        s.append(countZeroes, '0');
    in += (char) binaryToDecimal(s);
    //append number of appended zeroes (we need it when we want to decompress the file)
    in += (char) countZeroes;

    // writing the "in" string to the output file
    outFile.write(in.c_str(), in.size());
    inFile.close();
    outFile.close();
}

void Huffman::saveDecodedFile() {

    inFile.open(inFileName, ios::in | ios::binary);
    outFile.open(outFileName, ios::out);
    unsigned char heapSize;
    //First character of the encoded text is the size of the huffman tree
    inFile.read(reinterpret_cast<char *>(&heapSize), 1);
    //Reading countZeroes at the end of the file
    inFile.seekg(-1, ios::end);
    char countZeroes;
    inFile.read(&countZeroes, 1);
    //Ignoring the data from huffman tree (1: size of the tree, 17: 1 (character) + 16 (huffman code for that character))
    inFile.seekg(1 + 17 * heapSize, ios::beg);

    unsigned char temp;
    vector<unsigned char> text;
    inFile.read(reinterpret_cast<char *>(&temp), 1);
    while (!inFile.eof()) {
        text.push_back(temp);
        inFile.read(reinterpret_cast<char *>(&temp), 1);
    }

    Node *curr = root;
    string path;
    for (int i = 0; i < text.size() - 1; i++) {
        path = decimalToBinary(text[i]);
        if (i == text.size() - 2)
            path = path.substr(0, 8 - countZeroes);
        for (int j = 0; j < path.size(); j++) {
            curr = (path[j] == '0' ? curr->left : curr->right);
            //Check if we are on a leaf or not
            if (curr->left == NULL and curr->right == NULL) {
                outFile.put(curr->data);
                curr = root;
            }
        }
    }
    inFile.close();
    outFile.close();
}

void Huffman::getTree() {
    inFile.open(inFileName, ios::in | ios::binary);
    //Reading size of minHeap
    unsigned char heapSize;
    inFile.read(reinterpret_cast<char *>(&heapSize), 1);
    root = new Node();
    //next heapSize + (1 * 16) characters contain data and code (in decimal)
    for (int i = 0; i < heapSize; i++) {
        char data;
        unsigned char codes[16];
        inFile.read(&data, 1);
        inFile.read(reinterpret_cast<char *>(codes), 16);
        // Converting decimal numbers into their binary to get huffman codes
        string codeString = "";
        for (int i = 0; i < 16; i++)
            codeString += decimalToBinary(codes[i]);
        //removing leading zeroes
        int j = 0;
        while (codeString[j] == '0')
            j++;
        codeString = codeString.substr(j + 1);
        //Adding node with "code" data and "codeString" code to the huffman tree
        buildTree(data, codeString);
    }
    inFile.close();
}
