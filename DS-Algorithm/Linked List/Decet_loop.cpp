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
node *loop_decet(node *head)
{
    if(head==NULL||head->next==NULL)
        return head;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
         if(slow==fast)
            break;
    }
    slow=head;
    while (slow!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        if(slow==fast)
            return fast;
    }
    
    return head;
}
int main()
{
    node *loop;
    node *head = new node(1);
    head->next = new node(2);
    loop = head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    head->next->next->next->next->next->next->next = loop; // LOOP

    head = loop_decet(head);
    cout<<"Loop in Node No:"<<head->data<<endl;
    
    

    return 0;
}