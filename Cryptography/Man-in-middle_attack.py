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
    print("\t\t===================================")
    print("\t\t  Man-in-the-Middle (MITM) Attack  ")
    print("\t\t  on Diffie-Hellman Key Exchange   ")
    print("\t\t===================================")

    p = int(input("\nEnter a prime number (p): "))
    g = int(input(f"Enter a primitive root (g) modulo {p}: "))

    # Alice, Bob's and Eve's private keys
    a = int(input("Enter Alice's private key (a): "))
    b = int(input("Enter Bob's private key (b): "))
    e1 = int(input("Enter Eve's first private key (e1): "))
    e2 = int(input("Enter Eve's second private key (e2): "))

    # Step 1: Alice computes public key
    A = mod_exp(g, a, p)
    print(f"\nAlice transmits A = {A} to Bob")

    # Eve intercepts A and replaces it with her first public key
    E1 = mod_exp(g, e1, p)
    print(f"Eve intercepts {A} and transmits her own {E1} to Bob.")

    eve_with_alice = mod_exp(A, e2, p)
    print(f"Eve's shared key with Alice (K2)= A^e2 mod p = {A}^{e2} mod {p} = {eve_with_alice}")
    
    # Bob receives E1 instead of A
    print(f"\nBob receives E1 = {E1} instead of A = {A}")
    bob_shared = mod_exp(E1, b, p)
    print(f"Bob computes shared key = E1^b mod p = {E1}^{b} mod {p} = {bob_shared}")
    
    # Bob computes public key
    B = mod_exp(g, b, p)
    print(f"\nBob transmits B = {B} to Alice")

    # Eve intercepts B and replaces it with her second public key
    E2 = mod_exp(g, e2, p)
    print(f"Eve intercepts {B} and transmits her own {E2} to Alice.")

    eve_with_bob = mod_exp(B, e1, p)
    print(f"Eve's shared key with Bob (K1)= B^e1 mod p = {B}^{e1} mod {p} = {eve_with_bob}")

    # Alice receives E2 instead of B
    print(f"\nAlice receives E2 = {E2} instead of B = {B}")
    alice_shared = mod_exp(E2, a, p)
    print(f"Alice computes shared key = E2^a mod p = {E2}^{a} mod {p} = {alice_shared}")

    print("Man-in-the-Middle Attack Successful!")
    print(f"\nEve's shared key with Alice = {eve_with_alice}")
    print(f"Eve's shared key with Bob = {eve_with_bob}")
    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
