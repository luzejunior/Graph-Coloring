#include <iostream>
#include <vector>

using namespace std;

class Graph{
  public:
    vector<int> nodes;
    vector<vector<int>> *nextNode;
    vector<int> solution;
    int color = 1;

    void createMatrix();
    void createGraph(int);
    void printGraph();
    void createEdge(int, int);
    void colourGraph(int);
    bool canAssignColor(int, int);
  };
