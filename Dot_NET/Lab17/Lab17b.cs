using System;

namespace lab17b {
    internal class Parent {
        public virtual void Print() {
            Console.WriteLine("Parent class");
        }
    }
    internal class Child : Parent {
        public override void Print() {
            base.Print();
            Console.WriteLine("Child class");
        }
    }
    internal class Program {
        static void Main(string[] args) {
            Parent p = new Child();
            p.Print();  
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
