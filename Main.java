abstract class shape{
	abstract double calculateArea();
}

class Rectangle extends shape{
	double length;
	double bredth;

	Rectangle(double length, double bredth){
		this.length = length;
		this.bredth = bredth;
	}
	double calculateArea(){
		return length*bredth;
	}
}
class Circle extends shape{
	double radius;

	Circle(double radius){
		this.radius = radius;
	}
	double calculateArea(){
		return Math.PI * radius * radius;
	}
}
class Square extends shape{
	double side;

	Square(double side){
		this.side = side;
	}
	double calculateArea(){
		return side*side;
	}
}
class Triangle extends shape{
	double base;
	double height;

	Triangle(double base, double height){
		this.base = base;
		this.height = height;
	}
	double calculateArea(){
		return 0.5 * base * height;
	}
}
class Main{
	public static void main(String[] args){
		Circle c = new Circle(4);
		System.out.println(c.calculateArea());
	}
}