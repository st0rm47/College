package Unitfour.controller;

import Unitfour.service.StudentService;
import Unitfour.model.Student;

import java.util.List;

class StudentController {

    public static void main(String[] args) {
        StudentService studentService = new StudentService();

        // Insert Student
        Student s3 = new Student();
        s3.setName("Priyanka");
        studentService.addStudent(s3);

        // View Student
        List<Student> students1 = studentService.viewStudents();
        for (Student student : students1) {
            System.out.println("ID: " + student.getId() + ", Name: " + student.getName());
        }
        System.out.println();

        // Update Student
        Student s4 = new Student();
        s4.setId(4);
        s4.setName("Ramesh");
        studentService.updateStudent(s4);

        // View Student
        List<Student> students = studentService.viewStudents();
        for (Student student : students) {
            System.out.println("ID: " + student.getId() + ", Name: " + student.getName());
        }
        System.out.println();

        // Delete Student
        studentService.deleteStudent(11);

        // View Student
        List<Student> students2 = studentService.viewStudents();
        for (Student student : students2) {
            System.out.println("ID: " + student.getId() + ", Name: " + student.getName());
        }


    }
}
