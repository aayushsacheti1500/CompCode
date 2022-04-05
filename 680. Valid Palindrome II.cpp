// Given a string s, return true if the s can be palindrome after deleting at most one character from it.
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
        //This true for those cases when the string is already a palindrome
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
