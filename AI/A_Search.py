import heapq
from tabulate import tabulate

def a_star_search(graph, start, goal, heuristic, edge_costs):
    # Priority queue for A* Search
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
        'Current Node': None,
        'Total Cost': 0
    })

    while open_set:
        current_cost, current = heapq.heappop(open_set)

        # Check if we have reached the goal
        if current == goal:
            path = []
            total_cost = cost[goal]  # Total cost to reach the goal
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            return path, total_cost, steps
        
        visited.add(current)

        # Add neighbors to the priority queue
        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                new_cost = cost[current] + edge_costs.get((current, neighbor), 1)  # Edge cost
                priority = new_cost + heuristic.get(neighbor, float('inf'))
                if neighbor not in cost or new_cost < cost[neighbor]:
                    cost[neighbor] = new_cost
                    heapq.heappush(open_set, (priority, neighbor))
                    parent[neighbor] = current
        
        # Record the state of the A* Search process
        steps.append({
            'Open Set': [item[1] for item in open_set],
            'Visited': list(visited),
            'Current Node': current,
            'Total Cost': cost.get(current, 0)
        })
    
    # If no path is found
    return None, float('inf'), steps

def print_steps_table(steps):
    headers = ['Open Set', 'Visited', 'Current Node', 'Total Cost']
    table = []
    for step in steps:
        table.append([
            str(step['Open Set']),
            str(step['Visited']),
            step['Current Node'],
            step['Total Cost']
        ])
    print("\nA* Search Steps:")
    print(tabulate(table, headers=headers, tablefmt='grid'))

def main():
    graph = {}
    edge_costs = {}
    num_nodes = int(input("Enter the number of nodes: "))

    # Input graph edges
    for _ in range(num_nodes):
        node = input("Enter the node: ")
        neighbors = input(f"Enter the neighbors of node {node}: ").split()
        graph[node] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

    # Input edge costs
    print("\nEnter the costs for moving from one node to another:")
    for node in graph.keys():
        for neighbor in graph[node]:
            if (node, neighbor) not in edge_costs and (neighbor, node) not in edge_costs:
                cost = int(input(f"Enter the cost from {node} to {neighbor}: "))
                edge_costs[(node, neighbor)] = cost

    # Input heuristic values
    heuristic = {}
    for node in graph.keys():
        heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))

    start = input("Enter the start node: ")
    goal = input("Enter the goal node: ")

    path, total_cost, steps = a_star_search(graph, start, goal, heuristic, edge_costs)
    print_steps_table(steps)
    if path:
        print("Path found:", " -> ".join(path))
        print("Total cost:", total_cost)
    else:
        print("No path found.")

if __name__ == "__main__":
    main()
