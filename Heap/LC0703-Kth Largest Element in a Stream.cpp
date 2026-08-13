//Time Complexity--O(n log n + m log k)
//Space Complexity--O(k)
class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>>pq; // min heap banaya
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto& num:nums){
            pq.push(num);
        }
        if(pq.size()>k){
            pq.pop();
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>K){
            pq.pop();
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
