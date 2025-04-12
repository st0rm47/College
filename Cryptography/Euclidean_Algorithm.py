def euclidean_algorithm(a, b):
    steps = []
    
    while b != 0:
        q = a // b
        r = a % b
        steps.append((a, b, q, r))
        a, b = b, r

    # Final step when remainder is 0
    steps.append((a, 0, '', ''))
    return a, steps

def display_table(steps):
    print("\nSteps of Euclidean Algorithm:")
    print("+--------+--------+--------+-------+")
    print("│   A    │   B    │ Q=A//B │ R=A%B │")
    print("+--------+--------+--------+-------+")
    for a, b, q, r in steps:
        print(f"│ {str(a).center(6)} │ {str(b).center(6)} │ {str(q).center(6)} │ {str(r).center(5)} │")
    print("+--------+--------+--------+-------+")

def main():
    print("\t\t=======================")
    print("\t\t  Euclidean Algorithm  ")
    print("\t\t=======================")

    a = int(input("Enter first number (A): "))
    b = int(input("Enter second number (B): "))

    # Perform Euclidean Algorithm
    gcd, steps = euclidean_algorithm(a, b)
    display_table(steps)

    print(f"\nGCD of {a} and {b} is: {gcd}")
    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
