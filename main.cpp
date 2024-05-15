#include <iostream>

#include "Graph.h"

int main() {
    Graph* currentGraph;
    int graphCount, graphSize, listSize, vertex;

    std::cin >> graphCount;
    for(int i=0; i<graphCount; i++){
        std::cin >> graphSize;
        currentGraph = new Graph(graphSize);
        for(int j=0; j<graphSize; j++){
            std::cin >> listSize;
            currentGraph->setDegree(j, listSize);
            for(int k=0; k<listSize; k++){
                std::cin >> vertex;
                currentGraph->addEdge(j, vertex);
            }
        }
        currentGraph->printProperties();
        delete currentGraph;
    }

    return 0;
}
