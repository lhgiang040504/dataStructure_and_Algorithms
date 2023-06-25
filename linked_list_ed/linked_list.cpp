#include <bits/stdc++.h>
using namespace std;
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int d = 0, SinglyLinkedListNode* p = NULL) :
    data{d}, next{p} {}
};

class LinkedList {
private:
    int quantity;
    SinglyLinkedListNode* root;
public:
    LinkedList(SinglyLinkedListNode* p = NULL, int q = 0) : root(p), quantity(q) {}

    void Input() {
        SinglyLinkedListNode* curr = root;
        cin >> quantity;
        for (int i = 0; i < quantity; i++) {
            int value;
            cin >> value;

            if (!curr) {
                root = new SinglyLinkedListNode(value);
                curr = root;
            }
            else {
                curr->next = new SinglyLinkedListNode(value);
                curr = curr->next;
            }    
        }
    }

    void Output() {
        SinglyLinkedListNode* curr = root;
        
        while (curr!= nullptr){
            cout << curr->data << " " ;
            curr = curr->next;
        }
    }

    void ReveserDirection() {
        if (root == NULL || root->next == NULL)
            return; // Empty list or single node, no need to reverse

        SinglyLinkedListNode* curr = root;
        SinglyLinkedListNode* reverse = NULL;
        SinglyLinkedListNode* prev = NULL;

        while (curr != NULL) {
            reverse = curr;
            curr = curr->next;
    
            reverse->next = prev; 
            prev = reverse;
        }

        root = reverse;
    }

    bool Find(int data) {
        SinglyLinkedListNode* temp = root;
    
        while (temp != NULL) {
            if (temp -> data == data )
                return true;
            else 
                temp = temp-> next;
        }

        return false;
    }
};

int main() {
    LinkedList llist;
    llist.Input();
    llist.ReveserDirection();
    llist.Output();
    
    return 0;
}