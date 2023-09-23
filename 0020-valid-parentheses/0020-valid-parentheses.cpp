class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for(int i=0;i<s.size();i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                brackets.push(s[i]);
            else
            {
                if (brackets.empty() == false
                    && ((brackets.top() == '(' && s[i] == ')')
                    || (brackets.top() == '{' && s[i] == '}')
                    || (brackets.top() == '[' && s[i] == ']')))
                    brackets.pop();
                else
                    return false;
            }
        }
        if (brackets.empty() == false) return false;
        return true;
    }
};