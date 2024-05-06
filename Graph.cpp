#include "Graph.hpp"
#include <iostream>
 using namespace std;

namespace ariel{

    Graph::Graph() : edges_count(0), vertices_count(0){
        curr_graph = std::vector<std::vector<int>>();
    }


    void Graph::loadGraph(std::vector<std::vector<int>> givenGraph){
        if(givenGraph.size() == 0){
            throw invalid_argument("The graph is empty");
        }
        if(givenGraph.size() != givenGraph[0].size()){
            throw invalid_argument("The graph is not a square matrix");
        }

        curr_graph = givenGraph;
        vertices_count = givenGraph.size();
        edges_count = 0;
        for(int i=0; i < vertices_count; i++){
            for(int j=0; j < vertices_count; j++){
                if(curr_graph[i][j] != 0){
                    edges_count++;
                }
            }
        }

    }

    void Graph::printGraph(){
        int i=0, j=0;
        for(i=0; i < vertices_count-1; i++){
            cout << "{";
            for(j=0; j < vertices_count-1; j++){
                cout << curr_graph[i][j] << ", ";
            }
            cout << curr_graph[i][j+1];
            cout << "}," << endl;
        }
        cout << "}" << endl;
    }

    int Graph::getEdgesCount(){
        return edges_count;
    }

    int Graph::getVerticesCount(){
        return vertices_count;
    }

    int Graph::getGraphValue(int i, int j){
        return curr_graph[i][j];
    }
}
