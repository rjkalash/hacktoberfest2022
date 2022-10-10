class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> vc(num);
        for(int i=0;i<num;i++)
        {
            vc[i].resize(i+1);
            vc[i][0]=vc[i][i]=1;
            for(int j=1;j<i;j++)
                vc[i][j]=vc[i-1][j-1]+vc[i-1][j];
        }
        return vc;
    }
};
