class Solution {
public:
    bool isPalindrome(string s) {
        
        string s_cpy;
        for(int i=0;i<s.size();i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z') 
                s_cpy.push_back(s[i] + 'a' - 'A');
            else if (s[i] >= 'a' && s[i] <= 'z')
                s_cpy.push_back(s[i]);
            else if (s[i] >= '0' && s[i] <= '9')
                s_cpy.push_back(s[i]);
        }
        for(int i=0;i<s_cpy.size()/2;i++)
        {
            if (s_cpy[i] != s_cpy[s_cpy.size() - i - 1])
                return false;
        }
        return true;
    }
};