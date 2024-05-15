#include "Graph.h"

Graph::Graph(int size){
    this->size = size;
    this->adjacencyList = new MyList[size];
    this->degrees = new int[size];
}

void Graph::addEdge(int source, int destination){
    this->adjacencyList[source].addNode(destination);
}

void Graph::setDegree(int vertex, int degree){
    this->degrees[vertex] = degree;
}

void Graph::printProperties() {
    degreeSequence();
    std::cout << countComponents() << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
    std::cout << "?" << std::endl;
}

void Graph::printGraph(){
    std::cout << this->size << std::endl;
    for(int i = 0; i < this->size; i++)
        this->adjacencyList[i].printList();
}

Graph::~Graph(){
    delete[] this->degrees;
    delete[] this->adjacencyList;
}

void Graph::sortDegrees(int* copy){
    for(int i=0; i<this->size; i++){
        for(int j=i+1; j<this->size; j++){
            if(copy[i] < copy[j]){
                int temp = copy[i];
                copy[i] = copy[j];
                copy[j] = temp;
            }
        }
    }
}

void Graph::degreeSequence(){
    int* copy = new int[this->size];
    for(int i=0; i<this->size; i++)
        copy[i] = this->degrees[i];
    sortDegrees(copy);
    for(int i=0; i<this->size; i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    delete[] copy;
}

void Graph::dfs(int vertex, int* isVisited){
    MyList* stack = new MyList();
    stack->addNode(vertex);
    while(stack->getTopElement() != nullptr){
        int currentVertex = stack->deleteNode();
        if(!isVisited[currentVertex-1]){
            isVisited[currentVertex-1] = 1;
            for(int i=0; i<this->degrees[currentVertex-1]; i++){
                int adjacentVertex = this->adjacencyList[currentVertex-1].getNodeValue(i);
                if(!isVisited[adjacentVertex-1])
                    stack->addNode(adjacentVertex);
            }
        }
    }

    delete stack;
}

int Graph::countComponents(){
    int count = 0;
    int* isVisited = new int[this->size];
    for(int i=0; i<this->size; i++)
        isVisited[i] = 0;
    for(int i=0; i<this->size; i++){
        if(!isVisited[i]){
            dfs(i+1, isVisited);
            count++;
        }
    }

    delete[] isVisited;

    return count;
}