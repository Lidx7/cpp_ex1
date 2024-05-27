/*
 * Author: Lidor Borofker.
 * ID: 326065646
 * e-Mail: Lidor.borofker@windowslive.com
 * based on the provided test file
 */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0, 5, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 10, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 11, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 21, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 21}, 
        {0, 0, 0, 0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 5, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 10, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 11, 0, 0, 0, 0}, 
        {0, 8, 0, 0, 21, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 5, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 21}, 
        {0, 0, 0, 0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");

    CHECK(ariel::Algorithms::shortestPath(g, 0, 6) == "0->1->3->4->5->6");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph3 = {
        {0, 5, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 10, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 11, 0, 0, 0, 0}, 
        {0, 8, 0, 0, 21, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 5, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 21}, 
        {0, 0, 0, 0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph6 = {
        {0, 3, 7}, 
        {3, 0, 5}, 
        {7, 5, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 5, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 10, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 11, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 21, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 5, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 21}, 
        {0, 0, 0, 0, 0, 0, 0, 0}}; 
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    g.printGraph();

    vector<vector<int>> graph5 = {
        {0, 3, 7}, 
        {3, 0, 5}, 
        {7, 5, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph6 = {
        {0, 7, 0, 0}, 
        {7, 0, 42, 0}, 
        {0, 42, 0, 11}, 
        {0, 0, 11, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");

    
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not have a negative cycle");
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not have a negative cycle");
    vector<vector<int>> graph3 = {
        {0, 5, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 10, 5, 0, 0, 0, 0}, 
        {0, 0, 0, 11, 0, 0, 0, 0}, 
        {0, 8, 0, 0, 21, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 5, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 21}, 
        {0, 0, 0, 0, 0, 8, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not have a negative cycle");
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not have a negative cycle");
    vector<vector<int>> graph6 = {
        {0, 7, 0, 0}, 
        {7, 0, 42, 0}, 
        {0, 42, 0, -11}, 
        {0, 0, -11, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle");
}
