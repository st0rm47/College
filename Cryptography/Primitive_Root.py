def power(a, b, mod):
    result = 1
    a %= mod
    while b:
        if b % 2:
            result = (result * a) % mod
        a = (a * a) % mod
        b //= 2
    return result

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def is_primitive_root(r, n):
    for i in range(1, n - 1):
        if power(r, i, n) == 1:
            return False
    return True

def find_primitive_roots(n):
    return [r for r in range(2, n) if gcd(r, n) == 1 and is_primitive_root(r, n)]

def main():
    print("\t\t===================")
    print("\t\t  Primitive Roots  ")
    print("\t\t===================")

    num = int(input("Enter a number: "))
    roots = find_primitive_roots(num)
    
    if roots:
        print(f"\nPrimitive roots of {num} are: {roots}")
    else:
        print(f"\nNo primitive roots found for {num}.")
        
    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()