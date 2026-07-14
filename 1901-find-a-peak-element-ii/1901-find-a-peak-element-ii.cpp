class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = 0;
            for (int i = 1; i < m; i++)
                if (mat[i][mid] > mat[row][mid]) row = i;

            if ((mid == 0 || mat[row][mid] > mat[row][mid - 1]) &&
                (mid == n - 1 || mat[row][mid] > mat[row][mid + 1]))
                return {row, mid};

            if (mid > 0 && mat[row][mid - 1] > mat[row][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {};
    }
};