// DS/Algo used - DFS

// Time Complexity = O(R), where R is length of road array
// Space Complexity = O(R)

package homework3.Satyam_Mishra;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Q6_RoadNetworks {

    private static void dfs(String town, Set<String> visitedTowns, Map<String,List<String>> adjMap) {
        visitedTowns.add(town);
        
        List<String> nei = adjMap.get(town);

        for(String n : nei) {
            if(!visitedTowns.contains(n)) {
                dfs(n, visitedTowns, adjMap);
            }
        }
    }
    public static void main(String[] args) {
        String[] towns = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};
        String[][] roads = {{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}};

        Map<String, List<String>> adjMap = new HashMap<>();
        for(int i = 0; i < roads.length; i++) {
            String u = roads[i][0];
            String v = roads[i][1];

            if(!adjMap.containsKey(u)) {
                adjMap.put(u, new ArrayList<>());
            }
            adjMap.get(u).add(v);

            if(!adjMap.containsKey(v)) {
                adjMap.put(v, new ArrayList<>());
            }
            adjMap.get(v).add(u);
        }

        int numOfRoadNetworks = 0;
        Set<String> visitedTowns = new HashSet<>();
        for(String town : adjMap.keySet()) {
            if(!visitedTowns.contains(town)) {
                dfs(town, visitedTowns, adjMap);
                numOfRoadNetworks++;
            }
        }
        
        System.out.println("Number of road networks are: " + numOfRoadNetworks);
    }

}

// time taken 26m 30s
