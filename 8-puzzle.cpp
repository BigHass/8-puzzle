// Husni Abdelsalam Husni Abed 
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
class Node {
private:
	int findZero() {
		auto it = find(board.begin(), board.end(), 0);
		auto z = it - board.begin();
		return z;
	}
	Node* moveUp() {
		int loc = findZero();
		vector<int> temp = board;
		bool isUpAvailable = loc != 0 && loc != 1 && loc != 2;
		if (isUpAvailable)
			swap(temp[loc], temp[loc - 3]);
		return new Node(temp, this, 'U');

	}
	Node* moveDown() {
		int loc = findZero();
		vector<int> temp = board;
		bool isDownAvailable = loc != 6 && loc != 7 && loc != 8;
		if (isDownAvailable)
			swap(temp[loc], temp[loc + 3]);
		return new Node(temp, this, 'D');
	}
	Node* moveRight() {
		int loc = findZero();
		vector<int> temp = board;
		bool isRightAvailable = loc != 2 && loc != 5 && loc != 8;
		if (isRightAvailable)
			swap(temp[loc], temp[loc + 1]);
		return new Node(temp, this, 'R');
	}
	Node* moveLeft() {
		int loc = findZero();
		vector<int> temp = board;
		bool isLeftAvailable = loc != 0 && loc != 3 && loc != 6;
		if (isLeftAvailable)
			swap(temp[loc], temp[loc - 1]);
		return new Node(temp, this, 'L');
	}
public:
	vector<int> board;
	Node* parent;
	char action;

	Node(vector<int> b, Node* p, char a = '\0') {
		board = b;
		parent = p;
		action = a;
	}
	void printBoard() {
		int count = 0;
		for (auto i : board) {
			if (count % 3 == 0)
				cout << endl;
			if (i == 0) {
				cout << "  ";
			}
			else {
				cout << i << ' ';

			}
			count++;
		}
	}

	vector<Node*> expand() {
		return { moveUp(),moveDown(),moveRight(),moveLeft() };
	}

};
bool checkcontains(queue<Node*> fringe, Node* n) {
	bool exist = false;
	while (!fringe.empty()) {
		if (fringe.front()->board == n->board)
			exist = true;
		fringe.pop();
	}
	return exist;
}
void printSolutionPath(vector<Node*> solution, Node* node) {
	Node* currentNode = node;
	solution.push_back(node);
	vector<char> actions;
	while (currentNode->parent != nullptr) {
		currentNode = currentNode->parent;
		solution.push_back(currentNode);
	}
	reverse(solution.begin(), solution.end());
	for (auto i : solution) {
		i->printBoard();
		cout << endl;
		actions.push_back(i->action);
	}
	cout << "\n------------Summary------------" << endl;
	cout << "Actions taken:";
	for (auto i : actions) {
		cout << i << ' ';
	}
	cout << endl;
}
void BFS() {
	vector<int> initial;
	string userInput;
	cout << "Notic: Valid symbols are \"8 7 5 5 4 4 2 1 0\" " << endl;
	cout << "having two 4's and two 5's in this problem and no 3 or 6." << endl;
	cout << "Enter initial state: ";
	cin >> userInput;
	for (auto c : userInput) {
		initial.push_back(c - '0');
	}

	vector<int> goal{ 0,1,2,4,4,5,5,7,8 };
	Node* root = new Node(initial, nullptr);
	queue<Node*> fringe;
	queue<Node*> visited;
	fringe.push(root);
	bool found = false;
	int countE = 0;
	int countG = 0;
	vector<Node*> solution;
	auto startTime = chrono::steady_clock::now();
	while (!fringe.empty() && !found) {
		Node* currentNode = fringe.front();

		visited.push(currentNode);
		fringe.pop();
		auto children = currentNode->expand();
		for (auto i : children) {
			Node* currentChild = i;
			countG++;
			if (currentChild->board == goal) { // test at generation nodes

				printSolutionPath(solution, currentChild);
				found = true;
			}
			if (!checkcontains(visited, currentChild)) {
				fringe.push(currentChild);


			}

		}
		countE++;
	}
	auto endTime = chrono::steady_clock::now();
	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count()
		<< " ms" << endl;
	cout << "Number of generated nodes: " << countG << endl;
	cout << "Number of expanded nodes: " << countE << endl;
}
int main() {
	cout << "Start Gaming..." << endl;
	BFS();
	system("pause");
}