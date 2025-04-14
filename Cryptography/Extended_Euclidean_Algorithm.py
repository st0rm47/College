def extended_euclidean_algorithm(a, n):
    steps = []
    r1, r2 = n, a
    t1, t2 = 0, 1

    while r2 != 0:
        q = r1 // r2
        r = r1 - q * r2
        t = t1 - q * t2
        steps.append((q, r1, r2, r, t1, t2, t))
        r1, r2 = r2, r
        t1, t2 = t2, t

    steps.append(('', r1, 0, '', t1, '', ''))
    return r1, t1, steps

def display_table(steps):
    print("\nSteps of Extended Euclidean Algorithm:")
    print("+--------+--------+--------+--------+--------+--------+--------+")
    print("│   q    │  r1    │  r2    │   r    │  t1    │  t2    │   t    │")
    print("+--------+--------+--------+--------+--------+--------+--------+")
    for q, r1, r2, r, t1, t2, t in steps:
        print (f"│ {str(q).center(6)} │ {str(r1).center(6)} │ {str(r2).center(6)} │ {str(r).center(6)} │ {str(t1).center(6)} │ {str(t2).center(6)} │ {str(t).center(6)} │")
    print("+--------+--------+--------+--------+--------+--------+--------+")

def main():
    print("\t\t================================")
    print("\t\t  Extended Euclidean Algorithm  ")
    print("\t\t================================")

    a = int(input("Enter number (A): "))
    n = int(input("Enter modulo (N): "))

    # Perform the Extended Euclidean Algorithm
    gcd, inverse, steps = extended_euclidean_algorithm(a, n)
    display_table(steps)

    print(f"\nGCD of {a} and {n} is: {gcd}")
    if gcd == 1:
        print(f"Multiplicative Inverse of {a} mod {n} is: {inverse % n}")
    else:
        print(f"{a} has no multiplicative inverse modulo {n} since GCD ≠ 1.")
    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
