// Technique - QUEUE
// TIME COMPLEXITY - O(Klog K + E)
// SPACE COMPLEXITY - O(K + E)

package homework4.Satyam_Mishra;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class Q9_AdoptAPet {

    public static void main(String[] args) {
        Queue<String> dogs = new ArrayDeque<>();
        Queue<String> cats = new ArrayDeque<>();

        String[][] initialPets = {
            {"Lola", "dog", "1"},
            {"Sadie", "dog", "4"},
            {"Woof", "cat", "7"},
            {"Chirpy", "dog", "2"}
        };

        Arrays.sort(initialPets, (a, b) -> Integer.parseInt(b[2]) - Integer.parseInt(a[2]));

        for (String[] pet : initialPets) {
            if (pet[1].equals("dog")) dogs.add(pet[0]);
            else if (pet[1].equals("cat")) cats.add(pet[0]);
        }

        String[][] events = {
            {"Bob", "person", "dog"},
            {"Floofy", "cat"},
            {"Sally", "person", "cat"},
            {"Ji", "person", "cat"},
            {"Ali", "person", "cat"}
        };

        for (String[] event : events) {
            if (event.length == 3) {
                String species = event[2];
                if(species.equals("dog")) {
                    if(!dogs.isEmpty()) {
                        System.out.println(dogs.poll() + ", dog");
                    } else {
                        System.out.println(cats.poll() + ", cat");
                    }
                } else {
                    if(!cats.isEmpty()) {
                        System.out.println(cats.poll() + ", cat");
                    } else {
                        System.out.println(dogs.poll() + ", dog");
                    }
                }
                
            } else if (event.length == 2) {
                String name = event[0];
                String species = event[1];
                
                if(species.equals("dog")) {
                    dogs.add(name);
                } else {
                    cats.add(name);
                }
            }
        }
    }
}

// time taken - 20m