# EX1 - Graphs

This project initiates a graph (using adjacency matrix) and provides a handful of algorithms to use on the graph. the project is written in the C++ language. 

## Algorithms

The algorithms directory contains implementations of some helpful graph algorithms, including:

isConnected(graph) - checks if the graph is connected using a simple dfs function and checking if the dfs got to all the vertices

shortestPath(graph, start, end) - finds the shortest path on the graph from start to end by using simple dijkstra's implementation

isContainsCycle(g) - checks if there are cycle(s) in the graph using dfs and checking for a backedge, or bfs in case of an undirected graph(using a helper function)

negativeCycle(graph) - checks is there a negative cycle by running bellman-ford and checking if there is an edge that further decreases the distance of its destination vertex

isBipartite(graph) - checks if the graph is bipartite by trying to 2-color the graph



## Graph

The graph directory contains classes and utilities for representing and working with graphs. These include:  

loadGraph(vector<vector<int>>) - loads the graph into the given class instance, calculates the number of edges and vertices, and checks if the graph is undirected

printGraph() - prints a simple representation of the graph

getNeighbors(vertex) - returns the neighbors of a given vertex (used by some algorithms from the Algorithms directory)

## Usage
Here's a simple representation of how to use the namespace

```c++
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    g.printGraph();                                    
    cout << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, 2) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); 

    g.printGraph();                                    
    cout << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        


    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); 

    g.printGraph();                                    
    cout << Algorithms::isConnected(g) << endl;        
    cout << Algorithms::shortestPath(g, 0, 4) << endl; 
    cout << Algorithms::isContainsCycle(g) << endl;    
    cout << Algorithms::isBipartite(g) << endl;        

   
    return 0;
}

```