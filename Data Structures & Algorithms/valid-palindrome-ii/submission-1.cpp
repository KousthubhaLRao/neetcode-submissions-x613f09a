class Solution {
public:
    bool validPalindrome(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if(s == s1) return true;

        int i = 0, j = s.size() - 1;
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                if(isPal(s, i+1, j) or isPal(s, i, j-1)) return true;
                else return false;
                //return isPal(s,i+1, j) or isPal(s,i, j-1);
            }
            i++;
            j--;
        }
        return false;

    }
    bool isPal(string s, int i, int j) {
        //int i = 0, j = s.size()-1;
        while(i <= j)
        {
            // if(!isalnum(s[i]))
            // {
            //     i++;
            //     continue;
            // }
            // if(!isalnum(s[j]))
            // {
            //     j--;
            //     continue;
            // }
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};