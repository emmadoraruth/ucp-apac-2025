// Time Complexity : O(n) , Space Complexity : O(n)




#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int ZeroSum1 (vector<int> arr){
    map<int , int> freq; // A map for recording the frequency of each element in the given array
    int ans = 0;
    
    for(int i : arr){
        if(freq.find(i) != freq.end()){
            freq[i]++;
        }
        else{
            
            freq[i] = 1;
        }
    }
    for(auto& pair : freq){
        if(pair.first > 0){break;}
        else if (pair.first<0){
           if(freq[(pair.first)*(-1)]!=0){
            ans += min(freq[pair.first],freq[(pair.first)*(-1)]);
           }
           else {continue;}

        }
        else if(freq[0] > 1){
            
            ans += freq[0]/2;
        }
            
        
    }
    return ans;
}

// For the follow up question
int ZeroSum2 (vector<int> arr){
    map<int , int> freq; // A map for recording the frequency of each element in the given array
    int ans = 0;
    
    for(int i : arr){
        if(freq.find(i) != freq.end()){
            freq[i]++;
        }
        else{
            
            freq[i] = 1;
        }
    }
    for(auto& pair : freq){
        if(pair.first > 0){break;}
        else if (pair.first<0){
           if(freq[(pair.first)*(-1)]!=0){
            ans += freq[pair.first]*freq[(pair.first)*(-1)];
           }
           else {continue;}

        }
        else if(freq[0] > 1){
            // For the case of the element being a zero, it is being assumed that the same element can not be used with itself
            ans += freq[0]/2;
        }
            
        
    }
    return ans;
}

int main(){
    vector<int> testcase1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
    vector<int> testcase2 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
    vector<int> testcase3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
    vector<int> testcase4 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};

    cout<<"Output of testcase1: "<<ZeroSum1(testcase1)<<" , Follow up: "<<ZeroSum2(testcase1)<<endl;
    cout<<"Output of testcase2: "<<ZeroSum1(testcase2)<<" , Follow up: "<<ZeroSum2(testcase2)<<endl;
    cout<<"Output of testcase3: "<<ZeroSum1(testcase3)<<" , Follow up: "<<ZeroSum2(testcase3)<<endl;
    cout<<"Output of testcase4: "<<ZeroSum1(testcase4)<<" , Follow up: "<<ZeroSum2(testcase4)<<endl;

   
}