/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (51.78%)
 * Total Accepted:    2.3K
 * Total Submissions: 4.4K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * 
 * add(value)：向哈希集合中插入一个值。
 * contains(value) ：返回哈希集合中是否存在这个值。
 * remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例:
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // 返回 true
 * hashSet.contains(3);    // 返回 false (未找到)
 * hashSet.add(2);          
 * hashSet.contains(2);    // 返回 true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // 返回  false (已经被删除)
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 所有的值都在 [1, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希集合库。
 * 
 * 
 */ 
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000,vector<int>());
        //二维数组初始化，第一个数是个数，第二个参数是元素类型，vector<int>()表示初始化为0的容器。要加()!!!!
    }
    
    void add(int key) {
        int hashkey=key%1000; 
        if(data[hashkey].empty()) 
        {
            data[hashkey].resize(1000,0); 
        }
         data[hashkey][key/1000]=1;
        //这个赋值操作写在if外部。只做一次哈希值判空！！
    }
    
    void remove(int key) {
        int hashkey=key%1000;  
        if(!data[hashkey].empty())
        {
            data[hashkey][key/1000]=0;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return !data[key%1000].empty()&& (data[key%1000][key/1000]==1);
    }
    
    private: vector<vector<int>> data;
};
 
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
