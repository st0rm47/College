def print_tower(tower):
    for i in range(len(tower)):
        print(f"Peg {i + 1}: {tower[i]}")

def move_disk(tower, from_peg, to_peg):
    if len(tower[from_peg - 1]) == 0:
        print("Invalid move: The source peg is empty.")
    elif len(tower[to_peg - 1]) > 0 and tower[from_peg - 1][-1] > tower[to_peg - 1][-1]:
        print("Invalid move: Can't place a larger disk on top of a smaller one.")
    else:
        disk = tower[from_peg - 1].pop()
        tower[to_peg - 1].append(disk)
        print(f"Moved disk {disk} from Peg {from_peg} to Peg {to_peg}")

def check_win(tower, num_disks):
    return tower[2] == list(range(num_disks, 0, -1))

def tower_of_hanoi(num_disks):
    tower = [list(range(num_disks, 0, -1)), [], []]
    print("Initial State:")
    print_tower(tower)
    
    while True:
        print("\nEnter your move or type 'exit' to quit.")
        user_input = input("Your move: ").strip().lower()
        
        if user_input == "exit":
            print("Game exited.")
            break
        
        try:
            from_peg, to_peg = map(int, user_input.split())
            if from_peg in [1, 2, 3] and to_peg in [1, 2, 3]:
                move_disk(tower, from_peg, to_peg)
                print_tower(tower)
                if check_win(tower, num_disks):
                    print("Congratulations! You have solved the Tower of Hanoi puzzle.")
                    break
            else:
                print("Invalid move: Please enter valid peg numbers (1, 2, or 3).")
        except ValueError:
            print("Invalid input: Please enter your move in the format 'from_peg to_peg'.")

if __name__ == "__main__":
    num_disks = int(input("Enter the number of disks: "))
    tower_of_hanoi(num_disks)
