#include<bits/stdc++.h>
using namespace std;
// maximal rectangle 
// idea just try to use largest rectantle in histogram 
// for every row 
int largestSqureArea_optimal(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int ele = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int width = nse-pse-1;
            // if(heights[ele] == width){
            //     int area = heights[ele] * (nse - pse - 1);
            //     maxArea = max(maxArea, area);
            // }   worong thinking 

            // jsut pick smaller side
            int side = min(heights[ele], width);
            int area = side * side;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        int width = nse-pse-1;
        if(heights[ele] == width){
            int area = heights[ele] * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }  
    }

    return maxArea;
    // TC = O(n) + O(n)
    // SC = O(n)
}

vector<int> modifiedRow(vector<vector<char>>& matrix,int i,vector<int> prev){
    int m = matrix[0].size();
    vector<int> temp(m);

    for(int j = 0; j < m; j++){
        if(matrix[i][j] == '1'){
            temp[j] = prev[j] + 1;
        } else {
            temp[j] = 0;
        }
    }
    return temp;
    // TC = O(m)
    // SC = O(m) for ans
}

int maximalRectangle(vector<vector<char>>& matrix){
    int n = matrix.size(); // row
    int m = matrix[0].size(); // column
    vector<int> prev;
    for(int j=0;j<m;j++){
        prev.push_back(matrix[0][j]-'0');
    }
    int maxArea = largestSqureArea_optimal(prev);
    for(int i=1;i<n;i++){
        prev = modifiedRow(matrix,i,prev);
        int areaMaxRow = largestSqureArea_optimal(prev);
        maxArea = max(maxArea,areaMaxRow);
    }

    return maxArea;
    // Time: O(n × m)
    // Space: O(m)
}


int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    // Print matrix (optional)
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Max Area : " << maximalRectangle(matrix);

    return 0;
}