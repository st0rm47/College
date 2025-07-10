using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4 {
    internal class Program {
        static void Main(string[] args) {
            Console.WriteLine("sbyte:");
            Console.WriteLine($"  Max: {sbyte.MaxValue}");
            Console.WriteLine($"  Min: {sbyte.MinValue}");

            Console.WriteLine("\nbyte:");
            Console.WriteLine($"  Max: {byte.MaxValue}");
            Console.WriteLine($"  Min: {byte.MinValue}");

            Console.WriteLine("\nshort:");
            Console.WriteLine($"  Max: {short.MaxValue}");
            Console.WriteLine($"  Min: {short.MinValue}");

            Console.WriteLine("\nushort:");
            Console.WriteLine($"  Max: {ushort.MaxValue}");
            Console.WriteLine($"  Min: {ushort.MinValue}");

            Console.WriteLine("\nint:");
            Console.WriteLine($"  Max: {int.MaxValue}");
            Console.WriteLine($"  Min: {int.MinValue}");

            Console.WriteLine("\nuint:");
            Console.WriteLine($"  Max: {uint.MaxValue}");
            Console.WriteLine($"  Min: {uint.MinValue}");

            Console.WriteLine("\nlong:");
            Console.WriteLine($"  Max: {long.MaxValue}");
            Console.WriteLine($"  Min: {long.MinValue}");

            Console.WriteLine("\nulong:");
            Console.WriteLine($"  Max: {ulong.MaxValue}");
            Console.WriteLine($"  Min: {ulong.MinValue}");

            Console.WriteLine("\nfloat:");
            Console.WriteLine($"  Max: {float.MaxValue}");
            Console.WriteLine($"  Min: {float.MinValue}");

            Console.WriteLine("\ndouble:");
            Console.WriteLine($"  Max: {double.MaxValue}");
            Console.WriteLine($"  Min: {double.MinValue}");

            Console.WriteLine("\ndecimal:");
            Console.WriteLine($"  Max: {decimal.MaxValue}");
            Console.WriteLine($"  Min: {decimal.MinValue}");

            Console.WriteLine("\nchar:");
            Console.WriteLine($"  Min: \\u{((int)char.MinValue):X4}");
            Console.WriteLine($"  Max: \\u{((int)char.MaxValue):X4}");

            Console.WriteLine("Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
