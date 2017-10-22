// C++ program to delete a node from AVL Tree
// find num(x,y) i.e. numbers b/w x and y in the tree
// find sum(x,y)
// find avg(x,y)
#include<iostream>
#include<cstdlib>

using namespace std;
// An AVL tree node
struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
	int num; // to keep track of no. of children
  int sum; //stores prefix sum
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

// to get num of a node
int num(Node *N)
{
	if (N == NULL)
		return 0;
	return N->num;
}

// to get prefix sum of a node
int sum(Node *N)
{
	if (N == NULL)
		return 0;
	return N->sum;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
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
	node->num = 1; //since initially a leaf
  node->sum = key;
  return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(struct Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	//update num
	y->num = 1 + num(y->left) + num(y->right);
	x->num = 1 + num(x->left) + num(x->right);

  //update sum
	y->sum = y->key + sum(y->left) + sum(y->right);
	x->sum = x->key + sum(x->left) + sum(x->right);


	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(struct Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	//update num
	x->num = 1 + num(x->left) + num(x->right);
	y->num = 1 + num(y->left) + num(y->right);

  //update sum
	x->sum = x->key + sum(x->left) + sum(x->right);
  y->sum = y->key + sum(y->left) + sum(y->right);
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

	//for num
	node->num = 1 + num(node->left) + num(node->right);

  //for sum
  node->sum = node->key + sum(node->left) + sum(node->right);


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
	root->height = 1 + max(height(root->left),
						height(root->right));

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
		cout<<"\t"<<root->key<<" ("<<num(root)<<")"<<" {"<<sum(root)<<"}";
		preOrder(root->left);
		preOrder(root->right);
	}
}

//function for Rank
int Rank(Node * root,int x){
	Node * t = root;
	int r = 0;
	while(t){
		if(t->key < x)
			t=t->right;
		else
			{
				if(t->right != NULL)
					r = r + 1 + (t->right->num);
				else
					r =r + 1;
				t = t->left;
			}
	}
	return r;
}

//function to find node with given rank 'k'
Node * findRank(Node * root, int k){
  Node * t = root;
  int r;
  while(t){
    if(t->right != NULL)
      r =t->right->num;
    else
      r = 0;
    if(r+1 == k)
      return t;
    else if(r+1 < k){
      k = k - (r+1);
      t= t->left;
    }
    else
      t = t->right;

  }
}

//function for num(x,y) numbers>=x and <=y
int num(Node * root, int x, int y){
  int r1 = Rank(root, x);
  int r2 = Rank(root, y);
  return (r1-r2);
}

//function prefixSum : calculates the sum until that element
//from the lowest element
int prefixSum(Node * root, int x){
  int sum = 0;
  Node * t = root;
  while(t){
    if(t->key == x)
      if(t->left != NULL)
        return (sum + t->left->sum + t->key);
      else
        return (sum + t->key);

    else if(t->key < x){
      if(t->left != NULL)
        sum = sum + t->key + t->left->sum;
      else
        sum = sum + t->key;
      t = t->right;
    }
    else
      t = t->left;
  }
  return sum;
}

//uses prefixSum and calculates sum(x,y)
int sumBetween(Node *root, int x, int y){
  int s1 = prefixSum(root ,y);
  int s2 = prefixSum(root, x-1);
  return (s1-s2);
}

//function to calculate average(x,y)
int avg(Node *root, int x, int y){
  int n = sumBetween(root, x, y)/num(root, x, y);
  return n;
}




/* Driver program to test above function*/
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

	cout<<"Preorder traversal of the constructed AVL tree is(with num values)\n";
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

	cout<<"\nPreorder traversal after deletion of 10 (with num values)\n";
	preOrder(root);
  cout<<"\n";
  cout<<"Minimum value in tree is : "<<minValueNode(root)->key<<"\n";
  cout<<"Maximum value in tree is : "<<maxValueNode(root)->key<<"\n";
	cout<<"Number of elements : "<<num(root)<<"\n";
	cout<<"Rank of 11 is :"<<Rank(root, 11)<<endl;
	cout<<"Rank of 5 is :"<<Rank(root, 5)<<endl;
	//cout<<"Rank of 3 is :"<<Rank(root, 3)<<endl;
  cout<<"Node with rank 5 : "<<findRank(root, 5)->key<<endl;
  cout<<"Node with rank 1 : "<<findRank(root, 1)->key<<endl;
  cout<<"Node with rank 8 : "<<findRank(root, 8)->key<<endl;
  cout<<"Number of nodes between 3 and 15 are :"<<num(root, 3, 15)<<endl;
  cout<<"Sum of nodes between 3 and 15 is :"<<sumBetween(root, 3, 15)<<endl;
  cout<<"Average of nodes between 3 and 15 is :"<<avg(root, 3, 15)<<endl;

	return 0;
}
