#ifndef GRAPH_H
#define GRAPH_H

class Graph{
    private:
    int numVertices;
    int numEdges;
    int **adjMatrix;
    Vertex *vertices;
    public:
    Graph(int n);
    ~Graph();

    void addEdge(int u, int v, int weight);

    void solveNPrintAll();
};

#endif