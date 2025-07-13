using System;

namespace Lab11 {
    internal class Program {
        static void Main(string[] args) {
            DateTime dt = DateTime.Now;

            Console.WriteLine("Short date format (d): {0:d}\n", dt);
            Console.WriteLine("Long date format (D): {0:D}\n", dt);
            Console.WriteLine("Full date/time (short) (f): {0:f}\n", dt);
            Console.WriteLine("General date/time (short) (g): {0:g}\n", dt);
            Console.WriteLine("Full date/time (long) (F): {0:F}\n", dt);
            Console.WriteLine("Custom: Short & Long date: {0:d} | {1:D}\n", dt, dt);

            Console.WriteLine("Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
