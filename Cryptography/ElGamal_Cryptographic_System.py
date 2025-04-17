import random

def mod_exp(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2:
            result = (result * base) % mod
        base = (base * base) % mod
        exp //= 2
    return result

def generate_keys(p, g, x):
    y = mod_exp(g, x, p)
    print(f"\nPublic Key: (p = {p}, g = {g}, y = {y})")
    print(f"Private Key: x = {x}")
    return (p, g, y), x

def encrypt(p, g, y, message, k):
    a = mod_exp(g, k, p)
    b = (mod_exp(y, k, p) * message) % p
    print(f"\nEphemeral key (k): {k}")
    print(f"Encryption: a = g^k mod p = {a}")
    print(f"            b = (m * y^k) mod p = {b}")
    return a, b

def decrypt(a, b, x, p):
    s = mod_exp(a, x, p)
    s_inv = mod_exp(s, p - 2, p)  # Using Fermat's little theorem for inverse
    message = (b * s_inv) % p
    print(f"\nShared secret s = a^x mod p = {s}")
    print(f"Decryption: message = (b * s^(-1)) mod p = {message}")
    return message

def main():
    print("\t\t========================")
    print("\t\t  ElGamal Cryptography  ")
    print("\t\t========================")

    p = int(input("Enter a prime number (p): "))
    g = int(input(f"Enter primitive root modulo {p} (g): "))
    x = int(input("Enter private key (x): "))

    public_key, private_key = generate_keys(p, g, x)

    message = int(input("\nEnter the message (m): "))
    k = random.randint(2, p - 2)  # Ephemeral key

    a, b = encrypt(*public_key, message, k)
    print(f"\nEncrypted Message: (a, b) = ({a}, {b})")

    decrypted = decrypt(a, b, private_key, p)
    print(f"Decrypted Message: {decrypted}")

    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
