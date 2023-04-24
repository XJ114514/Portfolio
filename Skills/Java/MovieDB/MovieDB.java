import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

//A movie Database that can store movie objects 
public class MovieDB {

    //movie database
    private List<Movie> movieDB;
    //initial capacity of the movie database
    private static final int INITIAL_CAPACITY = 20;
    //the number of movies in the starter movie database
    private static final int STARTER_MOVIEDB_SIZE = 15;

    //decare a data field named titleIndex for the movie title index
    private Set<IndexEntry> titleIndex;

    //constructor of MovieDB
    public MovieDB() {
        movieDB = new ArrayList<Movie>();
        titleIndex = new TreeSet<IndexEntry>();
        
    }

    //create a starter movie DB
    public void createStartMovieDB() {
        int counter = 0;
        Set<Integer> hashSet = new HashSet<Integer>();
        while(counter < 15){
            Random random = new Random();
            int randomNum = random.nextInt(STARTER_MOVIEDB_SIZE)+1;
            if(!hashSet.contains(randomNum)){
                movieDB.add(new Movie("Title"+randomNum,"Director"+randomNum,2004+randomNum));
                hashSet.add(randomNum);
                counter++;
            }
        }
    }

    //display the movies in the database in a nice tabular format
    public void showMovieDB() {
        System.out.println("Movie Database:  \n" +
                " \n" +
                "\t\tTitle\t\tDirector\t\tYear \n" +
                "-------------------------------------------");
        for (Movie movie: movieDB) {
            System.out.printf("\t\t%s\t\t%s\t\t%d\n",movie.getTitle(),movie.getDirector(),movie.getYear());
        }
    }

    //create the index tree for all titles (unique) in the current movieDB
    public void createIndex() {
        int index = 0;
        IndexEntry indexEntry = null;
        for (Movie movie: movieDB) {
            indexEntry = new IndexEntry(movie.getTitle(),index++);
            titleIndex.add(indexEntry);
        }
    }

    //display the title index in in a tabular format
    public void showIndex() {
        System.out.println("Title Database:  \n" +
                " \n" +
                "\t\tTitle\t\tLocation \n" +
                "-------------------------------------------");
        for (IndexEntry indexEntry: titleIndex) {
            System.out.printf("\t\t%s\t\t%d\n",indexEntry.getTitle(),indexEntry.getLocation());
        }
    }    
    //for testing purpose
    public static void main(String[] args) {
        MovieDB movieDB = new MovieDB();
        movieDB.createStartMovieDB();
        movieDB.showMovieDB();
        movieDB.createIndex();
        System.out.println("__________________________________________________________________________________________________________________________");
        movieDB.showIndex();
    }

}
