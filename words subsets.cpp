class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
    {
       vector<string>ans;
       vector<int>b_requirement(26 , 0);
       for(int i = 0 ; i < B.size(); i++)
       {
           vector<int>tmp1(26 , 0);
           for(int j = 0 ; j < B[i].size(); j++)
           {
               tmp1[B[i][j] - 'a']++;
           }
           for(int k = 0 ; k < 26 ; k++)
           {
               b_requirement[k] = max(b_requirement[k] , tmp1[k]);
           }
       }
       for(int i = 0 ; i < A.size(); i++)
       {
           bool f = true;
           vector<int>tmp2(26 , 0);
           for(int j = 0 ; j < A[i].size(); j++)
           {
               tmp2[A[i][j] - 'a']++;
           }
           for(int k = 0 ; k < 26 ; k++)
           {
               if(tmp2[k] < b_requirement[k])
               {
                   f = false;
                   break;
               }
           }
           if(f == true)
           {
               ans.push_back(A[i]);
           }
       }
        return ans;
    }
};
