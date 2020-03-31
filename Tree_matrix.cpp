#include <bits/stdc++.h>
using namespace std;
#define a(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
int main()
{
    int X,Y; 
    X = Y = 10; 
    int cost_mat[X][Y];

    a(i,0,X-1){
        a(j,0,Y-1){
            
            cin>>cost_mat[i][j];
        }
    }

    int min_cost[X][Y]; 

    min_cost[0][0] = cost_mat[0][0];

    // initialize first row of min_cost matrix
    a(j,1,Y-1)
        min_cost[0][j] = min_cost[0][j-1] + cost_mat[0][j];

    //Initialize first column of min_cost Matrix
    a(i,1,X-1)
        min_cost[i][0] = min_cost[i-1][0] + cost_mat[i][0];

    //This bottom-up approach ensures that all the sub-problems needed
    
    a(i,1,X-1){
        a(j,1,Y-1){
            //Calculate cost_mat of visiting (i,j) using the
        
            min_cost[i][j] = min(min_cost[i-1][j],min_cost[i][j-1]) + cost_mat[i][j];
        }
    }

    cout<<"Minimum cost_mat from (0,0) to (X,Y) is "<<min_cost[X-1][Y-1];
    return 0;
}
