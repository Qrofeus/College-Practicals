package OOProgramming;

public class Student {
    private String name;
    private int semester;
    private int roll;

    public Student(String name, int semester, int roll) {
        this.name = name;
        this.semester = semester;
        this.roll = roll;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSemester() {
        return semester;
    }

    public void setSemester(int semester) {
        this.semester = semester;
    }

    public int getRoll() {
        return roll;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }
}
