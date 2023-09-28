class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> alp(26, 0);
        for(int i=0;i<ransomNote.size();i++)
            alp[ransomNote[i] - 'a']++;
        for(int i=0;i<magazine.size();i++)
            alp[magazine[i] - 'a']--;
        
        for(int i=0;i<26;i++)
        {
            if (alp[i] > 0) return false;
        }
        return true;
    }
};