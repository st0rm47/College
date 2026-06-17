# 2082

## Question 1: Write a socket program using UDP to create three programs, two of which are clients to a single server. Client1 will send a character to the server process. The server will circularly decrement the letter to the previous letter in the alphabet and send the result to Client2. Then Client2 prints the letter it receives and then all the processes terminate.


- Client1 Code:
```java
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class UDPClient1{
    public static void main(String[] args){
        try{
            DatagramSocket socket = new DatagramSocket();

            Scanner sc = new Scanner(System.in);

            System.out.print("Enter a character: ");
            char ch = sc.next().charAt(0);

            byte[] data = {(byte) ch};

            InetAddress address = InetAddress.getByName("localhost");
            int port = 12345;

            DatagramPacket sendPacket = new DatagramPacket(data, data.length, address, port);

            socket.send(sendPacket);

            System.out.println("Message sent to the Server");
            socket.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
```

- Server Code:
```java
import java.io.*;
import java.net.*;

public class UDPServer{
    public static void main(String[] args){
        try{
            int port  = 12345;
            DatagramSocket socket = new DatagramSocket(port);

            byte[] buffer = new byte[1024];

            DatagramPacket receivePacket = new DatagramPacket(buffer, buffer.length);

            socket.receive(receivePacket);

            char ch = (char) buffer[0];
            char result;
            if (ch == 'A'){
                result = 'Z';
            } else if (ch =='a'){
                result = 'z';
            } else{
                result = (char) (ch-1);
            }

            byte[] replydata = {(byte) result};

            InetAddress client2Address = InetAddress.getByName("localhost");
            int client2port = 1234;

            DatagramPacket sendPacket2 = new DatagramPacket(replydata, replydata.length, client2Address, client2port);
            socket.send(sendPacket2);

            System.out.println("Received from Client1: " + ch);
            System.out.println("Sent to Client2: " + result);

            socket.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}

```

- Client 2 Code
```java
import java.io.*;
import java.net.*;

public class UDPClient2{
    public static void main(String[] args){
        try{
            int port = 1234;

            DatagramSocket socket = new DatagramSocket(port);

            byte [] buffer2 = new byte[1024];

            DatagramPacket receivePacket2 = new DatagramPacket(buffer2, buffer2.length);

            socket.receive(receivePacket2);

            char ch = (char) buffer2[0];

            System.out.println("Reply from server : " + ch);

            socket.close();
        }catch(Exception e){
            e.printStackTrace();

        }

    }
}
```
---
# Model 2:

## Question 10: Write the steps for writing client and server programs using TCP with a suitable example.

---

# 2081

## Question 1: Write a socket program for a file server that makes a collection of files available for transmission to clients. When a client connects to the server, the server first reads a one-line command from the client. The command string can be of the form “GET <filename>”, where <filename> is a file name. The server checks whether the requested file actually exists. If so, it first sends the word “OK” as a message to the client. Then it sends the contents of the file and closes the connection. Otherwise, it sends “ERROR” to the client as message and closes the connection. Assume that there is no sub directories.

**Client Program:**
```java
package org.example.Midterm;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class FileClient {
    private static final String SERVER_ADDRESS = "localhost";
    private static final int PORT = 12345;

    public static void main(String[] args) {
        try {

            // Create a socket to connect to the file server
            Socket serverSocket = new Socket(SERVER_ADDRESS, PORT);
            System.out.println("Connected to file server");

            // Input stream to receive data from the server
            DataInputStream input = new DataInputStream(serverSocket.getInputStream());

            // Output Stream to send data to the server
            DataOutputStream output = new DataOutputStream(serverSocket.getOutputStream());

            // Read from keyboard
            Scanner userinput = new Scanner(System.in);

            // Read the filename from the user
            System.out.println("Enter the filename to retrieve:");
            String filename = userinput.nextLine();

            // Send the GET command to the server with the specified filename
            output.writeUTF("GET " + filename);

            // Read the response from the server
            String response = input.readUTF();

            // If the response is "OK", read and print the contents of the file
            if (response.equals("OK")) {
                System.out.println("File contents:");

                // Read file content line by line
                String line;
                while ((line = input.readUTF()) != null) {
                    System.out.println(line);
                }
            } else {
                System.out.println("File not found on server.");
            }

            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}


```


**Socket Program for File Server:**
```java
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class FileServer {
    private static final int PORT = 12345;

    public static void main(String[] args) {
        try {

            // Create a server socket to listen for incoming connections
            ServerSocket serverSocket = new ServerSocket(PORT);
            System.out.println("File server is running on port " + PORT);

            // Wait for a client to connect
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected");

            // Input stream to read data from the client
            DataInputStream input = new DataInputStream(clientSocket.getInputStream());

            // Output stream to send data to the client
            DataOutputStream output = new DataOutputStream(clientSocket.getOutputStream());

            // Read the command from the client
            String command = input.readUTF();

            // Check if the command is in the correct format and process it
            if (command.startsWith("GET "))
            {
                // Extract the filename from the command
                String filename = command.substring(4);

                // Create a File object for the requested filename
                File file = new File(filename);

                // Check if the file exists and is not a directory
                if (file.exists() && !file.isDirectory()) {

                    // Send "OK" to the client to indicate that the file is available
                    output.writeUTF("OK");

                    // Create a BufferedReader to read the contents of the file
                    Scanner br = new Scanner(file);

                    while (br.hasNextLine()) {
                        String line = br.nextLine();
                        output.writeUTF(line);
                    }
                    br.close();

                } else {
                    output.writeUTF("ERROR");
                }
            } else {
                output.writeUTF("ERROR");
            }

            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

```
 
- In this implementation, the `FileServer` class listens for incoming client connections and processes commands to retrieve files.
-  The `FileClient` class connects to the server, sends a request for a file, and displays the contents if the file is found. 
-  The server checks for the existence of the requested file and responds accordingly.
-  This simple client-server application demonstrates how to use sockets for file transmission in Java.

---
# 2080


## Question 8: Discuss Java Mail API.


## Question 10: Write a TCP client-server system in which the client program sends two integers to a server program, which returns the greatest among them.


**TCP Client:**
```java
import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) {
        String host = "localhost"; // Server host
        int port = 12345; // Server port

        try {
            // Step 1: Create a Socket to connect to the server
            Socket socket = new Socket(host, port);

            // Step 2: Obtain input and output streams from the socket
            DataInputStream input = new DataInputStream(socket.getInputStream());

            DataOutputStream output = new DataOutputStream(socket.getOutputStream());

            // Step 3: Send two integers to the server
            output.writeInt(10);
            output.writeInt(20);

            // Step 4: Read the greatest integer from the server
            int greatest = input.readInt();
            System.out.println("Greatest integer received from server: " + greatest);

            // Step 5: Close the connection
            socket.close();

        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
```

**TCP Server:**
```java
import java.io.*;
import java.net.*;
public class TCPServer {
    public static void main(String[] args) {
        int port = 12345; // Port number to listen on

        try {
            // Step 2: Create a ServerSocket to listen for incoming connections
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server is waiting");
            
            // Step 3: Accept a client connection
            Socket socket = serverSocket.accept();
            System.out.println("Client connected");

            // Step 4: Obtain input and output streams from the socket
            DataInputStream input = new DataInputStream(socket.getInputStream());
            DataOutputStream output = new DataOutputStream(socket.getOutputStream());

            // Step 5: Read two integers from the client
            int num1 = input.readInt();
            int num2 = input.readInt();

            // Step 6: Compute the greatest of the two integers
            int greatest = (num1 > num2) ? num1 : num2;

            // Step 7: Send the greatest integer back to the client
            output.writeInt(greatest);

            // Step 8: Close the connection
            socket.close();
            serverSocket.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
```

---

# Model 1

## Question 8: Write a java program using TCP such that client sends number to server and displays its factorial. The server computes factorial of the number received from client.

**TCP Client:**
```java
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient {
    public static void main(String[] args) {
        String host = "localhost"; // Server host
        int port = 12345; // Server port

        try {
            // Step 1: Create a Socket to connect to the server
            Socket socket = new Socket(host, port);

            // Step 2: Obtain input and output streams from the socket
            DataInputStream input = new DataInputStream(socket.getInputStream());

            DataOutputStream output = new DataOutputStream(socket.getOutputStream());

            // Step 3: Send a number to the server
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter a number: ");
            int number = sc.nextInt();
            output.writeInt(number);
            
            // Step 4: Read the factorial from the server
            long factorial = input.readLong();
            System.out.println("Factorial received from server: " + factorial);

            // Step 5: Close the connection
            socket.close();

        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
```

**TCP Server:**
```java
import java.io.*;
import java.net.*;
public class TCPServer {
    public static void main(String[] args) {
        int port = 12345; // Port number to listen on

        try {
            // Step 2: Create a ServerSocket to listen for incoming connections
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server is waiting");
            
            // Step 3: Accept a client connection
            Socket socket = serverSocket.accept();
            System.out.println("Client connected");

            // Step 4: Obtain input and output streams from the socket
            DataInputStream input = new DataInputStream(socket.getInputStream());
            DataOutputStream output = new DataOutputStream(socket.getOutputStream());

            // Step 5: Read a number from the client
            int number = input.readInt();

            // Step 6: Compute the factorial of the number
            long factorial = 1;
            for (int i = 1; i <= number; i++) {
                factorial *= i;
            }

            // Step 7: Send the factorial back to the client
            output.writeLong(factorial);

            // Step 8: Close the connection
            socket.close();
            serverSocket.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
```

---

# 2079

## Question 8: Write Java program that send messages with each other using TCP socket.

---

# 2078

## Question 8: What is Java Mail API ? How can you use this API to send email messages?

---

