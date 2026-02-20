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
