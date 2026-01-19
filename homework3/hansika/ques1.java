import java.util.*;
public class ques1 
{
    // adjacency list from edge list
    public static Map<Integer, Set<Integer>> buildGraph(int[][] edges) 
    {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        // initializing nodes
        for (int i = 0; i < edges.length; i++) 
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph.putIfAbsent(u, new HashSet<>());
            graph.putIfAbsent(v, new HashSet<>());
            graph.get(u).add(v);
        }
        return graph;
    }

    // BFS
    public static boolean bfs(int target, Map<Integer, Set<Integer>> graph) 
    {
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        Integer[] keys = graph.keySet().toArray(new Integer[0]);
        for (int i = 0; i < keys.length; i++) 
        {
            int start = keys[i];

            if (visited.contains(start)) 
            {
                continue;
            }
            queue.add(start);
            visited.add(start);
            while (!queue.isEmpty()) 
            {
                int node = queue.poll();
                if (node == target) return true;
                Integer[] neighbors = graph.get(node).toArray(new Integer[0]);
                for (int j = 0; j < neighbors.length; j++) 
                {
                    int nei = neighbors[j];
                    if (!visited.contains(nei)) 
                    {
                        visited.add(nei);
                        queue.add(nei);
                    }
                }
            }
        }
        return false;
    }

    // DFS
    public static boolean dfs(int target, Map<Integer, Set<Integer>> graph) 
    {
        Set<Integer> visited = new HashSet<>();
        Integer[] keys = graph.keySet().toArray(new Integer[0]);
        for (int i = 0; i < keys.length; i++) 
        {
            int node = keys[i];

            if (dfsHelper(node, target, graph, visited)) 
            {
                return true;
            }
        }
        return false;
    }

    private static boolean dfsHelper(int node,int target,Map<Integer, Set<Integer>> graph,Set<Integer> visited) 
    {
        if (visited.contains(node)) return false;
        if (node == target) return true;
        visited.add(node);
        Integer[] neighbors = graph.get(node).toArray(new Integer[0]);
        for (int i = 0; i < neighbors.length; i++) 
        {
            int nei = neighbors[i];
            if (dfsHelper(nei, target, graph, visited)) 
            {
                return true;
            }
        }
        return false;
    }

    // topological sort (DFS)
    public static List<Integer> topologicalSortDFS(Map<Integer, Set<Integer>> graph) 
    {
        Set<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        Integer[] keys = graph.keySet().toArray(new Integer[0]);
        for (int i = 0; i < keys.length; i++) 
        {
            int node = keys[i];
            if (!visited.contains(node)) 
            {
                topoDfs(node, graph, visited, stack);
            }
        }
        List<Integer> result = new ArrayList<>();
        while (!stack.isEmpty()) 
        {
            result.add(stack.pop());
        }
        return result;
    }
    private static void topoDfs(int node,Map<Integer, Set<Integer>> graph,Set<Integer> visited,Stack<Integer> stack) 
    {
        visited.add(node);
        Integer[] neighbors = graph.get(node).toArray(new Integer[0]);
        for (int i = 0; i < neighbors.length; i++) 
        {
            int nei = neighbors[i];

            if (!visited.contains(nei)) 
            {
                topoDfs(nei, graph, visited, stack);
            }
        }
        stack.push(node);
    }

    // topological Sort (Kahn's Algorithm)
    public static List<Integer> topologicalSortKahn(Map<Integer, Set<Integer>> graph) 
    {
        Map<Integer, Integer> indegree = new HashMap<>();
        Integer[] keys = graph.keySet().toArray(new Integer[0]);
        for (int i = 0; i < keys.length; i++) 
        {
            indegree.put(keys[i], 0);
        }

        for (int i = 0; i < keys.length; i++) 
        {
            int node = keys[i];
            Integer[] neighbors = graph.get(node).toArray(new Integer[0]);

            for (int j = 0; j < neighbors.length; j++) 
            {
                int nei = neighbors[j];
                indegree.put(nei, indegree.get(nei) + 1);
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        Integer[] indegKeys = indegree.keySet().toArray(new Integer[0]);
        for (int i = 0; i < indegKeys.length; i++) 
        {
            int node = indegKeys[i];
            if (indegree.get(node) == 0) 
            {
                queue.add(node);
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) 
        {
            int node = queue.poll();
            result.add(node);

            Integer[] neighbors = graph.get(node).toArray(new Integer[0]);
            for (int i = 0; i < neighbors.length; i++) 
            {
                int nei = neighbors[i];
                indegree.put(nei, indegree.get(nei) - 1);
                if (indegree.get(nei) == 0) 
                {
                    queue.add(nei);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) 
    {
        int[][] edges = { {1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0} };
        Map<Integer, Set<Integer>> graph = buildGraph(edges);
        System.out.println("Graph: " + graph);
        System.out.println("BFS search for 3: " + bfs(3, graph));
        System.out.println("DFS search for 3: " + dfs(3, graph));
        System.out.println("Topological Sort (DFS): " + topologicalSortDFS(graph));
        System.out.println("Topological Sort (Kahn): " + topologicalSortKahn(graph));
    }
}
