package java_final_review;

public class triangle extends geometry {
    public int side1;
    public int side2;
    public int side3;

    public triangle() {
        super();
        this.side1 = 0;
        this.side2 = 0;
        this.side3 = 0;
    }

    public triangle(int side1, int side2, int side3) {
        super();
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public triangle(int side1, int side2, int side3, int area, int perimeter) {
        super(area, perimeter);
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public int getArea() {
        int s = (this.side1 + this.side2 + this.side3) / 2;
        return (int) Math.sqrt(s * (s - this.side1) * (s - this.side2) * (s - this.side3));
    }

    public int getPerimeter() {
        return this.side1 + this.side2 + this.side3;
    }

    public String toString() {
        return "Area: " + this.getArea() + "\nPerimeter: " + this.getPerimeter();
    }

    public static void main(String[] args) {
        triangle t = new triangle(3, 4, 5);
        System.out.println(t);
    }

}
