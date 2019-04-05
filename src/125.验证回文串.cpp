/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (37.96%)
 * Total Accepted:    30K
 * Total Submissions: 77.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
//two pointers
class Solution {
public:
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1 ;
    while (right<s.size()&&left < right) {
        while (left<s.size()&&!isalnum(s[left])) ++left;
        while (right<s.size()&&!isalnum(s[right])) --right;
        if (left<s.size()&&right<s.size()&&(s[left++] + 32 - 'a') %32 != (s[right--] + 32 - 'a') % 32) return false;
    }
    return true;
}
};

