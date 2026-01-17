// DS/Algo used - Dijkstra's Algorithm

// Time Complexity = O(ElogV)
// Space Complexity = O(V + E)

package homework3.Satyam_Mishra;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

class Triplet {
    String city1;
    String city2;
    double time;

    public Triplet(String city1, String city2, double time) {
        this.city1 = city1;
        this.city2 = city2;
        this.time = time;
    }
}

class Pair {
    String city;
    double time;

    public Pair(String city, double time) {
        this.city = city;
        this.time = time;
    }
}

public class Q11_VacationDestinations {
    private static List<String> bfs(String origin, int k, Map<String, List<Pair>> adjMap) {
        List<String> res = new ArrayList<>();
        Set<String> visited = new HashSet<>();

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(a.time, b.time));
        pq.add(new Pair(origin, 0));

        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            String city = top.city;
            double time = top.time;

            if(visited.contains(city)) continue;

            visited.add(city);
            if(!city.equals(origin)) res.add(city);

            for(Pair nei : adjMap.get(city)) {
                double newTime = time + nei.time;

                if(!city.equals(origin)) {
                    newTime += 1;
                }

                if(newTime > k) continue;

                pq.add(new Pair(nei.city, newTime));
            }
        }

        return res;
    }
    public static void main(String[] args) {
        List<Triplet> edges = new ArrayList<>();
        edges.add(new Triplet("Boston", "New York", 4));
        edges.add(new Triplet("New York", "Philadelphia", 2));
        edges.add(new Triplet("Boston", "Newport", 1.5));
        edges.add(new Triplet("Washington, D.C.", "Harper's Ferry", 1));
        edges.add(new Triplet("Boston", "Portland", 2.5));
        edges.add(new Triplet("Philadelphia", "Washington, D.C.", 2.5));

        String origin = "New York";
        int k = 5;

        Map<String, List<Pair>> adjMap = new HashMap<>();

        for (Triplet edge : edges) {
            adjMap.putIfAbsent(edge.city1, new ArrayList<>());
            adjMap.putIfAbsent(edge.city2, new ArrayList<>());

            adjMap.get(edge.city1).add(new Pair(edge.city2, edge.time));
            adjMap.get(edge.city2).add(new Pair(edge.city1, edge.time));
        }

        System.out.println(bfs(origin, k, adjMap));
    }
}

// time taken 22m 40s
