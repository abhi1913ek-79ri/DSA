#include<bits/stdc++.h>
using namespace std;
// 1331 Rank Transform of an Array : sorting solution
vector<int> arrayRankTransform(vector<int>& arr){
    int n = arr.size();
    map<int,int> mpp;
    for(auto& ele : arr){
        mpp[ele]++;
    }

    // rank <num,rank> conversion
    int r= 1;
    for (auto& p:mpp)
    {
        p.second = r;
        r++;
    }

    vector<int> rank;
    for(auto& ele : arr){
        rank.push_back(mpp[ele]);
    }

    return rank;
    // TC = O(nlogn)
    // SC = O(n)
}

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& ele : arr){
            cin >> ele;
        }

        vector<int> rank = arrayRankTransform(arr);
        bool flg = false;
        for(auto& ele : rank){
            if(flg) cout << " ";
            cout << ele;
            flg = true;
        }
        cout << endl;
    }
    
    return 0;
}