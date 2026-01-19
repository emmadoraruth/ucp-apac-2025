/*
data structure: Graph  + Priority Queue
algorithm: Dijkstra's Algorithm 
time spent: 35 minutes
time complexity: O((V + E) log V)
space complexity: O(V + E)
*/
import java.util.*;
public class ques11
{
    static class Edge
    {
        String to;
        double time;
        Edge(String to, double time)
        {
            this.to = to;
            this.time = time;
        }
    }
    static class State
    {
        String city;
        double travelTime;
        int edgesUsed;
        State(String city, double travelTime, int edgesUsed)
        {
            this.city = city;
            this.travelTime = travelTime;
            this.edgesUsed = edgesUsed;
        }
    }
    public static int countDestinations(String origin,double k,List<String[]> routes)
    {
        Map<String, List<Edge>> graph = new HashMap<>();
        for (String[] r : routes)
        {
            String from = r[0];
            String to = r[1];
            double time = Double.parseDouble(r[2]);
            graph.putIfAbsent(from, new ArrayList<>());
            graph.putIfAbsent(to, new ArrayList<>());
            graph.get(from).add(new Edge(to, time));
            graph.get(to).add(new Edge(from, time));
        }
        Map<String, Double> bestTime = new HashMap<>();
        Map<String, Integer> bestEdges = new HashMap<>();
        PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> Double.compare(a.travelTime, b.travelTime));
        pq.add(new State(origin, 0, 0));
        bestTime.put(origin, 0.0);
        bestEdges.put(origin, 0);
        while (!pq.isEmpty())
        {
            State curr = pq.poll();
            for (Edge edge : graph.get(curr.city))
            {
                double newTravelTime = curr.travelTime + edge.time;
                int newEdges = curr.edgesUsed + 1;
                if (!bestTime.containsKey(edge.to)|| newTravelTime < bestTime.get(edge.to))
                {
                    bestTime.put(edge.to, newTravelTime);
                    bestEdges.put(edge.to, newEdges);
                    pq.add(new State(edge.to,newTravelTime,newEdges));
                }
            }
        }
        int count = 0;
        for (String city : bestTime.keySet())
        {
            if (city.equals(origin))
            {
                continue;
            }
            int edges = bestEdges.get(city);
            double totalTime = bestTime.get(city) + (edges - 1);
            if (totalTime <= k)
            {
                count++;
            }
        }

        return count;
    }
    public static void main(String[] args)
    {

        List<String[]> routes = Arrays.asList( new String[]{"Boston", "New York", "4"}, new String[]{"New York", "Philadelphia", "2"}, new String[]{"Boston", "Newport", "1.5"}, new String[]{"Washington, D.C.", "Harper's Ferry", "1"},new String[]{"Boston", "Portland", "2.5"},new String[]{"Philadelphia", "Washington, D.C.", "2.5"});
        System.out.println(countDestinations("New York", 5, routes)); 
        // Expected: 2
        System.out.println(countDestinations("New York", 7, routes));
         // Expected: 4
        System.out.println(countDestinations("New York", 8, routes)); 
        // Expected: 6
    }
}

