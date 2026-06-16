# 2082

## Question 3: Discuss about JSP implicit objects.

## Question 5: How do you handle HTTP Request and Response using JSP?

## Question 6: Describe the life cycle of servlet.

---

# Model 2

## Question 3: What is Servlet? Create an application where an HTML file displays a form containing field company name, city and ESTD and a save button and when we click on save button it must save records in the database.

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

# 2081

## Question 10: Explain the life cycle of a servlet.

## Question 11: Write a program in JSP to display the string taken in one page in another page.

## Question 12: Distinguish GET and POST Request

| GET Request | POST Request |
|-------------|--------------|
| GET requests are used to retrieve data from the server. | POST requests are used to send data to the server for processing. |
| GET requests append data to the URL, making it visible in the browser's address bar. | POST requests send data in the request body, keeping it hidden from the URL. |
| GET requests have a size limit (usually around 2048 characters) due to URL length restrictions. | POST requests do not have a size limit, allowing for larger amounts of data to be sent. |
| GET requests can be cached by browsers and are bookmarkable. | POST requests cannot be cached and are not bookmarkable. |
| GET requests are idempotent, meaning they can be repeated without causing side effects. | POST requests are not idempotent, as they may cause changes on the server each time they are executed. |
| GET requests are generally faster than POST requests due to their simplicity. | POST requests may take longer to process due to the need to handle the request body and potential server-side processing. |
| GET requests are suitable for retrieving data or performing actions that do not modify server state. | POST requests are suitable for submitting forms, uploading files, or performing actions that modify server state. |


---


# 2080

## Question 2: How does JSP differ from Servlet and show the life cycle of Servlet? How do you create and read the cookies and session using JSP? Illustrate with an example.

## Question 8: What do you mean by JSP implicit objects? Discuss Java Mail API.

---

# Model 1

## Question 3: Discuss various scopes of JSP objects briefly. Create a HTML file with principal, time and rate. Then create a JSP file that reads values from the HTML form, calculates simple interest and displays it

1. Create an HTML form (index.html):
```html
<!DOCTYPE html>
<html>
<head>
    <title>Simple Interest Calculator</title>
</head>
<body>
    <h2>Simple Interest Calculator</h2>
    <form action="CalculateInterest.jsp" method="post">
        Principal: <input type="text" name="principal"><br><br>
        Time (in years): <input type="text" name="time"><br><br>
        Rate of Interest: <input type="text" name="rate"><br><br>
        <input type="submit" value="Calculate">
    </form>
</body>
</html>
```

2. Create a JSP file (CalculateInterest.jsp):
```jsp
<%@ page language="java"%>

<html>
<head>
    <title>Simple Interest Result</title>
</head>
<body>
    <h2>Simple Interest Result</h2>
    <%
        // Read values from the form
        double principal = Double.parseDouble(request.getParameter("principal"));
        double time = Double.parseDouble(request.getParameter("time"));
        double rate = Double.parseDouble(request.getParameter("rate"));

        // Calculate simple interest
        double simpleInterest = (principal * time * rate) / 100;

    %>

    <p> <b> Simple Interest: </b> <%= simpleInterest %></p>
</body>
</html>
```

## Question 10: What are different ways of writing servlet programs? Write a sample Servlet program using any one way.

---

# 2079

## Question 3: Define JSP. What are the benefits of using JSP? Create a HTML file with two text fields to first name and last name. Create a JSP file that reads data from the HTML form and display full name.

1. Create an HTML form (index.html):
```html
<!DOCTYPE html>
<html>
<head>
    <title>Full Name Form</title>
</head>
<body>
    <h2>Enter Your Name</h2>
    <form action="FullName.jsp" method="post">
        First Name: <input type="text" name="firstName"><br><br>
        Last Name: <input type="text" name="lastName"><br><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
```

2. Create a JSP file (FullName.jsp):
```jsp
<%@ page language="java"%>
<!DOCTYPE html>
<html>
<head>
    <title>Full Name Result</title>
</head>
<body>
    <h2>Full Name Result</h2>
    <%
        // Read values from the form
        String firstName = request.getParameter("firstName");
        String lastName = request.getParameter("lastName");

        // Concatenate to get full name
        String fullName = firstName + " " + lastName;
    %>

    <p> <b> Full Name: </b> <%= fullName %></p>
</body>
</html>
```


## Question 10: Compare JSP with servlet. What are different implicit objects in JSP?


---

# 2078

## Question 2: Explain life-cycle of servlet in detail. Create a simple servlet that reads and displays data from HTML form. Assume form with two fields username and password.

1. Create an HTML form (index.html):
```html
<!DOCTYPE html>
<html>
<head>
    <title>Login Form</title>
</head>
<body>
    <h2>Login Form</h2>
    <form action="LoginServlet" method="post">
        Username: <input type="text" name="username"><br><br>
        Password: <input type="password" name="password"><br><br>
        <input type="submit" value="Login">
    </form>
</body>
</html>
```

2. Create a Servlet (LoginServlet.java):
```java
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class LoginServlet extends HttpServlet {

    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String username = request.getParameter("username");
        String password = request.getParameter("password");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        // For demonstration, we will just display the username and password
        out.println("<html><body>");
        out.println("<h2>Login Details</h2>");
        out.println("<p>Username: " + username + "</p>");
        out.println("<p>Password: " + password + "</p>");
        out.println("</body></html>");
    }
}
```

## Question 10: What is servlet? Write a simple JSP file to display “Tribhuwan University” five times.

1. Create a JSP file (DisplayUniversity.jsp):
```jsp
<%@ page language="java"%>
<html>
<head>
    <title>University Display</title>
</head>
<body>
    <h2>Tribhuwan University</h2>
    <%
        for (int i = 1; i <= 5; i++) {
            out.println(i  + ". Tribhuwan University <br>");
        }
    %>
</body>
</html>
```

---

# 2077

## Question 8: Explain the life cycle of a servlet.

## Question 11: How forms can be created and processed using JSP? Make it clear with your own assumptions.

## Question 13: Write short notes on:

a) Java Beans:
- JavaBeans are reusable software components for Java that can be manipulated visually in a builder tool. 
- They follow specific conventions, such as having a no-argument constructor, providing getter and setter methods for accessing properties, and being serializable.
- JavaBeans are used to encapsulate many objects into a single object (the bean), so that they can be passed around as a single bean object instead of as multiple individual objects.
- They are commonly used in JSP to manage application data and logic, allowing for separation of concerns between the presentation layer and business logic.
- Example:
```java
public class UserBean implements java.io.Serializable {
    private String name;
    private int age;

    public UserBean() {
        // No-argument constructor
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
```

b) JAR Files:
- JAR (Java ARchive) files are packages of Java classes and associated metadata and resources (text, images, etc.) that are bundled together into a single file for distribution.
- JAR files are used to aggregate many files into one, making it easier to distribute and deploy Java applications and libraries.
- They can be executed as standalone applications if they contain a manifest file specifying the main class.
- JAR files can also be used as libraries that can be included in other Java projects to provide additional functionality.
- Example of creating a JAR file:
```bash
jar cf mylibrary.jar com/mycompany/mypackage/*.class
```

c) MVC Design Pattern:
- MVC (Model-View-Controller) is a design pattern used in software engineering to separate the application into three interconnected components: Model, View, and Controller.
- Model: Represents the data and business logic of the application. It manages the data, logic, and rules of the application.
- View: Represents the presentation layer of the application. It displays the data to the user and sends user commands to the controller.
- Controller: Acts as an intermediary between the Model and the View. It processes user input, interacts with the Model to retrieve data, and updates the View accordingly.
- The MVC pattern helps in organizing code, improving maintainability, and allowing for separation of concerns.
- Example of MVC in a web application:
  - Model: A Java class that interacts with the database to retrieve and store data.
  - View: A JSP file that displays the data to the user.
  - Controller: A Servlet that handles user requests, interacts with the Model to get data, and forwards the request to the View for display.
- Example:
```java
// Model
public class User {
    private String name;
    private int age;

    // Getters and setters
}
// Controller (Servlet)
public class UserController extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        User user = new User();
        user.setName("John Doe");
        user.setAge(30);
        request.setAttribute("user", user);
        RequestDispatcher dispatcher = request.getRequestDispatcher("userView.jsp");
        dispatcher.forward(request, response);
    }
}
// View (userView.jsp)
<%@ page language="java"%>
<html>
<head>
    <title>User Information</title>
</head>
<body>
    <h2>User Information</h2>
    <p>Name: ${user.name}</p>
    <p>Age: ${user.age}</p>
</body>
</html>
```