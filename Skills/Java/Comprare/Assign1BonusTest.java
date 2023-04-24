/** Assign 1 Bonus Part - Write a Java generic method.
 * @author Cindy
 */
public class Assign1BonusTest {

    public static void main(String[] args) {
        //You do not need to change the code inside main(...)
        //They are provided for you to test your own solution.

        //It does not have "cookie" in the given code, I add the code
        //There is also one typo - "choclate" instead of "chocolate"
        String[] sweets = {"cake", "chocolate", "donut","cookie"};
        Integer[] numbers = {10, 20, 30, 40};

        
        //When you add your method, uncomment the following three lines.
        contains(sweets, "donut");  //should print Found

        //it should not print Found in the case that sweets does not contain cookie in the gived codes.
        contains(sweets, "cookie"); //should print Found
        contains(numbers, 100);     //should print Not Found

    }
    
    //Assign 1 Bonus Part Task:
    //Write a Java generic method named contains that takes in two parameters:
    //
    //A variable named anyArray that is an array of any type, and
    //A variable named anyValue that is of the same type as the element of anyArray.
    //
    //The method checks if anyValue is in anyArray. If yes, the method prints the message Found and return true.
    //
    //Otherwise, the method prints the message Not Found and returns false.

    //add your generic method here
    //Hints
    //- your method is a static method like checkEqual(...), printGenericArray(...) in Lec 2 Notes: GenericMethodTest.java.
    //- first write a non-static method taking in non-generic type, such as a String array, and a String.
    //-   And test your code using the given code in main(...)
    //- then change the non-generic method to generic method.
    //- test your generic method using the given code in main(...)
    public static <T> boolean contains(T[] anyArray,T anyValue){
        for (T value: anyArray) {
            if(anyValue.equals(value)){
                System.out.println("Found");
                return true;
            }
        }
        System.out.println("Not Found");
        return false;
    }
    
}
