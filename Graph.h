#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "MyList.h"

class Graph {
public:
    Graph(int size);

    void addEdge(int source, int destination);

    void setDegree(int vertex, int degree);

    void printProperties();

    void printGraph();

    ~Graph();

private:
    void sortDegrees(int* copy);
    void degreeSequence();
    void dfs(int vertex, int* isVisited);
    int countComponents();

    MyList* adjacencyList;
    int* degrees;
    int size;
};


#endif
