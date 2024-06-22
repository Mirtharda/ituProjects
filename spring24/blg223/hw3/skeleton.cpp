#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>  //getline
#include <algorithm> //sort
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

struct Node {
    string MID;
    vector<Node*> adj;
    vector<string> relation;
};


map<string, Node*> graph_map = {};
map<string, string> mid2name = {};

void helloNeighbor(string center_MID) {
    auto it = graph_map.find(center_MID);
    if (it == graph_map.end()) {
        std::cout << "MID not found" << endl;
        return;
    }

    Node* center = it->second;

    std::cout << center->adj.size() << " neighbors\n";
    for (int i = 0; i < center->adj.size(); i++) {
        string neighbor_MID = center->adj[i]->MID;
        string neighbor_name = mid2name[neighbor_MID];
        std::cout << neighbor_MID << " " << neighbor_name << endl;
    }
}

void degreeCentrality() {
    vector<pair<string, int>> degree_centrality;

    for (const auto& pair : graph_map) {
        string MID = pair.first;
        Node* node = pair.second;
        int degree = node->adj.size();
        degree_centrality.push_back({ MID, degree });
    }

    sort(degree_centrality.begin(), degree_centrality.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second;
	});

    for (int i = 0; i < 10 && i < degree_centrality.size(); i++) {
		string MID = degree_centrality[i].first;
		int degree = degree_centrality[i].second;
		string name = mid2name[MID];
        std::cout << MID << " " << name << " Degree: " << degree << endl;
	}
}

void shortestDistance(string start_MID, string end_MID) {
    if(graph_map.find(start_MID) == graph_map.end() || graph_map.find(end_MID) == graph_map.end()) {
        std::cout << "MID not found" << endl;
		return;
	}

    queue<string> q;
    unordered_map<string, string> parent;
    unordered_map<string, int> distance;

    q.push(start_MID);
    parent[start_MID] = "";
    distance[start_MID] = 0;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        Node* currentNode = graph_map[current];

        for (Node* neighbor : currentNode->adj) {
            if(distance.find(neighbor->MID) == distance.end()) {
                q.push(neighbor->MID);
                parent[neighbor->MID] = current;
				distance[neighbor->MID] = distance[current] + 1;

                if(neighbor->MID == end_MID) {
                    std::cout << "Shortest distance between " << start_MID << " (" << mid2name[start_MID] << ") and " << end_MID << " (" << mid2name[end_MID] << "): " << distance[end_MID] << endl;
					
                    stack<string> path;
                    string sted = end_MID;
                    while(sted != "") {
						path.push(sted);
						sted = parent[sted];
					}

                    std::cout << "Path: ";
                    while(!path.empty()) {
                        //prints MID and name of the node
                        std::cout << path.top() << " " << mid2name[path.top()] << " ";
                        path.pop();
                        if(!path.empty()) {
                            std::cout << "-> ";
						}
                    }
                    std::cout << endl;

					return;
				}
			}
		}
    }
    std::cout << "No path found" << endl;
}


int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Uage: ./main part1|part2|part3" << endl;
        return 1;
    }

    ifstream infile("freebase.tsv");

    std::cout << "Reading file\n";

    string line;
    while (getline(infile, line))
    {
        string ent1 = line.substr(0, line.find("\t"));
        string remain = line.substr(line.find("\t")+1,line.length()-ent1.length());
        string relationship = remain.substr(0, remain.find("\t"));
        remain = remain.substr(remain.find("\t")+1, remain.length()-relationship.length());
        //string ent2 = remain.substr(0, line.find("\t"));
        string ent2 = remain.substr(0, remain.find("\r"));

        Node* ent1_node, *ent2_node;

        if (graph_map.find(ent1) == graph_map.end()) {
            ent1_node = new Node;
            ent1_node->MID = ent1;
            graph_map[ent1] = ent1_node;
        } else {
            ent1_node = graph_map[ent1];
        }

        if (graph_map.find(ent2) == graph_map.end()) {
            ent2_node = new Node;
            ent2_node->MID = ent2;
            graph_map[ent2] = ent2_node;
        } else {
            ent2_node = graph_map[ent2];
        }

        ent1_node->adj.push_back(ent2_node);
        ent1_node->relation.push_back(relationship);

        ent2_node->adj.push_back(ent1_node);
        ent2_node->relation.push_back(relationship);
    }    


    ifstream infile2("mid2name.tsv");

    while (getline(infile2, line))
    {
        string MID = line.substr(0, line.find("\t"));
        string remain = line.substr(line.find("\t")+1,line.length()-MID.length());
        //string name = remain.substr(0, remain.find("\t"));
        string name = remain.substr(0, remain.find("\r"));
        if (mid2name.find(MID) == mid2name.end()) {
			mid2name[MID] = name;
        }
        
        //cout << name << endl;
    }


    //std::cout << "Graph size: " << graph_map.size() << endl;

    string part = argv[1];
    if(part == "part1") {
        if (argc != 3) {
            std::cout << "Usage: ./main part1 [MID]\n";
			return 1;
        }

		helloNeighbor(argv[2]);        
	} else if (part == "part2") {
        if (argc != 2) {
            std::cout << "Usage: ./main part2\n";
            return 1;
        }

		degreeCentrality();        
	} else if (part == "part3") {
        if (argc != 4) {
            std::cout << "Usage: ./main part3 [MID] [MID]\n";
            return 1;
        }
		shortestDistance(argv[2], argv[3]);		
	} else {
		cout << "Uage: ./main part1|part2|part3 [MID] [MID] (adding mids are proportional to part choice" << endl;
		return 1;
	}

    return 0;

}