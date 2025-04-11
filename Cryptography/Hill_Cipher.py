import numpy as np

# Find modular inverse of a matrix under mod 26
def mod_matrix_inverse(matrix):
    det = int(np.round(np.linalg.det(matrix)))  # Determinant
    det_inv = pow(det % 26, -1, 26)             # Modular inverse
    adj = np.round(np.linalg.inv(matrix) * det).astype(int) % 26  # Adjoint
    return (det_inv * adj) % 26

# Convert text to numbers (A=0 ... Z=25) and numbers to text
def text_to_nums(text):
    return [ord(c.upper()) - ord('A') for c in text if c.isalpha()]

def nums_to_text(nums):
    return ''.join(chr(n + ord('A')) for n in nums)

# Encrypt text using Hill Cipher
def hill_encrypt(text, key):
    nums = text_to_nums(text)
    n = key.shape[0]

    if len(nums) % n != 0:
        nums.append(23)  # 'X' = 23 for padding

    result = []
    for i in range(0, len(nums), n):
        block = nums[i:i+n]
        enc = np.dot(key, block) % 26
        result.extend(enc)

    return nums_to_text(result)

# Decrypt text using Hill Cipher
def hill_decrypt(text, key):
    inv_key = mod_matrix_inverse(key)
    nums = text_to_nums(text)
    n = inv_key.shape[0]

    result = []
    for i in range(0, len(nums), n):
        block = nums[i:i+n]
        dec = np.dot(inv_key, block) % 26
        result.extend(dec)

    return nums_to_text(result)

def main():
    print("\t\t===============")
    print("\t\t  Hill Cipher  ")
    print("\t\t===============")
    
    key_matrix = input("Enter the key matrix (space-separated): ")
    key_matrix = np.array([int(num) for num in key_matrix.split()]).reshape(2, 2)  # Reshape to 2x2 matrix
            
    while True:
        print("\n1. Encrypt Text \n2. Decrypt Text \n3. Exit")
        choice = input("Enter your choice (1/2/3): ")

        if choice == '1':   
            plaintext = input("Enter the text to encrypt: ")
            encrypted = hill_encrypt(plaintext, key_matrix)
            print("Encrypted text:", encrypted)
            
        elif choice == '2':
            ciphertext = input("Enter the text to decrypt: ")
            decrypted = hill_decrypt(ciphertext, key_matrix)
            print("Decrypted text:", decrypted)
            
        elif choice == '3':
            print("Exiting the program.")
            break
        
        else:
            print("Invalid choice.")
            
    print("\nCompiled by : Subodh Ghimire")

if __name__ == "__main__":
    main()
    
