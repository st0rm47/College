using System;
namespace Lab19b {
    internal class Program {
        static void Main() {
            try {
                Console.WriteLine("Enter a number: ");
                double num = double.Parse(Console.ReadLine());

                if (num < 0)
                    throw new Exception("Square root of a negative number is not allowed.");

                Console.WriteLine($"Square root of {num} = {Math.Sqrt(num)}");
            }
            catch (Exception ex) {
                Console.WriteLine("Error: " + ex.Message);
            }
            finally {
                Console.WriteLine("\nProgram Executed");
                Console.WriteLine("Made by: Subodh Ghimire");
                Console.ReadLine();
            }
        }
    }
}

