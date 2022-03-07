package figure;

import ExceptionR.ExceptionR;
import figure.Figure;

public class geometry3d
{
    protected double h;
    protected String str;
    protected Figure shp;
    protected Float temp;
    public geometry3d(double h_p, Figure shp_p){
        h = h_p;
        shp = shp_p;
    }
    public double Volume(){
        return h * shp.Area();
    }
    public String Show(){
        str = "Cylinder info: ";
        str += "Height h: ";
        temp = new Float(h);
        str += temp.toString();
        str += " Base area: ";
        temp = new Float(shp.Area());
        str += temp.toString();
        str += " Volume: ";
        temp = new Float(Volume());
        str += temp.toString();
        str += "\n";
        return str;
    }
}