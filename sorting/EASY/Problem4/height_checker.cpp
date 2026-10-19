class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int count = 0;

        vector<int> heights_sorted = heights;

        sort(heights_sorted.begin(), heights_sorted.end());

        for (int i = 0; i < heights.size(); i++)
        {
            if (heights_sorted[i] != heights[i])
                count++;
        }

        return count;
    }
};