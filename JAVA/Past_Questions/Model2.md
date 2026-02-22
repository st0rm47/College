# Model Set 2

## Question 1: Why is multithreading important? Explain thread life cycle with proper state diagram. Write a program that reads data of employees from the keyboard and write it into the file emp.doc using proper exception handling with try catch blocks.

**Multithreading**
- Multithreading is a concept in Java where multiple threads run concurrently within a single program. 
- It helps in performing multiple tasks simultaneously, improving performance and CPU utilization.

**Importance of Multithreading**
  1. **Improves Program Efficiency**
     - Multithreading allows a program to perform multiple tasks at the same time.  
     - It divides a large task into smaller threads that execute independently.  
     - This parallel execution improves the overall efficiency of the application.  
     - It helps in completing complex tasks faster compared to single-threaded execution.  

  2. **Better CPU Utilization**
     - Multithreading ensures that the CPU is not idle during program execution.  
     - While one thread is waiting for input/output operations, another thread can execute.  
     - This keeps the processor busy most of the time.  
     - It maximizes the usage of available system resources.  

  3. **Improves Application Responsiveness**
     - Multithreading makes applications more responsive, especially in user interfaces.  
     - In GUI applications, one thread can handle user input while another performs background tasks.  
     - It prevents applications from freezing during long-running operations.  
     - This is highly useful in web applications and desktop software.  

  4. **Reduces Execution Time**
     - Since multiple threads run in parallel, overall program execution time is reduced.  
     - Tasks that would take longer in a single thread complete faster in multithreading.  
     - It improves performance in large-scale applications.  
     - It is especially beneficial in CPU-intensive and I/O-intensive operations.

**Thread Life Cycle:**
1. **Newborn State**: 
   - A thread is in the Newborn state when it is created but not yet started.  
   - The thread object is created using the `Thread` class or implementing `Runnable`.  
   - In this state, the `start()` method has not been called yet.  
   - The thread is not scheduled for execution by the CPU.  
   - It remains inactive until it is started by the program. 
  
2. **Runnable State**:
   - A thread enters the Runnable state when the `start()` method is called.  
   - In this state, the thread is ready to run and is waiting for CPU allocation.  
   - The thread is placed in the thread queue managed by the thread scheduler.  
   - It does not mean the thread is running immediately; it is ready to run.  
   - The CPU scheduler selects threads from this pool for execution.  

3. **Running State**:
   - A thread enters the Running state when the CPU scheduler assigns CPU time to it.  
   - In this state, the thread executes its `run()` method.  
   - The thread performs its assigned task step by step.  
   - It may continue execution until completion or may be paused by the scheduler.  
   - Only one thread runs at a time per CPU core (in single-core systems).  
  
4. **Waiting / Blocked State**:
   - A thread enters this state when it cannot continue execution temporarily.  
   - It may be waiting for another thread to complete its task.  
   - It can also be blocked while waiting to acquire a lock on a resource.  
   - Methods like `wait()`, `sleep()`, or `join()` can cause this state.  
   - Once the condition is satisfied, the thread returns to the Runnable state.
  
5. **Terminated State**:
   - A thread enters the Terminated state when it completes its execution.  
   - It can also terminate due to an unhandled exception or error.  
   - Once a thread reaches this state, it cannot be restarted.  
   - The thread is removed from the system by the JVM.  
   - It represents the end of the thread lifecycle. 
  
        ![Thread Life Cycle Diagram](images\threads.png)




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

- In this program, we read employee details from the user and write them to a file named `emp.doc`.
- We use `try-catch` blocks to handle potential `IOException` during file operations and general exceptions during input.
- The `finally` block ensures that the Scanner resource is closed after use, preventing resource leaks
- This program demonstrates proper exception handling while performing file I/O operations and user input.
---

## Question 2: Write a program that divides the frame into five regions by using border layout and then add panels in the east, north and center region. Finally add some descriptive label in the north panel, buttons with icon in the east panel and a sample form in the center panel. You can further subdivide the center panel, if necessary. Prepare a program with three text boxes First Number, Second Number, and Result and four buttons add, subtract, multiply and divide. Handle  the events to perform the required operation and display results.

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CalculatorApp extends JFrame implements ActionListener {

    // Declare Buttons and Fields
    JLabel firstnumber, secondnumber, result;
    JTextField firsttext, secondtext, resulttext;
    JButton add, sub, mul, div;

    public CalculatorApp() {
        // Set the title of the frame
        setTitle("Calculator using BorderLayout");

        // Set the size of the frame
        setSize(400, 400);

        // Set the layout of the frame
        setLayout(new BorderLayout());

        // North Panel
        JPanel northPanel = new JPanel();
        JLabel title = new JLabel("Simple Calculator Application", JLabel.CENTER);
        northPanel.add(title);


        // East Panel (Buttons with icons)
        JPanel eastPanel = new JPanel();
        eastPanel.setLayout(new GridLayout(4,1));

        add = new JButton("Add");
        sub = new JButton("Subtract");
        mul = new JButton("Multiply");
        div = new JButton("Divide");

        // Add components to the east panel
        eastPanel.add(add);
        eastPanel.add(sub);
        eastPanel.add(mul);
        eastPanel.add(div);

        // Center Panel (Form)
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(3,2));

        firstnumber = new JLabel("First Number", JLabel.CENTER);
        firsttext = new JTextField(10);
        secondnumber = new JLabel("Second Number", JLabel.CENTER);
        secondtext = new JTextField(10);
        result = new JLabel("Result", JLabel.CENTER);
        resulttext = new JTextField(10);
        resulttext.setEditable(false);

        // Add components to the center panel
        centerPanel.add(firstnumber);
        centerPanel.add(firsttext);
        centerPanel.add(secondnumber);
        centerPanel.add(secondtext);
        centerPanel.add(result);
        centerPanel.add(resulttext);

        // Add panels to the window
        add(northPanel, BorderLayout.NORTH);
        add(eastPanel, BorderLayout.EAST);
        add(centerPanel, BorderLayout.CENTER);

        // Event Handling
        add.addActionListener(this);
        sub.addActionListener(this);
        mul.addActionListener(this);
        div.addActionListener(this);

        // Set App visibility
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            double num1 = Double.parseDouble(firsttext.getText());
            double num2 = Double.parseDouble(secondtext.getText());
            double result = 0;
            if (e.getSource() == add)
                result = num1 + num2;
            else if (e.getSource() == sub)
                result = num1 - num2;
            else if (e.getSource() == mul)
                result = num1 * num2;
            else if (e.getSource() == div)
                result = num1 / num2;
            resulttext.setText(String.valueOf(result));
        } catch (Exception ex) {
            resulttext.setText("Error");
        }
    }

    public static void main(String[] args) {
        new CalculatorApp();
    }
}
```
---


## Question 3: What is Servlet? Create an application where an HTML file displays a form containing field company name, city and ESTD and a save button and when we click on save button it must save records in the database.  

**Servlet**
- A Servlet is a Java class that handles HTTP requests and generates HTTP responses.  
- It runs inside a servlet container like Apache Tomcat.  
- It is part of Java EE (Jakarta EE) technology for web development.  
- It is mainly used to build dynamic, database-driven web applications.  

**Features of Servlet**
- It is platform independent because it is written in Java.  
- It is highly efficient due to multithreading support.  
- It is secure compared to traditional CGI programs.  
- It can handle multiple client requests simultaneously.  
- It provides better performance as it runs inside server memory. 

**Working of Servlet**
- The client sends a request through a web browser.  
- The request is received by the web server.  
- The server forwards the request to the servlet container.  
- The servlet processes the request and performs required operations.  
- The response is generated and sent back to the client. 

**Example Application to Save Records in Database**
1. Create an HTML form (index.html):
```html
<!DOCTYPE html>
<html>
<head>
    <title>Company Form</title>
</head>
<body>
    <h2>Company Details</h2>
    <form action="SaveServlet" method="post">
        Company Name: <input type="text" name="cname"><br><br>
        City: <input type="text" name="city"><br><br>
        ESTD: <input type="text" name="estd"><br><br>
        <input type="submit" value="Save">
    </form>
</body>
</html>
```

2. Create a Servlet (SaveServlet.java):
```java
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class SaveServlet extends HttpServlet {

    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String url = "jdbc:mysql://localhost:3306/test";
        String username = "root";
        String password = "password";

        String cname = request.getParameter("cname");
        String city = request.getParameter("city");
        String estd = request.getParameter("estd");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            // Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish a connection
            Connection con = DriverManager.getConnection(
                    url, username, password);

            // Sql query to insert data
            String sql = "INSERT INTO company (cname, city, estd) VALUES (?, ?, ?)";

            // Create a PreparedStatement
            PreparedStatement ps = con.prepareStatement(sql);

            // Set parameters
            ps.setString(1, cname);
            ps.setString(2, city);
            ps.setString(3, estd);

            // Execute the update
            int i = ps.executeUpdate();
            if (i > 0)
                out.println("Record Saved Successfully");
            else
                out.println("Error Saving Record");

            con.close();

        } catch (Exception e) {
            out.println(e);
        }
    }
}
```

---
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
  
---

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

## Question 6: Explain flow layout manager with suitable constructors and demonstrate it by  using suitable java code.  

**FlowLayout Manager**
- A FlowLayout Manager is a layout manager in Java used to arrange components in a linear sequence, similar to text in a paragraph. 
- It places components in a row and automatically wraps them to the next line when space is not sufficient.
- The FlowLayout manager is used to arrange components in left-to-right flow.  
- When the horizontal space is full, components are moved to the next line automatically.  
- It is the default layout manager for Panel in Java AWT.  
- It is simple and commonly used for basic GUI design.  


***Constructors of FlowLayout***
- `FlowLayout()` → Creates default FlowLayout with center alignment and default horizontal and vertical gaps.
- `FlowLayout(int align)` → Creates FlowLayout with specified alignment (LEFT, CENTER, RIGHT).  
- `FlowLayout(int align, int hgap, int vgap)` → Creates FlowLayout with alignment and custom horizontal and vertical gaps.

***Common alignment constants:***
- `FlowLayout.LEFT` → Aligns components to the left.  
- `FlowLayout.CENTER` → Aligns components to the center.  
- `FlowLayout.RIGHT` → Aligns components to the right.  


```java
import java.awt.*;

public class FlowLayoutDemo extends Frame {

    public FlowLayoutDemo() {
        setTitle("FlowLayout Example");
        setSize(400, 300);

        // Setting FlowLayout with LEFT alignment and gaps
        setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));

        // Adding components
        add(new Button("Button 1"));
        add(new Button("Button 2"));
        add(new Button("Button 3"));
        add(new Button("Button 4"));
        add(new Button("Button 5"));
        add(new Button("Button 6"));

        setVisible(true);

        // Close window
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new FlowLayoutDemo();
    }
}
```

---


## Question 7:  Write a program to create a form with employee id, name, salary fields and two  buttons add and cancel using appropriate components.

```java

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EmployeeForm extends JFrame implements ActionListener {

    // Declare Fields and Labels
    JLabel l1, l2, l3;
    JTextField t1, t2, t3;
    JButton add, cancel;

    public EmployeeForm() {

        // Set the title of the frame
        setTitle("Employee Form");

        // Set the size of the frame
        setSize(400, 300);

        // Set the default close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Set layout of the frame
        setLayout(new GridLayout(4, 2, 10, 10));

        // Labels and TextFields
        l1 = new JLabel("Employee ID:");
        l2 = new JLabel("Name:");
        l3 = new JLabel("Salary:");

        t1 = new JTextField();
        t2 = new JTextField();
        t3 = new JTextField();

        // Buttons
        add = new JButton("Add");
        cancel = new JButton("Cancel");

        // Adding components to the frame
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(add);
        add(cancel);

        // Event handling
        add.addActionListener(this);
        cancel.addActionListener(this);

        // Add visibility
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == add) {
            System.out.println("Employee Added:");
            System.out.println("ID: " + t1.getText());
            System.out.println("Name: " + t2.getText());
            System.out.println("Salary: " + t3.getText());
        }

        if (e.getSource() == cancel) {
            t1.setText("");
            t2.setText("");
            t3.setText("");
        }
    }
    public static void main(String[] args) {
        new EmployeeForm();
    }
}
```

---

## Question 8: What is an adapter class? Explain advantages of adapter classes over listener interfaces with suitable examples.  

**Adapter Class**
- An adapter class in Java is a class that provides default implementations for all methods of an interface. 
- It allows you to create a listener by extending the adapter class and overriding only the methods you need, rather than implementing all methods of the interface.
- It is mainly used in event handling in Java AWT and Swing to simplify the process of creating event listeners.
- Example: MouseAdapter, KeyAdapter, WindowAdapter are some of the commonly used adapter classes in Java.


**Advantages of Adapter Classes over Listener Interfaces:**
- **Simplicity**: 
  - Adapter classes provide default implementations for all methods, allowing you to override only the methods you need.
  -  This simplifies the code and reduces boilerplate.
  
- **Less Code**: 
    - When using listener interfaces, you must implement all methods, even if you only need one or two. 
    - Adapter classes eliminate the need to implement unused methods.
  
- **Improved Readability**: 
  - Using adapter classes can make the code more readable and maintainable, as it focuses on the relevant methods rather than cluttering the code with empty method implementations.
  
- **Flexibility**: 
  - Adapter classes allow you to create custom listeners by extending the adapter class, giving you more flexibility in handling events.

**Example using MouseListener (without adapter):**
```java
import java.awt.*;
import java.awt.event.*;
public class MouseListenerExample extends MouseListener {
    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse Clicked at: " + e.getPoint());
    }
    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
}
```

**Example using MouseAdapter:**
```java
import java.awt.*;
import java.awt.event.*;
public class MouseAdapterExample {
    
    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse Clicked at: " + e.getPoint());
    }
}
```

- In the above examples, using MouseAdapter allows us to only implement the `mouseClicked` method.
- While using MouseListener requires us to implement all methods, even if they are not needed.
---
