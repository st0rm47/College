package Unitone;

// Extending Thread Class
//public class MultiThreading extends Thread {
//    public void run(){
//        for(int i = 1; i <= 5; i++) {
//            System.out.println("Thread running: " + i);
//            try{
//                Thread.sleep(100);
//            }
//            catch (InterruptedException e){
//                System.out.println(e);
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        MultiThreading mt1 = new MultiThreading();
//        MultiThreading mt2 = new MultiThreading();
//
//        mt1.start();
//        mt2.start();
//    }
//}


// Runnable Interface
//class MultiThreading implements Runnable {
//    public void run() {
//        for(int i = 1; i <= 5; i++) {
//            System.out.println("Runnable Thread: " + i);
//            try{
//                Thread.sleep(100);
//            }
//            catch (InterruptedException e){
//                System.out.println(e);
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        MultiThreading r = new MultiThreading();
//        Thread t1 = new Thread(r);
//        Thread t2 = new Thread(r);
//        t1.start();
//        t2.start();
//    }
//}


// Lambda Expressions
public class Multithreading {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            for(int i = 1; i <= 5; i++) {
                System.out.println("Lambda Thread 1: " + i);
                try{
                    Thread.sleep(100);
                }
                catch (InterruptedException e){
                    System.out.println(e);
                }
            }
        });

        Thread t2 = new Thread(() -> {
            for(int i = 1; i <= 5; i++) {
                System.out.println("Lambda Thread 2: " + i);
                try{
                    Thread.sleep(100);
                }
                catch (InterruptedException e){
                    System.out.println(e);
                }
            }
        });

        t1.start();
        t2.start();

    }
}

