    //Median of Two Sorted Arrays
    //LeetCode - Hard
    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<cmath>
    using namespace std;

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution {
    public:

        bool is_integer(float k){
            return std::floor(k) == k;
        }

        double findMedianSortedArrays(vector<int>& vec1, vector<int>& vec2) {
            for(auto i : vec2){
                vec1.push_back(i);
                // cout << i << " ";
            }
            sort(vec1.begin(), vec1.end());

            int vel = vec1.size();
            double mid = (double)vel / 2.0; 
            
            if(!is_integer(mid)){
                return vec1[mid];
            }else{
                return (vec1[(mid)] + vec1[(mid)-1])/2.0;
            }
        }
    };  

    

    int main(){
        Solution sol;
        vector<int> vec1 = {1,3,4};
        vector<int> vec2 = {2};
        for(auto i : vec1){
            cout << i << ", ";
        }
        cout << '\n';
        cout << sol.findMedianSortedArrays(vec1, vec2) << endl;
        
    }
