using System;

namespace Lab19a {
    internal class Program {
        static void Main(string[] args) {
            int a, b, c;
            Console.WriteLine("Enter value of a: ");
            a = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter value of b: ");
            b = int.Parse(Console.ReadLine());
            if (b == 0) {
                Console.WriteLine("Enter a number other than zero.");
            } else {
                c = a / b;
                Console.WriteLine("Division of " + a + " by " + b + " = " + c);
            }
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}

