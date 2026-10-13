#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;  
    }
};

int main() {
    Solution sol;
    
    // Sample matrix (where elements are sorted row-wise and column-wise)
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Target " << target1 << (sol.searchMatrix(matrix, target1) ? " found!" : " not found.") << endl;
    cout << "Target " << target2 << (sol.searchMatrix(matrix, target2) ? " found!" : " not found.") << endl;

    return 0;
}