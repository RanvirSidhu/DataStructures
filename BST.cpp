
#include <iostream>

using namespace std;

class BST
{
    public:
    int data;
    BST *right;
    BST *left;
};

BST* insert(BST *root,int value)
{
    if(root==NULL)
    {
        root=new BST();
        root->data=value;
        root->left=NULL;
        root->right=NULL; 
    }
    else
    {
        if(value<root->data)
        {
            root->left=insert(root->left,value);
        }
        else
        {
            root->right=insert(root->right,value);
        }
    }
}

void inorder(BST *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

BST* min(BST* root)
{
    if(root->left==NULL)
    {
        cout<<root->data;
        return root;
    }
    min(root->left);
}

BST* deletion(BST* root,int value)
{
    if(root==NULL)
    {
    }
    else
    {
        if(value<root->data)
        {
            root->left=deletion(root->left,value);
        }
        else if(value>root->data)
        {
            root->right=deletion(root->right,value);
        }
        else
        {
            if(root->left==NULL)
            {
                BST* tmp=root->right;
                delete root;
                return tmp;
            }
            else if(root->right==NULL)
            {
                BST* tmp=root->left;
                delete root;
                return tmp;
            }
            else
            {
                BST* tmp=min(root->right);
                root->data=tmp->data;
                deletion(root->right,tmp->data);
            }
        }
    }
}

int main()
{
    BST* root=NULL;
    root=insert(root,20);
    insert(root,10);
    insert(root,12);
    insert(root,8);
    insert(root,15);
    insert(root,19);
    inorder(root);
    deletion(root,8);
    cout<<endl;
    inorder(root);
    delete root;
    return 0;
}
