#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;                      
    list<int>* adj;            

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void BFS(int s) {
        bool* visited = new bool[V];    
        for (int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;                

        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        delete[] visited;
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }

    void DFS(int v) {
        bool* visited = new bool[V];    
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFSUtil(v, visited);
        delete[] visited;
    }

    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 3);

    cout << "BFS Traversal: ";
    g.BFS(2); 

    cout << "\nDFS Traversal: ";
    g.DFS(2); 

    return 0;
}
