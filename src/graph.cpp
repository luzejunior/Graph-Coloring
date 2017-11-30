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



vector <int> Graph::sortVector() {
  vector <int> nodeIndices;
  vector <int> nextNodeCopy;

  for (int i = 0; i < (*nextNode).size(); i++) {
    nextNodeCopy.push_back((*nextNode)[i].size());
  }

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

void Graph::tryToRemoveColor(Solution *s, int color) {
  if (color == 0) {
    return;
  }

  int c = color;
  vector <int> nodesWithColor;
  //cout << "Searching Color: " << c << endl;
  for (int i = 0; i < s->colorGraph.size(); i++) {
    if (s->colorGraph[i] == c) {
      nodesWithColor.push_back(i);
    }
  }

  bool cantAssign = false;
  for (int j = 0; j<nodesWithColor.size(); j++) {
    int pontualColor = c-1;
    while (pontualColor >= 1) {
      if (canAssignColor(&s->colorGraph,s->colorGraph[nodesWithColor[j]], pontualColor)) {
        s->colorGraph[nodesWithColor[j]] = pontualColor;
        break;
      } else {
        pontualColor--;
      }
    }
    if (pontualColor == 0) {
      cantAssign = true;
    }
  }

  if (cantAssign == false) {
    s->numberOfColorsUsed--;
    tryToRemoveColor(s, --c);
  } else {
    tryToRemoveColor(s, --c);
  }
}

void Graph::RemoveColor(Solution *s) {
  int c = s->numberOfColorsUsed;

  while (c >= 1) {
    vector <int> nodesWithColor;
    //cout << "Searching Color: " << c << endl;
    for (int i = 0; i < s->colorGraph.size(); i++) {
      if (s->colorGraph[i] == c) {
        nodesWithColor.push_back(i);
        //cout << "Node inside: " << i << endl;
      }
    }

    int colorToReplace = c - 1;
    bool cantAssign = false;
    for (int j = 0; j<nodesWithColor.size(); j++) {
      if (canAssignColor(&s->colorGraph, s->colorGraph[nodesWithColor[j]], colorToReplace)) {
        s->colorGraph[nodesWithColor[j]] = colorToReplace;
      } else {
        cantAssign = true;
        for (int j = 0; j<nodesWithColor.size(); j++) {
          s->colorGraph[nodesWithColor[j]] = c;
        }
        break;
      }
    }

    if (cantAssign == false) {
      cout << "Cor removida: " << c << endl;
      s->numberOfColorsUsed--;

      c--;
    } else {
      c--;
    }

  }
}

void Graph::selectSolution(Solution *s, double alpha) {
  int randomIndex;
  vector <int> sortedVector = sortVector();
  int value = sortedVector.size() * 0.15;
  sortedVector.erase((sortedVector.begin() + value), sortedVector.end());
  vector <int> LCR;

  int tamLCR = alpha*(sortedVector.size());
  for (int i = 0; i <= tamLCR; i++) {
    LCR.push_back(sortedVector[i]);
  }

  randomIndex = rand() % LCR.size();

  cout << "Starting with node: " << LCR[randomIndex] << endl;
  (*s).index = LCR[randomIndex];
  colourGraph(&s->colorGraph, LCR[randomIndex], &s->numberOfColorsUsed);
}

void Graph::GRASP(Solution *s, int GRASPmax, double alpha) {
  int pontualBestSolution = 999999;
  int interactions = GRASPmax;

  while (interactions > 0) {
    Solution graspSolution;
    graspSolution.colorGraph = createColorgraph();
    selectSolution(&graspSolution, alpha);
    //cout << "Solution after Remove: " << graspSolution.numberOfColorsUsed << endl;
    RemoveColor(&graspSolution);
    if (graspSolution.numberOfColorsUsed < pontualBestSolution) {
      *s = graspSolution;
      pontualBestSolution = graspSolution.numberOfColorsUsed;
    }
    interactions--;
  }
}

void Graph::runAlgorithm() {
  Solution s1, s2, s3;
  s1.colorGraph = createColorgraph();
  srand(time(NULL));
  GRASP(&s1, 1000, 0.8);

  //colourGraph(&s1.colorGraph, 37, &s1.numberOfColorsUsed);
  //RemoveColor(&s1);
  //tryToRemoveColor(&s1, s1.numberOfColorsUsed);
  // for (int i = 0; i < s1.colorGraph.size(); i++) {
  //   cout << "Node inside: " << i << "Color: " << s1.colorGraph[i] << endl;
  // }

  cout << "Best Solution: " << s1.numberOfColorsUsed << endl;
  //cout << "Best Solution Index: " << s1.index << endl;
}
