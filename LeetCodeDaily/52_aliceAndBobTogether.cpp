#include<bits/stdc++.h>
using namespace std;
// LC : 2409. Count Days Spent Together
int dayNumber(string date){
    vector<int> months = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    int month = stoi(date.substr(0,2));
    int day = stoi(date.substr(3,2));

    int total = day;
    for(int i=0;i<month-1;i++){
        total += months[i];
    }

    return total;
}
int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
    int start = max(dayNumber(arriveAlice),dayNumber(arriveBob));
    int end = min(dayNumber(leaveAlice),dayNumber(leaveBob));
    return max(0,end-start+1);
    // TC = O(1)
    // SC = O(1)
}

int main(){
    string arriveAlice;
    cin >> arriveAlice;

    string leaveAlice;
    cin >> leaveAlice;

    string arriveBob;
    cin >> arriveBob;

    string leaveBob;
    cin >> leaveBob;

    cout << countDaysTogether(arriveAlice,leaveAlice,arriveBob,leaveBob);
    return 0;
}