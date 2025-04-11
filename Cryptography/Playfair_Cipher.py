# Function to generate the key matrix
def generate_key_matrix(key):
    key = key.upper().replace("J", "I")
    key = "".join(sorted(set(key), key=key.index))  # Remove duplicates, preserve order
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    key += ''.join(c for c in alphabet if c not in key)

    return [list(key[i:i+5]) for i in range(0, 25, 5)]

# Function to find the position of a character in the matrix
def find_position(matrix, char):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == char:
                return i, j
    return -1, -1

# Function to prepare the text for encryption/decryption
def prepare_text(text):
    text = text.upper().replace("J", "I")
    prepared = ""
    i = 0
    while i < len(text):
        a = text[i]
        b = text[i+1] if i+1 < len(text) else 'X'
        if a == b:
            prepared += a + 'X'
            i += 1
        else:
            prepared += a + b
            i += 2
    if len(prepared) % 2 == 1:
        prepared += 'X'
    return prepared

# Function to encrypt the text using Playfair Cipher
def playfair_encrypt(text, matrix):
    text = prepare_text(text)
    result = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i+1]
        row1, col1 = find_position(matrix, a)
        row2, col2 = find_position(matrix, b)

        if row1 == row2:
            result += matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            result += matrix[(row1 + 1) % 5][col1] +  matrix[(row2 + 1) % 5][col2]
        else:
            result += matrix[row1][col2] + matrix[row2][col1]
    return result

# Function to decrypt the text using Playfair Cipher
def playfair_decrypt(text, matrix):
    result = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i+1]
        row1, col1 = find_position(matrix, a)
        row2, col2 = find_position(matrix, b)

        if row1 == row2:
            result += matrix[row1][(col1 - 1) % 5] +  matrix[row2][(col2 - 1) % 5]
        elif col1 == col2:
            result += matrix[(row1 - 1) % 5][col1] +  matrix[(row2 - 1) % 5][col2]
        else:
            result += matrix[row1][col2] + matrix[row2][col1]
    return result

def main():
    print("\t\t===================")
    print("\t\t  Playfair Cipher  ")
    print("\t\t===================")
    
    key = input("Enter key: ")
    matrix = generate_key_matrix(key)

    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':
            text = input("Enter plaintext: ")
            encrypted = playfair_encrypt(text, matrix)      #Encryption
            print("Encrypted text:", encrypted)
            
        elif choice == '2':
            text = input("Enter ciphertext: ")
            decrypted = playfair_decrypt(text, matrix)      #Decryption
            print("Decrypted text:", decrypted)
            
        elif choice == '3':
            print("Exiting the program.")
            break
        
        else:
            print("Invalid choice!")

    print("\nCompiled by: Subodh Ghimire")
        
if __name__ == "__main__":
    main()

