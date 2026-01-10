// DS/Algo used - BFS

// Time Complexity = O(V+E)
// Space Complexity = O(V+E)

package homework3.Satyam_Mishra;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class Edge {
    String to;
    String color;

    public Edge(String to, String color) {
        this.to = to;
        this.color = color;
    }
}

class State {
    String node;
    String lastColor;
    int distance;

    public State(String node, String lastColor, int distance) {
        this.node = node;
        this.lastColor = lastColor;
        this.distance = distance;
    }
}

public class Q8_AlternatingPath {
    private static Map<String, List<Edge>> buildadjMap(String[][] edges) {
        Map<String, List<Edge>> adj = new HashMap<>();
        for (String[] edge : edges) {
            String u = edge[0];
            String v = edge[1];
            String color = edge[2];

            adj.putIfAbsent(u, new ArrayList<>());
            adj.putIfAbsent(v, new ArrayList<>());

            adj.get(u).add(new Edge(v, color));
        }

        return adj;
    }

    public static int bfs(String[][] edges, String origin, String destination, Map<String, List<Edge>> adjMap) {
        Queue<State> q = new ArrayDeque<>();
        
        Set<String> visited = new HashSet<>();

        q.add(new State(origin, "none", 0));
        visited.add(origin + "_none");

        while(!q.isEmpty()) {
            State front = q.poll();

            if (front.node.equals(destination)) {
                return front.distance;
            }

            if (!adjMap.containsKey(front.node)) continue;

            for (Edge nei : adjMap.get(front.node)) {
                if (front.lastColor.equals("none") || !nei.color.equals(front.lastColor)) {
                    
                    String stateKey = nei.to + "_" + nei.color;
                    
                    if (!visited.contains(stateKey)) {
                        visited.add(stateKey);
                        q.add(new State(nei.to, nei.color, front.distance + 1));
                    }
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String[][] edges = {
            {"A", "B", "blue"},
            {"A", "C", "red"},
            {"B", "D", "blue"},
            {"B", "E", "blue"},
            {"C", "B", "red"},
            {"D", "C", "blue"},
            {"A", "D", "red"},
            {"D", "E", "red"},
            {"E", "C", "red"}
        };

        Map<String, List<Edge>> adjMap = buildadjMap(edges);

        System.out.println("Shortest alternating path A -> E: " + bfs(edges, "A", "E", adjMap)); 

        System.out.println("Shortest alternating path E -> D: " + bfs(edges, "E", "D", adjMap));
    }
}

// time taken 37m
