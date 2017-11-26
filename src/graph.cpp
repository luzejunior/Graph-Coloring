#include "graph.hpp"

void Graph::createGraph(int node) {
    this->nodes.push_back(node);
    this->solution.push_back(0);
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
        if (solution[solution.size()-1] != 0) {
            return;
        }
        if (canAssignColor(node, c)) {
            this->solution[node] = c;
            int nextNode = node + 1;
            if (nextNode < this->nodes.size()) {
                colourGraph(nextNode);
            } else {
                return;
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
        if (color == solution[(*nextNode)[node][i]]) {
            return false;
        }
    }
    return true;
}
