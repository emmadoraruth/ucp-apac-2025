#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("Q10_input.txt");
    ofstream out("Q10_output.txt");
    
    int n;
    in>>n;
    in.ignore();
    
    vector<string>courses(n);
    for(int i=0;i<n;i++){
        getline(in,courses[i]);
    }
    
    map<string,vector<string>>prereq;
    map<string,int>indeg;
    
    for(auto c:courses){
        indeg[c]=0;
    }
    
    int m;
    in>>m;
    in.ignore();
    
    for(int i=0;i<m;i++){
        string line;
        getline(in,line);
        int colonPos=line.find(':');
        string course=line.substr(0,colonPos);
        string prereqs=line.substr(colonPos+2);
        
        stringstream ss(prereqs);
        string prereq_course;
        while(getline(ss,prereq_course,',')){
            size_t start=prereq_course.find_first_not_of(" ");
            size_t end=prereq_course.find_last_not_of(" ");
            prereq_course=prereq_course.substr(start,end-start+1);
            prereq[prereq_course].push_back(course);
            indeg[course]++;
        }
    }
    
    queue<string>q;
    for(auto c:courses){
        if(indeg[c]==0)
            q.push(c);
    }
    
    vector<string>order;
    while(!q.empty()){
        string curr=q.front();
        q.pop();
        order.push_back(curr);
        
        for(auto next:prereq[curr]){
            indeg[next]--;
            if(indeg[next]==0)
                q.push(next);
        }
    }
    
    out<<"[";
    for(int i=0;i<order.size();i++){
        out<<"\""<<order[i]<<"\"";
        if(i<order.size()-1) out<<", ";
    }
    out<<"]"<<endl;
    
    in.close();
    out.close();
    return 0;
}
