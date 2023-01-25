#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


class Node {
private :
    int frequency;
    char *data;
    Node *left;
    Node *right;
public:
    Node(char *d, int s);

    Node(Node *l, Node *r);

    ~Node();

    int getFrequency();
};


#endif //HUFFMAN_NODE_H
