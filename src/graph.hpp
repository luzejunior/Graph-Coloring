#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


using namespace std;

class Graph{
public:
    vector <int> nodes;
    vector <vector <int>> *nextNode;
    vector <int> coloredGraph;
    vector <int> independentVertices;
    vector <int> solutions;
    int color = 1;
    int bestSolution = 9999999;
    vector <int> bestSolutionColors;

    void createMatrix();
    void createGraph(int);
    void printGraph();
    void createEdge(int, int);
    void colourGraph(int);
    bool canAssignColor(int, int);
    void calculateNumGraph();
    void getIndependentVertices(vector<int>);
    void clearColorsSolution();
    void getBestSolution();
    void runAlgorithm();
    void copySolutionToVector(vector<int>*, vector<int>);
    void VND(int);
};

#endif
