class Solution {
public:
    int longestPalindrome(string s) {
        
        int answer = 0;
        
        vector<int> alp(52, 0);
        for(int i=0;i<s.size();i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                alp[s[i] - 'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z')
                alp[s[i] - 'A' + 26]++;
        }
        bool flag = false;
        for(int i=0;i<52;i++)
        {
            if (alp[i] % 2 == 1) flag = true;
            answer += ((alp[i] / 2) * 2);
        }
        if (flag == true) answer++;
        return answer;
    }
};