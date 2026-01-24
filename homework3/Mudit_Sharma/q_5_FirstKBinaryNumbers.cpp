//Question 5: FirstKBinaryNumbers
//Given a number, k, return an array of the first k binary numbers, represented as strings.

//-------------------------------------------------------------------------------------------------------
//I used the Binary Tree to implement this questions as in binary number 
//each we insert 0 and 1 to get next two numbers
//-------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
//using binary tree

//time complexity  :O(n)
//space complexity :O(n)  in storing the binary numbers
std::vector<std::string> firstKBinaryNumbers(int k) {
    std::vector<std::string> result;
    if (k <= 0) return result;

    std::queue<std::string> q;
    q.push("1");

    for (int i = 0; i < k; i++) {
        std::string curr = q.front();
        q.pop();

        result.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
    }

    return result;
}
int main(){
    int k1=4;
    int k2=7;
    std::vector<std::string> binnos1=firstKBinaryNumbers(k1);
    std::vector<std::string> binnos2=firstKBinaryNumbers(k2);
    for(auto& i:binnos1){
        std::cout<<i<<" , ";
    }
    std::cout<<std::endl;
    for(auto& i:binnos2){
        std::cout<<i<<" , ";
    }
    std::cout<<std::endl;
}
