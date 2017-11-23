#include "node.h"

Node::Node(int number, int nextNode) {
  this->number = number;
  this->nextNode = nextNode;
}

void Node::initializeColor(int color) {
  this->color = color;
}
