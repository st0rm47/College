package Unitfour.service;

import Unitfour.dbconnection.DatabaseConnection;
import Unitfour.model.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class StudentService {
    DatabaseConnection dbconn = new DatabaseConnection();

    /// View Student
    public List<Student> viewStudents() {
        List<Student> students = new ArrayList<>();
        String getAllStudents = "SELECT * FROM student";

        ///  Connection
        try {
            Connection conn = dbconn.getConnection();
            PreparedStatement preparedStmt = conn.prepareStatement(getAllStudents);
            ResultSet resultSet = preparedStmt.executeQuery();
            while (resultSet.next()) {
                Student student = new Student();
                student.setId(resultSet.getInt("student_id"));
                student.setName(resultSet.getString("student_name"));
                students.add(student);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return students;
    }

    ///  Insert Student
    public  boolean addStudent(Student student){
        String insertStudents = "INSERT INTO student (student_name) VALUES (?)";

        try {
            Connection conn = dbconn.getConnection();
            PreparedStatement preparedStmt = conn.prepareStatement(insertStudents);
            preparedStmt.setString(1, student.getName());

            int rowsInserted = preparedStmt.executeUpdate();
            System.out.println(student.getName()+ " Added");
            System.out.println();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return false;
    }

    // Update Student
    public boolean updateStudent(Student student) {
        String updateQuery = "UPDATE student SET student_name = ? WHERE student_id = ?";

        try {
            Connection conn = dbconn.getConnection();
            PreparedStatement preparedStmt = conn.prepareStatement(updateQuery);
            preparedStmt.setString(1, student.getName());
            preparedStmt.setInt(2, student.getId());

            int rowsUpdated = preparedStmt.executeUpdate();
            System.out.println(student.getName() + " Updated");
            System.out.println();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return false;
    }

    // Delete Student
    public boolean deleteStudent(int studentId) {
        String deleteQuery = "DELETE FROM student WHERE student_id = ?";

        try {
            Connection conn = dbconn.getConnection();
            PreparedStatement preparedStmt = conn.prepareStatement(deleteQuery);
            preparedStmt.setInt(1, studentId);

            int rowsDeleted = preparedStmt.executeUpdate();
            System.out.println(studentId + " Deleted");
            System.out.println();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return false;
    }
}
