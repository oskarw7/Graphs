#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "MyList.h"
#include "Utils.h"

#define LEFT 0
#define RIGHT 1
#define UNSORTED -1

class Graph {
public:
    explicit Graph(int size);

    void addEdge(int source, int destination);

    void setDegree(int vertex, int degree);

    void printProperties();

    void printGraph();

    ~Graph();

private:
    void degreeSequence();
    void dfs(int vertex, int* isVisited);
    int countComponents();
    int isComponentBipartite(int vertex, int* isVisited, int* flags);
    int isBipartite();

    int countC4();
    int complementEdges();

    MyList* adjacencyList;
    int* degrees;
    int size;
};


#endif
