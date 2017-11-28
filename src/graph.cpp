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

#include "graph.hpp"

void Graph::createGraph(int node) {
  this->nodes.push_back(node);
  this->coloredGraph.push_back(0);
}

vector <int> Graph::createColorgraph() {
  vector <int> colorGraph;

  for (int i = 0; i < this->nodes.size(); i++) {
    colorGraph.push_back(0);
  }

  return colorGraph;
}

void Graph::createMatrix() {
  this->nextNode = new vector<vector<int>>(this->nodes.size(), vector<int>());
}

void Graph::createEdge(int node, int next) {
  (*nextNode)[node].push_back(next);
  (*nextNode)[next].push_back(node);
}

void Graph::printGraph() {
  for (int i = 0; i < this->coloredGraph.size(); i++) {
  //if ((*nextNode)[i].size() == 1) {
      cout << "Node inside: " << i << "Color: " << this->coloredGraph[i] << endl;
    //}
      //for (int j = 0; j < (*nextNode)[i].size(); j++) {
      //    cout << "Node inside: " << (*nextNode)[i][j] << endl;
      //}
  }
}

void Graph::calculateNumGraph() {
  int count = 0;
  for (int i = 0; i < (*nextNode).size(); i++) {
    count += (*nextNode)[i].size();
  }
  cout << count << endl;
}

void Graph::colourGraph(vector <int> *vec, int node, int *colors) {
  int c = 1;
  while(c <= *colors) {
    if ((*vec)[node] != 0) {
      return;
    }
    if (canAssignColor(vec, node, c)) {
      (*vec)[node] = c;
      int nextNode = node + 1;
      if (nextNode < this->nodes.size()) {
        colourGraph(vec, nextNode, colors);
      } else {
        colourGraph(vec, 0, colors);
      }
    } else {
      c++;
      if (c > *colors) {
        (*colors)++;
      }
    }
  }
}

bool Graph::canAssignColor(vector <int> *vec, int node, int color) {
  for (int i = 0; i < (*nextNode)[node].size(); i++) {
    if (color == (*vec)[(*nextNode)[node][i]]) {
        return false;
    }
  }
  return true;
}

void Graph::getIndependentVertices(vector<int> cvector) {
  if (!this->independentVertices.empty()) {
    this->independentVertices.clear();
  }
  for (int i = 0; i < cvector.size(); i++) {
      if (cvector[i] == 1) {
        this->independentVertices.push_back(i);
      }
  }
}

void Graph::clearColorsSolution() {
  for (int i = 0; i < this->coloredGraph.size(); i++) {
    this->coloredGraph[i] = 0;
  }
  this->color = 1;
}

void Graph::getBestSolution() {
  for (int i = 0; i < this->solutions.size(); i++)  {
    if (this->solutions[i] < bestSolution) {
        bestSolution = this->solutions[i];
    }
  }
}

void Graph::copySolutionToVector(vector <int> *bsc, vector <int> fromVec) {
  if (!bsc->empty()) {
    bsc->clear();
  }
  for (int i = 0; i < fromVec.size(); i++) {
    bsc->push_back(fromVec[i]);
  }
}

vector <int> Graph::sortVector() {
  vector <int> nodeIndices;
  vector <int> nextNodeCopy;

  for (int i = 0; i < (*nextNode).size(); i++) {
    nextNodeCopy.push_back((*nextNode)[i].size());
  }

  cout << nextNodeCopy.size() << endl;

  while (nodeIndices.size() < nextNodeCopy.size()) {
    int aux = 0;
    int j = 0;
    for (int i = 0; i < nextNodeCopy.size(); i++) {
      if (nextNodeCopy[i] > aux) {
        aux = nextNodeCopy[i];
        j = i;
      }
    }
    nodeIndices.push_back(j);
    nextNodeCopy[j] = 0;
  }
  return nodeIndices;
}

void Graph::tryToRemoveColor(int color) {
  if (color == 0) {
    return;
  }
  int c = color;
  vector <int> nodesWithColor;
  cout << "Searching Color: " << c << endl;
  for(int i = 0; i < this->coloredGraph.size(); i++) {
    if (this->coloredGraph[i] == c) {
      nodesWithColor.push_back(i);
      //cout << "Node inside: " << i << endl;
    }
  }

  bool cantAssign = false;
  for (int j = 0; j<nodesWithColor.size(); j++) {
    int pontualColor = c-1;
    while (pontualColor >= 1) {
      // //if (canAssignColor(this->coloredGraph[nodesWithColor[j]], pontualColor)) {
      //   this->coloredGraph[nodesWithColor[j]] = pontualColor;
      //   break;
      // } else {
      //   //cantAssign = true;
      //   pontualColor--;
      //   //break;
      // }
    }
    if (pontualColor == 0) {
      cantAssign = true;
    }
  }
  if (cantAssign == false){
    this->color--;
    tryToRemoveColor(--c);
  } else {
    tryToRemoveColor(--c);
  }
}

void Graph::RemoveColor() {
  int c = this->color;

  while (c >= 1) {
    vector <int> nodesWithColor;
    cout << "Searching Color: " << c << endl;
    for(int i = 0; i < this->coloredGraph.size(); i++) {
      if (this->coloredGraph[i] == c) {
        nodesWithColor.push_back(i);
        //cout << "Node inside: " << i << endl;
      }
    }

    int colorToReplace = c - 1;
    bool cantAssign = false;
    for (int j = 0; j<nodesWithColor.size(); j++) {
      // if (canAssignColor(this->coloredGraph[nodesWithColor[j]], colorToReplace)) {
      //   break;
      // } else {
      //   cantAssign = true;
      // }
    }

    if (cantAssign == false){
      cout << "Cor removida: " << c << endl;
      this->color--;
      for (int j = 0; j<nodesWithColor.size(); j++) {
        // if (canAssignColor(this->coloredGraph[nodesWithColor[j]], colorToReplace)) {
        //   this->coloredGraph[nodesWithColor[j]] = colorToReplace;
        // } else {
        //   return;
        // }
      }
      c--;
    } else {
      c--;
    }

  }
}

void Graph::runAlgorithm() {
  solution s1;
  s1.colorGraph = createColorgraph();
  colourGraph(&s1.colorGraph, 0, &s1.numberOfColorsUsed);

  for (int i = 0; i < s1.colorGraph.size(); i++) {
    cout << "Node inside: " << i << "Color: " << s1.colorGraph[i] << endl;
  }

  cout << "Best Solution: " << s1.numberOfColorsUsed << endl;
  //tryToRemoveColor(this->color);
  //RemoveColor();
  vector <int> sortedVector = sortVector();
  // for (int i = 0; i < sortedVector.size(); i++) {
  //   cout << "Node inside: " << sortedVector[i] << " size: " << (*nextNode)[sortedVector[i]].size() << endl;
  // }
  //getIndependentVertices(this->coloredGraph);
  //this->bestSolution = this->color;
  //clearColorsSolution();
  //int valueForInteraction = (this->nodes.size()) * 0.15;
  //VND(valueForInteraction);
}

void Graph::VND(int timesVNDRuns) {
    int counter = 0;
    while (counter < timesVNDRuns) {
        int pontualBestSolution = 99999999;
        vector <int> pontualBestSolutionColors;
        int bestIndependentPosition = 0;
        for (int i = 0; i < this->independentVertices.size(); i++) {
            cout << "Starting search on independent vertice: " << this->independentVertices[i] << endl;
            colourGraph(&coloredGraph, this->independentVertices[i], &color);
            cout << "Best Solution in this case: " << this->color << endl;
            if (this->color < pontualBestSolution) {
                bestIndependentPosition = this->independentVertices[i];
                pontualBestSolution = this->color;
                if (!pontualBestSolutionColors.empty()) {
                    pontualBestSolutionColors.clear();
                }
                for (int i = 0; i < this->coloredGraph.size(); i++) {
                    pontualBestSolutionColors.push_back(this->coloredGraph[i]);
                }
            }
            clearColorsSolution();
        }
        if (pontualBestSolution < this->bestSolution) {
            this->bestSolution = pontualBestSolution;
            copySolutionToVector(&bestSolutionColors, pontualBestSolutionColors);
        }
        this->nodes.erase(this->nodes.begin() + (bestIndependentPosition));
        (*nextNode)[bestIndependentPosition].erase((*nextNode)[bestIndependentPosition].begin(), (*nextNode)[bestIndependentPosition].end());
        getIndependentVertices(pontualBestSolutionColors);
        counter++;
    }

}
