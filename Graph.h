#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

#include "MyVector.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "Utils.h"

// left, right and unsorted are used for coloring
// uncolored is used for coloring
// greedy and lf are flags used for coloring
#define LEFT 0
#define RIGHT 1
#define UNSORTED -1
#define UNSINGED -1
#define UNCOLORED 0
#define GREEDY 0
#define LF 1

class Graph {
public:
    explicit Graph(int size);

    // add edge between source and destination vertices
    void addEdge(int source, int destination);

    // set degree of vertex, initalize capacity of its adjacency list
    void setDegree(int vertex, int degree);

    // print properties of the graph
    void printProperties();

    ~Graph();

private:
    // sort degrees of vertices, print them
    void degreeSequence();

    // depth first search and matching component sizes of vertices
    void dfs(int vertex, bool* isVisited);
    // count components, run dfs for each unvisited vertex
    int countComponents();

    // check if component is bipartite
    bool isComponentBipartite(int vertex, bool* isVisited, short int* flags);
    // check if graph is bipartite by running isComponentBipartite for each component
    bool isBipartite();

    // breadth first search, return eccentricity of vertex
    int bfs(int vertex, int componentSize, int* distances);
    // eccentricity of each vertex
    void eccentricity();

    // coloring of vertices: greedy or largest-first (LF)
    void coloring(short int type);

    // count edges in complement graph
    long long complementEdges() const;

    MyVector* adjacencyList;    // adjacency list of vertices
    int* degrees;               // degree of each vertex
    int* componentsSize;        // size of components for each vertex
    int size;                   // number of vertices
};


#endif