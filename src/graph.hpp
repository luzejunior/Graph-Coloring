/*

Author: Luzenildo de Sousa Batista Junior
E-Mail: luzejunior94@gmail.com

License:

MIT License

Copyright (c) 2017 Luzenildo de Sousa Batista Junior

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


using namespace std;

struct Solution {
  vector <int> colorGraph;
  int numberOfColorsUsed = 1;
  int index;
};

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
    vector <int> createColorgraph();
    void createGraph(int);
    void printGraph();
    void createEdge(int, int);
    void colourGraph(vector <int>*, int, int*);
    bool canAssignColor(vector <int>* ,int, int);
    void calculateNumGraph();
    void getIndependentVertices(vector<int>);
    void clearColorsSolution();
    vector <int> sortVector();
    void getBestSolution();
    void runAlgorithm();
    void tryToRemoveColor(Solution*, int);
    void selectSolution(Solution*, double);
    void GRASP(Solution*, int, double);
    void RemoveColor(Solution*);
    void copySolutionToVector(vector<int>*, vector<int>);
    void VND(int);
};

#endif
