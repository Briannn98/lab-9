#include <iostream>
#include "list.h"

using namespace std;

List::List() {
    first = nullptr;
    last = nullptr;
}

List::~List() {
    while (!empty()) {
        removeFront();
    }
}

bool List::empty() const {
    return first == nullptr;
}

void List::addFront(int v) {
    Node* newNode = new Node(v);

    if (empty()) {
        first = last = newNode;
    } else {
        newNode->nextNode = first;
        first->prevNode = newNode;
        first = newNode;
    }
}

void List::addBack(int v) {
    Node* newNode = new Node(v);

    if (empty()) {
        first = last = newNode;
    } else {
        last->nextNode = newNode;
        newNode->prevNode = last;
        last = newNode;
    }
}

int List::removeFront() {
    if (empty()) {
        cout << "List is empty!" << endl;
        return -1;
    }

    Node* temp = first;
    int removedValue = temp->value;

    if (first == last) {
        first = last = nullptr;
    } else {
        first = first->nextNode;
        first->prevNode = nullptr;
    }

    delete temp;
    return removedValue;
}

int List::removeBack() {
    if (empty()) {
        cout << "List is empty!" << endl;
        return -1;
    }

    Node* temp = last;
    int removedValue = temp->value;

    if (first == last) {
        first = last = nullptr;
    } else {
        last = last->prevNode;
        last->nextNode = nullptr;
    }

    delete temp;
    return removedValue;
}

void List::deleteValue(int v) {
    Node* current = first;

    while (current != nullptr) {

        if (current->value == v) {

            if (current == first) {
                removeFront();
            }
            else if (current == last) {
                removeBack();
            }
            else {
                current->prevNode->nextNode = current->nextNode;
                current->nextNode->prevNode = current->prevNode;
                delete current;
            }
            return;
        }

        current = current->nextNode;
    }
}

bool List::find(int v) const {
    Node* temp = first;

    while (temp != nullptr) {
        if (temp->value == v)
            return true;

        temp = temp->nextNode;
    }

    return false;
}

void List::showForward() const {
    Node* temp = first;

    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->nextNode;
    }
    cout << endl;
}

void List::showBackward() const {
    Node* temp = last;

    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->prevNode;
    }
    cout << endl;
}