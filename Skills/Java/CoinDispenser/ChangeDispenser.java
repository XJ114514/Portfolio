import java.util.ArrayList;
import java.util.Scanner;

public class ChangeDispenser {

    //public wrapper
    //NOTE - your wrapper method does NOT have to be a void method.

    /**
     * It will print the coins changes according to amount enter
     * @param amount amount of money
     * @return true if the changes are successfully changed/printed
     *         false if the amount of money is negative
     *
     */
    public static boolean makeChange(int amount) {
        if(amount < 0){
            return false;
        }
        //add your code
        ArrayList<Integer> coinValue = new ArrayList<>();
        coinValue.add(100);
        coinValue.add(50);
        coinValue.add(25);
        coinValue.add(10);
        coinValue.add(5);
        coinValue.add(1);

        return makeChange(coinValue,0,amount);

        //Hints:
        //Use a list to store the denomination values of coins in decreasing order.
	//Use a second list to store the names of coins in the same order as their denomination value list.
      
        //call the private recursive counterpart and pass the corresponding
        //   arguments.
    }

    /**
     *
     * @param coinValue a list storing coin values in decreasing order
     * @param index indicator of coin value
     * @param amount amount of money
     * @return true if it prints out successfully
     */
    private static boolean makeChange(ArrayList<Integer> coinValue,int index,int amount){
        if(amount == 0 && index == 5){
            return true;
        }
        //get the count of current coin
        int count = amount/coinValue.get(index);
        //update the amount to what is remained.
        amount = amount % coinValue.get(index);

        //print the current coin change
        switch (index){
            case 0:
                //dollar
                if(count > 1){
                    System.out.println(count+" DOLLARS");
                }else{
                    System.out.println(count+" DOLLAR");
                }
                break;
            case 1:
                //half dollar
                if(count > 1){
                    System.out.println(count+" HALF_DOLLARS");
                }else{
                    System.out.println(count+" HALF_DOLLAR");
                }
                break;
            case 2:
                //quarter
                if(count > 1){
                    System.out.println(count+" QUATERS");
                }else{
                    System.out.println(count+" QUATER");
                }
                break;
            case 3:
                //dime
                if(count > 1){
                    System.out.println(count+" DIMES");
                }else{
                    System.out.println(count+" DIME");
                }
                break;
            case 4:
                //nickel
                if(count > 1){
                    System.out.println(count+" NICKELS");
                }else{
                    System.out.println(count+" NICKEL");
                }
                break;
            case 5:
                //penny
                if(count > 1){
                    System.out.println(count+" PENNIES");
                }else{
                    System.out.println(count+" PENNY");
                }
                return true;
        }
        return makeChange(coinValue,++index,amount);
    }


    //private recursive counterpart
    //NOTE - your recursive method does NOT have to be a void method.
    // example:
    // private static void makeChange(parameter list) {
    //   HintS -
    //       Your recursive method uses the coin value list and the coin name list. 
    //       In each call to the recursive method, the count of the first coin in the list 
    //          (coin in largest denomination value) is calculated and printed out. 
    //       Then the first coin is removed from the lists. 
    //       The remaining amount of money is calculated. 
    //       The coin lists and the remaining amount are passed to the next recursive call. 
    //       The recursion ends when no money is left.
    //}
    
    public static void main(String[] args) {
        //prompt the user to enter the amount in dollars and cents
        //get the amount
        //call the public wrapper method
        double amount = -1;
        do {
            java.util.Scanner s = new Scanner(System.in);

            //after user used the program first time, print this prompt.
            if(amount >= 0) {
                System.out.println("\nTo exit, please input negative number.");
            }
            System.out.print("Enter the money amount in dollars and cents: $");
            amount = s.nextDouble();

            //after user entered a negative amount to end the program, print this prompt.
            if(amount<0) {
                System.out.println("Thank you for using this program!");
            }
        //loops end if the amount is negative.
        }while(makeChange((int)(amount*100)));
        
        //NOTE -
        // test your code using $2.91, $0.91, $0.78, $0
//        makeChange(2.91);
//        makeChange(0.91);
//        makeChange(0.78);
//        makeChange(0);
    }

}
