class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n+1][n+1];
        
        //traverse through the diagonals
        int count =0;
        for( int g=0 ; g<n; g++){
            //j = g  just to make a new diagonal with shift of g 
            for( int i=0, j = g; j<n; j++, i++){
                
                if( g==0){
                    //only one element exists and one element is always a palindrome
                    dp[i][j] = true;
                }
                else if( g==1){
                    //when there are only two character in the substring
                    dp[i][j] = s[i]==s[j];
                }
                else{
                    if( s[i]== s[j] &&  dp[i+1][j-1] == true){
                        // to be a palindrome it is necessary that the extremes of the string are equal and the part of string between the string are also palindrome
                        dp[i][j] = true;
                    }
                    else dp[i][j] = false;
                }
                if( dp[i][j]== true){
                    count++;
                }
            }
        }
        return count;
    }
};