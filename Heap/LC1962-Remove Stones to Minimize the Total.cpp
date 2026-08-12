//Time Complexity--O(n+ klogn)
//Space Complexity-- O(n)

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n= piles.size();
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
            sum+=piles[i];
        }

        for(int i=0;i<k;i++){
            int max_element=pq.top();
            pq.pop();
            int remove= max_element/2;
            sum-=remove;
            max_element-=remove;
            pq.push(max_element);

        }
        return sum;
        
    }
};
