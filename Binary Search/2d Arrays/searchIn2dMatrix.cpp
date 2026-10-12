#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int low = 0 , high = (rows * cols) - 1;

        while(low <= high){
            int mid = (low + high)/2;
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid +1;
            else high = mid -1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    struct TestCase {
        vector<vector<int>> matrix;
        int target;
        bool expected;
    };

    vector<TestCase> tests = {
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false},
        {{{1, 1}}, 2, false},   // the case that failed earlier
        {{{1}}, 1, true},
        {{{1}}, 2, false},
        {{{1}, {3}}, 3, true},
        {{{1, 3}}, 3, true},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 60, true},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 0, false},
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        bool result = sol.searchMatrix(tests[i].matrix, tests[i].target);
        bool ok = (result == tests[i].expected);
        if (ok) passed++;

        cout << "Test " << i + 1 << ": target = " << tests[i].target
             << ", expected = " << (tests[i].expected ? "true" : "false")
             << ", got = " << (result ? "true" : "false")
             << " -> " << (ok ? "PASS" : "FAIL") << endl;
    }

    cout << "\n" << passed << "/" << tests.size() << " tests passed" << endl;
    return 0;
}