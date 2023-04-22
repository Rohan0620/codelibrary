// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

void generate(int index, int n, vector<int> &A, int target, vector<int> &ds, vector<vector<int>> &ans)
  {
      
          if(target == 0)
            {
                ans.push_back(ds);
                return;
            }
            
      
      
        for(int i=index;i<n;i++)
        {
            if(i>index && A[i] == A[i-1])
              continue;
            if(A[i] > target)
              generate(index+1,n,A,target,ds,ans);
            else
            {
                ds.push_back(A[index]);
                generate(index,n,A,target-A[index],ds,ans);
                ds.pop_back();
            }
        }
  }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        vector<int> ds;
        int n = candidates.size();
       sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        generate(0, n, candidates, target,ds,ans);
        
        return ans;      
    }
