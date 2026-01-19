/*
data structure: Graph 
algorithm: DFS
time spent : 25 minutes
time complexity: O(T + R) (T = number of towns, R = number of roads)
space complexity: O(T + R)
*/

import java.util.*;

public class ques6
{
    public static int countRoadNetworks(List<String> towns, List<String[]> roads)
    {
        Map<String, List<String>> graph = new HashMap<>();// build adjacency list
        for (String town : towns)
        {
            graph.put(town, new ArrayList<>());
        }
        for (String[] road : roads)
        {
            String a = road[0];
            String b = road[1];
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        Set<String> visited = new HashSet<>();
        int networks = 0;
        for (String town : towns) // count connected components
        {
            if (!visited.contains(town)&& graph.get(town).size() > 0)
            {
                dfs(town, graph, visited);
                networks++;
            }
        }

        return networks;
    }
    private static void dfs(String town, Map<String, List<String>> graph, Set<String> visited)
    {
        visited.add(town);
        for (String neighbor : graph.get(town))
        {
            if (!visited.contains(neighbor))
            {
                dfs(neighbor, graph, visited);
            }
        }
    }
    public static void main(String[] args)
    {
        List<String> towns1 = Arrays.asList("Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth","Glacier Bay", "Fairbanks", "McCarthy", "Copper Center","Healy", "Anchorage");
        List<String[]> roads1 = Arrays.asList(new String[]{"Anchorage", "Homer"},new String[]{"Glacier Bay", "Gustavus"},new String[]{"Copper Center", "McCarthy"},new String[]{"Anchorage", "Copper Center"},new String[]{"Copper Center", "Fairbanks"},new String[]{"Healy", "Fairbanks"},new String[]{"Healy", "Anchorage"});
        System.out.println("Output: " + countRoadNetworks(towns1, roads1)); 
        // Expected: 2
        List<String> towns2 = Arrays.asList("Kona", "Hilo", "Volcano", "Lahaina", "Hana","Haiku", "Kahului", "Princeville", "Lihue", "Waimea");
        List<String[]> roads2 = Arrays.asList(new String[]{"Kona", "Volcano"},new String[]{"Volcano", "Hilo"},new String[]{"Lahaina", "Hana"},new String[]{"Kahului", "Haiku"},new String[]{"Hana", "Haiku"},new String[]{"Kahului", "Lahaina"},new String[]{"Princeville", "Lihue"},new String[]{"Lihue", "Waimea"});
        System.out.println("Output: " + countRoadNetworks(towns2, roads2)); 
        // Expected: 3
    }
}

