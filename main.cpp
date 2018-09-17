#include <iostream>
#include<stdlib.h>
using namespace std;

struct BTNODE
{
    int value;
    BTNODE *leftChild;
    BTNODE *rightChild;
};

void insert(BTNODE **root)
{
    BTNODE *curr;
    curr=(struct BTNODE*)malloc(sizeof(struct BTNODE));
    cout<<"Enter Value"<<endl;
    cin>>curr->value;
    curr->leftChild=NULL;
    curr->rightChild=NULL;

    if(*root==NULL)
    {
        *root=curr;
        return;
    }
    else
    {
        BTNODE *prev=*root;

        /*while(prev->leftChild==NULL && prev->rightChild==NULL)
        {
            if(curr->value<=prev->value)
            {
                prev->leftChild=curr;
            }
            else if(curr->value>prev->value)
            {
                prev->rightChild=curr;
            }
        }*/

        while(prev->leftChild!=NULL && prev->rightChild!=NULL)
        {
            if(curr->value<prev->value)
            {
                prev=prev->leftChild;
            }
            else if(curr->value>prev->value)
            {
                prev=prev->rightChild;
            }
        }
        if(curr->value<=prev->value)
            {
                prev->leftChild=curr;
            }
            else if(curr->value>prev->value)
            {
                prev->rightChild=curr;
            }
    }

}
void display(BTNODE **root)
{
    BTNODE *prev=*root;
    if((*root)->value!=NULL)
    {
        cout<<"Value: "<<(*root)->value<<endl;
    }
}

void search(BTNODE *root,int val)
{
    if(root==NULL)
    {
        cout<<"Value NOT found "<<endl;
        return;
    }

    else if(val<root->value)
        {
            if(val==root->value)
            {
                cout<<"value found"<<endl;
                return;
            }
            search(root->leftChild,val);
        }


    else
        {
            if(val==root->value)
            {
                cout<<"value found"<<endl;
                return;
            }
            search(root->rightChild,val);
        }
    }


int main()
{
    BTNODE *root=NULL;
    insert(&root);
    insert(&root);
    insert(&root);
    cout<<"Display"<<endl;
    cout<<root->value<<endl;
cout<<root->rightChild->value<<endl;
cout<<root->leftChild->value<<endl;
search(root,9);
}
