//CIS2168 Data Structures
//Section Number: 003
//Student Name:Xu Jiang
//Email address: tul32391@temple.edu
//Assign 4, Peron class.
//Represent an applicant, or an employee

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Objects;

public class Person { //new applicants, current employees, past employees
    private String name;
    private String degree;
    private LinkedList<String> skills;

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", degree='" + degree + '\'' +
                ", skills=" + skills +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person person = (Person) o;
        return name.equals(person.name) && degree.equals(person.degree) && skills.equals(person.skills);
    }


    public Person() {
    }

    public Person(String name, String degree, LinkedList<String> skills) {
        this.name = name;
        this.degree = degree;
        this.skills = skills;
    }
}

