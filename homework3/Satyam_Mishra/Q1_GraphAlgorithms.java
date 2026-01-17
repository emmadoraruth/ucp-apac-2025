// Assumptions:
// 1. Node passed in method calls are assumed to be present in graph
// 2. Graph is assumed to be a single component
// 3. Graph is assumed to be non-cyclic 

package homework3.Satyam_Mishra;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class Q1_GraphAlgorithms {
    public Map<Integer, List<Integer>> buildGraph(int[][] edges) {
        Map<Integer, List<Integer>> adjMap = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!adjMap.containsKey(u)) {
                adjMap.put(u, new ArrayList<>());
            }
            if (!adjMap.containsKey(v)) {
                adjMap.put(v, new ArrayList<>());
            }
            adjMap.get(u).add(v);
        }

        return adjMap;
    }

    public boolean dfs(int target, Map<Integer, List<Integer>> adjMap) {
        Set<Integer> visited = new HashSet<>();
        
        for (int node : adjMap.keySet()) {
            if (!visited.contains(node)) {
                if(dfsHelper(node, target, adjMap, visited)) return true;
            }
        }
        return false;
    }

    private boolean dfsHelper(int node, int target, Map<Integer, List<Integer>> adjMap, Set<Integer> visited) {
        if(node == target) return true;

        visited.add(node);

        for(int nei : adjMap.get(node)) {
            if(!visited.contains(nei)) {
                if(dfsHelper(nei, target, adjMap, visited)) return true;
            }
        }

        return false;
    }

    public boolean bfs(int target, Map<Integer, List<Integer>> adjMap) {
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> q = new ArrayDeque<>();
        
        for (int node : adjMap.keySet()) {
            if (!visited.contains(node)) {
                if(bfsHelper(node, target, adjMap, visited, q)) return true;
            }
        }
        return false;
    }

    private boolean bfsHelper(int node, int target, Map<Integer, List<Integer>> adjMap, Set<Integer> visited, Queue<Integer> q) {
        if(node == target) return true;

        q.add(node);
        visited.add(node);

        while (!q.isEmpty()) {
            int currNode = q.poll();

            for(int nei : adjMap.get(currNode)) {
                if(nei == target) return true;

                if(!visited.contains(nei)) {
                    q.add(nei);
                    visited.add(nei);
                }
            }
        }

        return false;
    }
 
    public List<Integer> topologicalSortDfs(Map<Integer, List<Integer>> adjMap) {
        LinkedList<Integer> topoSort = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        
        for (int node : adjMap.keySet()) {
            if (!visited.contains(node)) {
                topoSortDfsHelper(node, adjMap, visited, topoSort);
            }
        }
        return topoSort;
    }

    private void topoSortDfsHelper(int node, Map<Integer, List<Integer>> adjMap, Set<Integer> visited, LinkedList<Integer> topoSort) {
        visited.add(node);
        for(int nei : adjMap.get(node)) {
            if(!visited.contains(nei)) {
                topoSortDfsHelper(nei, adjMap, visited, topoSort);
            }
        }
        topoSort.addFirst(node);
    }

    public List<Integer> topoSortBfs(Map<Integer, List<Integer>> adjMap) {
        Map<Integer, Integer> indegree = new HashMap<>();
        for(int key : adjMap.keySet()) {
            indegree.put(key, 0);
        }

        for(List<Integer> neighbors : adjMap.values()) {
            for(int n : neighbors) {
                indegree.put(n, indegree.get(n) + 1);
            }
        }

        Queue<Integer> q = new ArrayDeque<>();
        for(int node : indegree.keySet()) {
            if(indegree.get(node) == 0) {
                q.add(node);
            }
        }

        List<Integer> topoSort = new ArrayList<>();
        
        while (!q.isEmpty()) {
            int currNode = q.poll();
            topoSort.add(currNode);

            for(int nei : adjMap.get(currNode)) {
                indegree.put(nei, indegree.get(nei) - 1);
                if(indegree.get(nei) == 0) {
                    q.add(nei);
                }
            }
        }

        return topoSort;
    }
}
