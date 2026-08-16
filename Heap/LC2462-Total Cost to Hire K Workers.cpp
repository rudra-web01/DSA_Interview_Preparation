// Time Complexity: O(n log candidates)
// Space Complexity: O(candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n= costs.size();

        long long ans=0;

        priority_queue<int,vector<int>,greater<int>> pq1,pq2;

        int hired=0;

        int i=0,j=n-1;
        while(hired<k){
            while(i<=j && pq1.size()<candidates){
                pq1.push(costs[i]);
                i++;
            }
            while(j>=i && pq2.size()<candidates){
                pq2.push(costs[j]);
                j--;
            }
            int min_pq1= pq1.size()>0? pq1.top():INT_MAX;
            int min_pq2= pq2.size()>0? pq2.top():INT_MAX;

            if(min_pq1<=min_pq2){
                ans+=min_pq1;
                pq1.pop();
            }else{
                ans+=min_pq2;
                pq2.pop();
            }
            hired++;
        }
        return ans;
        
    }
};
