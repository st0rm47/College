from tabulate import tabulate

# Function to display the rails in table design
def display_rails_table(matrix):
    table = [[" " if ch == " " else ch for ch in row] for row in matrix]
    headers = [str(i) for i in range(1, len(matrix[0]) + 1)]
    print(tabulate(table, headers=headers, tablefmt="fancy_grid"))

# Function to encrypt using Rail Fence Cipher
def rail_fence_encrypt(text, key):
    text = text.replace(" ", "")
    n = len(text)
    rail = [[' ' for _ in range(n)] for _ in range(key)]

    dir_down = False
    row, col = 0, 0

    for char in text:
        rail[row][col] = char
        if row == 0 or row == key - 1:
            dir_down = not dir_down
        row += 1 if dir_down else -1
        col += 1

    print("\nRail Pattern (Encryption):")
    display_rails_table(rail)

    result = ''
    for r in rail:
        result += ''.join([c for c in r if c != ' '])
    return result

# Function to decrypt using Rail Fence Cipher
def rail_fence_decrypt(cipher, key):
    n = len(cipher)
    rail = [[' ' for _ in range(n)] for _ in range(key)]

    # Mark the zigzag path
    dir_down = None
    row, col = 0, 0
    for _ in range(n):
        if row == 0:
            dir_down = True
        elif row == key - 1:
            dir_down = False
        rail[row][col] = '*'
        row += 1 if dir_down else -1
        col += 1

    # Fill the path with the cipher characters
    index = 0
    for i in range(key):
        for j in range(n):
            if rail[i][j] == '*' and index < len(cipher):
                rail[i][j] = cipher[index]
                index += 1

    print("\nRail Pattern (Decryption):")
    display_rails_table(rail)

    # Read characters following the zigzag path
    result = ''
    row, col = 0, 0
    dir_down = None
    for _ in range(n):
        if row == 0:
            dir_down = True
        elif row == key - 1:
            dir_down = False
        result += rail[row][col]
        row += 1 if dir_down else -1
        col += 1

    return result

def main():
    print("\t\t=====================")
    print("\t\t  Rail Fence Cipher  ")
    print("\t\t=====================")

    key = int(input("Enter key (number of rails): "))
    
    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':
            text = input("Enter plaintext: ")
            encrypted = rail_fence_encrypt(text, key)
            print("Encrypted text:", encrypted)

        elif choice == '2':
            text = input("Enter ciphertext: ")
            decrypted = rail_fence_decrypt(text, key)
            print("Decrypted text:", decrypted)

        elif choice == '3':
            print("Exiting the program.")
            break

        else:
            print("Invalid choice!")

    print("\nCompiled by: Subodh Ghimire")

if __name__ == "__main__":
    main()
