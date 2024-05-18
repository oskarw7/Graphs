#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

#include "MyVector.h"
#include "MyStack.h"
#include "Utils.h"
//#include "MyList.h"

#define LEFT 0
#define RIGHT 1
#define UNSORTED -1
#define UNCOLORED 0
#define GREEDY 0
#define LF 1

class Graph {
public:
    explicit Graph(int size);

    void addEdge(int source, int destination);

    void setDegree(int vertex, int degree);

    void printProperties();

    ~Graph();

private:
    void degreeSequence();
    void dfs(int vertex, int* isVisited);
    int countComponents();
    int isComponentBipartite(int vertex, int* isVisited, int* flags);
    int isBipartite();
    void coloring(int type);
    //int countC4();
    int complementEdges() const;

    MyVector* adjacencyList;
    int* degrees;
    int size;
};


#endif