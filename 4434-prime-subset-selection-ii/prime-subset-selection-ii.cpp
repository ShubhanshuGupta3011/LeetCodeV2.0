class Solution {
public:
    vector<int> sieve(int n){
        vector<int> prime(n+1,1);
        for(int i=4;i<=n;i+=2){
            prime[i] = 0;
        }
        int rootn = sqrt(n);

        for(int i=3;i<=rootn;i+=2){
            if(!prime[i]) continue;
            for(int j=i*i;j<=n;j+=2*i){
                prime[j] = 0;
            }
        }
        vector<int> ans;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> prime = sieve(n);
        vector<int> cost(1+s,1e9);
        cost[0]=0;
        vector<vector<int>> arr(1+s);

        for(int i=prime.size()-1;i>=0;i--){
            int value = prime[i];
            for(int j=s;j>=0;j--){
                if((j-value)<0) break;
                if(cost[j] >= 1 + cost[j-value]){
                    cost[j] = 1 + cost[j-value];
                    arr[j] = arr[j-value];
                    arr[j].push_back(value);
                }
            }
        }

        while(arr.size() != 1){
            if(arr.back().size()){
                break;
            }
            arr.pop_back();
        }
        reverse(arr.back().begin(),arr.back().end());
        return arr.back();
    }
};