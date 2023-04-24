public class Undergraduate extends Student {

    //2.1.2 Add the code for tasks below
    //add new data fields: generalEduAdvisor, majorAdvisor
    private String generalEduAdvisor;
    private String majorAdvisor;

    //add two required constructors
    public Undergraduate() {
    	
    }
    public Undergraduate(String id, String firstName, String lastName, String major,
            String degree, double gpa, String generalEduAdvisor, String majorAdvisor) {
    	super(id,firstName,lastName,major,degree,gpa);
    	this.generalEduAdvisor = generalEduAdvisor;
    	this.majorAdvisor = majorAdvisor;
    }
    
    //add getters for all new data fields
    public String getGeneralEduAdvisor() {
    	return this.generalEduAdvisor;
    }
    
    public String getMajorAdvisor() {
    	return this.majorAdvisor;
    }
    
    //add setters for all new data fields
    public void setGeneralEduAdvisor(String generalEduAdvisor) {
    	this.generalEduAdvisor = generalEduAdvisor;
    }
    
    public void setMajorAdvisor(String majorAdvisor) {
    	this.majorAdvisor = majorAdvisor;
    }
    //add new toString() method that overrides the toString() in Student class
    @Override
    public String toString() {
    	
    	return super.toString()+ "\ngeneralEduAdvisor: "+ getGeneralEduAdvisor() + ". \nmajorAdvisor: " + getMajorAdvisor()+".";    
    }
    
    //optional: for testing the coding of your Undergraduate class.
    public static void main(String[] args) {
    }

}
