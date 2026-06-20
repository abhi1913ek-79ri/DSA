#include<bits/stdc++.h>
using namespace std;

//Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing 
// a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction.
// If you cannot achieve any profit, return 0.

// Example 1:
// Input:
//  prices = [7,1,5,3,6,4]
// Output:
//  5
// Explanation:
//  Buy on day 2 (price = 1) and 
// sell on day 5 (price = 6), profit = 6-1 = 5.

// Note
// : That buying on day 2 and selling on day 1 
// is not allowed because you must buy before 
// you sell.

pair<pair<int,int>,int> maxProfitBrute(vector<int>& arr){
    pair<pair<int,int>,int> ans;
    int BuyPrice=0;int SellPrice=0;
    int n=arr.size();int profit=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j>i){
                int cost=arr[j]-arr[i];
                if(profit<cost){
                    profit=cost;
                    BuyPrice=arr[i];
                    SellPrice=arr[j];
                }
            }
        }
    }
    ans.first.first=BuyPrice;
    ans.first.second=SellPrice;
    ans.second=profit;
    return ans;

    // TC = O(N*N)
}
pair<pair<int,int>,int> maxProfitOptimal(vector<int>& arr){
    // Using DP concept 
    pair<pair<int,int>,int> ans;
    int MinBuyPrice=arr[0];int maxSellPrice=0;
    int n=arr.size();int profit=0;
    for(int i=1;i<n;i++){
        // cost = sellPrice - minBuyPrice
        int cost=arr[i]-MinBuyPrice;
        if(profit<cost){
            profit=cost;
            maxSellPrice=arr[i];
        }
        MinBuyPrice=min(MinBuyPrice,arr[i]);
    }
    ans.first.first=MinBuyPrice;
    ans.first.second=maxSellPrice;
    ans.second=profit;
    return ans;
    // TC = O(N)

}

void printArray(vector<int>& arr){
    for(auto num: arr) cout<<num << " ";
    cout<<endl;
}
int main(){
    vector<int> price ={7,1,5,3,6,4};
    pair<pair<int,int>,int> ans = maxProfitOptimal(price);
    cout<<"Price : ";printArray(price);
    cout<<"Buy price : "<<ans.first.first<<" , Sell price : "<<ans.first.second<<" Max Profit : "<<ans.second<<endl;
    return 0;
}