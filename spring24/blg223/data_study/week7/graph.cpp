#include <iostream>

struct Node {
    int id;
    Node** adj = NULL;
    int capacity = 0;
    int numAdj = 0;

    void addEdge(Node* node) {
        if(numAdj == capacity) {
            int newCapacity = capacity == 0 ? 2 : capacity * 2;
            Node** newAdj = new Node*[newCapacity];
            for(int i = 0; i < numAdj; i++) {
                newAdj[i] = adj[i];
            }
            delete[] adj;
            adj = newAdj;
            capacity = newCapacity;       
        }
        adj[numAdj++] = node;
    }
};

struct Graph {
    Node** nodes = NULL;
    int capacity = 0;
    int numNodes = 0;

    void addNode(int id) {
        if(numNodes == capacity) {
            int newCapacity = capacity == 0 ? 4 : capacity * 2;
            Node** newNodes = new Node*[newCapacity];
            for(int i = 0; i < numNodes; i++) {
                newNodes[i] = nodes[i];
            }
            delete[] nodes;
            nodes = newNodes;
            capacity = newCapacity;
        }
        nodes[numNodes] = new Node;
        nodes[numNodes]->id = id;
        numNodes++;
    }
    void addEdge(int u, int v) {
        if(u < numNodes && v < numNodes && u != v) {
            nodes[u]->Node::addEdge(nodes[v]);
            //v inci node dan u uncu node a edge eklendi
        } else {
            std::cerr << "Cannot have an edge to itself.\n";
            return;
        }
    }

    void printGraph() {
        for(int i = 0; i < numNodes; i++) {
            std::cout << "Node " << nodes[i]->id << " has edges to: ";
            for(int j = 0; j <nodes[i]->numAdj; j++) {
                std::cout << nodes[i]->adj[j]->id << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g;
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addNode(5);
    g.addNode(6);
    g.addNode(7);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 6);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 7);
    g.addEdge(5, 0);
    g.addEdge(5, 5);

    g.printGraph();
    
    return 0;
}