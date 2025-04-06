#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left =0;
        int temp =0;
        int maxLength = 0;
        int n = s.size();
        unordered_map<char,int> v;
        for (int right = 0; right < s.size(); right++) {
            // Ako je znak već viđen i nalazi se unutar trenutnog prozora
            if (v.count(s[right]) && v[s[right]] >= left) {
                // Pomakni lijevi pokazivač odmah iza zadnje pojave dupliciranog znaka
                left = v[s[right]] + 1;
            }

            // Ažuriraj poziciju trenutnog znaka
            v[s[right]] = right;

            // Ažuriraj maksimalnu duljinu podstringa
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};


int main(){
    string s = "pwwkew";
    string temp = "";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
}