#include "graph.hpp"

void Graph::createGraph(int node) {
    this->nodes.push_back(node);
    this->coloredGraph.push_back(0);
}

void Graph::createMatrix() {
    this->nextNode = new vector<vector<int>>(this->nodes.size(), vector<int>());
}

void Graph::createEdge(int node, int next) {
    (*nextNode)[node].push_back(next);
    (*nextNode)[next].push_back(node);
}

void Graph::printGraph() {
    for (int i = 0; i < (*nextNode).size(); i++) {
        for (int j = 0; j < (*nextNode)[i].size(); j++) {
            cout << "Node inside: " << (*nextNode)[i][j] << endl;
        }
    }
}

void Graph::calculateNumGraph() {
  int count = 0;
  for (int i = 0; i < (*nextNode).size(); i++) {
      count += (*nextNode)[i].size();
  }
  cout << count << endl;
}

void Graph::colourGraph(int node) {
    int c = 1;
    while(c <= this->color) {
        if (coloredGraph[node] != 0) {
            return;
        }
        if (canAssignColor(node, c)) {
            this->coloredGraph[node] = c;
            int nextNode = node + 1;
            if (nextNode < this->nodes.size()) {
                colourGraph(nextNode);
            } else {
                colourGraph(0);
            }
        } else {
            c++;
            if (c > this->color) {
                this->color++;
            }
        }
    }
}

bool Graph::canAssignColor(int node, int color) {
    for (int i = 0; i < (*nextNode)[node].size(); i++) {
        if (color == coloredGraph[(*nextNode)[node][i]]) {
            return false;
        }
    }
    return true;
}

void Graph::getIndependentVertices() {
  for (int i = 0; i < this->coloredGraph.size(); i++) {
     if (this->coloredGraph[i] == 1) {
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

void Graph::runAlgorithm() {
  colourGraph(0);
  getIndependentVertices();
  clearColorsSolution();

  for (int i = 1; i < this->independentVertices.size(); i++) {
    cout << "Starting search on independent vertice: " << this->independentVertices[i] << endl;
    colourGraph(this->independentVertices[i]);
    cout << "Best Solution in this case: " << this->color << endl;
    this->solutions.push_back(color);
    clearColorsSolution();
  }
  getBestSolution();
}
