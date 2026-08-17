//Time complexity=O(nlogn)
//Space Complexity-o(n)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        int cnt=0;
        priority_queue<long long, vector<long long> , greater<long long>>pq;
        for(auto num:nums){
            pq.push(num);

        }
        while(pq.size()>=2 && pq.top()<k){
            long long x= pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();

            pq.push((min(x,y)*2) + max(x,y));
            cnt++;

        }
        return cnt;
        
    }
};
