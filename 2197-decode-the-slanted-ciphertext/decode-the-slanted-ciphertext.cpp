class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int totalSize = encodedText.size();
        int cols = totalSize / rows;

        unordered_map<int,string> umap;
        for(int k=0;k<totalSize;k++){
            int i = k / cols;
            int j = k % cols;
            umap[j-i]+=(encodedText[k]);
        }
        string res = "";
        for(int i=0;i<cols;i++){
            res += umap[i];
        }
        while(res.size() && res.back()==' '){
            res.pop_back();
        }
        return res;
    }
};