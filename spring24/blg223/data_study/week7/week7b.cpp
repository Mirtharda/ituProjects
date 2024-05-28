//GRAPHS
//with adjancency list
//this is a directed graph


#include <iostream>

using namespace std;

struct Node {
    int id;
    Node** adj = NULL;  //an array that holds pointers
    //pointers to adjacencies of this node

    int capacity = 0;
    int numAdj = 0;
    void addEdge(Node* node);
};

void Node::addEdge(Node* node) {
   if(numAdj == capacity) {
        int newCapacity = capacity == 0 ? 2 : capacity * 2;
        //if capacity is 0, then make newCapacity 2,
        //else do it capacity * 2

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

struct Graph {
    Node** nodes = NULL;
    int numNodes = 0;
    int capacity = 0;

    void addNode(int id);
    void addEdge(int u, int v);
    void printGraph();
};

void Graph::addNode(int id) {
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

void Graph::addEdge(int u, int v) {
    if(u < numNodes && v < numNodes && u != v) {
        nodes[u]->Node::addEdge(nodes[v]);
    }
}

void Graph::printGraph() {
    for(int i = 0; i < numNodes; i++) {
        cout << "Node " << nodes[i]->id << " has edges to: ";

        for(int j = 0; j <nodes[i]->numAdj; j++) {
            cout << nodes[i]->adj[j]->id << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g;
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.printGraph();
    
    return 0;
}