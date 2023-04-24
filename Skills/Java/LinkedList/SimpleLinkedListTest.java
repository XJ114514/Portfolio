public class SimpleLinkedListTest {

    public static void main(String[] args) {
        
        //create an empty list
        SimpleLinkedList numbers = new SimpleLinkedList();

        
        //append 3 integers
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        
        //dump the contents in the list in the original order
        System.out.println(numbers);
        System.out.println(numbers.indexOf(30));

        //test removeByIndex();
        System.out.println(numbers.removeByIndex(1));
        System.out.println(numbers);

        //test add();
        numbers.add(1,29);
        numbers.add(39);
        System.out.println(numbers);

        //test contains();
        System.out.println("Is the list contains 29? " + numbers.contains(29));
        System.out.println("Is the list contains 20? " + numbers.contains(20));

        //test removeByValue() and size()
        numbers.removeByValue(39);
        System.out.println(numbers);
        System.out.println(numbers.size());

        //test get();
        System.out.println(numbers.get(2));
    }
    
}
