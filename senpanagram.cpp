class Solution {
public:
    bool checkIfPangram(string sen) {
        set<int> st;
        for(char ch='a';ch<='z';ch++)
            st.insert(ch);
        for(int i=0;i<sen.length();++i)
        {
            if(st.find(sen[i])!=st.end())
                st.erase(sen[i]);
        }
        return st.size()==0;
    }
};
