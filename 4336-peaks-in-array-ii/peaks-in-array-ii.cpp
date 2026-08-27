class Solution {
public:
    int n;
    vector<int> isNotPeek;
    vector<int> num;
    vector<long long> seg;
    vector<long long> start;
    vector<long long> end;

    using T = tuple<long long, long long, long long, long long>;

    long long helper(long long n){
        return (n * (n + 1)) / 2;
    }

    void update(int node,int low,int high){
        if(low > high) return;

        if(low == high){
            seg[node] = 1;
            start[node] = 1;
            end[node] = 1;
            return;
        }

        int mid = (low + high) / 2;

        update(2 * node + 1,low,mid);
        update(2 * node + 2,mid + 1,high);

        start[node] = start[2 * node + 1] + start[2 * node + 2];
        end[node] = end[2 * node + 1] + end[2 * node + 2];

        seg[node] = helper(start[node]);
    }

    void updateByIndex(int node,int low,int high,int index){
        if(low > high) return;
        if(low > index || high < index) return;

        if(low == high){
            seg[node] = isNotPeek[index];
            start[node] = isNotPeek[index];
            end[node] = isNotPeek[index];
            return;
        }

        int mid = (low + high) / 2;

        if(index <= mid)
            updateByIndex(2 * node + 1,low,mid,index);
        else
            updateByIndex(2 * node + 2,mid + 1,high,index);

        long long gap1 = mid - low + 1;
        long long gap2 = high - mid;

        start[node] =
            start[2 * node + 1] +
            ((start[2 * node + 1] == gap1) ?
             start[2 * node + 2] : 0);

        end[node] =
            end[2 * node + 2] +
            ((end[2 * node + 2] == gap2) ?
             end[2 * node + 1] : 0);

        seg[node] =
            seg[2 * node + 1] +
            seg[2 * node + 2] -
            helper(end[2 * node + 1]) -
            helper(start[2 * node + 2]) +
            helper(end[2 * node + 1] + start[2 * node + 2]);
    }

    void check(int index){
        if(index < 0 || index >= n) return;

        if(index == 0 || index == n - 1){
            isNotPeek[index] = 1;
            return;
        }

        int prev = isNotPeek[index];

        isNotPeek[index] =
            !(num[index] > num[index - 1] &&
              num[index] > num[index + 1]);

        if(prev != isNotPeek[index]){
            updateByIndex(0,0,n - 1,index);
        }
    }

    T getSum(int node,int low,int high,int l,int r){

        if(low > r || high < l)
            return {0,0,0,0};

        if(l <= low && high <= r){
            return {
                seg[node],
                start[node],
                end[node],
                high - low + 1
            };
        }

        int mid = (low + high) / 2;

        T left =
            getSum(2 * node + 1,low,mid,l,r);

        T right =
            getSum(2 * node + 2,mid + 1,high,l,r);

        long long leftLen = get<3>(left);
        long long rightLen = get<3>(right);

        if(leftLen == 0)
            return right;

        if(rightLen == 0)
            return left;

        long long leftSum = get<0>(left);
        long long leftStart = get<1>(left);
        long long leftEnd = get<2>(left);

        long long rightSum = get<0>(right);
        long long rightStart = get<1>(right);
        long long rightEnd = get<2>(right);

        long long newStart =
            leftStart +
            ((leftStart == leftLen) ? rightStart : 0);

        long long newEnd =
            rightEnd +
            ((rightEnd == rightLen) ? leftEnd : 0);

        long long newSum =
            leftSum +
            rightSum -
            helper(leftEnd) -
            helper(rightStart) +
            helper(leftEnd + rightStart);

        return {
            newSum,
            newStart,
            newEnd,
            leftLen + rightLen
        };
    }

    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {

        num = nums;
        n = num.size();

        isNotPeek.resize(n,1);

        seg.resize(4 * n,0);
        start.resize(4 * n,0);
        end.resize(4 * n,0);

        update(0,0,n - 1);

        for(int i = 0;i < n;i++){
            check(i);
        }

        vector<long long> res;

        for(auto it : queries){

            if(it[0] == 1){

                int l = it[1];
                int r = it[2];

                int ele = r - l + 1;

                if(ele > 2){

                    long long part1 =
                        helper(1LL * (ele - 2));

                    T temp =
                        getSum(0,0,n - 1,l + 1,r - 1);

                    long long part2 = get<0>(temp);

                    res.push_back(part1 - part2);
                }
                else{
                    res.push_back(0);
                }
            }
            else{

                int index = it[1];
                int newValue = it[2];

                num[index] = newValue;

                check(index - 1);
                check(index);
                check(index + 1);
            }
        }

        return res;
    }
};