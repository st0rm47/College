def mod_exp(base, exponent, modulus):
    if exponent == 0:
        return 1
    result = 1
    base = base % modulus
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        exponent = exponent >> 1  # Right shift by 1
        base = (base * base) % modulus
    return result

def main():
    print("\t\t===============================")
    print("\t\t  Diffie-Hellman Key Exchange  ")
    print("\t\t===============================")

    p = int(input("\nEnter a prime number (p): "))
    g = int(input(f"Enter a primitive root (g) modulo {p}: "))
    
    # Alice and Bob's private keys
    a = int(input("Enter Alice's private key (a): "))
    b = int(input("Enter Bob's private key (b): "))

    # Alice and Bob's public keys
    A = mod_exp(g, a, p)
    B = mod_exp(g, b, p) 

    print(f"\nAlice's public key A = g^a mod p = {g}^{a} mod {p} = {A}")
    print(f"Bob's public key B = g^b mod p = {g}^{b} mod {p} = {B}")

    # A and B compute the shared secret key
    s1 = mod_exp(B, a, p)  
    s2 = mod_exp(A, b, p)

    print(f"\nAlice computes shared key = B^a mod p = {B}^{a} mod {p} = {s1}")
    print(f"Bob computes shared key = A^b mod p = {A}^{b} mod {p} = {s2}")

    # Check if the shared keys are equal
    if s1 == s2:
        print(f"\nShared secret key: {s1}")
    else:
        print("\n Key exchange failed!")

    print("Compiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
