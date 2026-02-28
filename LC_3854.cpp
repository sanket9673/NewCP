class Solution {
public:
    int solve(vector<int> nums, vector<int>& cons) {
        vector<int> nums1(nums.begin(), nums.end()) ;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        double diff = (mx - mn) / 2.0;
        double range = mn + diff;

        for (int i = 0; i < nums.size(); i++) {
            int parity = (nums[i] % 2 + 2) % 2 ;
            if (parity != cons[i]) {
                if ((double)nums[i] >= range)
                    nums[i]--;
                else
                    nums[i]++;
            }
        }

        mn = *min_element(nums.begin(), nums.end());
        mx = *max_element(nums.begin(), nums.end());
        int ans = mx - mn ;

        for (int i = 0; i < nums1.size(); i++) {
            int parity = (nums1[i] % 2 + 2) % 2 ;
            if (parity != cons[i]) {
                if ((double)nums1[i] > range)
                    nums1[i]--;
                else
                    nums1[i]++;
            }
        }
        mn = *min_element(nums1.begin(), nums1.end());
        mx = *max_element(nums1.begin(), nums1.end());
        ans = min(ans, mx - mn) ;
        return ans;
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0, 0};

        vector<int> arr;
        for (int x : nums) {
            int parity = (x % 2 + 2) % 2 ;
            arr.push_back(parity);
        }

        int pat1 = 0, pat2 = 0;
        vector<int> smp1, smp2;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                smp1.push_back(0);
                smp2.push_back(1);
            } else {
                smp1.push_back(1);
                smp2.push_back(0);
            }

            if (arr[i] != smp1[i]) pat1++;
            if (arr[i] != smp2[i]) pat2++;
        }

        int a = solve(nums, smp1);
        int b = solve(nums, smp2);

        if (pat1 == pat2)
            return {pat1, min(a, b)};
        else if (pat1 > pat2)
            return {pat2, b};
        else
            return {pat1, a};
    }
};