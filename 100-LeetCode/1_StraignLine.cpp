#include<bits/stdc++.h>
using namespace std;



// straight line -- slope concept
bool checkStraightLine(vector<vector<int>>& coordinates) {
    // Slope Concept
    int dy = coordinates[1][1] - coordinates[0][1];
    int dx = coordinates[1][0] - coordinates[0][0];

    for(int i = 2;i<coordinates.size();i++){
        int delY = coordinates[i][1] - coordinates[i-1][1];
        int delX = coordinates[i][0] - coordinates[i-1][0];

        if(delY*dx != delX*dy) return false;
    }

    return true; 
    // conclusion -- i get division errors so  i used multiplication instead
    // TC = O(n)
    // SC = O(1)
}

int main(){
    
    return 0;
}