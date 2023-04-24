
public class BinarySearchTreeTest3 {

    public static void main(String[] args) {
        //create an empty binary search tree
        BinarySearchTree<Integer> bstNumbers = new BinarySearchTree<Integer>();
        int[] numbers = {41,  50,  24,  37,  13,  84, 27, 34};  
        //populate the binary search tree        
        for (int i = 0; i < numbers.length; i++) {
            bstNumbers.add(numbers[i]);            
        }
        
        System.out.println("---------------------");
        System.out.println("Before deleting 24 using delete2(E)");
        //display the data and structure of the binary search tree before the deletion
        System.out.println(bstNumbers);
        
        System.out.println("---------------------");
        //delete a number using delete2 method
        bstNumbers.delete2(24);
        
        System.out.println("After deleting 24 using delete2(E)");
        //display the data and structure of the binary search tree after the deletion        
        System.out.println(bstNumbers);
        System.out.println("---------------------");
    }        
}

