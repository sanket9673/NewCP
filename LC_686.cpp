class Solution {
public:
    const int d = 31 ; // d : power ----> 2 * d^2 + 1 * d^1 + 0 * d^0
    const int q = 1e9 + 7 ;
    // txt : a &&&& pat : b
    bool rbsearch(string& txt, string& pat) {
        int n = txt.length() ;
        int m = pat.length() ;

        if (m > n) return false ;
        // hash value computation : we are following HORNER'S RULE
        
        // compute : d^m-1 % q : to compute the power to remove first character
        // d * 1 ----- d = d * (d * 1) = d2 ----- d = d * (d * (d * 1) = d3
        long long h = 1 ;
        for (int i = 1; i <= m - 1; i++) h = (h * d) % q ;

        // compute p and t0
        // p : hash value of pattern
        // t : hash value of current window of txt
        long long p = 0, t = 0 ;
        for (int i = 0; i < m; i++) {
            p = (p * d + pat[i]) % q ;
            t = (t * d + txt[i]) % q ;
        }

        // check for spurious hit (hash same but text not same) 
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                bool match = true ;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false ;
                        break ;
                    } // continue checking for rest
                }
                if (match == true) return true ;
            }

            // to check -> to calculate rolling hash calculates next window
            if (i < n - m) {
                // rolling hash
                // Ti+1 = d(Ti - txt[i] * d^m-1) + txt[i + m]
                t = (d * (t - txt[i] * h) + txt[i + m]) % q ;
                // t - txt[i] * h ========= remove first char
                // * d ==================== shift left
                // + txt[i + m] =========== add new char

                // if t went -ve
                if (t < 0) t += q ;
            }
        }
        return false ;
    }
    int repeatedStringMatch(string a, string b) {
        // naive appraoch : 
        // 1. max repeation : ceil(len(b) / len(a)) + 2 ---> 2 extra considering start and  end 
        // offset if the string starts from it 
        // 2. appead to a this repeating and check if b present. o(n * m) 
        
        // RABIN - KARP IDEA : (String Hashing) 
        // if hash(subtsing) == hash(b) 
        // STEPS 
        // 1.Build repeated string 
        // 2.Compute hash of b 
        // 3.Compute rolling hash on repeated string 
        // 4.Compare hashes // Rooling hash (string) formula // hash(i + 1) = {hash(i) - leftchar * power} * base + newchar

        string repeated = a ;
        int count = 1 ;
        while (repeated.size() < b.size()) {
            count++ ;
            repeated += a ;
        }

        if (rbsearch(repeated, b)) return count ;

        // for the boundary cases
        count++ ;
        repeated += a ;
        if (rbsearch(repeated, b)) return count ;
        return -1 ;
    }
};