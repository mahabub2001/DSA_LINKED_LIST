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
node *push(node *head , int newData){
        node *newNode = new node();
        newNode -> data = newData;
        newNode ->next = head;
        head = newNode;
        return head;
    }

void insertAfter(node *prev_node, int newData){
        node *newNode = new node();
        newNode -> data = newData;
        newNode -> next = prev_node -> next;
        prev_node -> next = newNode;

}

void append(node **head_ref,int newData){
        node *newNode = new node();
        newNode -> data = newData;
        newNode -> next = NULL;
        node *last = *head_ref;

        if(*head_ref == NULL){
            *head_ref = newNode;
            return;
        }

        while(last->next != NULL){
            last = last ->next;
        }
        last->next = newNode;
        return;
}


int main()
{
    node *head = NULL;
    head = push(head,5);
    head = push(head,8);
    head = push(head,258);

    append(&head,9);
    insertAfter(head->next,45);
    printList(head);

}
