#include<bits\stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
    node(int a)
    {
        data=a;
        next=NULL;
    }
};

node *reverse_list(node *head)
{
    node *crnt=head;
    node *prev=NULL;
    node *next=NULL;
    while(crnt!=NULL)
    {
        next = crnt->next;
        crnt->next = prev;
        prev = crnt;
        crnt=next;
    }   
    head = prev;
    return head;
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    node *t=head;
    
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
    head = reverse_list(head);
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
    return 0;
}