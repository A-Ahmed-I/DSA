class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int count = 0;

        int size = nums.size();

        sort(nums.begin(), nums.end());

        int diff = (nums[size - 1] * nums[size - 2]) - (nums[0] * nums[1]);

        return diff;
    }
};