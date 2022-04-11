#include<bits\stdc++.h>
using namespace std;
struct node {
    node *left;
    node *right;
    int data;
    node(int a)
    {
        data=a;
        right=left=NULL;
    }

};
void LOT_line_by_line(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1) // q.size()>1 at then end only null will remain
    {
        node *crnt=q.front();
        q.pop();
    
        if(crnt==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<crnt->data<<" ";
        if(crnt->left!=NULL) q.push(crnt->left);
        if(crnt->right!=NULL) q.push(crnt->right);
    }
}
void LOT_line_by_line2(node *root)
{
    queue<node*> q;
    q.push(root);
    while(q.size()>0)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *crnt=q.front();
            q.pop();
            cout<<crnt->data<<" ";
            if(crnt->left!=NULL) q.push(crnt->left);
            if(crnt->right!=NULL) q.push(crnt->right);

        }
        cout<<endl;
    }
}
int main()
{
    node *root=new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->left=new node(60);
    root->right->right=new node(70);
    LOT_line_by_line(root);
    // LOT_line_by_line2(root);
    return 0;
}