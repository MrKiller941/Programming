package lab4;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

import lab4.Variables;

public class Network {

    private Socket socket;
    private Variables variables;
    private ObjectInputStream in;
    private ObjectOutputStream out;
    
    public Network(String ip, int port) {
        try {
            socket = new Socket(ip, port);
            in = new ObjectInputStream(socket.getInputStream());
            out = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
        variables = new Variables();
    }

    public void stop() throws IOException {
        in.close();
        out.close();
        socket.close();
    }

    public void send(double a, double b, String operator) {
        variables.setA(a);
        variables.setB(b);
        variables.setOperator(operator);
        try {
            out.writeObject(variables);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public double get() throws ClassNotFoundException, IOException {
        return (Double)in.readObject();
    }

    public void clear() {
        try {
            out.reset();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}