#include <iostream>
#include "src/graph.h"

using namespace std;

int main() {
  Graph g1;

  g1.createGraph(0);
  g1.createGraph(1);
  g1.createGraph(2);
  g1.createGraph(3);

  g1.createMatrix();

  g1.createEdge(0,1);
  g1.createEdge(0,3);
  g1.createEdge(1,3);
  g1.createEdge(1,2);
  g1.createEdge(2,3);

  //g1.printGraph();
  g1.colourGraph(0);

  cout << "Number of colors used: " << g1.color << endl;
  for (int i = 0; i < g1.solution.size(); i++) {
    cout << "Node: " << i << " color: " << g1.solution[i] << endl;
  }

  return 0;
}
