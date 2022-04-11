#include<bits\stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    node(int a)
    {
        data=a;
        left=right=NULL;
    }
};
// by using one queue and one stack 
void print_tree_spiral_form(node *root)
{
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    node *crnt;
    cout<<root->data<<endl;
    while(q.size()>0)
    {
        int count=q.size();
        
        for(int i=0;i<count;i++)
        {
            crnt=q.front();
            q.pop();
            if(crnt->left!=NULL) 
            {q.push(crnt->left);
            s.push(crnt->left);}
            if(crnt->right!=NULL)
            { q.push(crnt->right);
            s.push(crnt->right);} 
        }
        while (!s.empty())
        {
            crnt = s.top();
            cout<<crnt->data<<" ";
            s.pop();
        }
        
        cout<<endl;
    }
}
// by using two stack
void print_tree_spiral_form2(node *root)
{
    stack<node*> s1,s2;
    s1.push(root);
    node *crnt;
    while(!s1.empty())
    {
        while(!s1.empty())
        {
            crnt=s1.top();
            s1.pop();
            cout<<crnt->data<<" ";
            if(crnt->left!=NULL) s2.push(crnt->left);
            if(crnt->right!=NULL) s2.push(crnt->right);
        }
        cout<<endl;
        while(!s2.empty())
        {
            crnt=s2.top();
            cout<<crnt->data<<" ";
            s2.pop();
            if(crnt->left!=NULL) s1.push(crnt->left);
            if(crnt->right!=NULL) s1.push(crnt->right);
        }
        cout<<endl;

    }
}
int main()
{
    node *root=new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right=new node(4);
    root->right=new node(12);
    root->right->left=new node(7);
    // print_tree_spiral_form(root);
    print_tree_spiral_form2(root);
    return 0;
}

