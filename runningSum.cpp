    vector<int> runningSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> runningSum;
        
        int currSum = 0;
        for(int i = 0;i<n;i++)
        {
            currSum+=nums[i];
            runningSum.push_back(currSum);
        }
        return runningSum;
    }
