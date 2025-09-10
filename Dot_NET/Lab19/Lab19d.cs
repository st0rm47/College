using System;
namespace Lab19d {
    internal class Program {
        static void Main() {
            try {
                Console.Write("Enter your name: ");
                string name = Console.ReadLine();

                if (int.TryParse(name, out _))
                    throw new FormatException("Name cannot be a number.");

                if (string.IsNullOrWhiteSpace(name))
                    throw new Exception("Name cannot be empty.");

                if (name.Length < 3)
                    throw new Exception("Name must have at least 3 characters.");

                Console.WriteLine($"Hello, {name}! Welcome to the program.");
            }
            catch (FormatException ex) {
                Console.WriteLine("Format Error: " + ex.Message);
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
