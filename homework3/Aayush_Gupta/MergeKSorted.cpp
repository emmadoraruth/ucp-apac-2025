#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays){
    vector<int> mergedResult;

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > minHeap;

    for(int arrayIndex=0;arrayIndex<arrays.size();arrayIndex++){
        if(arrays[arrayIndex].size()>0){
            minHeap.push({arrays[arrayIndex][0],{arrayIndex,0}});
        }
    }

    while(!minHeap.empty()){
        auto topElement=minHeap.top();
        minHeap.pop();

        int value=topElement.first;
        int arrayIndex=topElement.second.first;
        int elementIndex=topElement.second.second;

        mergedResult.push_back(value);

        if(elementIndex+1 < arrays[arrayIndex].size()){
            minHeap.push({
                arrays[arrayIndex][elementIndex+1],
                {arrayIndex,elementIndex+1}
            });
        }
    }
    return mergedResult;
}

int main(){
    vector<vector<int>> arrays1={
        {1,2,3,4,5},
        {1,3,5,7,9}
    };

    vector<int> result1=mergeKSortedArrays(arrays1);
    for(int x:result1) cout<<x<<" ";
    cout<<endl;

    vector<vector<int>> arrays2={
        {1,4,7,9},
        {2,6,7,10,11,13,15},
        {3,8,12,13,16}
    };

    vector<int> result2=mergeKSortedArrays(arrays2);
    for(int x:result2) cout<<x<<" ";
    cout<<endl;

    return 0;
}
