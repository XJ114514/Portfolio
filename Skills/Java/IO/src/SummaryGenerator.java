//This class generates the data summary based on the data in the file purchases.csv
// and show such summaries. 
//Currently it only counts how many times each country appears.


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.List;
import java.util.Map;
import java.util.regex.PatternSyntaxException;

public class SummaryGenerator {


    private final String COMMA_DELIMITER = ",";
    Map<String,Integer> countsByCountryMap;

    // create a new HashMap or TreeMap for the data summary.
    public SummaryGenerator() {
        countsByCountryMap = new TreeMap<>();
//        countsByCountryMap = new HashMap<>();
    }      
    
    //takes in a BufferedReader object that is already associated with
    //   the file purchases.csv, read the data line by line,
    //   create the country summary and save the summary entries in the summary map.
    public void createCountsByCountry(BufferedReader br) {      
        //build country summary
        List<String> purchase = new ArrayList<>();
        try {
            //read the header and do nothing with it
            String line;
            br.readLine();
            //read line by line until file reading is completed
            while ((line = br.readLine()) != null) {
                //split values in each line using the delimiter comma,
                String[] fields = line.split(COMMA_DELIMITER);
                //convert the array to an ArrayList
                purchase = Arrays.asList(fields);
                //get country data
                String country = purchase.get(7);
                //update the item to the map
                if(countsByCountryMap.containsKey(country)){
                    int count = countsByCountryMap.get(country);
                    countsByCountryMap.put(country,++count);
                }else {
                    countsByCountryMap.put(country,1);
                }
            }
        } catch (IOException ioe) { 
            System.out.println("file input error.");
            ioe.printStackTrace();
            System.exit(1);
        } catch (PatternSyntaxException pse) {
            System.out.println("pattern specification error.");            
            pse.printStackTrace();
            System.exit(1);            
        }
    }

    //print the data in a certain format
    public void showCountsByCountry(){
        //print header
        System.out.println("Country                       Count \n" +
                "------------------------------------------------------------");
        //print data
        for (Map.Entry<String,Integer> mapEntry: countsByCountryMap.entrySet()) {
            System.out.printf("%-30s",mapEntry.getKey());
            printNChars('*',mapEntry.getValue());
            System.out.println();
        }
    }
    
    //print the character ch count number of times in one line
    private void printNChars(char ch, int count) {
        for (int i = 0; i < count; i++) {
            System.out.print(ch);
        }
    }
}