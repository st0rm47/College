import random

def is_prime(n):
    """Check if n is a prime number using the Miller-Rabin primality test."""
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0:
        return False

    # Calculate n-1 as 2^k * m
    m = n - 1
    k = 0
    while m % 2 == 0:
        m //= 2
        k += 1
       
    print(f"Value of k: {k} and m: {m}")  
    a = 2
    b = pow(a, m, n)
    print(f"Value of a: {a}")
        
    print("\n+------------+-------+---------------+---------------+")
    print("| Iterations |   a   | b = a^m mod n | b = b^2 mod n |")
    print("+------------+-------+---------------+---------------+")  
    print(f"| {'0'.center(10)} | {str(a).center(5)} | {str(b).center(13)} | {str(b).center(13)} |")
    print("+------------+-------+---------------+---------------+")

    if b == 1 or b == n - 1:
        return True
        
    # Loop to square b and check conditions
    for j in range(k - 1):
        b = pow(b, 2, n)
        print(f"| {str(j + 1).center(10)} | {str(a).center(5)} | {str(b).center(13)} | {str(b).center(13)} |")
        print("+------------+-------+---------------+---------------+")
        if b == n - 1:
            return True
    
    return False

def main():
    print("\t\t=====================")
    print("\t\t  Miller-Rabin Test  ")
    print("\t\t=====================")

    num = int(input("Enter a number to test for primality: "))

    if is_prime(num):
        print(f"\n{num} is probably prime.")
    else:
        print(f"\n{num} is composite.")
        
    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
