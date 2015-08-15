class Solution {
public:
    static int min(int a,int b,int c){
        int t = a<b?a:b;
        return t<c?t:c;
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int dp[len1+1][len2+1] = {0};
        int i = 0, j = 0;
        for(i=0; i<=len1; i++)
            dp[i][0] = i;
        for(i=0; i<=len2; i++)
            dp[0][i] = i;
        for(i=1; i<=len1; i++){
            for(j=1; j<=len2; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
            }
        }
        return dp[len1][len2];
    }
};