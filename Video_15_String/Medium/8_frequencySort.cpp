#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char,int> freq;
    for(auto& ch : s){
        freq[ch]++;
    }

    priority_queue<pair<int,char>> pq;

    for(auto& p : freq){
        pq.push({p.second,p.first});
    }

    string ans = "";
    int n = s.length();
    while (n)
    {
        while (pq.top().first)
        {
            ans += pq.top().second;
            pq.top().first -=1;
        }-
        
    }
    
    
}

int main()
{

    return 0;
}