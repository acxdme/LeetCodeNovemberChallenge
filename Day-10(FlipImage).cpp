/*
Time complexity : O(N*M)
Space complexity : O(1) , no additional space required
My approach :  reverse every row and make the every element Xor with 1 to invert , can be done in one pass this way.
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int  r = A.size();
        if(r ==0 ) return A;
        int  c = A[0].size();
        for(int i =0 ;i<r;i++)
        {
            int start = 0 ,end = c-1;
                 if(start == end )   //  [[0]] , this case.
                     A[i][end] = A[i][end] ^1;
            
             while(start < end)
             {
               swap(A[i][start],A[i][end]);
               if(start < end)
                {
                    A[i][start]= A[i][start] ^ 1;
                    A[i][end] = A[i][end] ^1; 
                }
 
                 start++;
                 end--;
                 
                 if(start == end )  // xor of the element is not taken twice.
                     A[i][end] = A[i][end] ^1;
             } 
        }
        
        // for(int i=0;i<r;i++)
        // {
        //     for(int j=0;j<c;j++)
        //     {
        //         A[i][j]= A[i][j] ^ 1;
        //     }
        // }
         
        return A;
        
    }
};
