using System;

namespace Lab16c {
    internal class Program {
        string name;
        int age;

        public Program(string name, int age) {
            this.name = name;
            this.age = age;
        }

        public Program(Program other) {
            this.name = other.name;
            this.age = other.age;
        }

        public void Display() {
            Console.WriteLine($"Name: {name}, Age: {age}");
        }
 
        static void Main(string[] args) {
            Program p1 = new Program("Subodh", 20);
            p1.Display();
            Program p2 = new Program(p1);
            p2.Display();
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
