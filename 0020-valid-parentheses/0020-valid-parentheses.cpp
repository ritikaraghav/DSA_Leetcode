class Solution {
public:
    bool isValid(string s) {
        stack<char>q;
        if(s.size()%2 != 0)return false;
        
        else
        {
            for(char str : s){
                if(str == '{')q.push('}');
                else if(str == '[')q.push(']');
                else if (str == '(' )q.push(')');
                else{
                    if(q.empty() || q.top() != str)return false;
                    q.pop();
                }
            }
        }
        return q.empty();
    }
};