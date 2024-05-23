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
    if(degree > 1)
        this->adjacencyList[vertex].initCapacity(degree);
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
    printf("%lld\n", complementEdges());
}

Graph::~Graph(){
    delete[] this->degrees;
    delete[] this->adjacencyList;
}

void Graph::degreeSequence(){
    int* copy = new int[this->size];
    for(int i=0; i<this->size; i++)
        copy[i] = this->degrees[i];
    mergeSort(nullptr, copy, 0, this->size - 1);
    for(int i=0; i<this->size; i++)
        printf("%d ", copy[i]);
    printf("\n");

    delete[] copy;
}

void Graph::dfs(int vertex, bool* isVisited){
    MyStack stack;
    stack.push(vertex);
    while(!stack.isEmpty()){
        int currentVertex = stack.pop();
        if(!isVisited[currentVertex-1]){
            isVisited[currentVertex-1] = true;
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
    bool* isVisited = new bool[this->size];
    for(int i=0; i<this->size; i++)
        isVisited[i] = false;
    for(int i=0; i<this->size; i++){
        if(!isVisited[i]){
            dfs(i+1, isVisited);
            count++;
        }
    }
    delete[] isVisited;

    return count;
}

int Graph::isComponentBipartite(int vertex, bool *isVisited, short int *flags) {
    MyStack stack;
    stack.push(vertex);
    flags[vertex-1] = LEFT;
    while(!stack.isEmpty()){
        int currentVertex = stack.pop();
        if(!isVisited[currentVertex-1]) {
            isVisited[currentVertex-1] = true;
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
    bool* isVisited = new bool[this->size];
    short int* flags = new short int[this->size];
    for(int i=0; i<this->size; i++){
        isVisited[i] = false;
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

void Graph::coloring(short int type) {
    int* order = new int[this->size];
    for(int i=0; i<this->size; i++)
        order[i] = i;
    if(type == LF)
        mergeSort(this->degrees, order, 0, this->size - 1);

    bool* isColorAvailable = new bool[this->size];
    int* colors = new int[this->size];
    for(int i=0; i<this->size; i++){
        isColorAvailable[i] = true;
        colors[i] = UNCOLORED;
    }
    colors[order[0]] = 1;
    for(int i=1; i<this->size; i++){
        int currentIndex = order[i];
        for(int j=0; j<this->adjacencyList[currentIndex].getSize(); j++){
            int adjacentVertex = this->adjacencyList[currentIndex].getElement(j);
            if(colors[adjacentVertex-1] != UNCOLORED)
                isColorAvailable[colors[adjacentVertex-1]] = false;
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
                isColorAvailable[colors[adjacentVertex-1]] = true;
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

long long Graph::complementEdges() const{
    long long s = this->size;
    long long completeEdges = (s)*(s-1)/2;
    long long currentEdges = 0;
    for(int i=0; i<this->size; i++)
        currentEdges += (long long)this->degrees[i];
    currentEdges /= 2;

    return completeEdges-currentEdges;
}