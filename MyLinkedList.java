public class MyLinkedList<E> {
    private Node head, tail;
    private int size;

    public MyLinkedList() {
        this.head = new Node(null);
        this.tail = new Node(null);
        this.head.setNext(this.tail);
        this.tail.setNext(null);
        this.size = 0;
    }

    public int length() {
        return this.size;
    }

    public E get(int index) {
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException("Index out of bounds");
        Node returnNode = this.getNth(index);
        return returnNode.getData();
    }

    public void add(E data) {
        this.add(data, this.size);
    }

    public void add(E data, int index) {
        if (data == null) 
            throw new NullPointerException("Data cannot be Null");
        if (index < 0 || index > this.size) 
            throw new IndexOutOfBoundsException("Index out of bounds");
        Node curNode = this.head;
        for (int i = 0; i < index; i++) {
            curNode = curNode.getNext();
        }
        Node nextNode = curNode.getNext();
        curNode.setNext(new Node(data));
        curNode.getNext().setNext(nextNode);
        this.size++;
    }

    public E set(E data, int index) {
        if (data == null)
            throw new NullPointerException("Data cannot be Null");
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException("Index out of bounds");
        Node setNode = this.getNth(index);
        E toReturn = setNode.getData();
        setNode.setData(data);
        return toReturn;
    }

    public E remove(int index) {
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException("Index out of bounds");
        Node prevNode = this.head;
        for (int i = 0; i < index; i++) {
            prevNode = prevNode.getNext();
        }
        Node curNode = prevNode.getNext();
        prevNode.setNext(curNode.getNext());
        this.size--;
        return curNode.getData();
    }

    public void clear() {
        this.head.setNext(this.tail);
        this.size = 0;
    }

    public boolean isEmpty() {
        if (this.size == 0) return true;
        return false;
    }
    
    private Node getNth(int index) {
        if (index < 0 || index >= this.size) 
            throw new IndexOutOfBoundsException("Index out of bounds");
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

        public void setData(E data) {
            this.data = data;
        }

        public Node getNext() {
            return this.next;
        }

        public E getData() {
            return data;
        }
    }
}