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

void Graph::runAlgorithm() {
    colourGraph(0);
    getIndependentVertices(this->coloredGraph);
    this->bestSolution = this->color;
    clearColorsSolution();
    int valueForInteraction = (this->nodes.size()) * 0.15;
    VND(valueForInteraction);
}

void Graph::VND(int timesVNDRuns) {
    int counter = 0;
    while (counter < timesVNDRuns) {
        int pontualBestSolution = 99999999;
        vector <int> pontualBestSolutionColors;
        int bestIndependentPosition = 0;
        for (int i = 0; i < this->independentVertices.size(); i++) {
            cout << "Starting search on independent vertice: " << this->independentVertices[i] << endl;
            colourGraph(this->independentVertices[i]);
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
        this->nodes.erase(this->nodes.begin()+(bestIndependentPosition));
        getIndependentVertices(pontualBestSolutionColors);
        counter++;
    }

}
