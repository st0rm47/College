# 2082


## Question 3: Discuss about JSP implicit objects. Assume a database with the table TEACHER (ID, Name). Now using JDBC, execute the following SQL query:

```sql
SELECT * FROM TEACHER
INSERT INTO TEACHER VALUES (9, 'Ramesh')
SELECT name FROM TEACHER WHERE id = 9;
```

```java
import java.sql.*;
public class JDBCDemo{
    public static void main(String[] args){
        Class.forName("com.mysql.cj.jdbc.Driver");

        String url = "jdbc:mysql://localhost:3306/your_database";
        String username = "your_username";
        String password = "your_password";

        try{
            Connection con = DriverManager.getConnection(url,username,password);

            Statement stmt = con.createStatement();

            String query1 = "SELECT * FROM TEACHER";
            ResultSet rs1 = stmt.executeQuery(query1);
            while(rs1.next()){
                System.out.println("ID: " + rs1.getInt("ID") + ", Name: " + rs1.getString("Name"));
            }

            String query2 = "INSERT INTO TEACHER VALUES (9, 'Ramesh')";
            stmt.executeUpdate(query2);
            
            String query3 = "SELECT name FROM TEACHER WHERE id = 9";
            ResultSet rs3 = stmt.executeQuery(query3);
            if(rs3.next()){
                System.out.println("Name of teacher with ID 9: " + rs3.getString("name"));
            }
            con.close();
            rs1.close();
            rs3.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}    
```
---


## Question 4: Write a program to insert an icon in the frame and when the user presses the up arrow, it will move upward.

```java
import javax.swing.*;
import java.awt.event.*;

public class IconMover extends JFrame {

    JLabel iconLabel;
    int x = 150, y = 150;

    public IconMover() {

        setTitle("Icon Mover");
        setSize(400, 400);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Load icon
        ImageIcon icon = new ImageIcon("icon.png");

        iconLabel = new JLabel(icon);
        iconLabel.setBounds(x, y, 100, 100);
        add(iconLabel);

        addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_UP) {
                    y = y - 10;
                    iconLabel.setBounds(x, y, 100, 100);
                }
            }
        });

        setFocusable(true);
        setVisible(true);
    }

    public static void main(String[] args) {
        new IconMover();
    }
}

```


---
## Question 8: Write a program to design a layout of a simple calculator.

```java
import javax.swing.*;
import java.awt.*;

public class CalculatorLayout extends JFrame {
    JTextField display;

    public CalculatorLayout() {
        // Set the title of the frame
        setTitle("Simple Calculator");

        // Set the size of the frame
        setSize(400, 300);

        // Set the default close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set the layout of the frame
        setLayout(new BorderLayout());

        // Display field
        display = new JTextField();
        add(display, BorderLayout.NORTH);

        // Panel for buttons
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 4, 5, 5));

        // Button labels
        String[] buttons = {
                "7","8","9","/",
                "4","5","6","*",
                "1","2","3","-",
                "0","C","=","+"
        };

        // Create buttons and add to panel
        for (String text : buttons) {
            JButton btn = new JButton(text);
            panel.add(btn);
        }

        // Add the panel to the center
        add(panel, BorderLayout.CENTER);

        setVisible(true);
    }

    public static void main(String[] args) {
        new CalculatorLayout();
    }
}
```


---


# 2081

## Question 7: Design a simple form that takes name, password, hobbies and gender as input.

```java

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleForm extends JFrame implements ActionListener {
    JTextField nameField;
    JPasswordField passwordField;
    JCheckBox hobby1, hobby2;
    JRadioButton male, female, other;
    public SimpleForm() {

        setTitle("Simple Form");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(new FlowLayout());

        // Name
        JLabel nameLabel = new JLabel("Name:");
        nameField = new JTextField(20);
        add(nameLabel);
        add(nameField);

        // Password
        JLabel passwordLabel = new JLabel("Password:");
        passwordField = new JPasswordField(20);
        add(passwordLabel);
        add(passwordField);

        // Hobbies
        JLabel hobbiesLabel = new JLabel("Hobbies:");
        hobby1 = new JCheckBox("Reading");
        hobby2 = new JCheckBox("Traveling");

        add(hobbiesLabel);
        add(hobby1);
        add(hobby2);

        // Gender
        JLabel genderLabel = new JLabel("Gender:");
        male = new JRadioButton("Male");
        female = new JRadioButton("Female");
        other = new JRadioButton("Other");

        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(male);
        genderGroup.add(female);
        genderGroup.add(other);

        add(genderLabel);
        add(male);
        add(female);
        add(other);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(this);
        add(submitButton);

        setVisible(true);


    @Override
    public void actionPerformed(ActionEvent e) {
        // Handle button actions
        String cmd = e.getActionCommand();
        if (cmd.equals("Submit")) {
            String name = nameField.getText();
            String password = new String(passwordField.getPassword());
            String hobbies = "";
            if (hobby1.isSelected()) hobbies += "Reading ";
            if (hobby2.isSelected()) hobbies += "Traveling ";
            String gender = "" ;
            if (male.isSelected()) gender = "Male";
            else if (female.isSelected()) gender = "Female";
            else if (other.isSelected()) gender = "Other";

            JOptionPane.showMessageDialog(this, "Name: " + name + "\nPassword: " + password + "\nHobbies: " + hobbies + "\nGender: " + gender);
        }

    }

    public static void main(String[] args) {
        new SimpleForm();
    }
}
```
---

# Model Set 2

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

        add(northPanel, BorderLayout.NORTH);


        // East Panel (Buttons with icons)
        JPanel eastPanel = new JPanel();
        eastPanel.setLayout(new GridLayout(4,1));

        add = new JButton("Add", new ImageIcon("add.png"));
        sub = new JButton("Subtract", new ImageIcon("subtract.png"));
        mul = new JButton("Multiply", new ImageIcon("multiply.png"));
        div = new JButton("Divide", new ImageIcon("divide.png"));

        // Add components to the east panel
        eastPanel.add(add);
        eastPanel.add(sub);
        eastPanel.add(mul);
        eastPanel.add(div);

        add(eastPanel, BorderLayout.EAST);


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
        sum = new JButton("Add");
        cancel = new JButton("Cancel");

        // Adding components to the frame
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(l3);
        add(t3);
        add(sum);
        add(cancel);

        // Event handling
        sum.addActionListener(this);
        cancel.addActionListener(this);

        // Add visibility
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == sum) {
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


# 2080

## Question 3: Describe any two types of Layout manager. Using swing components, design a form with three buttons with captions “RED,” “BLUE,” and “GREEN,” respectively. Then write a program to handle the event such that when the user clicks the button, the color of that button will be the same as its caption.


```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Form3Buttons extends JFrame implements ActionListener {
    /// Declare Buttons
    JButton redButton, blueButton, greenButton;

    /// Declare Fields and Labels
    JLabel nameLabel;
    JTextField nameField;

    public Form3Buttons() {
        /// Set the title of the frame
        setTitle("Form with 3 Color Buttons");

        /// Set the size of the frame
        setSize(400, 400);

        /// Set the layout of the frame
        setLayout(new FlowLayout());

        ///  Create Form
        nameLabel = new JLabel("Name:", JLabel.CENTER);
        nameField = new JTextField(20);

        /// Create buttons
        redButton = new JButton("Red");

        blueButton = new JButton("Blue");
        greenButton = new JButton("Green");

        ///  Add label and fields to the frame
        add(nameLabel);
        add(nameField);

        /// Add buttons to the frame
        add(redButton);
        add(blueButton);
        add(greenButton);

        ///  Add ActionListeners
        redButton.addActionListener(this);
        blueButton.addActionListener(this);
        greenButton.addActionListener(this);

        ///  Set Visibility
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

            if (e.getSource() == redButton) {
                redButton.setBackground(Color.RED);
            }

            if (e.getSource() == blueButton) {
                blueButton.setBackground(Color.BLUE);
            }

            if (e.getSource() == greenButton) {
                greenButton.setBackground(Color.GREEN);
            }
    }

    public static void main(String[] args) {
        Form3Buttons f = new Form3Buttons();

    }
}
```

## Question 6: Assume a table MOVIE(id, title, genre). Now, using JDBC, perform the following queries:
```
a. Add any three records to the MOVIE table.
b. Using a prepared statement, update the genre to “Comedy” having the title “Jatra”.
```

```java
import java.sql.*;

public class MovieJDBC {
    public static void main(String[] args) {
        Class.forName("com.mysql.cj.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/your_database";
        String username = "your_username";
        String password = "your_password";

        try {
            Connection con = DriverManager.getConnection(url, username, password);

            // a. Add any three records to the MOVIE table
            ///  Insert 3 Records
            Statement stmt = con.createStatement();
            String sql1 = "INSERT INTO Movie (id, Title, Genre) VALUES (1, 'Jatra', 'Drama')";
            String sql2 = "INSERT INTO Movie (id, Title, Genre) VALUES (2, 'The Godfather', 'Crime')";
            String sql3 = "INSERT INTO Movie (id, Title, Genre) VALUES (3, 'Inceptiont', 'Science Fiction')";
            stmt.executeUpdate(sql1);
            stmt.executeUpdate(sql2);
            stmt.executeUpdate(sql3);

            ///  Update genre to Comedy using PreparedStatement
            String updateSql = "UPDATE Movie SET Genre = ? WHERE title = ?";
            PreparedStatement preparedStatement = con.prepareStatement(updateSql);
            preparedStatement.setString(1, "Comedy");
            preparedStatement.setString(2, "Jatra");
            preparedStatement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
```

## Question 9:  What is wrong in the following code?
```
public class Point {
   int p;
   public void setP(int p) {
      p = p;
   }
}
```

The problem in the code is that the parameter `p` in the method `setP` is hiding the instance variable `p` of the class. Because of this, when the statement `p = p;` is executed, it only assigns the value of the parameter to itself and does not update the instance variable. As a result, the value of the object’s variable remains unchanged. To solve this issue, the `this` keyword should be used to refer to the instance variable. Writing `this.p = p;` correctly assigns the value of the parameter to the instance variable of the object.

Here is the corrected code:

```java
public class Point {
   int p;
   public void setP(int p) {
      this.p = p; // Use 'this' to refer to the instance variable
   }
}
```

## Question 12: Write a program to create a menu named “File” with menu items “New,” “Save,” and “Exit”.

```java
import javax.swing.*;
import java.awt.event.*;

public class FileMenuExample extends JFrame {
    public FileMenuExample() {
        // Set the title of the frame
        setTitle("File Menu Example");

        // Set the size of the frame
        setSize(400, 300);

        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create a menu
        JMenu fileMenu = new JMenu("File");

        // Create menu items
        JMenuItem newItem = new JMenuItem("New");
        JMenuItem saveItem = new JMenuItem("Save");
        JMenuItem exitItem = new JMenuItem("Exit");

        // Add menu items to the menu
        fileMenu.add(newItem);
        fileMenu.add(saveItem);
        fileMenu.add(exitItem);

        // Add menu to the menu bar
        menuBar.add(fileMenu);

        // Set the menu bar for the frame
        setJMenuBar(menuBar);

        // Add action listener for Exit menu item
        exitItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0); // Exit the application
            }
        });

        // Set visibility
        setVisible(true);
    }

    public static void main(String[] args) {
        new FileMenuExample();
    }
}
```

---

## Model Set 1

## Question 2: Write a java program to create login form with user id, password, ok button, and cancel button. Handle key events such that pressing ‘l’ performs login and pressing ‘c’ clears text boxes and puts focus on user id text box. Assume user table having fields Uid and Password in the database named account.

```java

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class LoginForm extends JFrame implements ActionListener, KeyListener {
    JTextField userIdField;
    JPasswordField passwordField;
    JButton okButton, cancelButton;

    public LoginForm() {
        setTitle("Login Form");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 2));

        // User ID
        JLabel userIdLabel = new JLabel("User ID:");
        userIdField = new JTextField();
        add(userIdLabel);
        add(userIdField);

        // Password
        JLabel passwordLabel = new JLabel("Password:");
        passwordField = new JPasswordField();
        add(passwordLabel);
        add(passwordField);

        // Buttons
        okButton = new JButton("OK");
        cancelButton = new JButton("Cancel");
        add(okButton);
        add(cancelButton);

        // Add action listeners
        okButton.addActionListener(e -> login());
        cancelButton.addActionListener(e -> clearFields());

        // Add key listeners
        userIdField.addKeyListener(this);
        passwordField.addKeyListener(this);

        setVisible(true);
    }

    private void login() {
        String userId = userIdField.getText();
        String password = new String(passwordField.getPassword());

        // Database connection and authentication logic
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/account";
            String username = "your_username";
            String dbPassword = "your_password";

            Connection con = DriverManager.getConnection(url, username, dbPassword);

            String query = "SELECT * FROM user WHERE Uid = ? AND Password = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, userId);
            pstmt.setString(2, password);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                JOptionPane.showMessageDialog(this, "Login Successful!");
            } else {
                JOptionPane.showMessageDialog(this, "Invalid User ID or Password.");
            }

            rs.close();
            pstmt.close();
            con.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void clearFields() {
        userIdField.setText("");
        passwordField.setText("");
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyChar() == 'l') {
            login();
        } else if (e.getKeyChar() == 'c') {
            clearFields();
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyReleased(KeyEvent e) {}

    public static void main(String[] args) {
        new LoginForm();
    }
}
```

---

# 2079

## Question 2: Write a simple GUI program that displays “Hello World” in a text field. The program should display output if user clicks a button.

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HelloWorldGUI extends JFrame implements ActionListener {

    JTextField textField;
    JButton button;

    public HelloWorldGUI() {

        setTitle("Hello World GUI");
        setSize(300, 150);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Text field
        textField = new JTextField(15);
        add(textField);

        // Button
        button = new JButton("Click Me");
        add(button);

        // Add event listener
        button.addActionListener(this);

        setVisible(true);
    }

    // Button click event
    public void actionPerformed(ActionEvent e) {
        textField.setText("Hello World");
    }

    public static void main(String[] args) {
        new HelloWorldGUI();
    }
}
```
---

# 2078

## Question 1: Write a GUI program using components to find sum and difference of two numbers. Use two text fields for giving input and a label for output. The program should display sum if user presses mouse and difference if user release mouse.

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MousePress extends JFrame {

    JTextField num1Field, num2Field;
    JLabel num1label, num2label, resultlabel;
    JButton calculateButton;

    public MousePress() {

        setTitle("Sum and Differences");
        setSize(400, 200);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Labels and fields
        num1label = new JLabel("Num1:");
        num1Field = new JTextField(10);

        num2label = new JLabel("Num2:");
        num2Field = new JTextField(10);

        resultlabel = new JLabel("Result:");

        calculateButton = new JButton("Press / Release");

        add(num1label);
        add(num1Field);
        add(num2label);
        add(num2Field);
        add(calculateButton);
        add(resultlabel);

        // Mouse events
        calculateButton.addMouseListener(new MouseAdapter() {

            public void mousePressed(MouseEvent e) {
                try {
                    int num1 = Integer.parseInt(num1Field.getText());
                    int num2 = Integer.parseInt(num2Field.getText());
                    resultlabel.setText("Sum = " + (num1 + num2));
                } catch (Exception ex) {
                    resultlabel.setText("Enter valid numbers");
                }
            }

            public void mouseReleased(MouseEvent e) {
                try {
                    int num1 = Integer.parseInt(num1Field.getText());
                    int num2 = Integer.parseInt(num2Field.getText());
                    resultlabel.setText("Difference = " + (num1 - num2));
                } catch (Exception ex) {
                    resultlabel.setText("Enter valid numbers");
                }
            }
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        new MousePress();
    }
}
```
---

# 2077

## Question 2: You are hired by a reputed software company which is going to design an application for “Movie Rental System”. Your responsibility is to design a schema named MRS and create a table named Movie(id, Tille, Genre, Language, Length). Write a program to design a GUI form to take input for this table and insert the data into table after clicking the OK button.

```java
import javax.swing.*;
import java.sql.*;

/*
        -- Create schema
        CREATE DATABASE MRS;

        -- Use schema
        USE MRS;

        -- Create table
        CREATE TABLE Movie (
                id INT PRIMARY KEY,
                Title VARCHAR(100),
                Genre VARCHAR(50),
                Language VARCHAR(50),
                Length INT
        );
*/
public class MovieRentalSystem extends JFrame {
    JTextField idField, titleField, genreField, languageField, lengthField;
    JLabel idLabel, titleLabel, genreLabel, languageLabel, lengthLabel;
    JButton submitButton;

    public MovieRentalSystem() {
        // Set the title of the frame
        setTitle("Movie Rental System");

        // Set the size of the frame
        setSize(400, 400);

        // Set the layout of the frame
        setLayout(new FlowLayout());

        // Form Components
        idLabel = new JLabel("ID:");
        idField = new JTextField();

        titleLabel = new JLabel("Title:");
        titleField = new JTextField();

        genreLabel = new JLabel("Genre:");
        genreField = new JTextField();

        languageLabel = new JLabel("Language:");
        languageField = new JTextField();

        lengthLabel = new JLabel("Length:");
        lengthField = new JTextField();

        submitButton = new JButton("OK");

        // Add components
        add(idLabel);
        add(idField);
        add(titleLabel);
        add(titleField);
        add(genreLabel);
        add(genreField);
        add(languageLabel);
        add(languageField);
        add(lengthLabel);
        add(lengthField);
        add(submitButton);

        // Set Visibility
        setVisible(true);

        submitButton.addActionListener(e -> submitData());
        
    }

    private void submitData() {
        try {
            // Get input values
            String id = idField.getText();
            String title = titleField.getText();
            String genre = genreField.getText();
            String language = languageField.getText();
            String length = lengthField.getText();

            // Connect to database
            String URL = "jdbc:mysql://localhost:3306/MRS";
            String USERNAME = "root";
            String PASSWORD = "";

            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            // SQL Insert
            String sql = "INSERT INTO Movie (id, Title, Genre, Language, Length) VALUES (?, ?, ?, ?, ?)";

            PreparedStatement preparedStatement = conn.prepareStatement(sql);
            preparedStatement.setString(1, id);
            preparedStatement.setString(2, title);
            preparedStatement.setString(3, genre);
            preparedStatement.setString(4, language);
            preparedStatement.setString(5, length);

            // Execute query
            preparedStatement.executeUpdate();

        } catch (Exception ex) {
            System.out.println("Error: " + ex);
        }
    }

    public static void main(String[] args) {
         new  MovieRentalSystem();
    }
}
```