class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = L.size();
        int wl = 0;
        if (l > 0) wl = L[0].length();
        int n = S.length();
        vector<int> has(l, 0);
        for (int i = 0; i < n; i += wl) {
            string tomatch = "";
            for (int j = i; j < i + wl; ++j) {
                tomatch += S[j];
            }
            
        }
    }
};
