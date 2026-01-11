class Solution {
public:
    long long Th;
    map<int, int> d;
    map<int, int> g;
    vector<int> p;
    int fp(int a) {
        if (a == p[a])
            return a;
        return p[a] = fp(p[a]);
    }
    void un(int a, int b) {
        a = fp(a);
        b = fp(b);
        p[b] = a;
    }
    long long gcd(long long a, long long b) {
        if (a % b == 0)
            return b;
        return gcd(b, a % b);
    }
    long long lcm(long long a, long long b) {
        long long hcf = gcd(a, b);
        return (a / hcf) * (b);
    }
    void h(int value, int index) {
        set<int> fact = {1};
        for (int i = 1; i <= sqrt(value); i++) {
            if (value % i == 0) {
                fact.insert(i);
                fact.insert(value / i);
            }
        }
        for (auto it : fact) {
            if (d.find(it) != d.end()) {
                int beforeIndex = d[it];
                int valueBefore = g[beforeIndex];
                int valueNow = g[index];
                if (lcm(valueBefore, valueNow) <= Th) {
                    un(beforeIndex, index);
                }
            } else {
                d[it] = index;
            }
        }
    }
    int C() {
        set<int> st;
        for (int i = 0; i < p.size(); i++) {
            st.insert(fp(i));
        }
        return st.size();
    }
    int countComponents(vector<int>& n, int th) {
        Th = th;
        sort(n.begin(), n.end());
        int a = 0;
        while (n.size()) {
            if (n.back() <= th)
                break;
            n.pop_back();
            a++;
        }
        if (n.size() == 0)
            return a;
        if (n[0] == 1)
            return 1 + a;
        for (int i = 0; i < n.size(); i++) {
            g[i] = n[i];
            p.push_back(i);
        }
        for (int i = 0; i < n.size(); i++) {
            h(n[i], i);
        }
        return a + C();
    }
};