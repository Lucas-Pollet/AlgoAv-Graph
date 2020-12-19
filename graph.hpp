#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph{

    private:
        unordered_map<int, unordered_set<int>> dict;     
    public:
        void addVertex(int v);
        void addEdge(int u, int v);

        bool containsVertex(int v) const;
        bool containsEdge(int u, int v) const;

        int degree(int v) const;
        int maxDegree() const;
        int countVertices() const;
        int countEdges() const;

        void removeEdge(int u, int v);
        void removeVertex(int v);
        void contract(int u, int v);
        
        vector<int> neighbors(int v) const;
        vector<int> commonNeighbors(int u, int v) const;

        vector<int> dfs(int v) const;
        vector<int> bfs(int v) const;    
};

#endif
