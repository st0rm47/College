package Unitfour.dbconnection;

import java.sql.*;

public class DatabaseConnection {
    private static final String URL = "jdbc:mysql://localhost:3306/javaclass";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";

    public Connection getConnection() {
        Connection conn = null;
        try {
            conn =  DriverManager.getConnection(URL, USERNAME, PASSWORD);
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
            return null;
        }
        return conn;
    }

//    public  static void main(String[] args) {
//        DatabaseConnection dbConn = new DatabaseConnection();
//        Connection conn = dbConn.getConnection();
//        if (conn != null) {
//            System.out.println("Connection successful!");
//            try {
//                conn.close();
//            } catch (SQLException ex) {
//                System.out.println(ex.getMessage());
//            }
//        } else {
//            System.out.println("Failed to connect to the database.");
//        }
//    }

}
