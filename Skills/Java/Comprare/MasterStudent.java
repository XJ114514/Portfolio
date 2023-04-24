public class MasterStudent extends Student {

    //2.1.3 Add the code for the tasks below.
    //add new data fields: thesis, thesisAdvisor, theisCommittee
    private String thesis;
    private String thesisAdvisor;
    private String[] committee; //thesis committee, excluding thesis advisor    

    //add two required constructors
    public MasterStudent() {
    	
    }
    public MasterStudent(String id, String firstName, String lastName, String major,
            String degree, double gpa, String thesis, String thesisAdvisor,String[] committee) {
    	super(id,firstName,lastName,major,degree,gpa);
    	this.thesis = thesis;
    	this.thesisAdvisor = thesisAdvisor;
    	this.committee = committee;
    }
    
    
    //add getters for all new data fields
    public String getThesis() {
    	return this.thesis;
    }
    public String getThesisAdvisor() {
    	return this.thesisAdvisor;
    }
    public String[] getCommittee() {
    	return this.committee;
    }
    
    //add setters for all new data fields
    public void setThesis(String thesis) {
    	this.thesis = thesis;
    }
    public void setThesisAdvisor(String thesisAdvisor) {
    	this.thesisAdvisor = thesisAdvisor;
    }
    public void setCommittee(String[] committee) {
    	this.committee = committee; 
    }
    
    //add new toString() method that overrides the toString() in Student class
    @Override
    public String toString() {
    	StringBuffer text = new StringBuffer(super.toString());
    	text.append("Thesis: "+getThesis()+"\n");
    	text.append("ThesisAdvisor: "+getThesisAdvisor()+"\n");
    	text.append("Committee includes: \n");
    	for(String member :committee) {
    		text.append(member+" ");
    	}
    	return text.toString();
    }
    //optional: for testing the coding of your MasterStudent class.
    public static void main(String[] args) {
    }
}
