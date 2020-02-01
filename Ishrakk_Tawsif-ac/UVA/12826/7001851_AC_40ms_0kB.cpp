#include <bits/stdc++.h>
using namespace std;

int dir_r[] = {-1,-1,-1,0,0,1,1,1};
int dir_c[] = {-1,0,1,-1,1,-1,0,1};

int bfs(int start_row,int start_col,int end_row,int end_col,int res_row,int res_col){
    int arr[9][9];
    int cos[9][9];

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++) {arr[i][j]=0; cos[i][j]=0;}
    }

    queue <int> q;
    q.push(start_row);
    q.push(start_col);
    cos[start_row][start_col]=0;arr[start_row][start_col]=1;
    int ans=0;

        while(!q.empty()){
            int temp_r = q.front(); q.pop();
            int temp_c = q.front(); q.pop();

                for(int i=0; i<8; i++){
                    int t_r = temp_r + dir_r[i];
                    int t_c = temp_c + dir_c[i];

                                if((t_r>=1 && t_r<=8 && t_c>=1 && t_c<=8) && (t_r != res_row || t_c != res_col)){
                                 if(arr[t_r][t_c] == 0){
                                    cos[t_r][t_c] = cos[temp_r][temp_c]+1;
                                    arr[t_r][t_c]=1;
                                    q.push(t_r);
                                    q.push(t_c);
                                 }
                                }

                }
        }
        return cos[end_row][end_col];
}

int main(){

    int start_row,start_col,end_row,end_col,res_row,res_col,t=0;

        while(cin>>start_row >>start_col >>end_row >>end_col >>res_row >>res_col){

            cout << "Case " << ++t << ": " << bfs(start_row,start_col,end_row,end_col,res_row,res_col) << endl;
        }

return 0;
}