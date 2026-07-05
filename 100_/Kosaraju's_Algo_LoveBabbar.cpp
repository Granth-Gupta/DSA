// Kosaraju's Algorithm is a two-pass algorithm used to find strongly connected components (SCCs) in a directed graph.
// The algorithm works as follows:
// 1. Perform a depth-first search (DFS) on the original graph and push the vertices onto a stack in the order of their finishing times.
// 2. Create a transposed graph by reversing the direction of all edges.
// 3. Perform DFS on the transposed graph, starting from the vertices in the order defined by the stack. Each DFS call will give you one strongly connected component.
// 4. Repeat the process until all vertices have been processed. The output will be the strongly connected components of the graph.

// The time complexity of Kosaraju's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph. This is because we perform two depth-first searches, each taking O(V + E) time. The space complexity is also O(V + E) due to the storage of the graph and the stack used for processing vertices.
// The algorithm is efficient and works well for large graphs, making it a popular choice for finding strongly connected components in directed graphs.