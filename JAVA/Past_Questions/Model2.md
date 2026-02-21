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

  