class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto count=[&](int k)->long long{
            long long ans=0;
            int l=0,x=0;
            unordered_map<char,int>cnt;

            auto aeiou=[&](char c)->bool{
                return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
            };

            for(char c:word){
                if(aeiou(c))cnt[c]++;
                else ++x;

                while(x>=k&&cnt.size()==5){
                    char d=word[l++];
                    if(aeiou(d)){
                        if(--cnt[d]==0)cnt.erase(d);     
                    }
                    else --x;
                }
                ans+=l;
            }

            return ans;
        };

        return count(k)-count(k+1);
    }
};
