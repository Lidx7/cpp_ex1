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

    static void dfs(Graph g, int start, vector<bool> &visited){
        visited[start] = true;
        for(int i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(start, i) != 0 && !visited[i]){
                dfs(g, i, visited);
            }
        }
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

    static string shortestPath(Graph g, int start, int end){
        /*TODO: build this function*/
    }

    static bool isContainsCycle(Graph g){
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

    static string isBipartite(Graph g){
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
                    else if(g.getGraphValue(curr, i) && color[i] == color[curr]){ /*TODO: check if the getGraphValuecall is actually needed*/
                        return "The graph is not bipartite";
                    }
                }
            }
        }

        return "The graph is bipartite";
    }

    static string negativeCycle(Graph g){

    }
    
    bool hasLoopbacks(Graph g){
        for(int i=0; i < g.getVerticesCount(); i++){
            if(g.getGraphValue(i, i) != 0){
                return true;
            }
        }

        return false;
    }

}