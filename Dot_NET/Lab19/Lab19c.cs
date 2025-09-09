using System;
namespace Lab19c {
    internal class Program {
        static void Main() {
            try {
                Console.Write("Enter value of a: ");
                int a = int.Parse(Console.ReadLine());

                Console.Write("Enter value of b: ");
                int b = int.Parse(Console.ReadLine());

                if (b == 0)
                    throw new DivideByZeroException("Division by zero is not allowed.");

                int c = a / b;
                Console.WriteLine($"Division of {a} by {b} = {c}");
            }
            catch (Exception ex) {
                Console.WriteLine("Unexpected Error: " + ex.Message);
            }
            finally {
                Console.WriteLine("\nProgram Executed");
                Console.WriteLine("Made by: Subodh Ghimire");
                Console.ReadLine();
            }
        }
    }
}
