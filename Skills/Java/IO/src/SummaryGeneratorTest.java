//This class tests the implementation of SummaryGenerator class.
//It creates a BufferedReader to read from the data file purchases.csv,
//  creates an object of SummaryGenerator,
//  uses this object to call createCountsByCountry method and pass 
//     the BufferedReader object br to this method,
//  uses this object to call showCountsByCountry method, which displays the summary.


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SummaryGeneratorTest {

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("Assignment07/purchases.csv"));
            SummaryGenerator summaryGenerator = new SummaryGenerator();
            summaryGenerator.createCountsByCountry(br);
            summaryGenerator.showCountsByCountry();
        } catch (IOException ioe) {
            System.out.println("file input error.");
            ioe.printStackTrace();
            System.exit(1);
        }
    }

}

