class Solution {
public:
    int solve( int ind, int amount, vector<int>& coins, vector<vector<int>>& dp ){
        if( amount==0 ){
            return 0;
        }
        if( ind == -1 ){
            return 1e9; // large value
        }

        if( dp[ind][amount] != -1 ){
            return dp[ind][amount];
        }
        //not take
        int nt = solve( ind-1, amount, coins, dp );
        int take = INT_MAX;
        if( coins[ind]<=amount ){
            take = 1 + solve( ind, amount - coins[ind] , coins, dp );
        }
        return dp[ind][amount] = min( take, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp( n, vector<int>(amount+1, -1) );
        int ans = solve( n-1, amount, coins, dp );
        if( ans == 1e9 ){
            return -1;
        }
        return ans;
    }
// };

    // optimal
    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount==0) return 0;
    //     vector<int>dp(amount+1,1e9);
    //     dp[0]=0;
    //     for(int i=coins.size()-1;i>-1;i--){
    //         for(int j=coins[i];j<=amount;j++){
    //             dp[j]=min(dp[j],1+dp[j-coins[i]]);
    //         }
    //     }
    //     return dp[amount]==1e9?-1:dp[amount];
    // }



};