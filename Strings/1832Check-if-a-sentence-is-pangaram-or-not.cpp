class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>v(26,0);
        for(int i=0;i<sentence.size();i++){
            v[sentence[i]-'a']=1;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                return 0;
            }
        }
        return 1;
    }
};
