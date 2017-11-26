#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/graph.hpp"

using namespace std;

int main() {
    Graph g1;

    int numberOfElements;
    ifstream file("samples/fpsol2.i.2.col");
    string line;

    while(getline(file, line)) {
        string mark, edge;
        int int1, from, to;
        stringstream ss1(line);
        while(ss1 >> mark >> edge >> int1) {
           if(mark == "p") {
               numberOfElements = int1;
               for (int i = 0; i < numberOfElements; i++) {
                 g1.createGraph(i-1);
               }
               g1.createMatrix();
               break;
           }
        }
        stringstream ss2(line);
        while(ss2 >> mark >> from >> to) {
            if(mark == "e"){
                g1.createEdge(from-1, to-1);
            }
        }
    }

    g1.runAlgorithm();

    cout << "Best Solution: " << g1.bestSolution << endl;
    // for (int i = 0; i < g1.independentVertices.size(); i++) {
    //   cout << "Nodee: " << i << " color: " << g1.independentVertices[i] << endl;
    // }

    //g1.printGraph();

    //g1.calculateNumGraph();

    return 0;
}
