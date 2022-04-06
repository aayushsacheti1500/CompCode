// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
// As the answer can be very large, return it modulo 109 + 7.
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        long long answer = 0;
        long long mod = 1e9 + 7;
        for(int i=0; i<n-2; i++){
            int mid = arr[i];
            int l = i+1, r = n-1;
            while(l<r){
                int start = arr[l], end = arr[r];
                int sum = start + mid + end;
                if(sum==target){
                    int count1 = 1, count2 = 1;
                    while(l<r && arr[l+1]==start){
                        l++;
                        count1++;
                    }
                    while(l<r && arr[r-1]==end){
                        r--;
                        count2++;
                    }
                    if(r==l) answer = (answer + (count1*(count1-1)/2)%mod)%mod;
                    else answer = (answer + (count1*count2)%mod)%mod;
                    l++;
                    r--;
                }
                else{
                    if(sum>target) r--;
                    else l++;
                }
            }
        }
        return answer;
    }
};


// NOTE: IMPORTANT - If you replace while(l<r && arr[l+1]==start) and while(l<r && arr[r-1]==end) with 
//                                  while(arr[l+1]==start && l<r) and while(arr[r-1]==end && l<r)
// The code will give runtime error. Pretty wierd stuff!!
