def caesar_cipher(text, key):
    result = ""

    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            result += chr((ord(char) - base + key) % 26 + base)
        else:
            result += char  # Keep non-alphabet characters unchanged

    return result

def main():
    print("\t\t=================")
    print("\t\t  Caesar Cipher  ")
    print("\t\t=================")
    
    key = int(input("Enter the key: "))
    
    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':   
            text = input("Enter the text to encrypt: ")
            encrypted = caesar_cipher(text, key)    #Encryption
            print("Encrypted text:", encrypted)
            
        elif choice == '2':
            text = input("Enter the text to decrypt: ")
            decrypted = caesar_cipher(text, -key)   #Decryption
            print("Decrypted text:", decrypted)
            
        elif choice == '3':
            print("Exiting the program.")
            break
        
        else:
            print("Invalid choice.")
            
    print("\nCompiled by : Subodh Ghimire")            
    
if __name__ == "__main__":
    main()
    