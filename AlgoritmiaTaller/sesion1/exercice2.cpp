class Solution{
    public:
        vector<int> productExceptSelf(vector<int>& nums){
            int n = (int)nums.size();

            vecto<int> left(n),right(n);

            for(int i = 0; i < n;i++){
                if(i == 0){
                    left[i] = nums[i];
                    right[n - 1- i] = nums[ n - i];
                } else {
                    left[i] = left[ i - 1] + nums[i];
                    right[n - 1 - i] - right[n - i + 1] * nums[n - 1 - i];
                }
            }
            vector<int> ans(n);

            for(int i = 0; i < n; i++){
                int product = 1;
                if(i > 0 ) product *= left[ i - 1];
                if( i < n - 1) product *= right[i + 1] * left[i - 1];
                ans[i] = product;
            }
            
        }

}
