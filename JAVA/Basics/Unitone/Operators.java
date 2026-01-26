package Unitone;

public class Operators {
    public static void main(String[] args) {
        // Arithmetic Opertors
        int x = 10;
        int y = 3;
        int z = 5;

        System.out.println(x + y); // Addition
        System.out.println(x - y); // Subtraction
        System.out.println(x * y); // Multiplication
        System.out.println(x / y); // Division
        System.out.println(x % y); // Modulus

        ++z;    // Increment
        System.out.println(z);

        --z;    // Decrement
        System.out.println(z);


        // Assignment Operators
        int a = 10;           // Simple assignment
        System.out.println(a);

        a += 5;               // Add and assign
        System.out.println(a);

        a -= 3;               // Subtract and assign
        System.out.println(a);

        a *= 2;               // Multiply and assign
        System.out.println(a);

        a /= 4;               // Divide and assign
        System.out.println(a);

        a %= 3;               // Modulus and assign
        System.out.println(a);

        // Bitwise assignment operators
        int b = 0b1100;
        b &= 0b1010;          // AND and assign
        System.out.println(b);

        b |= 0b0101;          // OR and assign
        System.out.println(b);

        b ^= 0b0011;          // XOR and assign
        System.out.println(b);

        // Shift assignment operators
        int c = 8;
        c <<= 2;              // Left shift and assign
        System.out.println(c);

        c >>= 1;              // Right shift and assign (sign-propagating)
        System.out.println(c);

        c >>>= 1;             // Unsigned right shift and assign
        System.out.println(c);


        // Comparison Operators
        int p = 10;
        int q = 20;
        System.out.println(p == q);  // Equal to
        System.out.println(p != q);  // Not equal to
        System.out.println(p > q);   // Greater than
        System.out.println(p < q);   // Less than
        System.out.println(p >= q);  // Greater than or equal to
        System.out.println(p <= q);  // Less than or equal to

        // Logical Operators
        boolean m = true;
        boolean n = false;
        System.out.println(m && n);  // Logical AND
        System.out.println(m || n);  // Logical OR
        System.out.println(!m);      // Logical NOT
    }
}
