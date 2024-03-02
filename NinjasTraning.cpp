#include<bits/stdc++.h>
using namespace std;

int f(int i,int last,vector<vector<int>>&dp,vector<vector<int>>&points){
    if(i==0){
        int maxPoints=0;
          for(int k=0;k<3;k++){
              if(k!=last){
                   maxPoints=max(maxPoints,points[0][k]);
              }
          }
          return maxPoints;
    }
    if(dp[i][last]!=-1)return dp[i][last];
    int maxPoints=0;
      for(int k=0;k<3;k++){
              if(k!=last){
                  int point=points[i][k]+f(i-1,k,dp,points);
                   maxPoints=max(maxPoints,point);
              }
          }
          return dp[i][last]=maxPoints;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,dp,points);
    // Write your code here.
}

//tabulation

// #include<bits/stdc++.h>

// int ninjaTraining(int n, vector<vector<int>> &p)
// {
//     vector<vector<int>>dp(n,vector<int>(4,0));
//     dp[0][0]=max(p[0][1],p[0][2]);
//     dp[0][1]=max(p[0][0],p[0][2]);
//     dp[0][2]=max(p[0][1],p[0][0]);
//     dp[0][3]=max(p[0][1],max(p[0][0],p[0][2]));
    
//     for(int i=1;i<n;i++){
//         for(int last=0;last<4;last++){

//             dp[i][last]=0;
//             for(int task=0;task<3;task++){
//                 if(task!=last){
//                   int point=p[i][task]+dp[i-1][task];
//                   int x=dp[i][last];
//                    dp[i][last]=max(x,point);
//                 }
                
//             }
            
//         }
//     }
//     return dp[n-1][3];
//     // Write your code here.
// }


//space optimization

// #include<bits/stdc++.h>

// int ninjaTraining(int n, vector<vector<int>> &p)
// {
//     vector<int>dp(4,0);
//     dp[0]=max(p[0][1],p[0][2]);
//     dp[1]=max(p[0][0],p[0][2]);
//     dp[2]=max(p[0][1],p[0][0]);
//     dp[3]=max(p[0][1],max(p[0][0],p[0][2]));
    
//     for(int i=1;i<n;i++){
//         vector<int>temp(4,0);
//         for(int last=0;last<4;last++){

//             temp[last]=0;
//             for(int task=0;task<3;task++){
//                 if(task!=last){
//                   int point=p[i][task]+dp[task];
//                   int x=temp[last];
//                    temp[last]=max(x,point);
//                 }
                
//             }

            
//         }
//         dp=temp;
//     }
//     return dp[3];
    // Write your code here.
}