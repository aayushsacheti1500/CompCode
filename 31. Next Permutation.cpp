// Find the next permutation. Input is an array of integers.
// [0,1,2,5,3,3,0] -> [0,1,3,0,2,3,5]


//LOGIC:
// STEP 1: Find the longest non decreasing sequence from end (5,3,3,0)
// STEP 2: Pivot = index 2; Find the swapping element from end greater than pivot (3 at index 5 > 2 at index 2 ie pivot)
// STEP 3: Swap pivot and swapping element
// STEP 4: Reverse array after pivot
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l,r;
        for(l=n-2; l>=0; l--){
            if(nums[l]<nums[l+1]) break;
        }
        if(l==-1) reverse(nums.begin(),nums.end());
        else{
            for(r=n-1; r>l; r--){
                if(nums[r]>nums[l]) break;
            }
            swap(nums[r],nums[l]);
            reverse(nums.begin()+l+1,nums.end());
        }
    }
};
