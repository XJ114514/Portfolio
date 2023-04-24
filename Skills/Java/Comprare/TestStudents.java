public class TestStudents {
    public static void main(String[] args) {
        
        //2.2 Code given to you. Just use them.
        
        //create an array of Student objects.
        Student[] cisDept = new Student[4];
        
        
        //Create and add 4 students, two undergraduates, two master students
        String[] theisCommittee = {"Tom", "Richard", "Jamie"};
        String[] theisCommittee2 = {"Jie", "Zoran", "Gene"};
        
        //   add these students to the array 
        cisDept[0] = new MasterStudent("222", "Steve", "Jobs", "IST", "MS", 3.5,
                "How to make ipad smarter", "Jamie", theisCommittee); 
        cisDept[1] = new Undergraduate("444", "Bill", "Gates", "CS", "BS", 3.0, "Erin", "Sally");
        cisDept[2] = new MasterStudent("333", "Amy", "Jobs", "CS", "MS", 3.8,
                "Study of Robots That can Perform", "Eduard", theisCommittee2);
        cisDept[3] = new Undergraduate("111", "Melinda", "Gates", "IST", "BS", 3.0, "Erin", "Frank");
        //2.2 Add the code to do the task below.
        
        //Use a loop to print the information about all students in the student array.
        //   Must use the toString() methods
        System.out.println("Students in CIS Department \n ---- ");
        for(Student student : cisDept) {
        	System.out.println(student+"\n");
        }
        
        //2.3.2 add the code for the task below
        // call indexOfMin(...), passing the array  cisDept,
        int index = indexOfMin(cisDept);
        // print the student located at the return value of indexOfMin(...)
        System.out.println("The first student in alphabetical order is\n"+cisDept[index]);
        
    }
    
    
    //2.3.2 add the code for the task below
    //  implement this method, return the index of the first student in
    //   the array in the alphabetical order of student names (last name first, then first name)
    //  You must call compareTo(...) method in your Student class.
    //  Using Arrays.sort(...) in this method will lead to point deduction.
    public static int indexOfMin(Student[] myDept) {
    	 //you MUST call compareTo(...) method in your Student class
         //Using Arrays.sort(...) in this method will lead to point deductions.        
    	int min = 0;
    	for(int i = 1; i< myDept.length ; i++) {
    		if (myDept[min].compareTo(myDept[i]) > 0){
    			min = i;
    		}
    	}
    	return min;
    }
}
