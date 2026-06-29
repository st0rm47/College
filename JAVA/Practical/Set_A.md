# 1.	Design and develop a Java Swing application to manage Student records. The application should connect to a backend database (MySQL/PostgreSQL/Oracle) using JDBC.

a.	Database Setup: Create a table named students with the following columns:
-	roll_no (Primary Key, Integer)
-	name (Varchar)
-	age (Integer)
-	course (Varchar)

b.	UI Design: Build a GUI using JFrame that includes:
-	Labels and TextFields for Roll No, Name, Age, and Course.
-	An "Insert" button to save data to the database.
-	A "Clear" button to reset the input fields.

c.	Functionality:
-	Implement ActionListener for the buttons.
-	Use PreparedStatement to handle the SQL insertion.
-	Show a JOptionPane alert message for "Success" or "Error."
---

### Database
```sql
CREATE DATABASE student_db;

USE student_db;

CREATE TABLE students(
    roll_no INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    course VARCHAR(50)
);
```

### DBConnection.java
```java
import java.sql.*;
public class DBConnection {
    public static Connection getConnection() {
        Connection con = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/student_db";
            String username = "root";
            String password = "";
            con = DriverManager.getConnection(url, username, password);
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return con;
    }
}
```

### StudentForm.java
```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class StudentForm extends JFrame implements ActionListener {
    // Labels
    JLabel lblRoll = new JLabel("Roll No");
    JLabel lblName = new JLabel("Name");
    JLabel lblAge = new JLabel("Age");
    JLabel lblCourse = new JLabel("Course");

    // TextFields
    JTextField txtRoll = new JTextField();
    JTextField txtName = new JTextField();
    JTextField txtAge = new JTextField();
    JTextField txtCourse = new JTextField();

    // Buttons
    JButton btnInsert = new JButton("Insert");
    JButton btnClear = new JButton("Clear");

    public StudentForm() {
        setTitle("Student Registration");
        setSize(400,300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(5,2,10,10));

        add(lblRoll);
        add(txtRoll);
        add(lblName);
        add(txtName);
        add(lblAge);
        add(txtAge);
        add(lblCourse);
        add(txtCourse);
        add(btnInsert);
        add(btnClear);

        btnInsert.addActionListener(this);
        btnClear.addActionListener(this);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Insert Button
        if(e.getSource()==btnInsert){
            if(txtRoll.getText().isEmpty() ||
               txtName.getText().isEmpty() ||
               txtAge.getText().isEmpty() ||
               txtCourse.getText().isEmpty()){

                JOptionPane.showMessageDialog(this, "Please Fill All Fields");
                return;
            }
            try{
                int rollNo = Integer.parseInt(txtRoll.getText());
                int age = Integer.parseInt(txtAge.getText());
                String course = txtCourse.getText();
                String name = txtName.getText();

                Connection con = DBConnection.getConnection();
                String sql = "insert into students values(?,?,?,?)";
                PreparedStatement ps = con.prepareStatement(sql);
                ps.setInt(1, rollNo);
                ps.setString(2, name);
                ps.setInt(3, age);
                ps.setString(4, course);
                ps.executeUpdate();

                JOptionPane.showMessageDialog(this, "Record Inserted Successfully");
                con.close();
            } catch(Exception ex){
                JOptionPane.showMessageDialog(this, "Error : "+ex.getMessage());
            }
        }

        // Clear Button
        if(e.getSource()==btnClear){
            txtRoll.setText("");
            txtName.setText("");
            txtAge.setText("");
            txtCourse.setText("");
        }
    }

    public static void main(String[] args) {
        new StudentForm();
    }
}
```
---




# 2. Develop a Java Web Application using Servlets to perform basic arithmetic addition. The application must separate the input interface from the processing logic and the result display.
A.  Input Page (input.html):
-	Create an HTML form with two input fields of type number.
-	Include a "Submit" button to send the data to the Servlet.
-	The form should use the POST method for data transmission.

B. Processing Logic (AdditionServlet.java):
-	Create a Servlet that handles the incoming POST request.
-	Retrieve the two numbers using the appropriate request methods.
-	Perform the addition logic (handling potential NumberFormatException).

C. Output Page:
-	The Servlet should dynamically generate a new HTML response page.
-	The result page must clearly display the two input values and their calculated sum
---

### Input.html
```html
<!DOCTYPE html>
<html>
<head>
    <title>Addition Form</title>
</head>
<body>

<h2>Add Two Numbers</h2>

<form action="addition" method="post">

    Number 1:
    <input type="number" name="num1"><br><br>

    Number 2:
    <input type="number" name="num2"><br><br>

    <input type="submit" value="Add">

</form>

</body>
</html>
```

### AdditionServlet.java
```java
package org.example.servletpractical;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.WebServlet;

public class AdditionServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request,
                          HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html");

        PrintWriter out = response.getWriter();

        try {

            // Read values from HTML form
            int num1 = Integer.parseInt(request.getParameter("num1"));
            int num2 = Integer.parseInt(request.getParameter("num2"));

            // Perform addition
            int sum = num1 + num2;

            // Display result
            out.println("<html>");
            out.println("<body>");

            out.println("<h2>Addition Result</h2>");

            out.println("<p>First Number : " + num1 + "</p>");

            out.println("<p>Second Number : " + num2 + "</p>");

            out.println("<h3>Sum = " + sum + "</h3>");

            out.println("</body>");
            out.println("</html>");

        }

        catch(NumberFormatException e){

            out.println("<h3>Invalid Input!</h3>");

        }

    }

}
```

### Web.xml
```xml
<servlet>
    <servlet-name>AdditionServlet</servlet-name>
    <servlet-class>org.example.servletpractical.AdditionServlet</servlet-class>
</servlet>

<servlet-mapping>
    <servlet-name>AdditionServlet</servlet-name>
    <url-pattern>/addition</url-pattern>
</servlet-mapping>
```

---

# 3. Develop a distributed application using Java RMI that allows a client to perform arithmetic operations on a remote server. The client should send two numbers to the server, and the server should return the result of their addition.

a.	Define the Remote Interface (Calculator.java):
-	Define an interface.
-	Declare a method add(int x, int y).

b.	Implement the Remote Object (CalculatorImpl.java):
-	Implement the Calculator interface.
-	Extend UnicastRemoteObject to allow the object to be exported to the RMI runtime.
-	Provide the logic for the add method.

c.	Develop the Server (RMIServer.java):
-	Create an instance of the remote object.
-	Bind (register) the object in the RMI Registry using a unique name (e.g., "ComputeSum").
-	Print a message to the console indicating the server is ready.

d.	Develop the Client (RMIClient.java):
-	Look up the remote object in the RMI Registry on the localhost.
-	Invoke the add method with two integer values.
-	Display the result returned by the server.
---

### Calculator.java
```java

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Calculator extends Remote {

    int add(int x, int y) throws RemoteException;

}
```

### CalculatorImpl.java
```java

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class CalculatorImpl extends UnicastRemoteObject implements Calculator {

    public CalculatorImpl() throws RemoteException {
        super();
    }

    @Override
    public int add(int x, int y) throws RemoteException {
        return x + y;
    }

}
```


### RMIServer.java
```java

import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class RMIServer {

    public static void main(String[] args) {

        try {

            // Create RMI Registry
            LocateRegistry.createRegistry(1099);

            // Create Remote Object
            CalculatorImpl obj = new CalculatorImpl();

            // Bind Object
            Naming.rebind("ComputeSum", obj);

            System.out.println("RMI Server is Ready.");

        }

        catch (Exception e) {

            e.printStackTrace();

        }

    }

}
```

### RMIClient.java
```java
import java.rmi.Naming;
import java.util.Scanner;

public class RMIClient {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {

            // Lookup Remote Object
            Calculator cal = (Calculator)
                    Naming.lookup("rmi://localhost/ComputeSum");

            // Input
            System.out.print("Enter First Number: ");
            int a = sc.nextInt();

            System.out.print("Enter Second Number: ");
            int b = sc.nextInt();

            // Call Remote Method
            int result = cal.add(a, b);

            // Display Result
            System.out.println("Sum = " + result);

        }

        catch (Exception e) {

            e.printStackTrace();

        }

    }

}
```
---