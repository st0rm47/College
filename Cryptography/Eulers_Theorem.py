def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def euler_totient(n):
    return sum(1 for i in range(1, n) if gcd(i, n) == 1)

def power(a, b, mod):
    result = 1
    a %= mod
    while b:
        if b % 2:
            result = (result * a) % mod
        a = (a * a) % mod
        b //= 2
    return result

def euler_theorem(a, n):
    if gcd(a, n) != 1:
        return None
    phi  = euler_totient(n)
    return power(a, phi, n), phi

def main():
    print("\t\t===================")
    print("\t\t  Euler's Theorem  ")
    print("\t\t===================")

    a = int(input("Enter value of a: "))
    n = int(input("Enter value of n: "))
    result = euler_theorem(a, n)

    if result is None:
        print(f"\nSince gcd({a}, {n}) ≠ 1, Euler's Theorem is not applicable.")
    else:
        mod_result, phi_n = result
        print(f"\n ϕ({n}) = {phi_n}")
        print(f"\nAccording to Euler's Theorem: {a}^{phi_n} ≡ {mod_result} mod {n}")
        print("(Verified using modular exponentiation)")

    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()




