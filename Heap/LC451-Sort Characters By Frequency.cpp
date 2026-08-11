//Time Complexity-- O(n+ klogk)
//Space Complexity== O(n+k)

class Solution {
public:
    typedef pair<char,int>P;

    struct lambda{
        bool operator()(P &p1, P&p2){
            return p1.second<p2.second; //top me maximum frequecy wali entry hogi   (max heap)
        }
    };

    string frequencySort(string s) {

        priority_queue<P,vector<P>,lambda>pq;

        unordered_map<char,int>mpp;

        for(auto ch:s){
            mpp[ch]++;
        }
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }

        string res="";

        while(!pq.empty()){
            P temp= pq.top();
            pq.pop();

            res+=string(temp.second,temp.first);
        }
        return res;
        
    }
};
