#include "Graph.h"

Graph::Graph(int size){
    this->size = size;
    this->adjacencyList = new MyList[size];
}

void Graph::addEdge(int source, int destination){
    this->adjacencyList[source].addNode(destination);
}

void Graph::printGraph(){
    std::cout << this->size << std::endl;
    for(int i = 0; i < this->size; i++)
        this->adjacencyList[i].printList();
}

Graph::~Graph(){
    delete[] this->adjacencyList;
}