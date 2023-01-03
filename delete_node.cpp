#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void printList(node *n){
    int count=0;
    while(n!=NULL){
        cout<< n->data <<endl;
        n=n->next;
        count++;
    }
    cout<<"No. of element in linked list is: "<<count<<endl;
}

node *push(node *head,int newData){
    node *newNode = new node();
    newNode -> data = newData;
    newNode -> next = head;
    head = newNode;
    return head;
}

void deleteNode(node **head_ref,int key){
    node *prev, *temp;
    temp = *head_ref;

    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main()
{
    node *head = NULL;
    head = push(head,10);
    head = push(head,5);
    head = push(head,57);
    head = push(head,47);

    deleteNode(&head,5);
    printList(head);


}
