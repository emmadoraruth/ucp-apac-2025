//Question 10: PrerequisiteCourses
//Given a list of courses that a student needs to take to complete their major and a map of courses to
// their prerequisites, return a valid order for them to take their courses assuming they only take one 
//course for their major at once.

// Examples: 
// Input: ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"], { "Data 
// Structures": ["Intro to Programming"], "Advanced Algorithms": ["Data Structures"], "Operating Systems": ["Advanced 
// Algorithms"], "Databases": ["Advanced Algorithms"] } 
// Output: ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"] or  
// ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Databases", "Operating Systems"] 
 
// Input: ["Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & 
// Screenplays"], { "Contemporary Literature": ["Intro to Writing"], "Ancient Literature": ["Intro to Writing"], "Comparative 
// Literature": ["Ancient Literature", "Contemporary Literature"], "Plays & Screenplays": ["Intro to Writing"] } 
// Output: ["Intro to Writing", "Plays & Screenplays", "Contemporary Literature", "Ancient Literature", "Comparative 
// Literature"] or 
// ["Intro to Writing", "Contemporary Literature", "Plays & Screenplays", "Ancient Literature", "Comparative Literature"] or 
// ["Intro to Writing", "Contemporary Literature", "Ancient Literature", "Plays & Screenplays", "Comparative Literature"] or  
// ["Intro to Writing", "Ancient Literature", "Contemporary Literature",  "Plays & Screenplays", "Comparative Literature"] or  
// ["Intro to Writing", "Ancient Literature",  "Plays & Screenplays",  "Contemporary Literature", "Comparative Literature"] or 
// ["Intro to Writing", "Plays & Screenplays", "Ancient Literature",  "Contemporary Literature", "Comparative Literature"] or  
// ["Intro to Writing", "Ancient Literature",  "Contemporary Literature", "Comparative Literature", "Plays & Screenplays"] or  
// ["Intro to Writing", "Contemporary Literature",  "Ancient Literature", "Comparative Literature", "Plays & Screenplays"] 

#include<bits/stdc++.h>
std::vector<std::string> findOrder(std::vector<std::string>& subjects,std::vector<std::pair<std::string,std::string>>& edges){
    std::unordered_map<std::string,std::vector<std::string>> adj;
    std::unordered_map<std::string, int> indegree;
    for(auto& sub:subjects){
        adj[sub]={};
        indegree[sub]=0;
    }
    for(auto& edge:edges){
        std::string course = edge.first;
        std::string prereq = edge.second;

        adj[prereq].push_back(course);
        indegree[course]++;
    }

    //we can use the topological sort as then only we can get the correct order of course
    //so we have two methods as courses are Directed Acyclic Graph(DAG).

    //one->dfs
    //another one->bfs by khan's algorithm
    //here i am doing khan's algo
    std::queue<std::string> q;
    for(auto& i:indegree){
           if(i.second==0){
            q.push(i.first);
           }
    }
    std::vector<std::string> ans;
    while(!q.empty()){
        std::string front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto& neigh:adj[front]){
            indegree[neigh]--;
            if(indegree[neigh]==0) q.push(neigh);
        }
    }
    return ans;
    
}
int main(){
    std::vector<std::string> subjects={"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};
    std::vector<std::pair<std::string,std::string>> edges={ {"Data Structures","Intro to Programming"}, {"Advanced Algorithms","Data Structures"}, {"Operating Systems","Advanced Algorithms"}, {"Databases","Advanced Algorithms"}};
    std::vector<std::string> orderOfCourse=findOrder(subjects,edges);
    for(auto& i:orderOfCourse){
        std::cout<<i<<" , ";
    }
    std::cout<<std::endl;
}