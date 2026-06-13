# 2082

## Question 7: Write a program to input the name of faculty and throw an exception if that input is not “CSIT”.

Using Custom Exception:

```java
import java.util.Scanner;

class InvalidFacultyException extends Exception{
    public InvalidFacultyException(String message) {
        super(message);
    }
}

public class Faculty{
    public static void validateFaculty(String facultyname) throws InvalidFacultyException{
        if(facultyname.equals("CSIT")){
            System.out.println("Valid faculty name entered.");
        } else {
            throw new InvalidFacultyException("Invalid faculty name. Please enter 'CSIT'.");
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name of the faculty: ");
        String facultyname = sc.nextLine();
        try {
            validateFaculty(facultyname);
        } catch (InvalidFacultyException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

Without Custom Exception:
```java
import java.util.Scanner;

public class FacultyName {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the name of the faculty: ");
        String facultyName = scanner.nextLine();

        try {
            if (!facultyName.equals("CSIT")) {
                throw new IllegalArgumentException("Invalid faculty name. Please enter 'CSIT'.");
            }
            System.out.println("Valid faculty name entered.");
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```


## Question 9: What is a package? Differentiate between method overloading and overriding.



## Question 11: Write a program to create a class MOVIE with attributes name and genre. Write the movie with genre comedy on COM.DAT file.

```java
import java.io.*;

class Movie implements Serializable {
    private String name;
    private String genre;

    Movie(String name, String genre) {
        this.name = name;
        this.genre = genre;
    }

}

public class MovieFile {
    public static void main(String[] args) {
        Movie movie1 = new Movie("The Hangover", "Comedy");

        try {
            // Create a file output stream to write to COM.DAT
            FileOutputStream fout = new FileOutputStream("COM.DAT");

            // Create an object output stream to write the movie object
            ObjectOutputStream out = new ObjectOutputStream(fout);

            out.writeObject(movie1);
            out.close();
            fout.close();

            System.out.println("Comedy movie written to COM.DAT successfully.");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```


---

# 2081


## Question 2: Differentiate between path and class path in Java. When do you prefer anonymous inner class? Consider the following program and answer the given questions.

```java
class A {
    class B {
        public void test() {
            int i = 0;
            while (i<=100){
                System.out.println(i);
                i = i + 2; 
            }
        }
    }
}
```
1. Name the list of class file created after compiling above program.
2. Rewrite the above program using for loop.


**Anonymous Inner Class:**
- An anonymous inner class is a class that is defined without a name and is used to instantiate an object with certain modifications or to implement an interface on the fly.
- It is preferred when
    1. **For one time use**: 
        - When the class is needed only once in the program.
        - Avoids creating a separate class file.
    2. **To implement interfaces**:
        - When you want to implement an interface without creating a separate class.
    3. **To extend a class**:
        - When you want to extend a class and override its methods without creating a separate class.
    4. **For event handling**:
        - Commonly used in GUI applications for handling events like button clicks.

```java
public class A {
    class B {
        public void test() {
            int i = 0;
            while (i <= 100) {
                System.out.println(i);
                i = i + 2;
            }
        }
    }
    public static void main(String[] args) {
            A a = new A();
            A.B b = a.new B();
            b.test();
        }
}
```

1. The list of class files created after compiling the above program would be:
   - A.class
   - A$B.class
Here, `A.class` is the main class file for class A, and `A$B.class` is the class file for the inner class B.


2. The rewritten program using a for loop would look like this:

```java
public class A {
    class B {
        public void test() {
            for (int i = 0; i <= 100; i += 2) {
                System.out.println(i);
            }
        }
    }
    public static void main(String[] args) {
        A a = new A();
        A.B b = a.new B();
        b.test();
    }
}
```
- In this version, the `while` loop is replaced with a `for` loop that initializes `i` to 0, checks if `i` is less than or equal to 100, and increments `i` by 2 in each iteration. The output will be the same as the original program, printing even numbers from 0 to 100.

## Question 8: Assume that a text file named “ONE.TXT” contains a paragraph of text. Write a program to copy the word that starts with vowel from “ONE.TXT” to another file “TWO.TXT”.

```java
import java.io.*;

public class VowelWordCopy {
    public static void main(String[] args) {
        String inputFile = "ONE.TXT";
        String outputFile = "TWO.TXT";

        try {
            BufferedReader br = new BufferedReader(new FileReader(inputFile));
            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));

            String line;

            while ((line = br.readLine()) != null) {

                String[] words = line.split("\\s+");
                for (String word : words) {
                    if (startsWithVowel(word)) {
                        bw.write(word + System.lineSeparator());
                    }
                }
            }

            br.close();
            bw.close();
            System.out.println("Words starting with a vowel have been copied to TWO.TXT.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }

    private static boolean startsWithVowel(String word) {
        if (word.isEmpty()) {
            return false;
        }
        char firstChar = Character.toLowerCase(word.charAt(0));
        if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
            return true;
        }
        return false;
    }
}
```

---


# Model 2

## Question 1: **Example Program to Read Employee Data and Write to File:**

```java
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class EmployeeFileWrite {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            FileWriter fw = new FileWriter("Midterm_Files/emp.doc");

            System.out.print("Enter Employee ID: ");
            int id = sc.nextInt();
            sc.nextLine(); // consume newline

            System.out.print("Enter Employee Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Employee Salary: ");
            double salary = sc.nextDouble();

            fw.write("Employee Details:\n");
            fw.write("ID: " + id + "\n");
            fw.write("Name: " + name + "\n");
            fw.write("Salary: " + salary + "\n");

            fw.close();
            System.out.println("Data written successfully to file.");

        } catch (IOException e) {
            System.out.println("File handling error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Input error: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}
```

---

# 2080

## Question 1: **Function to check if an array is a centered array:**

```java
import java.util.Scanner;
public class CenteredArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ///  Enter the size of array
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();

        ///  Create array
        int[] array = new int[n];

        ///  Enter the array elements
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++){
            array[i] = sc.nextInt();
        }

        /// Check if the array is a centered array and print the result
        int result = centeredArray(array);

        ///  1= centered array, 0= not centered array
        if (result == 1) {
            System.out.println("The array is a Centered Array.");
        } else {
            System.out.println("The array is NOT a Centered Array.");
        }
    }

    /// Checks if the given array is a centered array, which means it contains all integers from 0 to n-1 exactly once and has an odd number of elements.
    public static int centeredArray(int[] array) {
        /// Check for null array and if array has odd number of elements
        if  (array == null || array.length % 2 == 0) {
            return 0;
        }

        int n = array.length;

        ///  Find the index of middle element
        int midindex = n / 2;

        ///  Find the value of middle element
        int midvalue = array[midindex];

        /// Check every elements
        for  (int i = 0; i < n; i++) {

            ///  Skip the middle element
            if (i == midindex) {
                continue;
            }
            ///  If the element is less than the middle value, return 0
            if (array[i] < midvalue){
                return 0;
            }
        }
        ///  If all elements are greater than middle elements
        return 1;
    }
}

``` 

## Question 11: Suppose that 9 integers are written in a file named “magic.txt” in the arrangement of 3 × 3 separated by space. Write a program to check whether the integers in all rows, all columns, and both diagonals sum to the same constant or not.

```java
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Magic {
    public static void main(String[] args) {
        int[][] matrix = new int[3][3];

        try {
            Scanner file = new Scanner(new File("Midterm_files/magic.txt"));

            // Read numbers into 3x3 array
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrix[i][j] = file.nextInt();
                }
            }

            int r1 = matrix[0][0] + matrix[0][1] + matrix[0][2];
            int r2 = matrix[1][0] + matrix[1][1] + matrix[1][2];
            int r3 = matrix[2][0] + matrix[2][1] + matrix[2][2];

            // Column sums
            int c1 = matrix[0][0] + matrix[1][0] + matrix[2][0];
            int c2 = matrix[0][1] + matrix[1][1] + matrix[2][1];
            int c3 = matrix[0][2] + matrix[1][2] + matrix[2][2];

            // Diagonal sums
            int d1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
            int d2 = matrix[0][2] + matrix[1][1] + matrix[2][0];

            // Check if all sums are equal
            if (r1 == r2 && r2 == r3 &&
                    r1 == c1 && c1 == c2 && c2 == c3 &&
                    r1 == d1 && d1 == d2) {

                System.out.println("It is a Magic Square.");
            } else {
                System.out.println("It is NOT a Magic Square.");
            }

        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
        }
    }
}
```

---

# Model 1 

## Question 4: Write a java program that writes objects of Employee class in the file named emp.doc. Create Employee class as of your interest.

```java
import java.io.*;

// Employee class
class Employee implements Serializable {
    int id;
    String name;
    double salary;

    Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }
}

public class EmployeeFile {
    public static void main(String[] args) {

        try {
            FileOutputStream fos = new FileOutputStream("emp.doc");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            // Create employee objects
            Employee e1 = new Employee(101, "Ram", 50000);
            Employee e2 = new Employee(102, "Sita", 60000);
            Employee e3 = new Employee(103, "Hari", 55000);

            // Write objects to file
            oos.writeObject(e1);
            oos.writeObject(e2);
            oos.writeObject(e3);

            oos.close();

            System.out.println("Employee objects written to emp.doc successfully.");

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```


---

# 2079

## Question 1:Create a class Distance with private variables feet of type integer and inches of type floating point. Use suitable constructor, and methods for adding and comparing two distance objects. [Hint: 1 feet = 12 inches]

```java

class Distance{
    private int feet;
    private float inches;

    // Constructor
    public Distance(int feet, float inches) {
        this.feet = feet;
        this.inches = inches;

        if (this.inches >= 12) {
            this.feet += (int)(this.inches / 12);
            this.inches = this.inches % 12;
        }
    }

    public Distance add(Distance d) {
        int newFeet = this.feet + d.feet;
        float newInches = this.inches + d.inches;

        if (newInches >= 12) {
            newFeet += (int) (newInches / 12);
            newInches = newInches % 12;
        }

        return new Distance(newFeet, newInches);
    }

    public void compare(Distance d) {
        float totalInches1 = this.feet * 12 + this.inches;
        float totalInches2 = d.feet * 12 + d.inches;

        if (totalInches1 > totalInches2) {
            System.out.println("Distance 1 is greater than Distance 2");
        } else if (totalInches1 < totalInches2) {
            System.out.println("Distance 2 is greater than Distance 1");
        } else {
            System.out.println("Both distances are equal");
        }
    }

    public void display() {
        System.out.println(feet + " feet " + inches + " inches");
    }

    public static void main(String[] args) {
        Distance d1 = new Distance(5, 8.5f);
        Distance d2 = new Distance(3, 15.2f);

        System.out.print("Distance 1: ");
        d1.display();

        System.out.print("Distance 2: ");
        d2.display();

        Distance sum = d1.add(d2);
        System.out.print("Sum of distances: ");
        sum.display();

        d1.compare(d2);
    }
}
```
---

# 2077

## Question 3: Describe the responsibility of Serializable interface. Write a program to read an input string from an user and write the vowels of that string in Vowel.txt and consonants in Consonant.txt


***Serializable Interface**
- The `Serializable` interface in Java is a marker interface that enables an object to be converted into a byte stream, which can then be saved to a file or transmitted over a network.
- It does not contain any methods; its purpose is to indicate that a class can be serialized
- When a class implements `Serializable`, it allows its instances to be serialized and deserialized, meaning they can be saved and restored.

Responsibility of Serializable Interface:
1. **Enabling Serialization**: It allows objects of a class to be serialized, which means converting the object into a byte stream for storage or transmission.
2. **Enabling Deserialization**: It allows the byte stream to be converted back into a copy of the original object, enabling the restoration of the object's state.
3. **Facilitating Object Persistence**: It allows objects to be saved to a file or database and later retrieved, making it useful for data persistence.
4. **Facilitating Remote Communication**: It allows objects to be sent over a network, enabling remote method invocation and distributed computing.

```java
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class VowelConsonant {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String input = scanner.nextLine();

        try {
            FileWriter vowelWriter = new FileWriter("Vowel.txt");
            FileWriter consonantWriter = new FileWriter("Consonant.txt");

            for (char c : input.toCharArray()) {
                if (isVowel(c)) {
                    vowelWriter.write(c);
                } else if (Character.isLetter(c)) {
                    consonantWriter.write(c);
                }
            }

            vowelWriter.close();
            consonantWriter.close();
            System.out.println("Vowels and consonants have been written to their respective files.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }

    private static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```


## Question 4: A non-empty array A of length n is called an array of all possibilities if it contains all numbers between 0 and A.length-1 inclusive. Write a method named isAllPossibilities that accepts an integer array and returns 1 if the array is an array of all possiblities, otherwise it returns 0.

```java
import java.util.Scanner;
public class AllPossibilities {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the length of the array:");
        int n = scanner.nextInt();

        int[] array = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        int result = isAllPossibilities(array);
        System.out.println(result);
    }

    /// Checks if the given array contains all integers from 0 to n-1 exactly once.
    public static int isAllPossibilities(int[] array) {

        /// Check for null array
        if  (array == null || array.length == 0) {
            return 0;
        }

        int n = array.length;
        /// Check for each number from 0 to n-1
        for  (int i = 0; i < n; i++) {
            boolean found = false;

            for (int j = 0; j < n; j++) {

                ///  If the current array element equals i
                if (array[j] == i) {
                    found = true;
                    break;
                }
            }

            ///  If no duplicate found
            if (!found) {
                return 0;
            }
        }

        ///  If found from 0 to n-1
        return 1;
    }
}

```

## Question 9: What is the task of manifest file? Write the procedure to create it.

**Manifest File**
- A manifest file is a special file inside a Java JAR file that contains important information about the program.
- It tells the Java Virtual Machine (JVM) how to run the JAR file.
- It is named `MANIFEST.MF`.  
- It is stored inside the `META-INF` folder of a JAR file.  
- It contains metadata like the main class, version, and classpath. 

**Task of Manifest File**
- The manifest file tells which class contains the `main()` method to start the program.  
- It uses the `Main-Class` attribute to define the entry point of the application.  
- It helps the JVM run the JAR file directly without specifying the main class manually.  
- It can also define extra information like version and classpath.  
- It is essential for creating executable JAR files.

**Procedure to Create a Manifest File**
1. Write java code and compile it to create class files.
   ```
    class MainClass {
        public static void main(String[] args) {
            System.out.println("Hello, World!");
        }
    }
   ```
2. Compile the code:
   ```
   javac MainClass.java
   ```
3. Create a text file named `MANIFEST.MF` and add the following content:
   ```
   Main-Class: MainClass
   ```
4. Save the `MANIFEST.MF` file.
5. Use the `jar` command to create a JAR file, including the manifest file:
   ```
   jar cfm MyApp.jar MANIFEST.MF *.class
   ```
6. This command creates a JAR file named `MyApp.jar` that includes the manifest file and all class files.
7. You can now run the JAR file using the command:
    ```
    java -jar MyApp.jar
    ```
This will execute the `main()` method in `MainClass` and print "Hello, World!" to the console.

---