//It is a simple implementation of Linked List.


public class SimpleLinkedList {

    //Remove the first occurrence of the specified item from this linked list. 
    // If success, return true. Otherwise, return false.
    public boolean removeByValue(int item) {
        int index = indexOf(item);
        if(index == -1) {
            System.out.println("The item is not found in the list.");
            return false;
        }
        Node current = head;
        Node prev = null;
        //when index equals 0, the item is in head
        //remove head
        if(index == 0){
            current.next = null;
            return true;
        }
        //in other case, update the current and prev node
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current.next;
        }
        //remove the current node
        prev.next = current.next;
        current.next = null;
        return true;
    }

    //add item to be at [index];
    // if index is [0, size-1], insert item between [index-1] and [index]
    // if index is size, append item to the end of this linked list.
    public void add(int index, int item) {
        if(size() ==0){
            System.out.println("The list is empty!");
            return;
        }
        Node prev = null;
        Node temp = head;
        //update the temp to the target node according to index
        for (int i = 0; i < index; i++) {
            prev = temp;
            temp = temp.next;
        }
        //"insert" the node
        Node newNode = new Node(item,temp);
        prev.next = newNode;

    }

    //Get the integer item at the specified position and return the integer value. 
    //If the index is not valid, throw an exception or print an error message 
    //  and return Integer.MIN_VALUE.
    public int get(int index) {
        if(index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Index need to be wihtin (0,size)");
        }
        if(size() ==0){
            System.out.println("The list is empty!");
            return -1;
        }
        Node temp = head;
        //update the temp to the target node according to index
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }

        return temp.data;
    }

    //Search this linked list for the first occurrence of the specified integer: item. 
    //If the item is found, return its index. Otherwise return -1.
    public int indexOf(int item) {

        if(size() ==0){
            System.out.println("The list is empty!");
            return -1;
        }
        Node temp = head;
        int index = 0;
        do{
            //if the item is found in the temp node, return its index
            if(temp.data == item){
                return index;
            }
            //update the temp node and index to next node.
            temp = temp.next;
            index++;
        } while(temp != null);
        //If loop ends, it has not yet return any value. The item does not exist in the list.
        return -1;
    }

    //Find out if the specified integer: item is in this linked list. 
    // Returns true if yes, false otherwise.
    public boolean contains(int item) {
        if(size() ==0){
            System.out.println("The list is empty!");
            return false;
        }
        //if indexOf(item) return -1, then the list does not contain the item.
        if(indexOf(item)  == -1){
            return false;
        }
        return true;
    }

    //return how many integers are in this linked list
    public int size() {
        //return 0 if the list is empty.
        if(head == null){
            return 0;
        }
        Node temp = head;
        int size = 1;
        //update the size until it reaches the end of list.
        while(temp.next != null){
            temp = temp.next;
            size++;
        }
        return size;
    }

    //-----Bonus ---------------//
    //Remove the item at the specified position from this linked list and 
    //  return the removed item.
    //If the index is not valid, throw an exception or print an error message 
    //   and return Integer.MIN_VALUE.
    public int removeByIndex(int index) {
        //Add your own code
        if(index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException("Index need to be wihtin (0,size)");
        }
        Node current = head;
        Node prev = null;
        //when index equals 0, the item is in head
        //remove head
        if(index == 0){
            current.next = null;
            return current.data;
        }

        //in other case, update the current and prev node
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current.next;
        }
        //remove the current node
        prev.next = current.next;
        current.next = null;
        return current.data;
    }

    
    //Following code were covered in Lec#6. 
    //Don't change them.
    //Nested class Node, enclosing class: SimpleLinkedList
    private static class Node {

        private int data;
        private Node next;

        private Node(int data) {
            this.data = data;
            next = null;
        }
        
        //constructor used to create a Node that has a following neighbor
        private Node(int dataNew, Node nextNew) {
            data = dataNew;
            next = nextNew;
        }

        @Override
        public String toString() {
            return data + "";  //"10"
        }        
    }

    //the reference to the first Node in this linked list.
    private Node head;
    //the size of this linked list
    private int size;

    //create an empty linked list
    public SimpleLinkedList() {
        head = null;
        size = 0;
    }

    //append newItem
    public boolean add(int newItem) {
        Node temp = new Node(newItem);
        if (head == null) { //empty list
            head = temp;
        } else { //non-empty list
            //locate last node
            Node current = head;    //start with the first node
            while (current.next != null) {  //check if current node is not the last node
                current = current.next;     //move on to the next node on the list
            }
            current.next = temp;    //append the new node immediately following the current node
        }
        size++;
        return true;
    }

    //return a string that contains all integers (in the original sequence) in the linked list.
    @Override
    public String toString() {
        String result = "";     //result string
        Node current = head;        //start with first Node
        while (current != null) {   //check if there is still nodes remaining
            result += current.data; //add the integer in current Node to the result string
            result += "-->";
            current = current.next; //move on to the next Node
        }
        return result;
    }
}
