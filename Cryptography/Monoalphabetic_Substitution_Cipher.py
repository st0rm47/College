import random
import string

def generate_key():
    letters = list(string.ascii_lowercase)
    random.shuffle(letters)
    return dict(zip(string.ascii_lowercase, letters))

def encrypt(text, key_map):
    result = ""
    for char in text:
        if char.isalpha():
            if char.isupper():
                result += key_map[char.lower()].upper()
            else:
                result += key_map[char]
        else:
            result += char
    return result

def decrypt(text, key_map):
    reverse_map = {v: k for k, v in key_map.items()}
    result = ""
    for char in text:
        if char.isalpha():
            if char.isupper():
                result += reverse_map[char.lower()].upper()
            else:
                result += reverse_map[char]
        else:
            result += char
    return result

def main():
    print("\t\t======================================")
    print("\t\t  Monoalphabetic Substitution Cipher  ")
    print("\t\t======================================")

    key_map = generate_key()
    
    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':
            text = input("Enter the text to encrypt: ")
            encrypted = encrypt(text, key_map)
            print("Encrypted text:", encrypted)

        elif choice == '2':
            text = input("Enter the text to decrypt: ")
            decrypted = decrypt(text, key_map)
            print("Decrypted text:", decrypted)

        elif choice == '3':
            print("Exiting the program.")
            break

        else:
            print("Invalid choice.")

    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
