#include "Node.h"

Node::Node(char *d, int s) {
    data = d;
    frequency = s;
    left = right = nullptr;
}

Node::Node(Node *l, Node *r) {
//    data = 0;
    frequency = l->getFrequency() + r->getFrequency();
    left = l;
    right = r;
}

Node::~Node() {
    delete left;
    delete right;
}

int Node::getFrequency() {
    return frequency;
}