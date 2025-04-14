def discrete_log(a, b, p):
    a = a % p
    b = b % p
    
    print(f"\nFinding i such that {a}^i ≡ {b} (mod {p}):")
    for i in range(p):
        power = pow(a, i, p)
        print(f"{a}^{i} mod {p} = {power}")
        if power == b:
            return i
    return -1

def main():
    print("\t\t======================")
    print("\t\t  Discrete Logarithm  ")
    print("\t\t======================")

    a = int(input("Enter value of a: "))
    b = int(input("Enter value of b: "))
    p = int(input("Enter value of p: "))
    
    result = discrete_log(a, b, p)

    if result is None:
        print(f"\nNo solution found.")
    else:
        print(f"\ndlog_{a},{p} ({b}) = {result}")

    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
