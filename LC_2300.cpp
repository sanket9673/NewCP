class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res ;
        int n = spells.size(), m = potions.size() ;
        // dont sort spells as the INDEX WILL BE CHANGED --> WRONG ANSWER
        sort(potions.begin(), potions.end()) ;
        for (int i = 0; i < n; i++) {
            int k = 0 ;
            // binary search
            long long need = (success + spells[i] - 1) / spells[i];
            int l = 0, r = m - 1, ans = m ; // make the ans = m so that if not exist we get 0
            while (l <= r) {
                // we need : spell * potion >= success
                // potion >= ceil(success / spell)
                // dont use CEIL : it causes error
                int mid = l + (r - l) / 2 ;
                if (potions[mid] >= need) {
                    ans = mid ;
                    r = mid - 1;
                }
                else l = mid + 1 ;
            }
            res.push_back(m - ans) ;
        }
        return res ;
    }
};