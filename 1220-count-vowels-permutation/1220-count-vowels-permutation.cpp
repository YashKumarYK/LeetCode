class Solution {
public:
    /*
0 -> 1;
1 -> 0, 2;
2->0,1,3,4
3->2,4
4->0
*/ 
    int dp[20001][7];
    int m = 1e9+7;
    bool possible( int prev , int curr){
        if( prev== 0) return true;
        if( prev ==1 && curr==2) return true;
        if( prev==2 && (curr==1||curr==3)) return true;
        if( prev==3 && (curr==1||curr==2||curr==4||curr==5)) return true;
        if( prev==4 && (curr==3 ||curr==5)) return true;
        if( prev==5 && (curr==1)) return true;
        return false;
    }
    int solve( int n, int prev){
        if( n == 0) return 1;
        if(dp[n][prev]!= -1) return dp[n][prev];
        int count=0;
        for( int i=1; i<=5; i++){
            if(possible(prev, i))
                count = (count%m +solve( n-1, i)%m)%m;
        }
        return dp[n][prev] = count%m;
    }
    
    int countVowelPermutation(int n) {
        memset(dp, -1,sizeof(dp));
        return solve( n, 0);
    }
};

