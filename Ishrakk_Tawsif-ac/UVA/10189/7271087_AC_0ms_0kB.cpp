#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mx 1000000


int row[] = {-1,-1,-1,0,0,1,1,1};
int col[] = {-1,0,1,-1,1,-1,0,1};

int main(){
    string grid[101];
    int n,m,field=0;

        while(cin>>m >> n){

            if(m==0 && n==0) break;
            for(int i=0; i<m; i++) cin>> grid[i];
            
                if(field!=0) cout << endl;
                cout << "Field #" << ++field << ":" << endl;
                for(int i=0; i<m; i++){
                    for(int j=0; j<n; j++){
                        if(grid[i][j] == '*') cout << grid[i][j];
                        else{
                            int cnt=0,r,c;
                                for(int k=0; k<8; k++){
                                    r = row[k] + i;
                                    c = col[k] + j;

                                        if(r>=0 && r<m && c>=0 && c<n){
                                            if(grid[r][c] == '*') cnt++;
                                        }
                                }
                                cout << cnt;
                        }
                    }cout << endl;
                }//cout<<endl;
        }
return 0;
}