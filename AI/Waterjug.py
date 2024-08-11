def print_jugs(jug1, jug2, cap1, cap2):
    print(f"Jug 1: {jug1}/{cap1} liters")
    print(f"Jug 2: {jug2}/{cap2} liters")

def fill_jug(cap):
    return cap

def empty_jug():
    return 0

def pour_water(from_jug, to_jug, cap_from, cap_to):
    transfer_amount = min(from_jug, cap_to - to_jug)
    return (from_jug - transfer_amount, to_jug + transfer_amount)

def print_steps(steps):
    print("\nSteps Taken:")
    print(f"+{'-'*15}+{'-'*15}+{'-'*30}+")
    print(f"| {'Gallons in A':<13} | {'Gallons in B':<13} | {'Rule Applied':<28} |")
    print(f"+{'-'*15}+{'-'*15}+{'-'*30}+")
    for step in steps:
        print(f"| {step['Gallons in A']:<13} | {step['Gallons in B']:<13} | {step['Rule Applied']:<28} |")
        print(f"+{'-'*15}+{'-'*15}+{'-'*30}+")
    print()

def water_jug_problem(cap1, cap2, goal):
    jug1 = 0
    jug2 = 0
    steps = []

    print("Welcome to the Water Jug Problem game!")
    print(f"Jug 1 Capacity: {cap1} liters")
    print(f"Jug 2 Capacity: {cap2} liters")
    print(f"Target Amount: {goal} liters\n")
    
    print("\nAvailable Actions:")
    print(f"+{'-'*7}+{'-'*24}+")
    print(f"| {'Choice':<6} | {'Action':<22} |")
    print(f"+{'-'*7}+{'-'*24}+")
    actions = [
        ["1", "Fill Jug 1"],
        ["2", "Fill Jug 2"],
        ["3", "Empty Jug 1"],
        ["4", "Empty Jug 2"],
        ["5", "Pour Jug 1 into Jug 2"],
        ["6", "Pour Jug 2 into Jug 1"],
        ["7", "Exit"]
    ]
    for action in actions:
        print(f"| {action[0]:<6} | {action[1]:<22} |")
    print(f"+{'-'*7}+{'-'*24}+\n")

    while True:
        
        if jug1 == goal or jug2 == goal:
            print("Congratulations! You've measured the target amount.")
            break

        choice = input("Enter the number of your choice: ").strip()

        if choice == "1":
            jug1 = fill_jug(cap1)
            rule_applied = "Fill Jug 1"
        elif choice == "2":
            jug2 = fill_jug(cap2)
            rule_applied = "Fill Jug 2"
        elif choice == "3":
            jug1 = empty_jug()
            rule_applied = "Empty Jug 1"
        elif choice == "4":
            jug2 = empty_jug()
            rule_applied = "Empty Jug 2"
        elif choice == "5":
            jug1, jug2 = pour_water(jug1, jug2, cap1, cap2)
            rule_applied = "Pour Jug 1 into Jug 2"
        elif choice == "6":
            jug2, jug1 = pour_water(jug2, jug1, cap2, cap1)
            rule_applied = "Pour Jug 2 into Jug 1"
        elif choice == "7":
            print("Game exited.")
            break
        else:
            print("Invalid choice. Please try again.")
            continue
        
        steps.append({
            'Gallons in A': f"{jug1}/{cap1} liters",
            'Gallons in B': f"{jug2}/{cap2} liters",
            'Rule Applied': rule_applied
        })
        print_steps(steps)

if __name__ == "__main__":
    # Set the capacities of the jugs and the goal amount
    capacity1 = int(input("Enter the capacity of Jug 1: "))
    capacity2 = int(input("Enter the capacity of Jug 2: "))
    goal_amount = int(input("Enter the target amount of water: "))
    
    water_jug_problem(capacity1, capacity2, goal_amount)
