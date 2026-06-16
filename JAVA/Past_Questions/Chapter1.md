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

## Question 1: Why is multithreading important? Explain thread life cycle with proper state diagram. Write a program that reads data of employees from the keyboard and write it into the file emp.doc using proper exception handling with try…catch blocks.

**Example Program to Read Employee Data and Write to File:**

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

## Question 4: What is the difference between final, finally, and finalize keywords in Java?

In Java, the keywords `final`, `finally`, and `finalize` serve different purposes:

**final Keyword**

- The final keyword is used to restrict modification of variables, methods, and classes.
- A final variable acts as a constant and cannot be reassigned after initialization.
- A final method cannot be overridden by a subclass.
- A final class cannot be inherited by other classes.


```java
class FinalExample {
    final int x = 10;

    void display() {
        // x = 20; // Error: cannot change final variable
        System.out.println("Value of x: " + x);
    }
}
```


**finally Block**   
- The finally block is used in exception handling to execute important code after try and catch blocks
- The finally block is always executed whether an exception occurs or not.
- It is mainly used for closing resources like files or database connections.

```java
class FinallyExample {
    public static void main(String[] args) {
        try {
            int a = 10 / 0;
        } catch (Exception e) {
            System.out.println("Exception handled");
        } finally {
            System.out.println("Finally block executed");
        }
    }
}
```

**finalize() Method**

- The finalize() method is called by the garbage collector before destroying an object.
- It is defined in the Object class and can be overridden by the programmer.
- It is used to perform cleanup operations before memory is released.
- Execution of finalize() is not guaranteed every time.

```java
class FinalizeExample {
    protected void finalize() {
        System.out.println("Finalize method called");
    }

    public static void main(String[] args) {
        FinalizeExample obj = new FinalizeExample();
        obj = null;
        System.gc();
    }
}
```

In summary,
- `final` is a keyword used to declare constants, prevent method overriding, and inheritance.
- `finally` is a block used in exception handling to ensure that certain code is executed regardless of exceptions.
- `finalize` is a method that is called by the garbage collector before an object is destroyed, used for cleanup operations.


## Question 5: How is exception different from error? Differentiate throws and throw keywords. When is the block finally important?

**Exception vs Error**

| Aspect | Exception | Error |
|--------|-----------|-------|
| Definition | An exception is an event that occurs during the execution of a program that disrupts the normal flow of instructions. | An error is a serious problem that a reasonable application should not try to catch. |
| Nature | Exceptions are typically recoverable and can be handled by the application. | Errors are usually unrecoverable and indicate serious problems in the application or environment. |
| Cause | Exceptions can be caused by user input, file handling issues, or other runtime conditions. | Errors are often caused by issues like memory leaks, stack overflow, or hardware failures. |
| Handling | Exceptions can be caught and handled using try-catch blocks. | Errors are typically not handled by applications and are often fatal. |
| Examples | IOException, NullPointerException, ArithmeticException | OutOfMemoryError, StackOverflowError |



**throws vs throw**

| Aspect | throw | throws |
|--------|--------|-------|
| Definition | The `throw` keyword is used to explicitly throw an exception from a method or block of code. |  The `throws` keyword is used in method signatures to declare that a method may throw one or more exceptions. |
| Usage | Followed by an instance of an exception class. | Followed by a list of exception types that the method can throw. |
| Followed by | Followed by an instance of an exception class. | Followed by a list of exception types that the method can throw. |
| Number of exceptions | Can throw a single exception at a time. | Can declare multiple exceptions that a method may throw. |
| Function | It is used to signal that an exception has occurred. | It is used to inform the caller of a method about potential exceptions that may be thrown. |
| Example | `public void myMethod() { throw new IOException("File not found"); }` | `public void myMethod() throws IOException, SQLException { ... }` |


**Importance of finally block**
- The *finally* block is used to execute code after try and catch blocks.  
- The block always executes whether an exception occurs or not.  
- The block is important for closing resources like files and database connections.  
- The block ensures proper cleanup and avoids resource leakage.  
- The block may not execute in special cases such as System.exit().  



---

# 2080

## Question 1: Why do we need to synchronize the thread? Justify with an example. An array with an odd number of elements is said to be centered if all elements (except the middle one) are strictly greater than the value of the middle element. Note that only arrays with an odd number of elements have a middle element. Write a function that accepts an integer array and returns 1 if it is a centered array, otherwise it returns 0.

**Function to check if an array is a centered array:**

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

## Question 1: What are the uses of final modifier? Explain each use of the modifier with suitable example.


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

## Question 12: When thread synchronization is necessary? Explain with suitable example.


---

# 2079

## Question 1: Explain feature of object-oriented programming.  Create a class Distance with private variables feet of type integer and inches of type floating point. Use suitable constructor, and methods for adding and comparing two distance objects. [Hint: 1 feet = 12 inches]

**Object-Oriented Programming (OOP) Features:**
The features of OOP are given below:

1. **Classes and Object:**
- A class is a blueprint.
- An object is a real item made from that blueprint.
- Memory is created when object is made, not when class is written.
- Example: `Vehicle` is a class, and `Car`, `Bike`, `Bus` are objects.

2. **Abstraction:**
- Abstraction means showing only important details.
- Internal working is hidden from the user.
- Example: We use a switch to turn light on/off, but we do not know its internal circuit.

3. **Inheritance:**
- Inheritance means one class can use properties and methods of another class.
- Parent class gives features to child class.
- It helps in code reuse and reduces repeated code.
- Example: `Shape` is parent class; `Circle` and `Rectangle` are child classes.

4. **Polymorphism:**
- Polymorphism means "one name, many forms".
- Same method name can do different tasks.
- Types: compile-time polymorphism and run-time polymorphism.

5. **Method Overloading:**
- Same method name, but different parameter list.
- Decided at compile time.
- Example: `add(int, int)` and `add(float, float)`.

6. **Method Overriding:**
- Child class gives its own version of parent class method.
- Same method signature is used.
- Decided at run time.

7. **Encapsulation:**
- Encapsulation means wrapping data and methods in one class.
- Data is kept safe using `private` variables.
- Access is given through public methods like getters/setters.



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

##  Question 4: What is multithreading? How can you create multithreaded program in Java? Explain.
---

# 2078

## Question 4: What is package? How can you create your own package in Java? Explain with example.

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

## Question 7: When does the finally block is mandatory in while handling exception? Describe with a suitable scenario.


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

## Question 10: Why multiple inheritance is not allowed in Java using classes? Give an example.

- Multiple inheritance is not allowed in Java using classes because it can lead to ambiguity and complexity. 
- When a class inherits from two or more classes that have methods with the same signature, the compiler cannot determine which method to call, resulting in a "diamond problem". 
- This can cause confusion and errors in the code.
- To avoid this issue, Java does not allow multiple inheritance with classes. 
- Instead, Java provides interfaces to achieve multiple inheritance without ambiguity.

```java
class A {
    void display() {
        System.out.println("Class A");
    }
}
class B {
    void display() {
        System.out.println("Class B");
    }
}
class C extends A, B { // This will cause a compile-time error due to multiple inheritance
    public static void main(String[] args) {
        C c = new C();
        c.display(); // Which display method should be called? A's or B's?  
        }
}
```

In the above example, class C is trying to inherit from both class A and class B, which have a method named `display()`. This creates ambiguity for the compiler, as it cannot determine which `display()` method to call when an object of class C invokes it. This is why multiple inheritance using classes is not allowed in Java.

Example using interfaces to achieve multiple inheritance:

```java
interface A {
    void display();
}
interface B {
    void display();
}
class C implements A, B {
    public void display() {
        System.out.println("Class C implementing both A and B");
    }
    public static void main(String[] args) {
        C c = new C();
        c.display(); // This will call the display method in class C
    }
}
```
In this example, class C implements both interfaces A and B, which allows it to provide its own implementation of the `display()` method without any ambiguity. This is how Java achieves multiple inheritance using interfaces while avoiding the issues associated with multiple inheritance using classes.

## Question 12: Why synchronization in essential in multithreading? Describe.