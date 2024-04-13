class Student{
	String name;
	int rollno;

	static int counter = 0;
	Student(String name){
		this.name = name;
		this.rollno = setrollno();
	}

	static int setrollno(){
		counter++;
		return counter;
	}
	public void printDetails(){
		System.out.println("name : " + this.name);
		System.out.println("rollno : " + this.rollno);
	}

}
class a{
	public static void main(String[] args) {
		Student krishna = new Student("krishna");
		Student rahul = new Student("rahul");
		krishna.printDetails();
		rahul.printDetails();
	}
}