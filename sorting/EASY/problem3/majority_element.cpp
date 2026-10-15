class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = 0, maxFreq = 0;

        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        for (auto &p : freq)
        {
            if (p.second > maxFreq)
            {
                majority = p.first;
                maxFreq = p.second;
            }
        }

        return majority;
    }
};