package Unitone;

public class Array {
    public static void main(String[] args) {

        // Array Initialization Type 1
        String[] x = new String[4]; //Size of Array is 4
        x[0] = "Volvo";
        x[1] = "BMW";
        x[2] = "Ford";
        x[3] = "Mazda";

        // Array Initialization Type 2
        String[] y = new String[] {"Volvo", "BMW", "Ford", "Mazda"};

        // Array Initialization Type 3
        String[] z = {"Volvo", "BMW", "Ford", "Mazda"};

        // Access Elements
        System.out.println(x[0]);

        // Change Array Element
        x[0] = "Ford";
        System.out.println(x[0]);

        // Array Length
        System.out.println(x.length);

        // Display all Array Elements
        for (int i = 0; i < x.length; i++) {
            System.out.println(x[i]);
        }
        System.out.println();
        for (String car: x){
            System.out.println(car);
        }


        // Multi-dimentional Arrays
        int[][] myNumbers = { {1, 4, 2}, {3, 6, 8} };
        System.out.println(myNumbers[1][2]);

        // Changing Element Values
        myNumbers[1][2] = 10;
        System.out.println(myNumbers[1][2]);
        System.out.println();

        // Loop Through
        for (int row = 0; row < myNumbers.length; row++) {
            for (int col = 0; col < myNumbers[row].length; col++) {
                System.out.println("myNumbers[" + row + "][" + col + "] = " + myNumbers[row][col]);
            }
        }
        System.out.println();

        // For each loop
        for (int[] row : myNumbers) {
            for (int num : row) {
                System.out.println(num);
            }
        }


        // Jagged Array (Multi-dimensional with different column sizes)
        int[][] mynumbers = {
                {1, 4},          // row 0 → 2 elements
                {3, 6, 8, 9},    // row 1 → 4 elements
                {5}              // row 2 → 1 element
        };

        // Accessing element
        System.out.println(mynumbers[1][2]);   // 8

        // Changing Element Values
        mynumbers[1][2] = 10;
        System.out.println(mynumbers[1][2]);
        System.out.println();

        // Loop Through (normal for loop)
        for (int row = 0; row < mynumbers.length; row++) {
            for (int col = 0; col < mynumbers[row].length; col++) {
                System.out.println("mynumbers[" + row + "][" + col + "] = " + mynumbers[row][col]);
            }
        }
        System.out.println();

        // For-each loop
        for (int[] row : mynumbers) {
            for (int num : row) {
                System.out.println(num);
            }
        }


    }
}
