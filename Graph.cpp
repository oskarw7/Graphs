#include "Graph.h"

Graph::Graph(int size){
    this->size = size;
    this->adjacencyList = new MyVector[size];
    this->degrees = new int[size];
}

void Graph::addEdge(int source, int destination){
    this->adjacencyList[source].addElement(destination);
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
    coloring(GREEDY);
    coloring(LF);
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
        printf("%d ", copy[i]);
    printf("\n");

    delete[] copy;
}

void Graph::dfs(int vertex, int* isVisited){
    MyStack stack;
    stack.push(vertex);
    while(!stack.isEmpty()){
        int currentVertex = stack.pop();
        if(!isVisited[currentVertex-1]){
            isVisited[currentVertex-1] = 1;
            for(int i=0; i<this->adjacencyList[currentVertex-1].getSize(); i++){
                int adjacentVertex = this->adjacencyList[currentVertex-1].getElement(i);
                if(!isVisited[adjacentVertex-1])
                    stack.push(adjacentVertex);
            }
        }
    }
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
    MyStack stack;
    stack.push(vertex);
    flags[vertex-1] = LEFT;
    while(!stack.isEmpty()){
        int currentVertex = stack.pop();
        if(!isVisited[currentVertex-1]) {
            isVisited[currentVertex-1] = 1;
            for (int i=0; i<this->adjacencyList[currentVertex-1].getSize(); i++) {
                int adjacentVertex = this->adjacencyList[currentVertex-1].getElement(i);
                if (flags[adjacentVertex-1] == UNSORTED && !isVisited[adjacentVertex-1]) {
                    flags[adjacentVertex-1] = (flags[currentVertex-1] == LEFT) ? RIGHT : LEFT;
                    stack.push(adjacentVertex);
                }
                else if (flags[adjacentVertex-1] == flags[currentVertex-1])
                    return 0;
            }
        }
    }
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

void Graph::coloring(int type) {
    int* order = new int[this->size];
    for(int i=0; i<this->size; i++)
        order[i] = i;
    if(type == LF)
        twoArraysMergeSort(this->degrees, order, 0, this->size-1);

    int* isColorAvailable = new int[this->size];
    int* colors = new int[this->size];
    for(int i=0; i<this->size; i++){
        isColorAvailable[i] = 1;
        colors[i] = UNCOLORED;
    }
    colors[order[0]] = 1;
    for(int i=1; i<this->size; i++){
        int currentIndex = order[i];
        for(int j=0; j<this->adjacencyList[currentIndex].getSize(); j++){
            int adjacentVertex = this->adjacencyList[currentIndex].getElement(j);
            if(colors[adjacentVertex-1] != UNCOLORED)
                isColorAvailable[colors[adjacentVertex-1]] = 0;
        }
        for(int j=1; j<this->size; j++){
            if(isColorAvailable[j]){
                colors[currentIndex] = j;
                break;
            }
        }
        for(int j=0; j<this->adjacencyList[currentIndex].getSize(); j++){
            int adjacentVertex = this->adjacencyList[currentIndex].getElement(j);
            if(colors[adjacentVertex-1] != UNCOLORED)
                isColorAvailable[colors[adjacentVertex-1]] = 1;
        }
    }
    for(int i=0; i<this->size; i++)
        printf("%d ", colors[i]);
    printf("\n");

    delete[] colors;
    delete[] isColorAvailable;
    delete[] order;
}


/*
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
            int currentDepth = depthStack->pop();
            if(currentVertex==i+1 && currentDepth==maxDepth)
                count++;
            else if(currentDepth<maxDepth){
                for(int j=0; j<this->degrees[currentVertex-1]; j++){
                    int adjacentVertex = this->adjacencyList[currentVertex-1].getElement(j);
                    if(adjacentVertex!=parentVertex){
                        stack->addNode(adjacentVertex);
                        stack->getTopElement()->setPrevious(currentVertex);
                        depthStack->push(currentDepth+1);
                    }
                }
            }
        }
    }
    delete depthStack;
    delete stack;

    return count/8;
}
*/

int Graph::complementEdges() const{
    int completeEdges = (this->size)*(this->size-1)/2;
    int currentEdges = 0;
    for(int i=0; i<this->size; i++)
        currentEdges += this->degrees[i];
    currentEdges /= 2;

    return completeEdges-currentEdges;
}