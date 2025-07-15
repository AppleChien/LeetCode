class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;

        bool hasvowel=false,hasconsonant=false;
        bool vs[26]{};
        string vowel="aeiou";
        for(char v:vowel)vs[v-'a']=true;

        for(char c:word){
            if(isalpha(c)){
                if(vs[tolower(c)-'a'])hasvowel=true;
                else hasconsonant=true;
            }
            else if(!isdigit(c))return false;
        }

        return hasvowel&&hasconsonant;
    }
};
