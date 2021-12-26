#if !defined(GRAPH_H)
#define GRAPH_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <vector>

/* Graph representations */

class AdjacencyListGraph {
   public:
    struct Adj {
        int dst, weight;
        Adj(int dst, int weight) : dst(dst), weight(weight) {}
    };

    std::vector<std::list<Adj>> adjListVec;

    AdjacencyListGraph(int n) : adjListVec(std::vector<std::list<Adj>>(n)) {}

    void addEdge(int src, int dst, int weight = 1) {
        this->adjListVec[src].emplace_back(Adj(dst, weight));
    }

    void removeEdge(int src, int dst) {
        auto &adjList = this->adjListVec[src];
        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            if (it->dst == dst) {
                adjList.erase(it);
                break;
            }
        }
    }
};

class AdjacencyMatrixGraph {
   public:
    std::vector<std::vector<int>> adjMatrix;

    AdjacencyMatrixGraph(int n) : adjMatrix(n, std::vector<int>(n, INT32_MAX)) {
        for (int i = 0; i < n; i++) {
            adjMatrix[i][i] = 0;
        }
    }

    void addEdge(int src, int dst, int weight = 1) {
        this->adjMatrix[src][dst] = weight;
    }
};

/* IO utils */

int getVertex(char label) {
    return label - 'A';
}
char getLabel(int vertex) {
    return vertex + 'A';
}

AdjacencyListGraph constructAdjListGraph(int V, int E, int edges[][3], bool undirected = true) {
    AdjacencyListGraph g(V);
    for (int i = 0; i < E; i++) {
        int src = getVertex(edges[i][0]);
        int dst = getVertex(edges[i][1]);
        int weight = edges[i][2];
        g.addEdge(src, dst, weight);
        // Add both edge for undirected
        if (undirected) {
            g.addEdge(dst, src, weight);
        }
    }
    return g;
}

AdjacencyMatrixGraph constructAdjMatrixGraph(int V, int E, int edges[][3], bool undirected = true) {
    AdjacencyMatrixGraph g(V);
    for (int i = 0; i < E; i++) {
        int src = getVertex(edges[i][0]);
        int dst = getVertex(edges[i][1]);
        int weight = edges[i][2];
        g.addEdge(src, dst, weight);
        // Add both edge for undirected
        if (undirected) {
            g.addEdge(dst, src, weight);
        }
    }
    return g;
}

void printVertices(std::queue<int> q, std::string sep = " ") {
    if (q.empty()) {
        std::cout << "\n";
        return;
    }

    std::cout << getLabel(q.front());
    q.pop();
    while (!q.empty()) {
        std::cout << sep << getLabel(q.front());
        q.pop();
    }
    std::cout << "\n";
}

template <class T>
void printVertices(T q, std::string sep = " ") {
    if (q.empty()) {
        std::cout << "\n";
        return;
    }

    auto it = q.begin();
    std::cout << getLabel(*it++);
    while (it != q.end()) {
        std::cout << sep << getLabel(*it++);
    }
    std::cout << "\n";
}

#endif  // GRAPH_H
