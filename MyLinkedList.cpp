#include <stdexcept>
using namespace std;

template <class E>
class MyLinkedList {
    private:
        class Node {
            private:
                Node *next;
                E data;
            public:
                Node(E data);
                void setNext(Node *next);
                void setData(E data);
                Node *getNext();
                E getData();
        };

        Node *head;
        Node *tail;
        int size;
        Node *getNth(int index);
        
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

template<class E>
MyLinkedList<E>::MyLinkedList() {
    this->head = new Node(NULL);
    this->tail = new Node(NULL);
    this->head->setNext(this->tail);
    this->tail->setNext(NULL);
    this->size = 0;
}

template <class E>
int MyLinkedList<E>::length() {
    return this->size;
}

template <class E>
E MyLinkedList<E>::get(int index) {
    if (index < 0 || index >= this->size) 
        throw out_of_range("Index out of bounds");
    Node *returnNode = this->getNth(index);
    return returnNode->getData();
}

template <class E>
void MyLinkedList<E>::add(E data) {
    this->add(data, this->size);
}

template <class E>
void MyLinkedList<E>::add(E data, int index) {
    if (data == NULL)
        throw invalid_argument("Data cannot be NULL");
    if (index < 0 || index > this->size)
        throw out_of_range("Index out of bounds");
    Node *curNode = this->head;
    for (int i = 0; i < index; i++) {
        curNode = curNode->getNext();
    }
    Node *nextNode = curNode->getNext();
    Node *toAdd = new Node(data);
    curNode->setNext(toAdd);
    curNode->getNext()->setNext(nextNode);
    this->size++;
}

template <class E>
E MyLinkedList<E>::set(E data, int index) {
    if (data == NULL)
        throw invalid_argument("Data cannot be NULL");
    if (index < 0 || index >= this->size)
        throw out_of_range("Index out of bounds");
    Node *setNode = this->getNth(index);
    E toReturn = setNode->getData();
    setNode->setData(data);
    return toReturn;
}

template <class E>
E MyLinkedList<E>::remove(int index) {
    if (index < 0 || index >= this->size)
        throw out_of_range("Index out of bounds");
    Node *prevNode = this->head;
    for (int i = 0; i < index; i++) {
        prevNode = prevNode->getNext();
    }
    Node *curNode = prevNode->getNext();
    prevNode->setNext(curNode->getNext());
    this->size--;
    return curNode->getData();
}

template <class E>
void MyLinkedList<E>::clear() {
    this->head->setNext(this->tail);
    this->size = 0;
}

template <class E>
bool MyLinkedList<E>::isEmpty() {
    if (this->size == 0) return true;
    return false;
}

template <typename E>
typename MyLinkedList<E>::Node *MyLinkedList<E>::getNth(int index) {
    if (index < 0 || index >= this->size)
        throw out_of_range("Index out of bounds");
    Node *curNode = this->head->getNext();
    for (int i = 0; i < index; i++) {
        curNode = curNode->getNext();
    }
    return curNode;
}

template <class E>
MyLinkedList<E>::Node::Node(E data) {
    this->data = data;
    this->next = NULL;
}

template <class E>
void MyLinkedList<E>::Node::setNext(Node *next) {
    this->next = next;
}

template <class E>
void MyLinkedList<E>::Node::setData(E data) {
    this->data = data;
}

template <class E>
class MyLinkedList<E>::Node *MyLinkedList<E>::Node::getNext() {
    return this->next;
}

template <class E>
E MyLinkedList<E>::Node::getData() {
    return this->data;
}