				// find min-max
				// find height

#include <iostream>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;
struct bstnode
{
	int data;
	bstnode *left;
	bstnode *right;
};
bstnode *getnewnode(int data)
{
	bstnode* root = new bstnode();
	root->data = data;
	root->right = NULL;
	root->left = NULL;
	return root; 
}
// to find min
bstnode *min(bstnode *root)
{
	if(root->left == NULL)
		return root;
	else
		return min(root->left);
}
int countLeaves(bstnode *root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return (countLeaves(root->left) + countLeaves(root->right));
}
bstnode *insert(bstnode *root ,int data)
{
	if(root == NULL)
	{
		root = getnewnode(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right,data);
	}
	return root;	
}
int height(bstnode *root)
{
	if(root == NULL)
		return -1;
	int rleft = height(root->left);
	int rright = height(root->right);
	return max(rleft,rright)+1;
}
void levelorder(bstnode *root)
{
	if(root == NULL)
		return;
	queue<bstnode*>q;
	q.push(root);
	while(!q.empty())
	{
		bstnode *t = q.front();
		cout << t->data << " ";
		if(t->left != NULL)
			q.push(t->left);
		if(t->right != NULL)
			q.push(t->right);
		q.pop();
	}
	cout << endl;
}
void preorder(bstnode *root)
{
	if(root == NULL)
		return ;
	cout << root->data << endl;
	if(root->left != NULL)
		preorder(root->left);
	if(root->right != NULL)
		preorder(root->right);
}
void inorder(bstnode *root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		inorder(root->left);
	cout << root->data << endl;
	if(root->right != NULL)
		inorder(root->right);
}
static bstnode *prev = NULL; 
int is_bst( bstnode* root)
{
   
   if (root)
    {
        if (!is_bst(root->left)) //moves towards the leftmost child of the tree and checks for the BST
         return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;

        return is_bst(root->right);    //moves the corresponding right child of the tree and checks for the BST
	}
	return 1;
}
bool search(bstnode *root,int val)
{
	if(root == NULL)
		return false;
	else if(root->data == val)
		return true;
	else if(val < root->data)
	{
		return search(root->left,val);
	}
	else if(val > root->data)
	{
		return search(root->left,val);
	}
}
bstnode* Delete(bstnode* root,int data)
{
	if(root == NULL)
		return root;
	else if(data < root->data){root->left = Delete(root->left,data);}
	else if(data > root->data){root->right = Delete(root->right,data);}
	else
	{
		// case 1: no child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// case 2 : one child
		else if(root->left != NULL)
		{
			bstnode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right != NULL)
		{
			bstnode *temp = root;
			root = root->left;
			delete temp;
		}
		// 3 rd case both present
		else
		{
			bstnode *temp = min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int countfullnodes(bstnode *root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 0;
	return countfullnodes(root->left) + countfullnodes(root->right) + ((root->left && root->right)?1:0);
}
int identicalTrees(bstnode* a, bstnode* b)
{
    if (a==NULL && b==NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
} 
int main()
{
	bstnode *root = NULL;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,8);
	root = insert(root,12);
	root = insert(root,17);
	root = insert(root,25);
	return 0;
}