import heapq
from tabulate import tabulate

def best_first_search(graph, start, goal, heuristic):
    # Priority queue for Best-First Search
    open_set = []
    heapq.heappush(open_set, (0, start))
    visited = set()
    parent = {start: None}
    cost = {start: 0}
    steps = []

    # Record the initial state
    steps.append({
        'Open Set': [item[1] for item in open_set],
        'Visited': list(visited),
        'Current Node': None
    })

    while open_set:
        current_cost, current = heapq.heappop(open_set)

        # Check if we have reached the goal
        if current == goal:
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return path, steps
        
        visited.add(current)

        # Add neighbors to the priority queue
        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                new_cost = cost[current] + 1  # Assuming cost to each neighbor is 1
                priority = heuristic.get(neighbor, float('inf'))
                heapq.heappush(open_set, (priority, neighbor))
                parent[neighbor] = current
                cost[neighbor] = new_cost

        # Record the state of the Best-First Search process
        steps.append({
            'Open Set': [item[1] for item in open_set],
            'Visited': list(visited),
            'Current Node': current
        })
    
    # If no path is found
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
    graph = {}
    num_nodes = int(input("Enter the number of nodes: "))

    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node}: ").split()
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    # Input heuristic values
    heuristic = {}
    for node in graph.keys():
        heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))

    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    path, steps = best_first_search(graph, start, goal, heuristic)
    print_steps_table(steps)
    if path:
        print("Path found:", " -> ".join(path))
    else:
        print("No path found.")

if __name__ == "__main__":
    main()
