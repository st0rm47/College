package Unitone;

public class Exception_Handling {

    // Throws with Single Exception
    static void checkAge(int age) throws ArithmeticException {
        if (age < 18) {
            throw new ArithmeticException("Not eligible to vote");
        }
        System.out.println("Eligible to vote");
    }

    static void main(String[] args) {
        int x = 10;
        int y = 0;

        // try
        try{
            int z = x/y;
        }

        // catch
        catch (Exception e){
            System.out.println("Error");
        }

        // finally
        finally{
            System.out.println("This always works");
        }

//        // throw
//        if (y == 0){
//            throw new ArithmeticException("The number cannot be zero");
//        }


        // throws
        try {
            checkAge(15);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}