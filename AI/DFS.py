from collections import deque
from tabulate import tabulate

def dfs(graph, start, goal):
    # Stack for DFS
    stack = [start]
    visited = set()
    parent = {start: None}
    steps = []

    # Record the initial state
    steps.append({
        'Stack': list(stack),
        'Visited': list(visited),
        'Current Node': None
    })

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

        if current not in visited:
            visited.add(current)

            # Add neighbors to the stack
            for neighbor in reversed(graph.get(current, [])):
                if neighbor not in visited:
                    stack.append(neighbor)
                    parent[neighbor] = current

        # Record the state of the DFS process
        steps.append({
            'Stack': list(stack),
            'Visited': list(visited),
            'Current Node': current
        })
    
    # If no path is found
    return None, steps

def print_steps_table(steps):
    headers = ['Stack', 'Visited', 'Current Node']
    table = []
    for step in steps:
        table.append([
            str(step['Stack']),
            str(step['Visited']),
            step['Current Node']
        ])
    print("\nDFS Steps:")
    print(tabulate(table, headers=headers, tablefmt='grid'))

def main():
    graph = {}
    num_nodes = int(input("Enter the number of nodes: "))

    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node}: ").split()
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    path, steps = dfs(graph, start, goal)
    print_steps_table(steps)
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")

if __name__ == "__main__":
    main()
