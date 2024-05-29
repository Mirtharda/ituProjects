#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    vector<Node*> adj;
};

//first is the vertice (it's number), second is the vector adj that holds the neighbours
map<int, Node*> graph_map = {};

void addEdge(Node* node1, Node* node2){
    node1->adj.push_back(node2);
    node2->adj.push_back(node1);
}

//to calculate degrees
int nodeDegree(Node* vertice){
    int degree = 0;
    for(auto neighbour : vertice->adj){
        degree++;
    }
    return degree;
}

class Comparator{
    public:
    //we take two pairs n1 and n2(we take the pairs because in int main() our p.q. is made with pairs)
    bool operator()(const std::pair<int,Node*>& n1, const std::pair<int,Node*>& n2) const{
        //if n1's degree is > n2's degree return true
        return n1.first > n2.first;
    }
};

int main(){
 
   Node* nodes[15];

    // Create 15 nodes
    for (int i = 0; i < 15; i++) {
        nodes[i] = new Node();
        nodes[i]->data = i + 1;
        graph_map[nodes[i]->data] = nodes[i];
    }

    addEdge(nodes[0], nodes[2]);
    addEdge(nodes[1], nodes[11]);
    addEdge(nodes[0], nodes[4]);
    addEdge(nodes[1], nodes[3]);
    addEdge(nodes[1], nodes[14]);
    addEdge(nodes[2], nodes[9]);
    addEdge(nodes[2], nodes[11]);
    addEdge(nodes[3], nodes[14]);
    addEdge(nodes[3], nodes[6]);
    addEdge(nodes[4], nodes[14]);
    addEdge(nodes[5], nodes[6]);
    addEdge(nodes[6], nodes[14]);
    addEdge(nodes[6], nodes[7]);
    addEdge(nodes[6], nodes[8]);
    addEdge(nodes[7], nodes[8]);
    addEdge(nodes[7], nodes[12]);
    addEdge(nodes[8], nodes[13]);
    addEdge(nodes[10], nodes[13]);
    addEdge(nodes[10], nodes[14]);

    //print the graph
    for(auto it = graph_map.begin() ; it != graph_map.end(); it++){
        cout << "Node: " << it->first << " Adj: ";
        for(auto adj_node : it->second->adj){
            cout << adj_node->data << " ";
        }
        cout << endl;
    }

    for(auto vertice: graph_map){
        //to print degrees
        cout << "Vertice " << vertice.first <<" has ";
        cout << nodeDegree(vertice.second) << " neighbours." <<endl;
    }
    cout << endl;
    //this priorty queue stores pairs: int and node
    //int value is the degrees and queue will be ordered according to them.
    //by default they are ordered from biggest to smallest.
    priority_queue<std::pair<int,Node*>> max_cent;
    for(auto vertice: graph_map){
        max_cent.push({nodeDegree(vertice.second),vertice.second});
    }
    
    cout << "Three most central nodes:" <<endl;
    for(int i = 0; i < 3; i++){
        cout << "Vertice: "<<max_cent.top().second->data << " degree: " << max_cent.top().first <<  endl;
        max_cent.pop();
    }
    cout << endl;

    //if we want to order them in azalan order we have to define a Comparator
    //in the declaration of p.q. we take 3 parametres(pair, vector, Comparator)
    //pair is like the default, it shows what we will be storing 
    //vector is the container (We have to tell the p.q. which container to use when we define it using a comparator)
    priority_queue<std::pair<int, Node*>,std::vector<std::pair<int,Node*>>,Comparator> min_cent;
    for(auto vertice: graph_map){
        min_cent.push({nodeDegree(vertice.second),vertice.second});
    }
    
    cout << "Five min central nodes:" <<endl;
    for(int i = 0; i < 5; i++){
        cout << "Vertice: "<<min_cent.top().second->data << " degree: " << min_cent.top().first <<  endl;
        min_cent.pop();
    }
    cout << endl;

    return 0;
}