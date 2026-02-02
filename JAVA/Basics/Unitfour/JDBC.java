package Unitfour;

import java.sql.*;

public class JDBC {
    public static void main(String[] args) {
        String URL = "jdbc:mysql://localhost:3306/javaclass";
        String USERNAME = "root";
        String PASSWORD = "";
        String query = "SELECT * FROM Student";
        try{
            // 1. Connect to the database
            Connection con = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            // 2. Create a statement
            Statement stmt = con.createStatement();

            // 3. Execute the query returning a result set
            ResultSet rs = stmt.executeQuery(query);

            // 4. Process the result set
            while(rs.next()){
                System.out.println("ID: " + rs.getInt("student_id"));
                System.out.println("Name: " + rs.getString("student_name"));
            }

            // 5. Close the resources
            rs.close();
            stmt.close();
            con.close();

        } catch(SQLException ex){
            System.out.println(ex.getMessage());
        }

    }
}

