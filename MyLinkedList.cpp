#include <iostream>
#include <stdexcept>
using namespace std;
template <typename E>
class MyLinkedList {
    private:
        class Node {
            private:
                E data;
                MyLinkedList::Node *next;
            public:
                Node(E data);
                void setNext(Node next);
                void setData(E data);
                Node getNext();
                E getData();
        };
        Node *head;
        Node *tail;
        int size;
        Node getNth(int index);
    public:
        MyLinkedList();
        int length();
        E get(int index);
        void add(E data);
        void add(E data, int index);
        E set(E data, int index);
        E remove(int index);
        void clear();
        bool isEmpty();
};
template<typename E>
MyLinkedList<E>::MyLinkedList() {
    this->head = new Node(NULL);
    this->tail = new Node(NULL);
    this->head->setNext(*this->tail);
    this->tail->setNext(NULL);
    this->size = 0;
}
template <typename E>
int MyLinkedList<E>::length() {
    return this->size;
}
template <typename E>
E MyLinkedList<E>::get(int index) {
    if (index < 0 || index >= this->size) 
        throw out_of_range("Index out of bounds");
    Node returnNode = this->getNth(index);
    return returnNode.getData();
}
template <typename E>
void MyLinkedList<E>::add(E data, int index) {
    if (data == NULL)
        throw invalid_argument("Data cannot be NULL");
    if (index < 0 || index > this->size)
        throw out_of_range("Index out of bounds");
    Node curNode = this->head;
    for (int i = 0; i < index; i++) {
        curNode = curNode.getNext();
    }
    Node nextNode = curNode.getNext();
    curNode.setNext(new Node(data));
    curNode.getNext().setNext(nextNode);
    this->size++;
}
template <typename E>
typename MyLinkedList<E>::Node MyLinkedList<E>::getNth(int index) {
    if (index < 0 || index >= this->size)
        throw out_of_range("Index out of bounds");
    Node curNode = this->head->getNext();
    for (int i = 0; i < index; i++) {
        curNode = curNode.getNext();
    }
    return curNode;
}
template <typename E>
MyLinkedList<E>::Node::Node(E data) {
    this->data = data;
    this->next = NULL;
}
template <typename E>
void MyLinkedList<E>::Node::setNext(Node next) {
    this->next = &next;
}
template <typename E>
void MyLinkedList<E>::Node::setData(E data) {
    this->data = data;
}
template <typename E>
typename MyLinkedList<E>::Node MyLinkedList<E>::Node::getNext() {
    return *this->next;
}
template <typename E>
E MyLinkedList<E>::Node::getData() {
    return this->data;
}
int main() {
    MyLinkedList<int> *test = new MyLinkedList<int>();
    cout << test->get(0);
    return 0;
}