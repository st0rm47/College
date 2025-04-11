# Function to repeat the key to match the length of the text
def generate_full_key(text, key):
    key = key.upper()
    key = (key * (len(text) // len(key))) + key[:len(text) % len(key)]
    return key

# Function to encrypt text
def vigenere_encrypt(text, key):
    text = text.upper().replace(" ", "")
    key = generate_full_key(text, key)
    result = ""

    for t, k in zip(text, key):
        if t.isalpha():
            enc_char = chr(((ord(t) - ord('A')) + (ord(k) - ord('A'))) % 26 + ord('A'))
            result += enc_char
        else:
            result += t
    return result

# Function to decrypt text
def vigenere_decrypt(text, key):
    text = text.upper().replace(" ", "")
    key = generate_full_key(text, key)
    result = ""

    for t, k in zip(text, key):
        if t.isalpha():
            dec_char = chr(((ord(t) - ord('A')) - (ord(k) - ord('A')) + 26) % 26 + ord('A'))
            result += dec_char
        else:
            result += t
    return result

# Main program
def main():
    print("\t\t===================")
    print("\t\t  Vigenère Cipher  ")
    print("\t\t===================")
    
    key = input("Enter key: ")

    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':
            text = input("Enter plaintext: ")
            encrypted = vigenere_encrypt(text, key)
            print("Encrypted text:", encrypted)

        elif choice == '2':
            text = input("Enter ciphertext: ")
            decrypted = vigenere_decrypt(text, key)
            print("Decrypted text:", decrypted)

        elif choice == '3':
            print("Exiting the program.")
            break

        else:
            print("Invalid choice!")

    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
