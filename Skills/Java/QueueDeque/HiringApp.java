//CIS2168 Data Structures
//Section Number: 003
//Student Name:Xu Jiang
//Email address: tul32391@temple.edu
//Assign 4, HiringApp
//A simple program does not store any data that integrated four functions
//Accept an application
//Hire
//Fire
//Quit

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class HiringApp {

    public static void main(String[] args) {

        //Define the data structures for 3 different groups of people:
        //  new applicants
        // Applicant should be taken on a subsequence of queue, who ever came first will be considered firstly.
        //the first data will be frequently removing
        //the queue of a LinkedList is the best data structure storing them
        Queue<Person> applicants = new LinkedList<>();

        //  current employees (those who were hired),
        //the most recently hired employees will be fired first
        //the last data will be frequently removing
        //the stack of ArrayDeque is the best data structure storing them.
        Deque<Person> currentEmployees = new ArrayDeque<>();

        //  past employees (those who were fired)
        //past employee will not be removed when rehiring but also adding when firing employee
        //the data will be frequently removing and adding
        //LinkedList is the best data structure storing them
        Queue<Person> pastEmployees = new LinkedList<>();

        do {
            //display the menu
            //get the menu choice
            int choice = getChoice();
            //process user selected service request.
            switch (choice) {
                case 1:
                    applicants.offer(getApplication());
                    break;
                case 2:
                    hire(applicants, currentEmployees, pastEmployees);
                    break;
                case 3:
                    fire(applicants, currentEmployees, pastEmployees);
                    break;
                //If user entered any number besides 1,2,3, The loop will end in default case;
                default:
                    System.out.println("\nThank you for using the HiringApp, Have a good day!");
                    return;
            }
        } while (true);
        //loop until the user decides to quit.

    }

    //other methods for code modularization
    //method for getting user choice
    public static int getChoice() {
        System.out.println("\nWelcome to HiringApp, Please input number to operate your action:");
        //display the menu
        System.out.print("Action(1.Accept an application | " + "2.Hire |" + " 3.Fire | " + "4. Quit):");
        //get user choice
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        //return user choice as an integer
        return choice;

    }

    //method for accepting an applicant and reurn this applicant as a Person object
    public static Person getApplication() {
        Scanner scanner = new Scanner(System.in);
        //display prompt for user to enter an applicant's name
        //get user input
        System.out.print("Enter the applicant��s name: ");
        String name = scanner.nextLine();

        //display prompt for user to enter an applicant's degree
        //get user input
        System.out.print("Enter the applicant��s degree: ");
        String degree = scanner.nextLine();

        //display prompt for user to enter an applicant's skill list
        //  (first how many skills, then enter skill one by one)
        //use a loop to get each skill
        System.out.print("Enter the number of skills: ");
        int size = scanner.nextInt();
        scanner.nextLine();
        LinkedList<String> skills = new LinkedList<String>();
        for (int i = 0; i < size; i++) {
            System.out.print("Enter the skill list: ");
            skills.add(scanner.nextLine());
        }

        //create a Person object using the name, degree, skill list
        //and return this Person object
        return new Person(name, degree, skills);
    }

    /**
     * @param applicants       A list of applicants
     * @param currentEmployees A list of current employees
     * @param pastEmployees    A list of fired employees
     * @return true if hiring succeeded
     * false if hiring failed
     */
    public static boolean hire(Queue<Person> applicants, Deque<Person> currentEmployees, Queue<Person> pastEmployees) {
        if(!(pastEmployees.isEmpty())) {
            Person exEmployee = pastEmployees.poll();
            //rehire the past employee and remove him/her from pastEmployees list
            currentEmployees.push(exEmployee);
            System.out.println("The Employee " + exEmployee + " is hired");
            return true;
        }
        //if there is no applicant
        if (applicants.isEmpty()) {
            //sending a message to supervisor
            System.out.println("\nSupervisor, there is no applicant for our company.\n");
            return false;
        }

        //secondly hire whoever applied earliest
        Person employee = applicants.poll();
        System.out.println("The Employee " + employee + " is hired");
        currentEmployees.push(employee);
        return true;
    }

    /**
     * @param applicants       A list of applicants
     * @param currentEmployees A list of current employees
     * @param pastEmployees    A list of fired employees
     * @return true if firing succeeded
     * false if firing failed
     */

    public static boolean fire(Queue<Person> applicants, Deque<Person> currentEmployees, Queue<Person> pastEmployees) {
        //if there is no employee
        if (currentEmployees.isEmpty()) {
            //sending a message to supervisor
            System.out.println("\nSupervisor, there is no current employees in our company.\n");
            return false;
        }

        //fire the most recently hired employee
        Person employee = currentEmployees.pop();
        pastEmployees.offer(employee);
        System.out.println("The Employee " + employee + " is fired");
        return true;

    }
}
