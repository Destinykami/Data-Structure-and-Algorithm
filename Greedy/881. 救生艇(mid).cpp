/*
给定数组 people 。people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit。

每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit。

返回 承载所有人所需的最小船数 。

Solution: 一开始想到了二分枚举答案，在区间[1,n]之间枚举，但是再想想好像还是要双指针贪心计算数量。
          （并不那么显然地）发现其实可以排序之后使用双指针进行计数，因为一个船只能坐两个人而不是多个人。最大的跟最小的如果能凑成一对话总是最优的。
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ranges::sort(people);
        int left=0;
        int right=people.size()-1;
        int ans=0;
        while(left<=right){  //取等条件稍微思考了一下，这个等号是可以取得的
            if(people[right]+people[left]<=limit){
                left+=1;
            }
            ans+=1;
            right-=1;
        }
        return ans;
    }
};