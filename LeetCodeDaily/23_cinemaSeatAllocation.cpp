#include <bits/stdc++.h>
using namespace std;
// 1386. Cinema Seat Allocation
int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
{
    int maxGroups = 2 * n;
    map<int, vector<int>> mpp;
    for (auto &seat : reservedSeats)
    {
        mpp[seat[0]].push_back(seat[1]);
    }

    for (auto &p : mpp)
    {
        int row = p.first;
        bool state1 = false;
        bool state2 = false;
        bool state3 = false;

        for (auto &col : p.second)
        {
            if (col >= 2 && col <= 5)
            {
                state1 = true;
            }
            if (col >= 4 && col <= 7)
            {
                state2 = true;
            }
            if (col >= 6 && col <= 9)
            {
                state3 = true;
            }
        }

        if (state1 && state2 && state3)
        {
            maxGroups -= 2;
        }
        else if ((state1 && state2) || (state2 && state3) || (state1 && state3))
        {
            maxGroups -= 1;
        }
        else if (state1)
        {
            maxGroups -= 1;
        }
        else if (state3)
        {
            maxGroups -= 1;
        }
    }

    return maxGroups;
}
int main()
{
    int n;
    cin >> n;
    int seats;
    cin >> seats;
    vector<vector<int>> reservedSeats(seats);
    for (auto &seat : reservedSeats)
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int ele;
            cin >> ele;
            seat.push_back(ele);
        }
    }

    cout << maxNumberOfFamilies(n,reservedSeats);

    return 0;
}