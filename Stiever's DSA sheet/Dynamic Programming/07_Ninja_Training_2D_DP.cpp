// Memoization
int solve(int n,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(n==0){
        int m=-1;
        for(int i=0;i<3;i++) {
            if(i!=last) m= max(m,points[0][i]);
        }
        return m;
    }
    if(dp[n][last]!=-1) return dp[n][last];

    int m=-1;
    for(int i=0;i<3;i++){
        if(i!=last) m=max(m,solve(n-1, i,points,dp)+points[n][i]);        
    }
    return dp[n][last]=m;

}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}
// tabulation

int ninjaTraining(int n, vector<vector<int>> &points) {

    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3]= max(points[0][1],max(points[0][2],points[0][0]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int i=0;i<3;i++){
                if(i!=last) {
                    dp[day][last]=max(dp[day][last],dp[day-1][i]+points[day][i]);
                }
            }
        }
    }
    return dp[n-1][3];
}