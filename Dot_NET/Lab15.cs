using System;

namespace Lab15 {
    internal class Program {
        static void Main(string[] args) {
            Console.WriteLine("Enter the age of a student:");
            int a = int.Parse(Console.ReadLine());
            string b = (a >= 18) ? "You are eligible to vote" : "You are not eligible to vote";
            Console.WriteLine(b);

            Console.WriteLine("\n Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}

