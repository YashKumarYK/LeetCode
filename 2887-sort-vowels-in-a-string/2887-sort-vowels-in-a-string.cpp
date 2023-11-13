class Solution {
public:
    string vowels = "AEIOUaeiou";
    bool isVowel(char ch){
        for(int i=0;i<10;i++){
            if(ch == vowels[i]){
                return true;
            }
        }
        return false;
    }
    string sortVowels(string s) {
        vector<int> ind;
        vector<char> vowels;
        for(int i=0;i<s.size(); i++){
            if(isVowel(s[i])){
                ind.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        for(int i=0;i<vowels.size();i++){
            s[ind[i]] =  vowels[i];
        }
        
        return s;
    }
};

// 1 2 5 7
