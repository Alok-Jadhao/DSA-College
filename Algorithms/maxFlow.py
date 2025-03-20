import networkx as nx

# Define the number of vertices and edges
V = 25
edges = [
    (0, 1, 16), (0, 2, 13), (1, 2, 10), (1, 3, 12), (2, 1, 4), (2, 4, 14),
    (3, 2, 9), (3, 5, 20), (4, 3, 7), (4, 5, 4), (5, 6, 10), (6, 7, 6),
    (7, 8, 12), (8, 9, 15), (9, 10, 10), (10, 11, 8), (11, 12, 14),
    (12, 13, 16), (13, 14, 18), (14, 15, 20), (15, 16, 22), (16, 17, 24),
    (17, 18, 26), (18, 19, 28), (19, 20, 30), (20, 21, 32), (21, 22, 34),
    (22, 23, 36), (23, 24, 38), (24, 0, 40), (1, 6, 5), (2, 7, 8), 
    (3, 8, 3), (4, 9, 7), (5, 10, 12), (6, 11, 15), (7, 12, 9), (8, 13, 6),
    (9, 14, 11), (10, 15, 7)
]

source = 0
sink = 24

# Create a directed graph and add edges with capacities
G = nx.DiGraph()
G.add_weighted_edges_from(edges, weight="capacity")

# Compute the maximum flow using Ford-Fulkerson (Edmonds-Karp algorithm)
max_flow_value, flow_dict = nx.maximum_flow(G, source, sink)

max_flow_value

