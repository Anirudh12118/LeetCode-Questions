class Solution {
public:
    bool isAlphaNumeric(char ch){
        if(tolower(ch)>='a' && tolower(ch)<='z' || ch>='0' && ch<='9'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int st=0;
        int end=s.length()-1;
        while(st<end){
            if(!isAlphaNumeric(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};