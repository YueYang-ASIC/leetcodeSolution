/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (35.70%)
 * Total Accepted:    24.1K
 * Total Submissions: 65.8K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
//无序关联式容器，哈希表，计数。unordered_map<char,pair<int,int>>
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;//key:char:字符。value：int；次数,int:index
        int index =s.size();
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].first++;//value.first:出现次数++
            m[s[i]].second=i;//value.sencon:字符出现的索引更新为最新
        }

        for(auto const &it : m)
        {
            if(it.second.first==1)//这里不能忘记写second啊，只有second才说明是value！
            {
                index=min(index,it.second.second);//这里一定要写min(index,curindex)，否则会返回最后一次的index,而不是第一次出现的！！
            }
        }
        return index==s.size()?-1:index;
    }
};

