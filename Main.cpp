#include <iostream>
#include "Edge.h"
#include "Graph.h"

using namespace std;

int main(){
    int numOfVertices;
    int numOfEdges;

    if (!(cin >> numOfVertices >> numOfEdges)){
        cout << "Input not found!" << endl;
        return 0;
    }

    Graph graph(numOfVertices);

    for (int i = 0; i < numOfEdges; i++){
        int startVertice;
        int endVertice;
        int weight;

        cin >> startVertice >> endVertice >> weight;

        graph.addEdge(startVertice, endVertice, weight);
    }

    graph.solveNPrintAll();

    return 0;
}