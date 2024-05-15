#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "MyList.h"

class Graph {
public:
    Graph(int size);

    void addEdge(int source, int destination);

    void printGraph();

    ~Graph();

private:
    MyList* adjacencyList;
    int size;
};


#endif
