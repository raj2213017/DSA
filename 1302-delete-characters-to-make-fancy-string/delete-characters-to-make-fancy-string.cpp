class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int count = 1;
        result.push_back(s[0]);

        for(int i=1; i<s.length(); i++){
            if(s[i] == result.back()){
                count++;
                if(count<3){
                   result.push_back(s[i]);
                }
            }
            else{
                result.push_back(s[i]);
                count = 1;
            }
        }
        return result;
    }
};