import heapq
from tabulate import tabulate

def best_first_search(graph, start, goal, heuristic):
    # Priority queue for Best-First Search
    open_set = []
    heapq.heappush(open_set, (0, start))
    # Set for visited nodes
    visited = set()
    # Dictionary to track the path
    parent = {start: None}
    # To store the table of steps
    steps = []

    while open_set:
        _, current = heapq.heappop(open_set)

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

        # Add neighbors to the priority queue
        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                priority = heuristic.get(neighbor, float('inf'))
                heapq.heappush(open_set, (priority, neighbor))
                parent[neighbor] = current

        # Record the state of the Best-First Search process
        steps.append({
            'Open Set': [item[1] for item in open_set],
            'Visited': list(visited),
            'Current Node': current
        })

    return None, steps

def print_steps_table(steps):
    headers = ['Open Set', 'Visited', 'Current Node']
    table = []
    for step in steps:
        table.append([
            str(step['Open Set']),
            str(step['Visited']),
            step['Current Node']
        ])
    print("\nBest-First Search Steps:")
    print(tabulate(table, headers=headers, tablefmt='grid'))

def main():
    # Input graph
    graph = {}
    
    # Input number of nodes
    num_nodes = int(input("Enter the number of nodes: "))
    
    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node} (space-separated): ").split(' ')
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    # Input heuristic values
    heuristic = {}
    for node in graph.keys():
        heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))

    # Input start and goal nodes
    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    # Perform Best-First Search
    path, steps = best_first_search(graph, start, goal, heuristic)
    
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")
    
    # Print the Best-First Search steps in table format
    print_steps_table(steps)

if __name__ == "__main__":
    main()
