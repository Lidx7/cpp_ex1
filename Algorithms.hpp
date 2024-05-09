#include "Graph.hpp"

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    class Algorithms{
        private:
            vector<vector<int>> curr_graph;
            static void dfs(Graph g, int start, vector<bool> &visited);
            static void bellmanFord(Graph g, int start, vector<int> &distances);
            static bool hasLoopbacks(Graph g);
            int minDistance(vector<int> distances, vector<bool> visited);
            
        public:
            Algorithms();
            static bool isConnected(Graph g);
            static string shortestPath(Graph g, int start, int end);
            static bool isContainsCycle(Graph g);
            static string isBipartite(Graph g);
            static string negativeCycle(Graph g);
    };
}