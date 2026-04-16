package testProject5;

public class Test1 {

	public static void main(String[] args) {
		Shape[] shp = new Shape[6];
		shp[0] = new Rect();
		shp[1] = new Rect();
		shp[2] = new Circle();
		shp[3] = new Triangle();
		shp[4] = new Circle();
		shp[5] = new Rect();
		
		for(int i=0; i<shp.length; i++) {
			shp[i].draw();
		}
		
	}

}

class Shape {
	int x;
	int y;
	void draw() {
		System.out.println("draw shape");
	}
}

class Rect extends Shape{
	void draw() {
		System.out.println("draw Rect");
	}
}

class Circle extends Shape {
	void draw() {
		System.out.println("draw Circle");
	}
}

class Triangle extends Shape {
	void draw() {
		System.out.println("draw Triangle");
	}
}