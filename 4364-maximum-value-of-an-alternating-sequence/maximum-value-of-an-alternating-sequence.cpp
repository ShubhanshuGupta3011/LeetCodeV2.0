class Solution {
public:
    using ll = long long;
    long long maximumValue(int n, int s, int m) {
        if (n < 3) return s + (n - 1) * m;
        if (m == 1) return 1 + s;
        ll start1 = s;
        ll start2 = s+m;
        ll half1 = (n/2) + (n&1) - 1;
        ll half2 = (n/2) - 1;
        ll diff = m-1;
        // cout<<" start1 = "<<start1<<endl;
        // cout<<" start2 = "<<start2<<endl;
        // cout<<" half1 = "<<half1<<endl;
        // cout<<" half2 = "<<half2<<endl;
        // cout<<" diff = "<<diff<<endl;
        return max(start1 + half1 * diff, start2 + half2 * diff);

        /*

        s s+m s+m-1

        n=6 s=5 m=6

        3 8 7 12



        */
    }
};