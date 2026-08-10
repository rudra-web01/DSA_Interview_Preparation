//Approach (Using vector as a stack)
//T.C : O(n * log(x)), where log comes from GCD
//S.C : O(1)
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; //or you can use a stack

        for(int num : nums) {

            while(!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM;
            }
            result.push_back(num);
        }
        return result;
    }
};
