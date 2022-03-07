package figure;

import ExceptionR.ExceptionR;
import figure.Figure;

public class Circle implements Figure {
    protected String str;
    protected double r;
    protected Float temp;
    public Circle(double r_p) throws Exception {
        if (r_p <= 0) {
            throw new ExceptionR(r_p);
        }
        r = r_p;
    }
    public double Area(){
        return 3.14 * (r * r);
    }
    public String Show(){
        str = "Circle info: ";
        str += "Radius: ";
        temp = new Float(r);
        str += temp.toString();
        str += " Area: ";
        temp = new Float(Area());
        str += temp.toString();
        str += "\n";
        return str;
    }
}
