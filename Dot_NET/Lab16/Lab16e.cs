using System;

namespace Lab16e {
    class Person {
        public static string PersonName;
        public static int PersonAge;

        static Person() {
            PersonName = "Subodh Ghimire";
            PersonAge = 20;
            Console.WriteLine("Static constructor called");
        }

        public Person() {
            Console.WriteLine("Default constructor called");
        }

        public static void GetDetails() {
            Console.WriteLine($"Name: {PersonName}");
            Console.WriteLine($"Age: {PersonAge}");
        }
    }

    internal class Program {
        static void Main(string[] args) {
            Person p1 = new Person();
            Person p2 = new Person();
            Person.GetDetails();

            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
