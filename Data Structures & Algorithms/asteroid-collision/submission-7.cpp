class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        int n = asteroids.size();

        //stack.push(asteroids[0]);

        for(int i = 0; i < n; i++)
        {
            //bool flag = false;
            if(asteroids[i] >= 0)
            {
                stack.push(asteroids[i]);
                //flag = true;
                continue;
            }
            bool destroyed = false;
            while (!stack.empty() && asteroids[i] < 0 && stack.top() > 0) {
                if (abs(stack.top()) < abs(asteroids[i])) {
                    stack.pop();
                    continue; // Keep checking the next top
                } else if (abs(stack.top()) == abs(asteroids[i])) {
                    stack.pop();
                }
                destroyed = true; // Current asteroid is gone (either tie or top was bigger)
                break;
            }
            if (!destroyed) stack.push(asteroids[i]);
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