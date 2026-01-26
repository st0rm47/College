package Unitone;

public class Strings {
    static void main(Strings[] args) {
        String text = "Hello World, This is a string";

        // String Length
        int a = text.length();
        System.out.println("The length of text is " + a);
        System.out.println(); // Prints blank line

        // Uppercase
        var b = text.toUpperCase();
        System.out.println("The uppercase is: " + b);
        System.out.println();

        // Lowercase
        var c = text.toLowerCase();
        System.out.println("The lowercase is: " + c);
        System.out.println();

        // Searching a character
        var d = text.indexOf("World");
        System.out.println("The word 'World' starts from index "+ d);
        System.out.println();

        var e = text.charAt(8);
        System.out.println("The character at index 8 is " + e);
        System.out.println();

        // Compare
        Strings x = "Hello";
        Strings y = "Hello";
        var f = x.equals(y);
        System.out.println(f);
        System.out.println();

        // Remove Whitespaces
        var g = text.trim();
        System.out.println("Before Removing WhiteSpaces");
        System.out.println(text);
        System.out.println();

        System.out.println("After Removing WhiteSpaces");
        System.out.println(g);
        System.out.println();

        // Concatenation of Strings
        String fname = "Subodh";
        String lname = "Ghimire";
        String name = fname.concat(lname);
        System.out.println(name);
    }
}

