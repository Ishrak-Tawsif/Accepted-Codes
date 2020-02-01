#include<bits/stdc++.h>
using namespace std;

int rr[] = {-1,0,0,1};
int cc[] = {0,-1,1,0};
//int dir[4][2]={-1,0,0,-1,1,0,0,1};
int main(){

    int testcase,row,col;
        scanf("%d", &testcase);

            while(testcase--){
                scanf("%d %d", &row, &col);
                    int arr[55][55];
                    memset(arr,0,sizeof(arr));

                    long long int sum,t_sum,roof=0;

                        for(int i=1; i<=row; i++){
                            for(int j=1; j<=col; j++) {
                                    scanf("%d", &arr[i][j]);
                                    if(arr[i][j] != 0) roof++;
                            }
                        }
                        sum=0;

                            for(int i=1; i<=row; i++){
                                for(int j=1; j<=col; j++){

                                    t_sum=0;
                                    /*if((i==1 && j==1) || (i==row&&j==1) || (i==1&&j==col) || (i==row&&j==col)){
                                        t_sum += arr[i][j]*2;
                                    }
                                    else if(i==1 || j==1 || i==row || j==col) t_sum += arr[i][j];*/

                                    for(int k=0; k<4; k++){
                                        int t_r = i+rr[k];
                                        int t_c = j+cc[k];

                                            //if(t_r>=1 && t_r<=row && t_c>=1 && t_c<=col){

                                                if(arr[t_r][t_c]<arr[i][j]) t_sum += arr[i][j]-arr[t_r][t_c];
                                            //}
                                    }//cout << i << " " << j << "   " << t_sum << endl;
                                    sum += t_sum;//cout << sum << " " << t_sum << endl;
                                }
                            }
                            cout << sum+roof << endl;
            }
return 0;
}