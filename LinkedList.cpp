#include "LinkedList.h"


LinkedList::LinkedList() {
    length = 0;
}

LinkedList::LinkedList(const LinkedList &list) {

    Node* curr = list.head;

    while(curr != 0){
        this -> pushTail(curr->data);
        curr = curr -> next;
    }

}

LinkedList &LinkedList::operator=(const LinkedList &list) {

    Node* curr = this -> head;

    while(curr != 0){
        Node* temp = curr -> next;
        delete curr;
        curr = temp;
    }

    this -> head = 0;
    this -> tail = 0;

    curr = list.head;

    while(curr != 0){
        this -> pushTail(curr -> data);
        curr = curr -> next;
    }

    return *this;
}

void LinkedList::pushTail(Member data) {

    if(length == 0){
        tail = new Node(data);
        head = tail;
    }else{
        tail -> next = new Node(data);
        tail = tail -> next;

    }

    length++;
}

LinkedList::~LinkedList() {

    if(head){ delete head; }

    head = 0;
    tail = 0;

}
