#include"bits/stdc++.h"
using namespace std;

struct Node
{
	int data,height;
	Node *left, *right;
};
struct Node* root = NULL;

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
	root = insert(root, 50);  
    root = insert(root, 40);  
    root = insert(root, 70);  
    root = insert(root, 60);  
    root = insert(root, 80);
    root = insert(root, 75);  
    root = insert(root, 85);  
    root = insert(root, 90);  

    cout<<"Before Delete : ";
    inOrder(root);
    root = del(root,16);
   	cout<<"After Delete : ";
   	inOrder(root);
   	cout<<endl;

	return 0;
}

