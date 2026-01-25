package Unitone;
class Variables {
    public static void main(){
        // Variables
        int x = 10;
        String name = "Subodh";     //strings surrounded by double quotes
        float y = 9.99f;    // f denotes float
        char z = 'D';   // char surrounded by single quotes
        boolean bool = true;

        System.out.println(x);
        System.out.println(name);
        System.out.println(y);
        System.out.println(z);
        System.out.println(bool);

        x = 15;
        System.out.println(x);

        /*
        Constant (final keyword)
        final int a = 10;
        a = 15;
        */
        System.out.println("This will generate an error. ");
        System.out.println("Cannot assign a new value to a final variable");

        // Mixing Text and Numbers
        System.out.println("The sum is " + x+y); // Concatenation
        System.out.println("The sum is " + (x+y));  // Sum

    }
}
