class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        /*
        First Approach : 
            Time : O(n + (max - min))
            space : O(n)
        */
        /*
        unordered_set<int> st;
        //find max and min from the vector
        int maximum = *max_element(nums.begin(),nums.end());
        int minimum = *min_element(nums.begin(),nums.end());
        //insert all number in set
        for(auto &num:nums){
            st.insert(num);
        }
        vector<int> ans;
        //iterate from minimum to maximum and search for missing number
        for(int i = minimum;i <= maximum;i++){
            //insert missing number in the answer 
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
        */ 
        
        //find max and min from the vector
        //sort the array
        vector<int> ans;
        //sort the nums array
        sort(nums.begin(),nums.end());
        //iterate nums
        for(int i = 1; i < nums.size();i++){
            //check the difference between two nums , it should be 1 because numbers are consecutive 
            if(nums[i] - nums[i-1] > 1 ){
                // add all missing number in ans vector
                for(int j = nums[i-1] + 1 ; j < nums[i]; j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
}; 