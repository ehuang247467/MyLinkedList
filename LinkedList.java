public class LinkedList<E> {
    private Node head, tail;
    private int size;

    public LinkedList() {
        this.head = new Node(null);
        this.tail = new Node(null);
        this.head.setNext(this.tail);
        this.tail.setNext(null);
        this.size = 0;
    }

    public int length() {
        return this.size;
    }

    public Node get(int index) {
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException();
        Node returnNode = this.getNth(index);
        return returnNode;
    }

    private Node getNth(int index) {
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException();
        Node curNode = this.head.getNext();
        for (int i = 0; i < index; i++) {
            curNode = curNode.getNext();
        }
        return curNode;
    }

    private class Node {
        E data;
        Node next;

        public Node(E data) {
            this.data = data;
            this.next = null;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public void setElement(E element) {
            this.data = element;
        }
        
        public Node getNext() {
            return this.next;
        }

        public E getElement() {
            return data;
        }
    }
}