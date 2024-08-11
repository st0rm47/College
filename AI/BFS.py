from collections import deque
from tabulate import tabulate

def bfs(graph, start, goal):
    # Queue for BFS
    queue = deque([start])
    visited = set()
    parent = {start: None}
    steps = []

    # Record the initial state
    steps.append({
        'Queue': list(queue),
        'Visited': list(visited),
        'Current Node': None
    })

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
    
    # If no path is found
    return None, steps

def print_steps_table(steps):
    headers = ['Queue', 'Visited', 'Current Node']
    table = []
    for step in steps:
        table.append([
            str(step['Queue']),
            str(step['Visited']),
            step['Current Node']
        ])
    print("\nBFS Steps:")
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

    path, steps = bfs(graph, start, goal)
    print_steps_table(steps)
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")

if __name__ == "__main__":
    main()
