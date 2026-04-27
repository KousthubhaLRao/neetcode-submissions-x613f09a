class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int& a : asteroids) {
            while (!stack.empty() && a < 0 && stack.top() > 0) {
                int diff = a + stack.top();
                if (diff < 0) {  //the left-moving asteroid is bigger.
                    stack.pop();
                } else if (diff > 0) {   //the right-moving asteroid is bigger.
                    a = 0;
                } else {
                    a = 0;   //both of equal size
                    stack.pop();
                }
            }
            if (a != 0) {
                stack.push(a);
            }
        }
        
        int sz = stack.size();
        vector<int> res(sz);
        for(int i = sz-1; i >= 0; i--)
        {
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
};