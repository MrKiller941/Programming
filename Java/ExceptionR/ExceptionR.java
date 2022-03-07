package ExceptionR;

public class ExceptionR extends Exception {
    private double r;
    private String msg;
    private Float temp;
    public ExceptionR(double r_p) {
        r = r_p;
        msg = "The radius must be greater than 0. Invalid values: ";
        temp = new Float(r);
        msg += temp.toString();
    }
    public String getMessage() {
        return msg;
    }
}
