using System;

namespace Lab16b {
    internal class Program {
        public Program() {
            Console.WriteLine("This is the first constructor");
        }
        public Program(int a, int b) {
            Console.WriteLine("This is the second constructor:{0}", (a + b));
        }
        public Program(int a, int b, int c) {
            Console.WriteLine("This is the third constructor:{0}", (a + b + c));
        }

        static void Main(string[] args) {
            Program p1 = new Program();
            Program p2 = new Program(10, 20);
            Program p3 = new Program(10, 20, 30);
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
