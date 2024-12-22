#include<algorithm>
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            if (s.empty()) return "";

            int start = 0, maxLength = 1;  // Početak i duljina najduljeg palindroma

            for (int i = 0; i < s.size(); ++i) {
                // Provjeravamo palindrom s jednim centrom (neparna duljina)
                expandFromCenter(s, i, i, start, maxLength);
                
                // Provjeravamo palindrom s dva centra (parna duljina)
                expandFromCenter(s, i, i + 1, start, maxLength);
            }

            return s.substr(start, maxLength);  // Vraćamo najdulji palindrom
        }

    private:
        void expandFromCenter(const string& s, int left, int right, int& start, int& maxLength) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentLength = right - left + 1;
                if (currentLength >= maxLength) {
                    start = left;            // Početak najduljeg palindroma
                    maxLength = currentLength;  // Duljina najduljeg palindroma
                }
                --left;
                ++right;
            }
        }
    };


int main(){
    Solution sol;
    cout << sol.longestPalindrome("babad") << '\n' ; 
    
}
