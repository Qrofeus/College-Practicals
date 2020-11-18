package OOProgramming;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StudentData {

    private static final List<Student> studentList = new ArrayList<>();// Collections, Generics **
    // ** Generic class template --List<>-- is used instead of --Arraylist<>--, because after creation
    // the only functions further used are common to all list type data structures

    private static void getData(){
        String name;
        int count, sem, roll;
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter number of students:: ");
        count = scan.nextInt();

        System.out.println("Enter student details--\n");

        for (int i = 0; i < count; i++) {
            System.out.print("Name: ");
            name = scan.next() + " " + scan.next();
            if (!checkName(name)){
                System.out.println("Invalid name, Iteration skipped");
                continue;
            }
            System.out.print("Roll No.: ");
            roll = scan.nextInt();
            System.out.print("Semester (1-8) : ");
            sem = scan.nextInt();

            studentList.add(new Student(name, sem, roll));
        }
    }

    private static void displayList(){
        System.out.println("\n-------------------------------\nDisplaying Student List:");
        for (Student student : studentList) {
            System.out.println("\nName: " + student.getName());
            System.out.println("Roll: " + student.getRoll());
            System.out.println("Semester: " + student.getSemester());
        }
        // Object Oriented Programming: Encapsulation
    }

    private static boolean checkName(String name){
        for (int i = 0; i < 10; i++) {
            if (name.contains(Integer.toString(i))){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        getData();
        displayList();
    }
}