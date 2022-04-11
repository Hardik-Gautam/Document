#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = NULL;
    }
};

int Floyd_detect_cycl(node *head)
{
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast !=NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }

    slow = head;
    
    while(slow!=NULL)
    {
        if(slow==fast)
        return slow->next->data;
        slow = slow->next;
    }
    
    return -1;
}

int main()
{
    node *head = new node(1);
    head->next = new node(3);
    head->next->next = new node(5);
    head->next->next->next = new node(7);
    head->next->next->next->next = new node(9);

    // below line is represent the cycle between 3 to 9 node
    head->next->next->next->next->next = head->next;

    // head = NULL;

    cout<<"Cyclic Node: "<<Floyd_detect_cycl(head);   

    return 0; 
}