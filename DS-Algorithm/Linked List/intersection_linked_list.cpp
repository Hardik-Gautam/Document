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

node *intersection_point(node *head, node *head2)
{
    int len1=0;
    int len2=0;
    node *h = head;
    node *hh= head2; 
    while(h!=NULL)
    {
        len1++;
        h=h->next;
    }
    while (hh!=NULL)
    {
        len2++;
        hh=hh->next;
    }

    int m = abs(len1-len2==0);
    m = (m==0)?len1/2:m;
    int i=0;
    while(i<m)
    {
        head=head->next;
        i++;
    }
    return head;
}
int main()
{
    node *intsct;
    node *head2;
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    intsct=head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    
    node *t;
    head2 = new node(13);
    head2->next = new node(12);
    head2->next->next = new node(11);
    head2->next->next->next = intsct;
    
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    while(head2!=intsct)
    {
        cout<<head2->data<<" ";
        head2=head2->next;
    }
    
    node * rs = intersection_point(head,head2);

    return 0;
}