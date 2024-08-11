def dfs(graph, start, goal):
    # Stack for DFS
    stack = [start]
    # Set for visited nodes
    visited = set()
    # Dictionary to track the path
    parent = {start: None}
    # To store the table of steps
    steps = []

    while stack:
        current = stack.pop()

        # Check if we have reached the goal
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return path, steps
        
        # Mark the current node as visited
        visited.add(current)

        # Add neighbors to the stack
        for neighbor in reversed(graph.get(current, [])):
            if neighbor not in visited and neighbor not in stack:
                stack.append(neighbor)
                parent[neighbor] = current

        # Record the state of the DFS process
        steps.append({
            'Stack': list(stack),
            'Visited': list(visited),
            'Current Node': current
        })

    return None, steps

def print_steps_table(steps):
    print("\nDFS Steps:")
    print(f"+---------------------+---------------------+------------------+")
    print(f"| {'Stack':<19} | {'Visited':<19} | {'Current Node':<14} |")
    print(f"+---------------------+---------------------+------------------+")
    for step in steps:
        print(f"| {str(step['Stack']):<19} | {str(step['Visited']):<19} | {step['Current Node']:<14} |")
        print(f"+---------------------+---------------------+------------------+")

def main():
    # Input graph
    graph = {}
    
    # Input number of nodes
    num_nodes = int(input("Enter the number of nodes: "))
    
    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node} : ").split(' ')
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    # Input start and goal nodes
    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    # Perform DFS using stack
    path, steps = dfs(graph, start, goal)
    
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")
    
    # Print the DFS steps in table format
    print_steps_table(steps)

if __name__ == "__main__":
    main()
