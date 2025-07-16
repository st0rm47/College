using System;

namespace Lab16d {
    class Example {
        private Example() { }

        public static int a;

        public static int GetIncrement() {
            return ++a;
        }

        public static void GetTime() {
            Console.WriteLine(DateTime.Now);
        }
    }

    internal class Program {
        static void Main(string[] args) {
            Example.GetTime();
            Example.a = 99;
            Console.WriteLine(Example.GetIncrement());
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
