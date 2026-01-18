// Assumptions:
// 1. There is atleast one valid order in which all courses can be completed

// DS/Algo used - Kahn's algorithm

// Time Complexity = O(V + E), where V is the number of courses
// Space Complexity = O(V + E), excluding output list space

package homework3.Satyam_Mishra;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Q10_PrerequisiteCourses {
    public static List<String> prerequisiteCourses(String[] courses, Map<String, List<String>> adjMap) {
        List<String> result = new ArrayList<>();

        Map<String, Integer> indegree = new HashMap<>();
        for (String course : courses) {
            indegree.put(course, 0);
        }

        for (String course : adjMap.keySet()) {
            for (String dependency : adjMap.get(course)) {
                indegree.put(dependency, indegree.get(dependency) + 1);
            }
        }

        Queue<String> q = new ArrayDeque<>();
        for(String key : indegree.keySet()) {
            if(indegree.get(key) == 0) {
                q.add(key);
            }
        }

        while (!q.isEmpty()) {
            String front = q.poll();
            result.add(front);

            if(!adjMap.containsKey(front)) continue;

            List<String> prerequisites = adjMap.get(front);
            for(String prerequisite : prerequisites) {
                indegree.put(prerequisite, indegree.get(prerequisite) - 1);
                if(indegree.get(prerequisite) == 0) {
                    q.add(prerequisite);
                }
            }
        }

        Collections.reverse(result);
        return result;
    }

    public static void main(String[] args) {
        String[] courses = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};

        Map<String, List<String>> adjMap = new HashMap<>();
        adjMap.put("Data Structures", Arrays.asList("Intro to Programming"));
        adjMap.put("Advanced Algorithms", Arrays.asList("Data Structures"));
        adjMap.put("Operating Systems", Arrays.asList("Advanced Algorithms"));
        adjMap.put("Databases", Arrays.asList("Advanced Algorithms"));

        System.out.println("Test Case Result: " + prerequisiteCourses(courses, adjMap));
    }
}

// time taken 19m 40s
