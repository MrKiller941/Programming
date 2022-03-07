import java.util.Scanner;
import ExceptionR.ExceptionR;
import figure.Figure;
import figure.geometry2d;
import figure.Circle;
import figure.geometry3d;

class Main {
    public static void main(String[] args) throws ExceptionR {
        Figure shp = null;
        geometry3d clr = null;
        try {
            shp = new Circle(5);
	        clr = new geometry3d(3, new Circle(3));
            shp = new geometry2d(4,5);
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
            System.out.println("Try again...");
        }
        System.out.println(shp.Show());
	    System.out.println(clr.Show());
        System.out.println(shp.Show());
    }
}