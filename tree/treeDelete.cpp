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
		Node* deleteNode(Node* r) {
			if (r == NULL)
				return NULL;
		
			if (r->left == NULL && r->right == NULL) {
				return NULL;
			}
			else if (r->left == NULL && r->right != NULL) {
				return r->right;
			}
			else if (r->left != NULL && r->right == NULL) {
				return r->left;
			}
			else {
				Node* subNode = r->right;
				Node* parentNode = NULL;
				while (subNode->left != NULL) {
					parentNode = subNode;
					subNode = subNode->left;
				}
		
				r->key = subNode->key;
				if (subNode == r->right) {
					r->right = subNode->right;
				}
				else {
					parentNode->left = subNode->right;
				}
				return r;
			}
		}
		
		
		void treeDelete(Node* t, Node* r, Node* p) {
			if (r == t) {
				root = deleteNode(t);
			}
			else if (r == p->left) {
				p->left = deleteNode(r);
			}
			else {
				p->right = deleteNode(r);
			}
		}
		void preorder(Node* r) {
		   cout << r->key << " ";
		   if(r->left != NULL) preorder(r->left);
		   if(r->right != NULL) preorder(r->right);
		}
		
		void inorder(Node* r) {
		   if(r->left != NULL) inorder(r->left);
		   cout << r->key << " ";
		   if(r->right != NULL) inorder(r->right);
		}
		
		void postorder(Node* r) {
		   if(r->left != NULL) postorder(r->left);
		   if(r->right != NULL) postorder(r->right);
		   cout << r->key << " ";
		}
	public: 
		BinarySearchTree() {
			root = NULL;
		}
		~BinarySearchTree() {}
		void TreeInsert(int o) {
			root = treeinsert(root, o);
		}
		void TreeDelete(int o) {
			Node* r = root;
			Node* p = 0;
		
			while (r != NULL && r->key != o) {
				p = r;
				if (o < r->key) r = r->left;
				else if (o > r->key) r = r->right;
			}
			if (r) {
				treeDelete(root, r, p);
			}
		}
		void print(int i) {
			if (i==0) {
				preorder(root);
			}
			else if(i==1) {
				inorder(root);
			}
			else if (i==2) {
				postorder(root);
			}
		}
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
	cin >> n;
	int order;
	for (int i=0; i<n; i++) {
		cin >> order >> num;
		bst.TreeDelete(num);
		bst.print(order);
		cout << '\n';
	}
	
}
