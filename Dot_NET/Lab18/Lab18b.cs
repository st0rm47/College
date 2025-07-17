using System;
using System.Threading;
using System.Threading.Tasks;

namespace Lab18b {
    internal class Program {
        static void Main(string[] args) {
            Task1();
            Task2();
            Task3();
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }

        public static async void Task1() {
            await Task.Run(() => {
                Console.WriteLine("\nTask 1 is Starting");
                Thread.Sleep(3000);
                Console.WriteLine("Task 1 Completed.");
            });
        }

        public static async Task Task2() {
            await Task.Run(() => {
                Console.WriteLine("\nTask 2 is Starting");
                Thread.Sleep(4000);
                Console.WriteLine("Task 2 Completed.");
            });
        }

        public static async Task Task3() {
            await Task.Run(() => {
                Console.WriteLine("\nTask 3 is Starting");
                Thread.Sleep(5000);
                Console.WriteLine("Task 3 Completed.");
            });
        }
    }
}
