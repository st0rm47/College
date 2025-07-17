using System;

namespace Lab17a {
    internal class Program {
        public void Add() {
            int a = 22;
            int b = 15;
            int c = a + b;
            Console.WriteLine("Adding default integers: " + c);
        }

        public void Add(int a, int b) {
            int c = a + b;
            Console.WriteLine($"\nAdding integers: {c}");
        }

        public void Add(string a, string b) {
            string c = a + " " + b;
            Console.WriteLine($"\nConcatenating strings: {c}");
        }

        public void Add(float a, float b) {
            float c = a + b;
            Console.WriteLine($"\nAdding floats: {c}");
        }

        static void Main(string[] args) {
            Program p = new Program();
            p.Add();
            p.Add(17, 85);
            p.Add("Subodh", "Ghimire");
            p.Add(8.7f, 11.5f);
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
