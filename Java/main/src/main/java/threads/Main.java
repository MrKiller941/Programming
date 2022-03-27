package threads;
public class Main {
    
    public static void main(String[] args) {
        MyThread t = new MyThread();
        new Threads(t, "Thread first ");
        new Threads(t, "Thread second");
    }
}

class MyThread {

    boolean first = true;

    public void print(String threadName) {
        System.out.println(threadName);
    }
}

class Threads implements Runnable {

    MyThread t;
    String name;
    Thread thread;

    public Threads(MyThread t, String name) {
        this.t = t;
        this.name = name;
        thread = new Thread(this, name);
        thread.start();
    }

    @Override
    public void run() {
        while(true) {
            synchronized (t) {
                try {
                    Thread.sleep(500);
                    t.print(name);
                    t.notify();
                    t.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}