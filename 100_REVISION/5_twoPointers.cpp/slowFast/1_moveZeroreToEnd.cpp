#include<bits/stdc++.h>
using namespace std;
// Move Zerores 
void moveBrute(vector<int>& arr){
    int n = arr.size();
    vector<int> aux;
    for(auto& ele : arr){
        if(ele != 0) aux.push_back(ele);
    }

    int i = 0;

    for(auto x : aux){
        arr[i++] = x;
    }

    for(int i = aux.size();i < arr.size();i++){
        arr[i] = 0;
    }
}

void moveZeroEndOptimal(vector<int>& arr){
    int n = arr.size();

    int i = 0;
    int j = 0;

    while(j<n){
        if(arr[j] != 0){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto& num : nums){
        cin >> num;
    }

    moveZeroEndOptimal(nums);
    bool flag = false;
    for(auto& num : nums){
        if(flag) cout << " ";
        cout << num;
        flag = true;
    }
    return 0;
}