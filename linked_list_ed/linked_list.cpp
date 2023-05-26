#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Typedef nodes
struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode* create_node(int node_data){
    SinglyLinkedListNode* p = new SinglyLinkedListNode();
    p -> data = node_data;
    p -> next = nullptr;
    return p;
}

SinglyLinkedListNode* CreateLinkedList(int n){
    
    SinglyLinkedListNode* head = nullptr;
    SinglyLinkedListNode* tail = nullptr;
    

    for (int i = 0; i< n; i++){
        int data;
        cin >> data;
        SinglyLinkedListNode* new_node = create_node(data);
        if( head == nullptr){
            head = new_node;
            tail = new_node;
        }
        else{
            
            tail -> next = new_node;
            tail = new_node;
        }
    }
    
    return head;
}

void output(SinglyLinkedListNode* p){
    SinglyLinkedListNode* temp = p;
    while(temp != NULL){
        cout << temp -> data;
        temp = temp -> next;
    }
}

void reversePrint(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *reverse;
    
    reverse = llist;
    while (llist -> next != NULL){
        reverse -> next = reverse;
        llist = llist -> next;
        reverse = llist;
    }
    
    output(reverse);
}    
int main(){
    SinglyLinkedListNode* head = nullptr;
    int llist_count;
    cin >> llist_count;

    head = CreateLinkedList(llist_count);
    reversePrint(head);
    return 0;
}