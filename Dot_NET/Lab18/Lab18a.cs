using System;
using System.Threading;

namespace Lab18a {
    internal class Program {
        static void Main(string[] args) {
            Task1();
            Task2();
            Task3();
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }

        public static void Task1() {
            Console.WriteLine("\nTask 1 is Starting");
            Thread.Sleep(3000); 
            Console.WriteLine("Task 1 Completed.");
        }

        public static void Task2() {
            Console.WriteLine("\nTask 2 is Starting");
            Thread.Sleep(4000);
            Console.WriteLine("Task 2 Completed.");
        }

        public static void Task3() {
            Console.WriteLine("\nTask 3 is Starting");
            Thread.Sleep(5000);
            Console.WriteLine("Task 3 Completed.");
        }
    }
}
