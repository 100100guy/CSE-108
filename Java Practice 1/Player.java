public class Player {
    private int number;
    private String name;
    private double salary;

    // you are not allowed to write any other constructor
    public Player(int number, String name) {
        setNumber(number);
        setName(name);
    }

    public void setNumber(int n) {
        this.number = n;
    }

    public void setName(String a) {
        this.name = a;
    }

    public void setSalary(double n) {
        this.salary = n;
    }

    public double getSalary() {
        return this.salary;
    }

    public String getName() {
        return this.name;
    }

    // add your code here
}
