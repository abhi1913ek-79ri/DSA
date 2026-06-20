#include <bits/stdc++.h>
using namespace std;



int bitCount(int n){
    int cnt = 0;
    while (n > 0)
    {
        if(n%2==1) cnt++;
        n/=2;
    }
    return cnt;
}
vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> ans;
    for (int h = 0; h < 12; h++)
    {
        for (int m = 0; m < 60 ; m++)
        {
            if(bitCount(h)+bitCount(m)==turnedOn){
                string hour = to_string(h);
                string minute =(m < 10) ? "0" + to_string(m) : to_string(m);
                ans.push_back(hour + ":"+ minute);
            }
        }
        
    }

    return ans;
}



void printArray(vector<string> arr){
    cout << "[";
    for (auto i = 0; i < arr.size(); i++)
    {
        for(auto ch : arr[i]){
            cout << ch;
        }
        cout <<",";
    }
    cout << "]";
    cout <<endl;
    
}


int main()
{
    int turnedOn = 1;
    vector<string> ans = readBinaryWatch(turnedOn);
    cout << "turnedOn :" << turnedOn <<endl;
    cout << "All Possible Times : ";
    printArray(ans);
    return 0;
}