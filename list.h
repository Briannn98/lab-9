#ifndef MYLIST_H
#define MYLIST_H

class Node {
public:
    int value;
    Node* nextNode;
    Node* prevNode;

    Node(int v) {
        value = v;
        nextNode = nullptr;
        prevNode = nullptr;
    }
};

class List {
public:
    List();
    ~List();

    bool empty() const;

    void addFront(int v);
    void addBack(int v);

    int removeFront();
    int removeBack();

    void deleteValue(int v);
    bool find(int v) const;

    void showForward() const;
    void showBackward() const;

private:
    Node* first;
    Node* last;
};

#endif