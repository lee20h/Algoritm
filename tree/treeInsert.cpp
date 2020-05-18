#include<iostream>
using namespace std;

class Node {
	friend class BinarySearchTree;
	private:
		int key;
		Node* left;
		Node* right;
	public:
		Node() {
			key = 0;
			left = right = 0;
		};
		Node(int k) {
			key = k;
			left = right = 0;
		};
		~Node() {}
};

class BinarySearchTree{
	friend class Node;
	private:
		Node* root;
		Node* treeinsert(Node* n, int o) {
			cnt++;
			Node* new_node = new Node();
			if(n == NULL) {
			    new_node->key = o;
				new_node->left = NULL;
				new_node->right = NULL;
			    return new_node;
			}
		   if(o < n->key)  {
				n->left = treeinsert(n->left, o); 
				return n;
		   }
		   else {
				n->right = treeinsert(n->right, o);
				return n;
		   }
		}
	public: 
		BinarySearchTree() {
			root = NULL;
			cnt = 0;
		}
		~BinarySearchTree() {}
		void TreeInsert(int o) {
			root = treeinsert(root, o);
		}
		int cnt;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int num;
	BinarySearchTree bst;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num;
		bst.TreeInsert(num);
	}
	cout << bst.cnt;
}
