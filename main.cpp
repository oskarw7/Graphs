#include <stdio.h>

#include "Graph.h"

int main() {
    int graphCount, graphSize, listSize, vertex;

    scanf("%d", &graphCount);
    for(int i=0; i<graphCount; i++){
        scanf("%d", &graphSize);
        Graph currentGraph(graphSize);
        for(int j=0; j<graphSize; j++){
            scanf("%d", &listSize);
            currentGraph.setDegree(j, listSize);
            for(int k=0; k<listSize; k++){
                scanf("%d", &vertex);
                currentGraph.addEdge(j, vertex);
            }
        }
        currentGraph.printProperties();
    }

    return 0;
}
