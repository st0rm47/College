def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def mod_inverse(e, phi):
    t, new_t = 0, 1
    r, new_r = phi, e

    while new_r != 0:
        quotient = r // new_r
        t, new_t = new_t, t - quotient * new_t
        r, new_r = new_r, r - quotient * new_r

    if r > 1:
        return None  # inverse doesn't exist
    if t < 0:
        t += phi
    return t

def generate_keys(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    # Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 2
    while gcd(e, phi) != 1:
        e += 1
        
    d = mod_inverse(e, phi)

    print(f"\nStep 1: Choose primes p = {p}, q = {q}")
    print(f"Step 2: Compute n = p * q = {n}")
    print(f"Step 3: Compute φ(n) = (p-1)(q-1) = {phi}")
    print(f"Step 4: Choose e = {e} such that gcd(e, φ(n)) = 1")
    print(f"Step 5: Compute d such that (e * d) % φ(n) = 1 → d = {d}")
    return ((e, n), (d, n))

def encrypt(message, public_key):
    e, n = public_key
    cipher = pow(message, e, n)
    return cipher

def decrypt(cipher, private_key):
    d, n = private_key
    message = pow(cipher, d, n)
    return message

def main():
    print("\t\t=================")
    print("\t\t  RSA Algorithm  ")
    print("\t\t=================")

    p = int(input("Enter first prime number (p): "))
    q = int(input("Enter second prime number (q): "))
    message = int(input("\nEnter the message (as integer): "))
    public_key, private_key = generate_keys(p, q)

    print(f"\nPublic Key (e, n): {public_key}")
    print(f"Private Key (d, n): {private_key}")

    cipher = encrypt(message, public_key)
    print(f"\nEncrypted message (ciphertext): {cipher}")

    decrypted = decrypt(cipher, private_key)
    print(f"Decrypted message: {decrypted}")

    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
