#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

class Graph{
    private:
    int numVertices;
    int numEdges;
    int **adjMatrix;
    Vertex *vertices;
    
    void runDijkstra(int source, int *distances);

    public:
    Graph(int n);
    ~Graph();

    void addEdge(int u, int v, int weight);

    void solveNPrintAll();
};

#endif