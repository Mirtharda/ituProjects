#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

/////////////////// Player ///////////////////
class publisher
{
public:
	string name;
	float na_sales;
	float eu_sales;
	float others_sales;
};

/////////////////// Node ///////////////////
class Node{
	public:
		publisher key;
		int color; // "Red"=1 or "Black"=0
		Node *parent, *left, *right;
	
		Node(publisher);
		~Node();
		int get_color();
        void set_color(int);
};

/////////////////// RB-Tree ///////////////////
class RB_tree{
	private:
		Node* root;
	public:	
        publisher* best_seller[3];	
		stack<string> tree_deep_stack;

        Node* get_root();

		Node* RB_insert(Node* root, Node* ptr);
        void insertValue(vector<string>);
		void RB_left_rotate(Node*);
		void RB_right_rotate(Node*);
		void RB_insert_fixup(Node*);
        void preorder();
        void find_best_seller(); 

        RB_tree();
		~RB_tree();
};
/////////////////// HELPER ///////////////////
int currentDecade = (1980 / 10) * 10;
std::vector<Node*> publisherVector;

void print_best_sellers(int year, publisher* temp_publisher[3]){
    cout.precision(5);
    cout<< "End of the "+to_string(year)+" Year"<<endl;
    cout<< "Best seller in North America: "+temp_publisher[0]->name+" - "<<temp_publisher[0]->na_sales<<" million"<<endl;
    cout<< "Best seller in Europe: "+temp_publisher[1]->name+" - "<<temp_publisher[1]->eu_sales<<" million"<<endl;
    cout<< "Best seller rest of the World: "+temp_publisher[2]->name+" - "<<temp_publisher[2]->others_sales<<" million"<<endl;
}

RB_tree generate_RBT_tree_from_csv(string file_name){
	RB_tree temp_RBtree;
    publisherVector.clear();    //cleared to vector to put the new tree in it
    currentDecade = (1980 / 10) * 10;

    // Fill this function.
    std::ifstream file(file_name);
    if(!file.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
        return {};
    }

    std::string line;
    //titles
    getline(file, line);

    while(getline(file, line)) {

        std::istringstream iss(line);
		std::string nameStr, platformStr, yearStr, publisher_nameStr, 
					naStr, euStr, otherStr;
		int year;

		if(getline(iss, nameStr, ',') &&
            getline(iss, platformStr, ',') &&
            getline(iss, yearStr, ',') &&
            getline(iss, publisher_nameStr, ',') &&
            getline(iss, naStr, ',') &&
            getline(iss, euStr, ',') &&
            getline(iss, otherStr)) {
            
            year = std::stoi(yearStr);
			int decade = (year / 10) * 10;	// calculate the current decade

/*
			// yeni 10 yıla geçilmeden önce best_seller hesabı
			if(decade != currentDecade && year % 10 == 1) {
				currentDecade = decade;
				temp_RBtree.find_best_seller();
			}
*/
			std::vector<string> n;

			// node için publisher class oluşturulmasını sağlayacak vektör
			n.push_back(publisher_nameStr);
			n.push_back(naStr);
			n.push_back(euStr);
			n.push_back(otherStr);

			temp_RBtree.insertValue(n);
		}
    }
    file.close();

    //for the last decade
    currentDecade += 10;
    temp_RBtree.find_best_seller();

    return temp_RBtree;
}

/////////////////// HELPER ///////////////////
void write_ordered_csv(string file_name);
Node* generate_random_node(std::vector<Node*>& nodes);
Node* search(RB_tree& t, Node* node);
////////////////////////////////////////////
//----------------- MAIN -----------------//
////////////////////////////////////////////
int main(int argc, char* argv[]){

    // Fill this function.
	string fname = argv[1];	

    
    std::cout << "----------------- C BEST SELLER&PREORDER -----------------\n";
	auto start = std::chrono::high_resolution_clock::now();
    RB_tree RBtree = generate_RBT_tree_from_csv(fname);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    //RBtree.preorder();

	std::cout << "----------------- A DATA INSERTION -----------------\n";
	std::cout << "Creating RBT time: " << duration.count() << " microseconds.\n";
    

    
	std::cout << "----------------- B SEARCH EFFICIENCY -----------------\n";
	// search 50 random nodes
    
    auto total_duration = chrono::nanoseconds(0);
    for(int i = 1; i <= 50; i++) {
        Node* randNode = generate_random_node(publisherVector);
        start = chrono::high_resolution_clock::now();
        search(RBtree, randNode);
        end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        total_duration += duration;
        std::cout << "Searching random node " << i << ": " << randNode->key.name << " "
                    << duration.count() << " nanoseconds.\n";
    }

    std::cout << "Average time is: " << total_duration.count() / 50 << " nanoseconds.\n";
    

    std::cout << "----------------- F ORDERED DATASET AND SEARCH -----------------\n";
    // search 50 random nodes
    write_ordered_csv(fname);
    RB_tree ordered_RBTree = generate_RBT_tree_from_csv("./ordered_name.csv");

    total_duration = chrono::nanoseconds(0);
    for(int i = 1; i <= 50; i++) {
        Node* randNode = generate_random_node(publisherVector);
        start = chrono::high_resolution_clock::now();
        search(ordered_RBTree, randNode);
        end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        total_duration += duration;
        std::cout << "Searching random node " << i << ": " << randNode->key.name << " "
                    << duration.count() << " nanoseconds.\n";
    }

    std::cout << "Average time is: " << total_duration.count() / 50 << " nanoseconds.\n";
 

    return EXIT_SUCCESS;
}


/////////////////// Node ///////////////////

Node::Node(publisher key){
	this->key = key;
    this->color = 1; // "RED";
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}
Node::~Node() {}

int Node::get_color() {
    return this->color;
}

void Node::set_color(int i) {
    this->color = i;
}

/////////////////// RB-Tree ///////////////////
Node* RB_tree::get_root(){

    // Fill this function.

    return this->root;
}

Node* RB_tree::RB_insert(Node* root, Node* ptr){

    // Fill this function.
    Node* current = root;
    Node* parent = NULL;

    // find where to put
    while(current != NULL) {
        parent = current;
        if(ptr->key.name == current->key.name) {
            current->key.na_sales += ptr->key.na_sales;
            current->key.eu_sales += ptr->key.eu_sales;
            current->key.others_sales += ptr->key.others_sales;
            return root;
        } else if(ptr->key.name < current->key.name) { 
            current = current->left; 
        } else { 
            current = current->right; 
        }
    }
        
    ptr->parent = parent;

    if(parent == NULL) {
        this->root = ptr;
    } else if(ptr->key.name < parent->key.name) {
        parent->left = ptr;
    } else {
        parent->right = ptr;
    }
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->color = 1;	
    publisherVector.push_back(ptr);
    RB_insert_fixup(ptr);

	return this->root;
}

void RB_tree::insertValue(vector<string> n) {
    
    // Fill this function.
	publisher newPublisher;
	newPublisher.name = n[0];
	newPublisher.na_sales = stof(n[1]);
	newPublisher.eu_sales = stof(n[2]);
	newPublisher.others_sales = stof(n[3]);

	Node* newNode = new Node(newPublisher);

	root = RB_insert(root, newNode);
}

void RB_tree::RB_left_rotate(Node *ptr){

    // Fill this function.
    Node* y = ptr->right;
    ptr->right = y->left;
    if(y->left != NULL) {
        y->left->parent = ptr;
    }
    y->parent = ptr->parent;
    if(ptr->parent == NULL) {
        this->root = y;
    } else if(ptr == ptr->parent->left) {
        ptr->parent->left = y;
    } else {
        ptr->parent->right = y;
    }

    y->left = ptr;
    ptr->parent = y;
    
}

void RB_tree::RB_right_rotate(Node *ptr){

    // Fill this function.
    Node* y = ptr->left;
    ptr->left = y->right;
    if(y->right != NULL) {
       y->right->parent = ptr;
    }

    y->parent = ptr->parent;
    if(ptr->parent == NULL) {
        this->root = y;
    } else if(ptr == ptr->parent->right) {
        ptr->parent->right = y;
    } else {
        ptr->parent->left = y;
    }
    
    y->right = ptr;
    ptr->parent = y;    
}

void RB_tree::RB_insert_fixup(Node *ptr) {

    // Fill this function.
    while(ptr->parent != nullptr && ptr->parent->color == 1) {
        if(ptr->parent == ptr->parent->parent->left) {
            Node* uncle = ptr->parent->parent->right;

            if(uncle != nullptr && uncle->color == 1) {
                ptr->parent->color = 0;
                uncle->color = 0;
                ptr->parent->parent->color = 1;
                ptr = ptr->parent->parent;
            } else {
                if(ptr == ptr->parent->right) {
                    ptr = ptr->parent;
                    RB_left_rotate(ptr);
                }
                ptr->parent->color = 0;
                ptr->parent->parent->color = 1;
                RB_right_rotate(ptr->parent->parent);
            }
        } else {
            Node* uncle = ptr->parent->parent->left;

            if(uncle != nullptr && uncle->color == 1) {
                ptr->parent->color = 0;
                uncle->color = 0;
                ptr->parent->parent->color = 1;
                ptr = ptr->parent->parent;
            } else {
                if(ptr == ptr->parent->left) {
                    ptr = ptr->parent;
                    RB_right_rotate(ptr);
                }
                ptr->parent->color = 0;
                ptr->parent->parent->color = 1;
                RB_left_rotate(ptr->parent->parent);
            }
        }
    }
    root->color = 0;
}

void RB_tree::preorder(){

    // Fill this function.
    if(root == NULL) {
        std::cerr << "ERROR: Empty tree (preorder).\n";
        return;        
    }
    std::stack<std::pair<Node*, int>> s;
    s.push({root, 0});

    while(!s.empty()) {
        // get the current node and its depth
        Node* current = s.top().first;
        int depth = s.top().second;
        s.pop();

        // Determine the color
        std::string color = (current->color == 1) ? "(RED)" : "(BLACK)";

        // prnt the node with dashes corresponding to its depth
        std::cout << std::string(depth, '-') << color << current->key.name << "\n";

        if(current->right != NULL) {
            s.push({current->right, depth + 1});
        } 
        if(current->left != NULL) {
            s.push({current->left, depth + 1});
        }
    } 
}

void RB_tree::find_best_seller(){

    // Fill this function.
	if(root == NULL) {
		std::cerr << "ERROR: Empty tree.\n";
		return;
	}

    stack<Node*> s;
    s.push(root);

    while(!s.empty()) {
        Node* current = s.top();
        s.pop();

        if(best_seller[0] == NULL) {
            best_seller[0] = &current->key;
            best_seller[1] = &current->key;
            best_seller[2] = &current->key;
        } else {
            // Update best_seller
            if(current->key.na_sales > best_seller[0]->na_sales) {
                best_seller[0] = &current->key;
            } 
            if(current->key.eu_sales > best_seller[1]->eu_sales) {
                best_seller[1] = &current->key;
            }
            if(current->key.others_sales > best_seller[2]->others_sales) {
                best_seller[2] = &current->key;
            }
        }

        // Push the children to stack
        if(current->right != NULL) { s.push(current->right); }
        if(current->left != NULL) { s.push(current->left); }
    }

    // Best_seller her seferinde print best_seller ı çağırmalı
    print_best_sellers(currentDecade, best_seller);    
}

RB_tree::RB_tree(){
	this->root = NULL;
    this->best_seller[0] = NULL;
    this->best_seller[1] = NULL;
    this->best_seller[2] = NULL;
}

RB_tree::~RB_tree(){
}

/////////////////// HELPERS ///////////////////
Node* generate_random_node(vector<Node*>& nodes) {
    if(nodes.empty()) {
        return NULL;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, nodes.size() - 1);

    int random_index = dis(gen);

    return nodes[random_index];
}

Node* search(RB_tree& t, Node* node) {
	if(t.get_root() == NULL) {
        return NULL;
    }

    Node* current = t.get_root();
    while(current != NULL) {
        if(node->key.name < current->key.name) {
            current = current->left;
        } else if(node->key.name > current->key.name) {
            current = current->right;
        } else {
            return current;
        }
    }
	return NULL;
}

/////////////////// NEW CSV ///////////////////
void write_ordered_csv(string file_name) {
    std::ifstream file(file_name);
    if(!file.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
        return;
    }

    std::ofstream outputFile("ordered_name.csv");
    if(!outputFile.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
        return;
    }

    string line;
    // header
    getline(file, line);
    outputFile << line << "\n";

    // start reading
    int row = 1;
    vector<vector<string>> rows;
    while(getline(file, line)) {
        std::stringstream ss(line);

        string name = "";
        string platform = "";
        string year_of_release = "";
        string publisher_n = "";
        string na_sales = "";
        string eu_sales = "";
        string other_sales = "";

        if(rows.size() < row) {
            rows.resize(row);
        }

        getline(ss, name, ',');
        if(!name.empty() && name[0] == ' ') {
            name.erase(0, 1);
        }

        rows[row - 1].push_back(name);

        getline(ss, platform, ',');
        rows[row - 1].push_back(platform);

        getline(ss, year_of_release, ',');
        rows[row - 1].push_back(year_of_release);

        getline(ss, publisher_n, ',');
        rows[row - 1].push_back(publisher_n);

        getline(ss, na_sales, ',');
        rows[row - 1].push_back(na_sales);

        getline(ss, eu_sales, ',');
        rows[row - 1].push_back(eu_sales);

        getline(ss, other_sales);
        rows[row - 1].push_back(other_sales);

        row++;
    }

    sort(rows.begin(), rows.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[0] < b[0];
    });

    // write on output file
    for(int i = 0; i < rows.size(); i++) {
        const auto& row = rows[i];

        for(size_t j = 0; j < row.size(); ++j) {
            outputFile << row[j];
            if(j < row.size() - 1) {
                outputFile << ",";
            }
        }
        outputFile << "\n";
    }

    std::cout << "ordered_name.csv created\n";

    file.close();
    outputFile.close();
}