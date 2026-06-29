# 1.	Design and develop a Java Swing application to manage Employee records. The application should connect to a backend database (MySQL/PostgreSQL/Oracle) using JDBC.
Requirements:

a.	Database Setup: Create a table named employees with the following columns:
-	emp_id (Primary Key, Integer)
-	name (Varchar)
-	age (Integer)
-	department (Varchar)

b.	UI Design: Build a GUI using JFrame that includes:
-	Labels and TextFields for Name, Age, and Department.
-	An "Insert" button to save data to the database.
-	A "Clear" button to reset the input fields.

c.	Functionality:
-	Implement ActionListener for the buttons.
-	Use PreparedStatement to handle the SQL insertion.
-	Show a JOptionPane alert message for "Success" or "Error."
---

### Database
```sql
CREATE DATABASE employee_db;

USE employee_db;

CREATE TABLE employees(
    emp_id INT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    department VARCHAR(50)
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
            String url = "jdbc:mysql://localhost:3306/employee_db";
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

### EmployeeForm.java

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class EmployeeForm extends JFrame implements ActionListener {

    // Labels
    JLabel lblId = new JLabel("Employee ID");
    JLabel lblName = new JLabel("Name");
    JLabel lblAge = new JLabel("Age");
    JLabel lblDepartment = new JLabel("Department");

    // Text Fields
    JTextField txtId = new JTextField();
    JTextField txtName = new JTextField();
    JTextField txtAge = new JTextField();
    JTextField txtDepartment = new JTextField();

    // Buttons
    JButton btnInsert = new JButton("Insert");
    JButton btnClear = new JButton("Clear");

    public EmployeeForm() {

        setTitle("Employee Registration");

        setSize(400,300);

        setDefaultCloseOperation(EXIT_ON_CLOSE);

        setLocationRelativeTo(null);

        setLayout(new GridLayout(5,2,10,10));

        add(lblId);
        add(txtId);

        add(lblName);
        add(txtName);

        add(lblAge);
        add(txtAge);

        add(lblDepartment);
        add(txtDepartment);

        add(btnInsert);
        add(btnClear);

        btnInsert.addActionListener(this);
        btnClear.addActionListener(this);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        // Insert Button
        if(e.getSource() == btnInsert){

            if(txtId.getText().isEmpty() ||
               txtName.getText().isEmpty() ||
               txtAge.getText().isEmpty() ||
               txtDepartment.getText().isEmpty()){

                JOptionPane.showMessageDialog(this,
                        "Please Fill All Fields");

                return;
            }

            try{

                Connection con = DBConnection.getConnection();

                String sql = "INSERT INTO employees VALUES(?,?,?,?)";

                PreparedStatement ps = con.prepareStatement(sql);

                ps.setInt(1,
                        Integer.parseInt(txtId.getText()));

                ps.setString(2,
                        txtName.getText());

                ps.setInt(3,
                        Integer.parseInt(txtAge.getText()));

                ps.setString(4,
                        txtDepartment.getText());

                ps.executeUpdate();

                JOptionPane.showMessageDialog(this,
                        "Employee Record Inserted Successfully");

                con.close();

            }

            catch(Exception ex){

                JOptionPane.showMessageDialog(this,
                        "Error : " + ex.getMessage());

            }

        }

        // Clear Button
        if(e.getSource() == btnClear){

            txtId.setText("");
            txtName.setText("");
            txtAge.setText("");
            txtDepartment.setText("");

        }

    }

    public static void main(String[] args) {

        new EmployeeForm();

    }
}
```

---

# 2. Develop a Java Web Application using Servlets to perform basic arithmetic subtraction. The application must separate the input interface from the processing logic and the result display.
A.  Input Page (input.html):
-	Create an HTML form with two input fields of type number.
-	Include a "Submit" button to send the data to the Servlet.
-	The form should use the POST method for data transmission.

B. Processing Logic (SubtractionServlet.java):
-	Create a Servlet that handles the incoming POST request.
-	Retrieve the two numbers using the appropriate request methods.
-	Perform the subtraction logic (handling potential NumberFormatException).

C. Output Page:
-	The Servlet should dynamically generate a new HTML response page.
-	The result page must clearly display the two input values and their calculated difference
---

### Input.html
```html
<!DOCTYPE html>
<html>
<head>
    <title>Subtraction Form</title>
</head>
<body>

<h2>Subtract Two Numbers</h2>

<form action="subtraction" method="post">

    Number 1:
    <input type="number" name="num1"><br><br>

    Number 2:
    <input type="number" name="num2"><br><br>

    <input type="submit" value="Subtract">

</form>

</body>
</html>
```

### SubtractionServlet.java
```java
package org.example.servletpractical;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.WebServlet;

public class SubtractionServlet extends HttpServlet {

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

            // Perform subtraction
            int difference = num1 - num2;

            // Display result
            out.println("<html>");
            out.println("<body>");

            out.println("<h2>Subtraction Result</h2>");

            out.println("<p>First Number : " + num1 + "</p>");

            out.println("<p>Second Number : " + num2 + "</p>");

            out.println("<h3>Difference = " + difference + "</h3>");

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
    <servlet-name>SubtractionServlet</servlet-name>
    <servlet-class>org.example.servletpractical.SubtractionServlet</servlet-class>
</servlet>

<servlet-mapping>
    <servlet-name>SubtractionServlet</servlet-name>
    <url-pattern>/subtraction</url-pattern>
</servlet-mapping>
```

---


# 3. Develop a distributed application using Java RMI that allows a client to perform arithmetic operations on a remote server. The client should send two numbers to the server, and the server should return the result of their multiplication.

a.	Define the Remote Interface (Calculator.java):
-	Define an interface.
-	Declare a method multiply(int x, int y).

b.	Implement the Remote Object (CalculatorImpl.java):
-	Implement the Calculator interface.
-	Extend UnicastRemoteObject to allow the object to be exported to the RMI runtime.
-	Provide the logic for the multiply method.

c.	Develop the Server (RMIServer.java):
-	Create an instance of the remote object.
-	Bind (register) the object in the RMI Registry using a unique name (e.g., "ComputeProduct").
-	Print a message to the console indicating the server is ready.

d.	Develop the Client (RMIClient.java):
-	Look up the remote object in the RMI Registry on the localhost.
-	Invoke the multiply method with two integer values.
-	Display the result returned by the server.
---

### Calculator.java
```java

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Calculator extends Remote {

    int multiply(int x, int y) throws RemoteException;

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
    public int multiply(int x, int y) throws RemoteException {
        return x * y;
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
            Naming.rebind("ComputeProduct", obj);

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
                    Naming.lookup("rmi://localhost/ComputeProduct");

            // Input
            System.out.print("Enter First Number: ");
            int a = sc.nextInt();

            System.out.print("Enter Second Number: ");
            int b = sc.nextInt();

            // Call Remote Method
            int result = cal.multiply(a, b);

            // Display Result
            System.out.println("Product = " + result);

        }

        catch (Exception e) {

            e.printStackTrace();

        }

    }

}
```
---