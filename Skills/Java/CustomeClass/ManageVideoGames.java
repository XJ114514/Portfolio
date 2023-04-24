import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Date;
import java.util.List;
import java.util.LinkedList;
import java.util.Scanner;

public class ManageVideoGames {

    public static void main(String[] args) {
        
        VideoGame videoGame = new VideoGame("None","Me",new String[]{"1","2"},LocalDate.of(2020,9,15));
        System.out.println(videoGame);

        //create an empty list of VideoGames
        List<VideoGame> list = new LinkedList<>();
        int input = 0;

        do {
            //1. display menu
            displayMenu();

            //2. get user choice
            input = getUserChoice();


            //3. take action based on user choice
            switch (input){
                case 1:
                    //add new game
                    addGame(list,getNewGame());
                    break;
                case 2:
                    //remove game based on the user input title
                    removeGame(list);
                    break;
                case 3:
                    //display the game collection
                    for (VideoGame videogame:list) {
                        System.out.println(videogame+"\n");
                    }
                    break;
                case 4:
                    //Find and display the game with the latest release date
                    System.out.println("The game release most recently is :");
                    System.out.println(findLatestDate(list)+"\n");
                    break;
                case 5:
                    //add new game in alphabetic order
                    addGameOrdered(list);
                    break;
                default:
                    System.out.println("Thank you for using this program!");
            }

            // 4. loop through steps 1, 2, 3 above until user quits
        }while(input < 7  && input > 0);



    }

    //define other methods for modularization, samples are listed below.
    
    //method to display menu
    public static void displayMenu() {
        //add your code
        //display the menu like in Page 5 in Assign2-F21.pdf 
        System.out.println("-----Menu--------  \n" +
                "1. Add a new game  \n" +
                "2. Remove an existing game  \n" +
                "3. Display the games in the order they were inserted  \n" +
                "4. Find games with latest release  \n" +
                "5. Add a new game in the alphabetical order of game titles \n" +
                "6 or other number. Exit  ");
        
    }    
    
    //method to get user choice 
    public static int getUserChoice() {
        //add your code
        // keep reading user input until user enters correct input
        java.util.Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number to make your selection: ");
        int input = scanner.nextInt();
        
        return input;
    }    
    
    
    //method to get user input, create and return a video game
    public static VideoGame getNewGame() {
        java.util.Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the new game title: ");
        String title = scanner.nextLine();
        System.out.print("Enter the developer: ");
        String developer = scanner.nextLine();
        System.out.print("Enter the number of available platforms: ");
        int number = scanner.nextInt();
        String[] platforms = new String[number];
        scanner.nextLine();
        for (int i = 0; i < number; i++) {
            System.out.print("Enter the platform: ");
            platforms[i] = scanner.nextLine();
        }
        System.out.println("Please enter the reliease date: ");
        System.out.print("Year: ");
        int year = scanner.nextInt();
        System.out.print("Month: ");
        int month = scanner.nextInt();
        System.out.print("Day: ");
        int day = scanner.nextInt();

        return new VideoGame(title,developer,platforms,LocalDate.of(year,month,day));

        
    }
    
    //method to add a video game without maintaining sorted order
    //add your own code
    public static void addGame(List<VideoGame> list,VideoGame videoGame){
        list.add(videoGame);
    }

    //method to remove a game based on user input
    //add your own code
    public static void removeGame(List<VideoGame> list){
        if(list == null){
            System.out.println("Operation fails, Collection is empty!");
        }
        //get user input
        java.util.Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the title that you want to remove: ");
        String input = scanner.nextLine();
        //remove all game that has the same title
        for (VideoGame videogame: list) {
            if(videogame.getTitle().equals(input)){
                list.remove(videogame);
            }
        }
    }

    //method to find the game with latest release date
    public static VideoGame findLatestDate(List<VideoGame> list){
        if(list == null){
            System.out.println("Operation fails, Collection is empty!");
            return null;
        }
        VideoGame latest = null;
        //keep updating the latest as the latest released game
        for (VideoGame videoGame:list) {
            if(latest == null){
                latest = videoGame;
            }else if(latest.getReleaseDate().isBefore(videoGame.getReleaseDate())){
                latest = videoGame;
            }
        }
        return latest;
    }
    
    
    //OPTIONAL BONUS:
    //  method to add a video game in alphabetical order of game titles
    public static void addGameOrdered(List<VideoGame> list){
        VideoGame newGame = getNewGame();
        //iterate the collection and insert new game if there is a game whose title is alphabetically larger.
        for (VideoGame videoGame:list) {
            if(newGame.getTitle().compareToIgnoreCase(videoGame.getTitle()) < 0){
                list.add(list.indexOf(videoGame),newGame);
                return;
            }
        }
        //if no such videoGame is found, add the new game to the end of collection
        list.add(newGame);
    }
}
