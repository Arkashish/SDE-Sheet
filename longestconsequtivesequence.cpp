#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> hst;
    for(auto it : arr){
        hst.insert(it);
    }
    int longeststreak=0;
    for(auto num : arr){
        if(!hst.count(num-1)){
            int currentstreak=1;
            int currnum=num;
            while(hst.count(currnum+1)){
                currentstreak++;
                currnum++;
            }
            longeststreak=max(longeststreak,currentstreak);
        }
    }
    return longeststreak;
}