#include<bits/stdc++.h>
using namespace std;

int alternatingPath(string startNode,string endNode,
                     vector<tuple<string,string,string>>& edges){

    map<string,vector<pair<string,string>>> adjacencyList;
    for(auto edge:edges){
        string fromNode,toNode,edgeColor;
        tie(fromNode,toNode,edgeColor)=edge;
        adjacencyList[fromNode].push_back({toNode,edgeColor});
    }

    queue<pair<string,string>> bfsQueue;
    map<pair<string,string>,int> distanceFromStart;

    bfsQueue.push({startNode,""});
    distanceFromStart[{startNode,""}]=0;

    while(!bfsQueue.empty()){
        auto currentState=bfsQueue.front();
        bfsQueue.pop();

        string currentNode=currentState.first;
        string lastEdgeColor=currentState.second;

        if(currentNode==endNode){
            return distanceFromStart[currentState];
        }

        for(auto next:adjacencyList[currentNode]){
            string nextNode=next.first;
            string nextEdgeColor=next.second;

            if(nextEdgeColor!=lastEdgeColor){
                pair<string,string> nextState={nextNode,nextEdgeColor};
                if(!distanceFromStart.count(nextState)){
                    distanceFromStart[nextState]=distanceFromStart[currentState]+1;
                    bfsQueue.push(nextState);
                }
            }
        }
    }
    return -1;
}

int main(){
    vector<tuple<string,string,string>> edges={
        {"A","B","blue"},
        {"A","C","red"},
        {"B","D","blue"},
        {"B","E","blue"},
        {"C","B","red"},
        {"D","C","blue"},
        {"A","D","red"},
        {"D","E","red"},
        {"E","C","red"}
    };

    cout<<alternatingPath("A","E",edges)<<endl;
    cout<<alternatingPath("E","D",edges)<<endl;

    return 0;
}
