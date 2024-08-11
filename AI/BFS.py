from collections import deque

def bfs(graph, start, goal):
    # Queue for BFS
    queue = deque([start])
    # Set for visited nodes
    visited = set()
    # Dictionary to track the path
    parent = {start: None}
    # To store the table of steps
    steps = []

    while queue:
        current = queue.popleft()

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

        # Add neighbors to the queue
        for neighbor in graph.get(current, []):
            if neighbor not in visited and neighbor not in queue:
                queue.append(neighbor)
                parent[neighbor] = current

        # Record the state of the BFS process
        steps.append({
            'Queue': list(queue),
            'Visited': list(visited),
            'Current Node': current
        })

    return None, steps

def print_steps_table(steps):
    print("\nBFS Steps:")
    print(f"+---------------------+---------------------+------------------+")
    print(f"| {'Queue':<19} | {'Visited':<19} | {'Current Node':<14} |")
    print(f"+---------------------+---------------------+------------------+")
    for step in steps:
        print(f"| {str(step['Queue']):<19} | {str(step['Visited']):<19} | {step['Current Node']:<14} |")
        print(f"+---------------------+---------------------+------------------+")

def main():
    # Input graph
    graph = {}
    
    # Input number of nodes
    num_nodes = int(input("Enter the number of nodes: "))
    
    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node} (comma-separated): ").split(',')
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    # Input start and goal nodes
    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    # Perform BFS using queue
    path, steps = bfs(graph, start, goal)
    

    # Print the BFS steps in table format
    print_steps_table(steps)
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")

if __name__ == "__main__":
    main()
