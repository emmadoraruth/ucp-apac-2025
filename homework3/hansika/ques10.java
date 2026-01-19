/*
data structure: graph
algorithm: bfs (topological sort using kahn's algorithm)
time taken: 32 minutes
time complexity: o(v + e) (v = number of vertices and e = number of edges)
space complexity: o(v + e)
*/
import java.util.*;
public class ques10
{
    public static List<String> findCourseOrder(List<String> courses, Map<String, List<String>> prerequisites)
    {
        // build graph
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> indegree = new HashMap<>();
        for (int i = 0; i < courses.size(); i++)
        {
            graph.put(courses.get(i), new ArrayList<>());
            indegree.put(courses.get(i), 0);
        }
        // build edges
        Set<String> prereqKeys = prerequisites.keySet();
        String[] keys = prereqKeys.toArray(new String[0]);
        for (int i = 0; i < keys.length; i++)
        {
            String course = keys[i];
            List<String> prereqList = prerequisites.get(course);
            for (int j = 0; j < prereqList.size(); j++)
            {
                String prereq = prereqList.get(j);
                graph.get(prereq).add(course);
                indegree.put(course, indegree.get(course) + 1);
            }
        }
        // queue for courses with no prerequisites
        Queue<String> queue = new LinkedList<>();
        Set<String> indegKeys = indegree.keySet();
        String[] indegArr = indegKeys.toArray(new String[0]);
        for (int i = 0; i < indegArr.length; i++)
        {
            if (indegree.get(indegArr[i]) == 0)
            {
                queue.add(indegArr[i]);
            }
        }
        List<String> order = new ArrayList<>();
        // topological sort
        while (!queue.isEmpty())
        {
            String curr = queue.poll();
            order.add(curr);
            List<String> neighbors = graph.get(curr);
            for (int i = 0; i < neighbors.size(); i++)
            {
                String next = neighbors.get(i);
                indegree.put(next, indegree.get(next) - 1);
                if (indegree.get(next) == 0)
                {
                    queue.add(next);
                }
            }
        }
        return order;
    }
    public static void main(String[] args)
    {
     List<String> courses1 = Arrays.asList("Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases");

     Map<String, List<String>> prereqs1 = new HashMap<>();
     prereqs1.put("Data Structures", Arrays.asList("Intro to Programming"));
     prereqs1.put("Advanced Algorithms", Arrays.asList("Data Structures"));
     prereqs1.put("Operating Systems", Arrays.asList("Advanced Algorithms"));
     prereqs1.put("Databases", Arrays.asList("Advanced Algorithms"));

     System.out.println(findCourseOrder(courses1, prereqs1));

     List<String> courses2 = Arrays.asList("Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays");

     Map<String, List<String>> prereqs2 = new HashMap<>();
     prereqs2.put("Contemporary Literature", Arrays.asList("Intro to Writing"));
     prereqs2.put("Ancient Literature", Arrays.asList("Intro to Writing"));
     prereqs2.put("Comparative Literature", Arrays.asList("Intro to Writing", "Ancient Literature"));
     prereqs2.put("Plays & Screenplays", Arrays.asList("Intro to Writing"));

     System.out.println(findCourseOrder(courses2, prereqs2));
    }
}