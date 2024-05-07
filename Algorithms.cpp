#include "Algorithms.hpp"
#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*TODO: ensure that all these functions also work on a weighted graph*/
namespace ariel{

    Algorithms::Algorithms(){
        curr_graph = vector<vector<int>>();
    }

    static bool isConnected(Graph g){
        vector<bool> visited = vector<bool>(g.getVerticesCount(), false);
        dfs(g, 0, visited);
        for(int i=0; i < g.getVerticesCount(); i++){
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }

    //TODO: make this function find the shortest path to "end" and not all vertices
    static string shortestPath(ariel::Graph g, int start, int end){
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX); //initializing the "distances" vector with the closest value we can get to infinity
        vector<bool> included_stp = vector<bool>(g.getVerticesCount(), false);
        distances[start] = 0;

        for(int i=0; i < g.getVerticesCount() - 1; i++){
            int u = minDistance(distances, included_stp);
            included_stp[u] = true;

            for(int j=0; j < g.getVerticesCount(); j++){
                if(g.getGraphValue(u, j) != 0 && !included_stp[j] && distances[u] != INT32_MAX && distances[j] > distances[u] + g.getGraphValue(u, j)){
                    distances[j] = distances[u] + g.getGraphValue(u, j);
                }
            }
        }

        //TODO: fix this to much only the end vertice and not all of them
        for(int i=0; i < g.getVerticesCount(); i++){
        string ans = "Shortest path from " + to_string(start) + " to all other vertices:\n";
            ans += to_string(distances[i]) + " ";
        }
    }

    int minDistance(vector<int> distances, vector<bool> visited){
        int min = INT32_MAX;
        int min_index = -1;

        for(int i=0; i < distances.size(); i++){
            if(!visited[i] && distances[i] <= min){
                min = distances[i];
                min_index = i;
            }
        }

        return min_index;
    }

    static bool isContainsCycle(ariel::Graph g){
        vector<bool> visited = vector<bool>(g.getVerticesCount(), false);
        for(int i=0; i < g.getVerticesCount(); i++){
            if(!visited[i]){
                dfs(g, i, visited); /*TODO: may need to fix the dfs function so it can detect if a 
                                    currently visited vetics is already found (meaning breaking the taget
                                    of this function into smaller target and integrate it into the dfs
                                    function; could possibly need to make the dfs function a boolean type)*/
            }
            else{
                return true;
            }
        }

        return false;
    }

    static string isBipartite(ariel::Graph g){
        if(hasLoopbacks(g)){
            return "The graph is not bipartite";
        }
        vector<int> color = vector<int>(g.getVerticesCount(), -1);
        color[0] = 1;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i=0; i < g.getVerticesCount(); i++){
                if(g.getGraphValue(curr, i) != 0){
                    if(color[i] == -1){
                        color[i] = 1 - color[curr];
                        q.push(i);
                    }       
                    else if(g.getGraphValue(curr, i) && color[i] == color[curr]){ /*TODO: check if the "getGraphValue" call is actually needed*/
                        return "The graph is not bipartite";
                    }
                }
            }
        }

        return "The graph is bipartite";
    }

    static string negativeCycle(ariel::Graph g){
        vector<int> distances = vector<int>(g.getVerticesCount(), INT32_MAX); //initializing the "distances" vector with the closest value we can get to infinity
        bellmanFord(g, 0, distances);

        for(int i=0; i < g.getVerticesCount(); i++){
            for(int j=0; j < g.getVerticesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    return "The graph contains a negative cycle";
                    
                }
            }
        }

        return "The graph does not have a negative cycle";
    }

    /************************
     *   Helper functions   *
     ************************/

    static void dfs(ariel::Graph g, int start, vector<bool> &visited){
        visited[start] = true;
        for(int i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(start, i) != 0 && !visited[i]){
                dfs(g, i, visited);
            }
        }
    }

    //Please note that before calling the function for the first time, the "distances" vector should be initialized with the maximum possible value
    static void bellmanFord(ariel::Graph g, int start, vector<int> &distances){ //TODO: check if "distances" should be a 2D vector
        distances[start] = 0;
        for(int i=0; i < g.getVerticesCount() - 1; i++){
            for(int j=0; j < g.getEdgesCount(); j++){
                if(g.getGraphValue(i, j) != 0 && distances[j] > distances[i] + g.getGraphValue(i, j)){
                    distances[j] = distances[i] + g.getGraphValue(i, j);
                }
            }
        }
    }
    
    bool hasLoopbacks(ariel::Graph g){
        for(int i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(i, i) != 0){
                return true;
            }
        }

        return false;
    }

}