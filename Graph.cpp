#include "Graph.h"
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX /4;

Graph::Graph(int n){
    numVertices = n;
    numEdges =0;

    vertices = new Vertex[n + 1];

    for (int i = 0; i <= n; i++){
        vertices[i].setIndex(i);
        vertices[i].setDegree(0);

    }

    adjMatrix = new int*[n + 1];
    for (int i = 0; i <= n; i++){
        adjMatrix[i] = new int[n + 1];
        for (int j = 0; j <= n; j++){
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph(){
    for (int i = 0; i <= numVertices; i++){
        delete [] adjMatrix[i];
    }
    delete [] adjMatrix;

    delete [] vertices;
}

void Graph::addEdge(int u, int v, int weight){
    if (u < 1 || u > numVertices || v < 1 || v > numVertices){
        return;
    }

    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;

    numEdges++;

    int degreeU = vertices[u].getDegree();
    vertices[u].setDegree(degreeU + 1);

    int degreeV = vertices[v].getDegree();
    vertices[v].setDegree(degreeV + 1);
}

void Graph::runDijkstra(int source, int *distances){
    int *visited = new int[numVertices +1];

    for (int i = 1; i <= numVertices; i++){
        distances[i] = INF;
        visited[i] = 0;
    }

    distances[source] = 0;

    for (int count = 1; count <= numVertices; count++){
        int u =-1;
        int bestDist = INF;

        for (int i = 1; i <= numVertices; i++){
            if (visited[i] == 0 && distances[i] < bestDist){
                bestDist = distances[i];
                u = i;
            }
        }
        if (u == -1){
            break;
        }

        visited[u] = 1;

        for (int v = 1; v <= numVertices; v++){
            int w = adjMatrix[u][v];

            if (w > 0 && visited[v] == 0){
                if (distances[u] + w < distances[v]){
                    distances[v] = distances[u] + w;
                }
            }
        }
    }
    delete [] visited;
}

void Graph::solveNPrintAll(){
    cout << "The adjacency matrix of G is:" << endl;
    for (int i = 1; i <= numVertices; i++){
        for (int j = 1; j <= numVertices; j++){
            cout << adjMatrix[i][j];
            if (j < numVertices){
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int *oddNodes = new int[numVertices];
    int oddCount = 0;

    for (int i = 1; i <= numVertices; i++){
        int deg = vertices[i].getDegree();
        if (deg % 2 ==1){
            oddNodes[oddCount] = i;
            oddCount++;
        }
    }

    cout << "The nodes with odd degrees in G are:" << endl;
    cout << "O = { ";
    for (int i = 0; i < oddCount; i++){
        if (i > 0){
            cout << " ";
        }
        cout << oddNodes[i];
    }
    cout << " }" << endl;
    cout << endl;

    int *distances = new int[numVertices + 1];

    for (int i = 0; i < oddCount; i++){
        int source = oddNodes[i];

        runDijkstra(source, distances);

        cout << "The shortest path lengths from Node " << source 
        << " to all other nodes are:" << endl;
        cout << endl;

        for (int v = 1; v <= numVertices; v++){
            cout << v << ": ";
            if (distances[v] == INF){
                cout << "INF" << endl;
            } else {
                cout << distances[v] << endl;
            }
        }

        cout << endl;
    }

    delete [] distances;
    delete [] oddNodes;
}