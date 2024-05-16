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
    printf("%d\n", countComponents());
    (isBipartite()) ? printf("T\n") : printf("F\n");
    printf("?\n");
    printf("?\n");
    printf("?\n");
    printf("?\n");
    printf("?\n");
    printf("?\n");
    printf("%d\n", complementEdges());
}

Graph::~Graph(){
    delete[] this->degrees;
    delete[] this->adjacencyList;
}

void Graph::degreeSequence(){
    int* copy = new int[this->size];
    for(int i=0; i<this->size; i++)
        copy[i] = this->degrees[i];
    mergeSort(copy, 0, this->size-1);
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

int Graph::isComponentBipartite(int vertex, int *isVisited, int *flags) {
    MyList* stack = new MyList();
    stack->addNode(vertex);
    flags[vertex-1] = LEFT;
    while(stack->getTopElement() != nullptr){
        int currentVertex = stack->deleteNode();
        if(!isVisited[currentVertex-1]) {
            isVisited[currentVertex-1] = 1;
            for (int i = 0; i < this->degrees[currentVertex-1]; i++) {
                int adjacentVertex = this->adjacencyList[currentVertex-1].getNodeValue(i);
                if (flags[adjacentVertex-1] == UNSORTED && !isVisited[adjacentVertex-1]) {
                    flags[adjacentVertex-1] = (flags[currentVertex-1] == LEFT) ? RIGHT : LEFT;
                    stack->addNode(adjacentVertex);
                }
                else if (flags[adjacentVertex-1] == flags[currentVertex-1]) {
                    delete stack;
                    return 0;
                }
            }
        }
    }

    delete stack;

    return 1;
}

int Graph::isBipartite() {
    int isBipartite = 1;
    int* isVisited = new int[this->size];
    int* flags = new int[this->size];
    for(int i=0; i<this->size; i++){
        isVisited[i] = 0;
        flags[i] = UNSORTED;
    }
    for(int i=0; i<this->size; i++){
        if(!isVisited[i]){
            isBipartite = isComponentBipartite(i+1, isVisited, flags);
            if(!isBipartite)
                break;
        }
    }
    delete[] flags;
    delete[] isVisited;

    return isBipartite;
}

int Graph::countC4() {
    int count = 0;
    const int maxDepth = 4;
    MyList* stack = new MyList();
    MyList* depthStack = new MyList();
    for (int i=0; i<this->size; i++) {
        stack->addNode(i+1);
        depthStack->addNode(0);
        while (stack->getTopElement() != nullptr) {
            int parentVertex = stack->getTopElement()->getPrevious();
            int currentVertex = stack->deleteNode();
            int currentDepth = depthStack->deleteNode();
            if(currentVertex==i+1 && currentDepth==maxDepth)
                count++;
            else if(currentDepth<maxDepth){
                for(int j=0; j<this->degrees[currentVertex-1]; j++){
                    int adjacentVertex = this->adjacencyList[currentVertex-1].getNodeValue(j);
                    if(adjacentVertex!=parentVertex){
                        stack->addNode(adjacentVertex);
                        stack->getTopElement()->setPrevious(currentVertex);
                        depthStack->addNode(currentDepth+1);
                    }
                }
            }
        }
    }
    delete depthStack;
    delete stack;

    return count/8;
}

int Graph::complementEdges(){
    int completeEdges = (this->size)*(this->size-1)/2;
    int currentEdges = 0;
    for(int i=0; i<this->size; i++)
        currentEdges += this->degrees[i];
    currentEdges /= 2;

    return completeEdges-currentEdges;
}