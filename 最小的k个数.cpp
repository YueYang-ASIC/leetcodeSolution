/*输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。*/

//法1。快排std::sort。O(nlogn)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if(input.size()<k)
            return ret;
        std::sort(input.begin(),input.end());
        for(auto i=input.begin();i-input.begin()<k;i++)
        {
            ret.push_back(*i);
        }
        return ret;
    }
};