#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/graph.hpp"

using namespace std;

int main() {
    Graph g1;

    int numberOfElements;
    ifstream file("Samples/le450_15a.col");
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

    // g1.createEdge(0,9);
    // g1.createEdge(0,7);
    // g1.createEdge(1,2);
    // g1.createEdge(1,4);
    // g1.createEdge(2,4);
    // g1.createEdge(3,4);
    // g1.createEdge(3,5);
    // g1.createEdge(4,5);
    // g1.createEdge(4,6);
    // g1.createEdge(4,8);
    // g1.createEdge(5,8);
    // g1.createEdge(5,7);
    // g1.createEdge(6,7);
    // g1.createEdge(7,9);
    // g1.createEdge(7,8);

    //g1.printGraph();
    //g1.colourGraph(0);

    g1.runAlgorithm();

    cout << "Best Solution: " << g1.bestSolution << endl;
    // for (int i = 0; i < g1.coloredGraph.size(); i++) {
    //    cout << "Nodee: " << i << " color: " << g1.coloredGraph[i] << endl;
    // }

    //g1.printGraph();

    g1.calculateNumGraph();

    return 0;
}
