#include <iostream>

using namespace std;

class Node{
  public:
    int number;
    int nextNode;
    int color;

    Node(int, int);
    void initializeColor(int);
  };
