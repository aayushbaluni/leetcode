class Solution {
    public: vector < int > findPeakGrid(vector < vector < int >> & mat) {
        int n = mat.size(), m = mat[0].size();

        // low = 1st column, high = last column
        int loCol = 0, hiCol = m - 1;

        while (loCol <= hiCol) {
            int midCol = (loCol + hiCol) >> 1;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int currElement = mat[maxRow][midCol];
            int leftElement = (midCol == 0) ? -1 : mat[maxRow][midCol - 1];
            int rightElement = (midCol == m - 1) ? -1 : mat[maxRow][midCol + 1];

            if (currElement > leftElement && currElement > rightElement) {
                return { maxRow, midCol };
            }

            if (currElement < leftElement) {
                hiCol = midCol - 1;
            } else {
                loCol = midCol + 1;
            }
        }
        
        return {-1, -1};
    }
};