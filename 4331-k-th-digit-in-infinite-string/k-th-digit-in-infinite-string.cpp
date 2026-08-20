class Solution {
public:
    long long helper(long long mid){
        /*
        1050

        9 - 1
        90 - 2
        900 - 3

        */
        long long ln = log(mid+0.1)/log(10);
        long long value = 1;
        long long power = 1;
        long long count = 0;
        for(int i=1;i<=ln;i++){
            count += (i*9*value);
            value = 10*value;
        }
        count += (1+ln)*(mid-value+1);
        return count;
    }
    int kthDigit(long long k) {
        if(k==1) return 1; 
        long long low = 1;
        long long high = 1e15;

        while(low<=high){
            long long mid = (low+high)/2;
            long long digits = helper(mid);
            if(digits < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        string number = to_string(low);
        long long before = helper(low-1);
        int index = k - before;
        if(index == number.size()){
            int value = number.back()-'0';
            number.pop_back();
            if(number.size() && ((number.back()-'0')&1)){
                return 9-value;
            }
            return value;
        }
        return number[index-1]-'0';
    }
};