

import java.io.FileInputStream;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

/**
 * @author Your name
 */
public class ReadBinaryTreeTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BinaryTree<String> binaryTree1 = new BinaryTree<>();

        try {
            //1. Create a Scanner for reading from the data file WordBT_Data.txt
            Scanner scanner01 = null;
            try{
                scanner01= new Scanner(new File("Assignment06/WordBT_Data.txt"));

            }catch (FileNotFoundException e){
                e.printStackTrace();
            }
            //2. call the static method readBinaryTree(....) to 
            BinaryTree<String> binaryTree01 = binaryTree1.readBinaryTree(scanner01);

            //3. call each method implemented and verify the result.
            System.out.println(binaryTree01);
            System.out.println("________________________________");

            System.out.println("preOrder: " + binaryTree01.preOrderTraverse());
            System.out.println("inOrder: " + binaryTree01.inOrderTraverse());
            System.out.println("postOrder: " + binaryTree01.postOrderTraverse());

            System.out.println("size: "+binaryTree01.size());
            System.out.println("height: "+binaryTree01.height());
            
            //---Assignment End -------//
                       
            
            //the code below was given in the lectures and will be helpful for you.
            
            
            //create a Scanner object that is associated with the file Fig_6_12.txt.
            Scanner input = new Scanner(new File("Assignment06/Fig_6_12.txt"));
            //call the static method readBinaryTree1 to read data in Fig_6_12.txt
            //   and construct the corresponding binary tree
            //   and assign the reference to this tree to binaryTree1.
            binaryTree1 = BinaryTree.readBinaryTree(input);
            //close the scanner object.
            input.close();
            //print the string, which is the preorder traversal sequence of data stored in binaryTree1.
            System.out.println(binaryTree1.toString());
        } catch (FileNotFoundException e) { //handle the case when Fig_6_12.txt is not found.
            e.printStackTrace();    //Print the error stack: this exception, and its backtrace for the cause of this exception.
            System.exit(1);         //terminate this program with the status code 1, indicating abnormal termination.
        }
    }

}
