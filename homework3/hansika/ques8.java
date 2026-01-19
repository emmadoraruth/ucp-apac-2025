/*
data structure: Graph  + Queue
algorithm: BFS
time :38 minutes
time complexity: O(V + E)
space complexity: O(V + E)
*/

import java.util.*;
public class ques8
{
    static class Edge
    {
        String to;
        String color;
        Edge(String to, String color)
        {
            this.to = to;
            this.color = color;
        }
    }

    static class State
    {
        String node;
        String lastColor;
        int distance;
        State(String node, String lastColor, int distance)
        {
            this.node = node;
            this.lastColor = lastColor;
            this.distance = distance;
        }
    }
    public static int shortestAlternatingPath(String origin,String destination,List<String[]> edges)
    {
        Map<String, List<Edge>> graph = new HashMap<>();
        for (String[] e : edges)
        {
            graph.putIfAbsent(e[0], new ArrayList<>());
            graph.putIfAbsent(e[1], new ArrayList<>());
            graph.get(e[0]).add(new Edge(e[1], e[2]));
        }
        // visited[node-color]
        Set<String> visited = new HashSet<>();
        Queue<State> queue = new LinkedList<>();
        // Start with no previous color
        queue.add(new State(origin, "none", 0));
        visited.add(origin + "-none");
        while (!queue.isEmpty())
        {
            State curr = queue.poll();
            if (curr.node.equals(destination))
            {
                return curr.distance;
            }
            for (Edge edge : graph.getOrDefault(curr.node, new ArrayList<>()))
            {
                // Colors must alternate
                if (!edge.color.equals(curr.lastColor))
                {
                    String key = edge.to + "-" + edge.color;
                    if (!visited.contains(key))
                    {
                        visited.add(key);
                        queue.add(new State(edge.to,edge.color,curr.distance + 1));
                    }
                }
            }
        }
        return -1;
    }
    public static void main(String[] args)
    {

        List<String[]> edges = Arrays.asList(new String[]{"A", "B", "blue"},new String[]{"A", "C", "red"},new String[]{"B", "D", "blue"},new String[]{"B", "E", "blue"},new String[]{"C", "B", "red"},new String[]{"D", "C", "blue"},new String[]{"A", "D", "red"},new String[]{"D", "E", "red"},new String[]{"E", "C", "red"});
        System.out.println(shortestAlternatingPath("A", "E", edges)); 
        // Expected: 4
        System.out.println(shortestAlternatingPath("E", "D", edges)); 
        // Expected: -1
    }
}

