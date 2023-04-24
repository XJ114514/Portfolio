//The class for the console application of the Movie Database.

public class MovieDBConsole {

    public static void main(String[] args) {
        //create an empty movie database
        MovieDB myMovieDB = new MovieDB();
        //populate the movie DB with random movie data
        myMovieDB.createStartMovieDB();
        //display the starter movie DB information
        myMovieDB.showMovieDB();

        //create the movie title index
        myMovieDB.createIndex();
        //display the movie title index
        myMovieDB.showIndex();
    }

}
