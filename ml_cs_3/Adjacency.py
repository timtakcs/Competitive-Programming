#  File: Adjacency.py
#  Description: Converts an edge list into an adjacency matrix
#  Student Name:
#  Student UT EID:
#  Course Name: CS 313E
#  Unique Number:

def edge_to_adjacency(edge_list):
    nodes = sorted({node for edge in edge_list for node in [edge[0], edge[1]]})
    node_index = {node: i for i, node in enumerate(nodes)}
    size = len(nodes)
    matrix = [[0 for _ in range(size)] for _ in range(size)]
    
    for edge in edge_list:
        src, dest, weight = edge
        src_index = node_index[src]
        dest_index = node_index[dest]
        matrix[src_index][dest_index] = weight

    return matrix


# ------ DO NOT CHANGE BELOW HERE ------ #
import ast

def main():
    matrix = edge_to_adjacency(ast.literal_eval(input()))

    print('\n'.join([' '.join([str(cell) for cell in row]) for row in matrix]))

if __name__ == "__main__":
    main()
