#include <stdexcept>
using namespace std;

template <class E>
struct Node {
    Node<E> *next;
    E data;
};

template <class E>
class MyLinkedList {
    public:
        Node<E> *head;
        Node<E> *tail;
        int size;

        MyLinkedList() {
            this->head = new Node<E>;
            this->head->data = NULL;
            this->tail = new Node<E>;
            this->tail->data = NULL;
            this->head->next = this->tail;
            this->tail->next = NULL;
            this->size = 0;
        }

        int length() {
            return this->size;
        }

        E get(int index) {
            if (index < 0 || index >= this->size) 
                throw out_of_range("Index out of bounds");
            Node<E> *returnNode = this->getNth(index);
            return returnNode->data;
        }

        void add(E data) {
            this->add(data, this->size);
        }

        void add(E data, int index) {
            if (data == NULL)
                throw invalid_argument("Data cannot be NULL");
            if (index < 0 || index > this->size)
                throw out_of_range("Index out of bounds");
            Node<E> *curNode = this->head;
            for (int i = 0; i < index; i++) {
                curNode = curNode->next;
            }
            Node<E> *nextNode = curNode->next;
            Node<E> *toAdd = new Node<E>;
            toAdd->data = data;
            curNode->next = toAdd;
            toAdd->next = nextNode;
            this->size++;
        }

        E set(E data, int index) {
            if (data == NULL)
                throw invalid_argument("Data cannot be NULL");
            if (index < 0 || index >= this->size)
                throw out_of_range("Index out of bounds");
            Node<E> *setNode = this->getNth(index);
            E toReturn = setNode->data;
            setNode->data = data;
            return toReturn;
        }

        E remove(int index) {
            if (index < 0 || index >= this->size)
                throw out_of_range("Index out of bounds");
            Node<E> *prevNode = this->head;
            for (int i = 0; i < index; i++) {
                prevNode = prevNode->next;
            }
            Node<E> *curNode = prevNode->next;
            prevNode->next = curNode->next;
            this->size--;
            return curNode->data;
        }

        void clear() {
            this->head->next = this->tail;
            this->size = 0;
        }

        bool isEmpty() {
            if (this->size == 0) return true;
            return false;
        }

    private:
        Node<E> *getNth(int index) {
            if (index < 0 || index >= this->size)
                throw out_of_range("Index out of bounds");
            Node<E> *curNode = this->head->next;
            for (int i = 0; i < index; i++) {
                curNode = curNode->next;
            }
            return curNode;
        }
};