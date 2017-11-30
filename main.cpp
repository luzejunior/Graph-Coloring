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

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/graph.hpp"

using namespace std;

int main() {
    Graph g1;

    int numberOfElements;
    ifstream file("samples/fpsol2.i.1.col");
    //latin_square_10.col - 100 -- 168
    //le450_15a.col - 15 -- 15
    //1-Insertions_4.col - 4 -- 3
    //qg.order30.col - 30 -- 31
    //fpsol2.i.1.col - 65 -- 39

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

    return 0;
}
