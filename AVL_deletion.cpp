#include"bits/stdc++.h"
using namespace std;

struct Node
{
	int data,height;
	Node *left, *right;
};
struct Node* root = NULL;

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	return root->height;
}

int getBalance(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return height(root->left) - height(root->right);
}

Node *rightRotate(Node* root)
{
	Node *root_left = root->left;
	Node *root_left_right = root_left->right;

	//rotation
	root_left->right = root;
	root->left = root_left_right;

	//update heights

	root_left->height = max(height(root_left->left),height(root_left->right))+1;
	root->height = max(height(root->left),height(root->right))+1;

	return root_left;
}

Node *leftRotate(Node* root)
{
	Node *root_right = root->right;
	Node *root_right_left = root_right->left;

	//rotation
	root_right->left = root;
	root->right = root_right_left;

	//update height

	root_right->height = max(height(root_right->left),height(root_right->right))+1;
	root->height = max(height(root->left),height(root->right))+1;

	return root_right;
}


Node *insert(Node *root, int data)
{
	if(root == NULL)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->height = 1; //new node added at leaf
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else if(root->data > data)
	{
		root->left = insert(root->left,data);
	}
	else if(root->data < data)
	{
		root->right = insert(root->right,data);
	}
	else
	{
		return root;
	}

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);

	//if this node becomes unbalanced then there are 4 cases

	//left left case
	if(balance > 1 and data < root->left->data)
	{
		return rightRotate(root);
	}

	//left right case 
	if(balance > 1 and data > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//right right case
	if(balance < -1 and data > root->right->data)
	{
		return leftRotate(root);
	}

	//right left case
	if(balance < -1 and data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;

	return root;
}

Node* minValNode(Node* root)
{
	Node* temp = root;

	while(temp!=NULL and temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

Node* del(Node* root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	else if(root->data > data)
	{
		root->left = del(root->left, data);
	}
	else if(root->data < data)
	{
		root->right = del(root->right, data);
	}
	else
	{
		//case-1 only one child or leaf node
		if(root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}

		Node* temp = minValNode(root->right);

		root->data = temp->data;

		root->right = del(temp, temp->data);
	}

	// If the tree had only one node 
    // then return  
    if (root == NULL)  
    	return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }

	return root;
}

void inOrder(Node *root)  
{  
    if(root != NULL)  
    {    
        inOrder(root->left);  
        cout << root->data << " ";
        inOrder(root->right);  
    }  
}  

int main(int argc, char const *argv[])
{
	root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
    root = insert(root, 6);  
    root = insert(root, 11);  
    root = insert(root, -1);  
    root = insert(root, 1);  
    root = insert(root, 2);  

    cout<<"Before Delete : ";
    inOrder(root);
    root = del(root, 10); 
   	cout<<"After Delete : ";
   	inOrder(root);
   	cout<<endl;

	return 0;
}

