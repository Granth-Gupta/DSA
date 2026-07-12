class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int s = 0;
        int e = rows * cols - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return false;
    }
};