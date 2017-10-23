// C++ program to delete a node from AVL Tree
#include<iostream>
#include<cstdlib>
#include<climits>

using namespace std;
// An AVL tree node
struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
	int min;
	int max;
	int mingap;
	//int maxgap;  // if you want maxgap also
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}
//min of two numbers
int min(int a, int b)
{
	return (a < b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	node->min = key;
	node->max = key;
	node->mingap = INT_MAX;
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(struct Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;
	int m1, m2;
	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	//update max of x
		x->max = y->max;

	//update min of y
	if(T2!=NULL)
		y->min = T2->min;
	else
		y->min = y->key;

	//update mingap of y
	if(T2!=NULL){
		m1 = min(T2->mingap, (y->key - T2->max));
		y->mingap = m1;
		m2 = min(y->right->mingap, (y->right->min - y->key));
		y->mingap = min(m2, m1);

	}
	else{
		m2 = min(y->right->mingap, (y->right->min - y->key));
		y->mingap = m2;
	}
	//update mingap of x
	m1 = min(x->left->mingap, (x->key - x->left->max));
	m2 = min(x->right->mingap, (x->right->min - x->key ));
	x-> mingap = min(m1, m2);

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(struct Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;
	int m1, m2;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	//update max of x
	if(T2!=NULL)
		x->max = T2->max;
	else
		x->max=x->key;

	//update min of y
		y->min = x->min;

	//update mingap of x
	if(T2!=NULL){
		m1 = min(T2->mingap, (T2->min - x->key));
		x->mingap = m1;
		m2 = min(x->left->mingap, (x->key - x->left->max));
		m2 = min(m2, x->mingap);
		x->mingap = m2;
	}
	else{
		m2 = min(x->left->mingap, (x->key - x->left->max));
		x->mingap = m2;
	}
	//update mingap of y
	m1 = min(y->left->mingap, (y->key - y->left->max));
	m2 = min(y->right->mingap, (y->right->min - y->key ));
	y-> mingap = min(m1, m2);

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),height(node->right));

	//update min
	if(node->left != NULL)
		node->min = node->left->min;

	//update max
	if(node->right != NULL)
		node->max = node->right->max;

	//update mingap
	if(node->left !=NULL){
		int m1 = min(node->left->mingap, (node->key - node->left->max));
		node->mingap = m1;
	}
	if(node->right !=NULL){
		int m2 = min(node->right->mingap, (node->right->min - node->key));
		m2 = min(m2, node->mingap);
		node->mingap = m2;
	}

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the
node with minimum key value found in that tree.
Note that the entire tree does not need to be
searched. */
Node * minValueNode(Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}
//function to find max value in the tree
Node * maxValueNode(Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->right != NULL)
		current = current->right;

	return current;
}


// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
Node* deleteNode(Node* root, int key)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct Node *temp = root->left ? root->left :
											root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			Node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),height(root->right));

	//update min
	if(root->left != NULL)
		root->min = root->left->min;

	//update max
	if(root->right != NULL)
		root->max = root->right->max;

		int m1, m2;
	//update mingap
	if(root->left !=NULL){
		m1 = min(root->left->mingap, (root->key - root->left->max));
		root->mingap = m1;
	}
	if(root->right !=NULL){
		int m2 = min(root->right->mingap, (root->right->min - root->key));
		//m2 = min(m2, root->mingap);
		root->mingap = m2;
	}

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout<<"\t"<<root->key<<" ["<<root->min<<"]"<<" ["<<root->max<<"]";
		cout<<" {"<<root->mingap<<"}";
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Drier program to test above function*/
int main()
{
Node *root = NULL;

/* Constructing tree given in the above figure */
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	/* The constructed AVL Tree would be
			9
	   / \
		1  10
	 / \	 \
	0  5	 11
 /  / \
-1  2 6
	*/

	cout<<"Preorder traversal of the constructed AVL tree is \n";
	preOrder(root);

	root = deleteNode(root, 10);

	/* The AVL Tree after deletion of 10
			1
		/ \
		0 9
		/	 / \
	-1 5	 11
		/ \
		2 6
	*/

	cout<<"\nPreorder traversal after deletion of 10 \n";
	preOrder(root);
  cout<<"\n";
  cout<<"Minimum value in tree is : "<<minValueNode(root)->key<<"\n";
  cout<<"Maximum value in tree is : "<<maxValueNode(root)->key<<"\n";

	return 0;
}
