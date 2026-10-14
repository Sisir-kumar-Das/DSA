#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // row with the max value in column mid
            int maxRow = 0;
            for (int i = 1; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) maxRow = i;
            }

            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m)  ? mat[maxRow][mid + 1] : -1;
            int cur   = mat[maxRow][mid];

            if (cur > left && cur > right) return {maxRow, mid};
            else if (left > cur) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};

// checks that mat[r][c] is strictly greater than all 4 neighbors
bool isPeak(vector<vector<int>>& mat, int r, int c) {
    int n = mat.size(), m = mat[0].size();
    int cur = mat[r][c];
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k], nc = c + dc[k];
        int val = (nr >= 0 && nr < n && nc >= 0 && nc < m) ? mat[nr][nc] : -1;
        if (val >= cur) return false;
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the matrix (" << n << " x " << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    Solution sol;
    vector<int> ans = sol.findPeakGrid(mat);

    cout << "Peak at: [" << ans[0] << ", " << ans[1] << "]\n";
    cout << "Value: " << mat[ans[0]][ans[1]] << "\n";
    cout << (isPeak(mat, ans[0], ans[1]) ? "Valid peak" : "NOT a valid peak") << "\n";
    return 0;
}