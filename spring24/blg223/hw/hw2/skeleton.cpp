//////////////////////////////////////////
// The code from Zeynep Gurler's HW is altered for the application. Sincere thanks!
//////////////////////////////////////////
#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
#include "doublelinklist.h"

using namespace std;

struct attack{   // class for pokemon attacks
	private:
		string name;
		int pp;
		int accuracy;
		int damage;
		int first;
	public:
		attack(const string&, int, int, int, int);
		int get_first();
		int get_accuracy();
		int get_damage();
		int get_pp();
		string get_name();
};

attack::attack(const string& name_in, int p, int a, int d, int f){
	name = name_in;
	pp = p;
	accuracy = a;
	damage = d;
	first = f;
}

string attack::get_name(){
	return name;
}

int attack::get_pp(){
	return pp;
}

int attack::get_damage(){
	return damage;
}

int attack::get_first(){
	return first;
}

int attack::get_accuracy(){
	return accuracy;
}

struct pokemon{  // class for pokemons
	int pp;
	int hp;
	string name;
	DoublyList<attack*> attacks;
	pokemon(const string &name_in, int, int); 
	string get_name();
	void set(char, int to_reduce);
};

pokemon::pokemon(const string &name_in, int p, int h){
	name = name_in;
	pp = p;
	hp = h;
}


void pokemon::set(char which, int to_reduce){
	if(which == 'p'){
		pp += to_reduce;
	}else{
		hp -= to_reduce;
	}
}


struct node{  // class for the nodes of the graph
	string ifef;  // attack is efficient or nonefficent
	string curattack;  // attack name
	int num;  // node num
	pokemon* pikachu;  // current pikachu
	pokemon* blastoise;  // currrent blastoise
	char status;  // whose turn?
	int level;  // level of the node
	bool isleaf;  // node is a leaf or not
	double prob;  // prob of the node happening
	 
	DoublyList<node*> child;  // children nodes of the node
	node* parent;
	
	//Member functions goes there...
	node(string ifef, string curattack, int num, pokemon* pikachu, pokemon* blastoise,
		char status, int level, bool isleaf, double prob, node* parent)
		: ifef(ifef), curattack(curattack), num(num), pikachu(pikachu), 
		blastoise(blastoise), status(status), level(level), isleaf(isleaf), 
		prob(prob), parent(parent) {}
	
	void addChild(node* childNode) {
		//std::cout << "p_pp: " << childNode->pikachu->pp;
		//std::cout << " b_pp: " << childNode->blastoise->pp << endl;
		child.addBack(childNode);
		childNode->parent = this;
	}
};


struct graph{
	//Graph definitions goes there...
	node* root;
	int max_level;
	int num;

	DoublyList<node*> leafNodes;

	graph(node* root, int max_level) {
		this->root = root;
		this->max_level = max_level;
		this->num = 0;
	}

	void addChild(node* parent) {
		// need to know which pokemon is attacking that time (DONE)
		// (use parent->status)
		// need to choose the attack for that node (DONE)
		// any attack type is not an option until level >= first_usage (DONE)
		// increase level by one (DONE)
		// 
		// need to find the probablity of that node
		// update ifef
		// find the logic for pp, damage and update these values for child
		// 
		// check if max_level is reached or hp is zero
		// if yes isleaf=true
		// update status for the next pokemon to attack 
		//

		if (parent->isleaf == true) {
			//cerr << "Adding new node is not allowed. (This is a leaf node.)\n";
			return;
		}

		pokemon* current_attacker = (parent->status == 'p') ? parent->pikachu : parent->blastoise;
		int performable_attacks = 0;
		for (int i = 0; i < current_attacker->attacks.elemcount; i++) {
			attack* current_attack = current_attacker->attacks.get(i);

			if (parent->level + 1 >= current_attack->get_first() &&
				((parent->status == 'p' && parent->pikachu->pp >= current_attack->get_pp()) ||
				(parent->status == 'b' && parent->blastoise->pp >= current_attack->get_pp()))) {

				performable_attacks++;
			}
		}

		for (int i = 0; i < current_attacker->attacks.elemcount; i++) {
			attack* current_attack = current_attacker->attacks.get(i);
			int current_level = parent->level + 1;

			if (parent->level + 1 >= current_attack->get_first() &&
				((parent->status == 'p' && parent->pikachu->pp >= current_attack->get_pp()) ||
				(parent->status == 'b' && parent->blastoise->pp >= current_attack->get_pp()))) {

				//for each attack there should be two nodes
				//one for 'effective' attack, other for 'not effective' attack

				pokemon* pikachu_copy1 = new pokemon(*(parent->pikachu));
				pokemon* pikachu_copy2 = new pokemon(*(parent->pikachu));
				pokemon* blastoise_copy1 = new pokemon(*(parent->blastoise));
				pokemon* blastoise_copy2 = new pokemon(*(parent->blastoise));

				node* child1 = new node(parent->ifef, current_attack->get_name(), ++num,
								pikachu_copy1, blastoise_copy1,
								(parent->status == 'p') ? 'b' : 'p',
								parent->level + 1, false, 0.0, parent);
				//std::cout << child1->num << " node is effective and in level " << child1->level << std::endl;
				node* child2 = new node(parent->ifef, current_attack->get_name(), ++num,
								pikachu_copy2, blastoise_copy2,
								(parent->status == 'p') ? 'b' : 'p',
								parent->level + 1, false, 0.0, parent);
				//std::cout << child2->num << " node is not effective and in level " << child2->level << std::endl;
				

				{
					//EFFECTIVE NODE
					double probablity1 = (parent->prob / static_cast<double>(performable_attacks)) * (current_attack->get_accuracy() / 100.0);
					child1->ifef = " effective ";
					child1->prob = probablity1;

					if (current_attacker == parent->pikachu) {
						child1->pikachu->pp = parent->pikachu->pp + current_attack->get_pp();
						child1->blastoise->hp = parent->blastoise->hp - current_attack->get_damage();
						child1->status = 'b';
					}
					else {
						child1->blastoise->pp = parent->blastoise->pp + current_attack->get_pp();
						child1->pikachu->hp = parent->pikachu->hp - current_attack->get_damage();
						child1->status = 'p';
					}

					if (child1->pikachu->hp <= 0 || child1->blastoise->hp <= 0 || child1->level == max_level) {
						child1->isleaf = true;
						//leafNodes.addBack(child1);
					}

					parent->child.addBack(child1);
				}
				{
					//NOT EFFECTIVE NODE

					//if probablity of that attack is '100' then there is no 'not effective' attack.
					if (current_attack->get_accuracy() == 100) {
						delete child2;
						num--;
						//std::cout << "child2 is deleted. num is " << num << std::endl;
					}
					else {
						double probablity2 = (parent->prob / static_cast<double>(performable_attacks)) * ((100 - current_attack->get_accuracy()) / 100.0);
						child2->ifef = " not effective ";
						child2->prob = probablity2;

						if (current_attacker == parent->pikachu) {
							child2->pikachu->pp = parent->pikachu->pp + current_attack->get_pp();
							child2->status = 'b';
						}
						else {
							child2->blastoise->pp = parent->blastoise->pp + current_attack->get_pp();
							child2->status = 'p';
						}
						if (child2->level == max_level) { 
							child2->isleaf = true;
							//leafNodes.addBack(child2);
						}

						parent->child.addBack(child2);
					}
				}

				//parent->addChild(child);
			}
		}
	}

	void buildGraph(node* root) {
		DoublyList<node*> q;
		q.addBack(root);

		while (q.elemcount != 0) {
			node* current = q.get(0);
			//std::cout << "First of queue: " << q.get(0)->num << std::endl;
			q.removeFront();

			if (current->level == max_level || current->pikachu->hp <= 0 || current->blastoise->hp <= 0) {
				current->isleaf = true;
				node* temp = new node(*current);
				leafNodes.addBack(temp);
				//cout << "Leafnode count: " << leafNodes.elemcount << endl;
			}
			else {
				addChild(current);
				//std::cout << current->child.elemcount << std::endl;

				for (int i = 0; i < current->child.elemcount; i++) {
					q.addBack(current->child.get(i));
				}
			}
		}
	}

	void printLevel(node* root, int level) {
		if (root == nullptr)
			return;

		if (level == 0) {
			cout << "P_HP:" << root->pikachu->hp
				<< " P_PP:" << root->pikachu->pp
				<< " B_HP:" << root->blastoise->hp
				<< " B_PP:" << root->blastoise->pp
				<< " PROB:" << root->prob << endl;
		}
		else {
			for (int i = 0; i < root->child.elemcount; ++i) {
				printLevel(root->child.get(i), level - 1);
			}
		}
	}

	void easiestPath(node* startnode) {
		if (leafNodes.elemcount == 0) {
			cout << "No leaf nodes found. Cannot find easiest path." << endl;
			return;
		}

		// Find the leaf node with the highest probability
		double maxProb = 0.0;
		node* easiestLeaf = nullptr;

		for (int i = 0; i < leafNodes.elemcount; i++) {
			node* leaf = leafNodes.get(i);
			if (leaf->prob > maxProb) {
				maxProb = leaf->prob;
				easiestLeaf = leaf;
			}
		}
		// Check if easiestLeaf is null
		if (easiestLeaf == nullptr) {
			cout << "No easiest leaf node found." << endl;
			return;
		}

		// Trace back from the easiest leaf node to the startnode
		DoublyList<node*> path;
		node* current = easiestLeaf;while (current != NULL) {
			path.addFront(current);
			current = current->parent;
		}

		// Output the easiest path
		
		for (int i = 0; i < path.elemcount; ++i) {
			node* n = path.get(i);
			if (path.get(i-1)->status == 'p') {
				cout << "Pikachu used " << n->curattack << ": " << n->ifef << endl;
			}
			else  {
				cout << "Blastoise used " << n->curattack << ": " << n->ifef << endl;
			}
		}
		cout << "Level count: " << easiestLeaf->level << endl;
		cout << "Probability: " << easiestLeaf->prob << endl;

	}

};



int main(int argc, char** argv){
	/*
	string part = argv[1];
	int max;
	string which;
	char* pika_or_blastoise;

	if (part == "part1") {
		max = atoi(argv[2]);
	}
	else if (part == "part2") {
		pika_or_blastoise = argv[2];
	}
	else
		return -1;
	*/ 

	pokemon* pikachu = new pokemon("pikachu", 100, 200);
	pokemon* blastoise = new pokemon("blastoise", 100, 200);
	
	attack* thundershock = new attack("thundershock", -10, 100, 40, 0);
	attack* skullbash = new attack("skullbash", -15, 70, 50, 0);
	attack* slam = new attack("slam", -20, 80, 60, 0);
	attack* pskip = new attack("skip", 100, 100, 0, 3);
	pikachu->attacks.addBack(thundershock);
	pikachu->attacks.addBack(skullbash);
	pikachu->attacks.addBack(slam);
	pikachu->attacks.addBack(pskip);

	attack* tackle = new attack("tackle", -10, 100, 30, 0);
	attack* watergun = new attack("watergun", -20, 100, 40, 0);
	attack* bite = new attack("bite", -25, 100, 60, 0);
	attack* bskip = new attack("skip", 100, 100, 0, 3);
	blastoise->attacks.addBack(tackle);
	blastoise->attacks.addBack(watergun);
	blastoise->attacks.addBack(bite);
	blastoise->attacks.addBack(bskip);
	//I CHANGED STARTING HERE
	//PART 1
	node* root = new node("", "", 0, pikachu, blastoise, 'p', 0, false, 1.0, NULL); //use WHICH for status
	graph gameGraph(root, 8);
	gameGraph.buildGraph(root);
	gameGraph.printLevel(root, 1);
	//PART 2
	// Find the shortest path
	gameGraph.easiestPath(root);
	
	return 0;
}