// Technique : Maintain two heaps
// T.C : O(n*logn)
// M.C : O(n)


#include <bits/stdc++.h>
using namespace std;

void runShelter(vector<vector<string>> &initialPets, vector<vector<string>> &events) {
    priority_queue<pair<pair<int, string>, string>, vector<pair<pair<int, string>, string>>> cats, dogs;

    for (int i = 0; i < initialPets.size(); i++) {
        string name = initialPets[i][0];
        string species = initialPets[i][1];
        int time = stoi(initialPets[i][2]);

        pair<pair<int, string>, string> pet = {{time, name}, species};

        if (species == "cat") {
            cats.push(pet);
        } else {
            dogs.push(pet);
        }
    }

    for (int i = 0; i < events.size(); i++) {
        if (events[i][1] == "person") {
            string desiredPet = events[i][2];
            if (desiredPet == "cat") {
                if (!cats.empty()) {
                    auto adopted = cats.top();
                    cats.pop();
                    cout << adopted.first.second << " " << adopted.second << endl;
                }
                else if (!dogs.empty()) {
                    auto adopted = dogs.top();
                    dogs.pop();
                    cout << adopted.first.second << " " << adopted.second << endl;
                }
            }
            else if (desiredPet == "dog") {
                if (!dogs.empty()) {
                    auto adopted = dogs.top();
                    dogs.pop();
                    cout << adopted.first.second << " " << adopted.second << endl;
                }
                else if (!cats.empty()) {
                    auto adopted = cats.top();
                    cats.pop();
                    cout << adopted.first.second << " " << adopted.second << endl;
                }
            }
        }
        else if (events[i][1] == "animal") {
            string name = events[i][0];
            string species = events[i][2];
            int time = stoi(events[i][3]);

            pair<pair<int, string>, string> pet = {{time, name}, species};

            if (species == "cat") {
                cats.push(pet);
            } else {
                dogs.push(pet);
            }

            cout << endl;
        }
    }
}

int main() {

    vector<vector<string>> initialPets = {
        {"Lola", "dog", "1"},
        {"Sadie", "dog", "4"},
        {"Woof", "cat", "7"},
        {"Chirpy", "dog", "2"}
    };

    vector<vector<string>> events = {
        {"Bob", "person", "dog"},
        {"Floofy", "animal", "cat", "0"},
        {"Sally", "person", "cat"},
        {"Ji", "person", "cat"},
        {"Ali", "person", "cat"}
    };

    runShelter(initialPets, events);

    return 0;
}

// Time Taken : 30 mins