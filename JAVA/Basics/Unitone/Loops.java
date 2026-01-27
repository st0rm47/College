package Unitone;

public class Loops {
    static void main(String[] args) {
        // While Loop
        int i = 0;
        while (i < 5) {
            System.out.println(i);
            i++;
        }
        System.out.println();

        // Do While Loop
        int j = 0;
        do {
            System.out.println(j);
            j++;
        }
        while (j < 5);
        System.out.println();

        // For loop
        int sum = 0;
        for (int k = 1; k <= 5; k++) {
            sum = sum + k;
        }
        System.out.println("Sum is " + sum);
        System.out.println();

        // For each loop (Array)
        String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
        for (String car : cars) {
            System.out.println(car);
        }
        System.out.println();

        // Nested Loop
        for (int l = 1; l <= 3; l++) {
            for (int m = 1; m <= 3; m++) {
                System.out.print(l * m + " ");
            }
            System.out.println();
        }
    }

}

