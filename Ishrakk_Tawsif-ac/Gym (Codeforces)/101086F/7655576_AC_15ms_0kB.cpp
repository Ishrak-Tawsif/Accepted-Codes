#include<bits/stdc++.h>
using namespace std;

int arr[7][4][7],state[4]; ///level state number

void reset(){

    memset(arr,0,sizeof(arr));
        arr[1][1][1]=1;
        arr[2][1][1]=2;
        arr[2][2][2]=1;
        arr[3][1][1]=arr[3][1][2]=arr[3][2][3]=1;
        arr[4][1][1]=arr[4][1][3]=arr[4][3][4]=1;
        arr[4][2][2]=2;
        arr[5][1][2]=arr[5][1][3]=arr[5][2][1]=arr[5][2][4]=arr[5][3][5]=1;
    state[1]=1; state[2]=2; state[3]=2; state[4]=3; state[5]=3;
}

int main(){

    int cnt[7],how_much[7],tc;
    string str;
    reset();
    /*for(int i=1; i<=5; i++){
        for(int j=1; j<=3; j++){
            for(int k=1; k<=5; k++) cout<<" " <<arr[i][j][k];
            cout<<" ||| "<<endl;
        }
        cout<<" --------- "<<endl;
    }*/

        scanf("%d", &tc);

            while(tc--){
                cin>> str;
                    memset(cnt,0,sizeof(cnt));
                    for(int i=0; i<str.length(); i++)cnt[(str[i]-'A')+1]++;
                        int fl=0;//for(int i=1; i<=5; i++)cout<<cnt[i]<<endl;
                        for(int i=1; i<=state[1]; i++){ if(fl==1) break; ///1
                            memset(how_much,0,sizeof(how_much));
                            for(int tm=1; tm<=5; tm++)how_much[tm]+=arr[1][i][tm];

                            //for(int a=1; a<=5; a++) cout << " "<<how_much[a];cout<<endl;
                            for(int j=1; j<=state[2]; j++){ if(fl==1) break; ///2
                                for(int tm=2; tm<7; tm++)how_much[tm]=0;
                                if(j!=1)for(int tm=1; tm<=5; tm++)how_much[tm]-=arr[2][j-1][tm];
                                for(int tm=1; tm<=5; tm++)how_much[tm]+=arr[2][j][tm];

                                //for(int a=1; a<=5; a++) cout << " "<<how_much[a];cout<<endl;
                                for(int k=1; k<=state[3]; k++){ if(fl==1) break; ///3
                                    for(int tm=3; tm<7; tm++)how_much[tm]=0;
                                    if(k!=1)for(int tm=1; tm<=5; tm++)how_much[tm]-=arr[3][k-1][tm];
                                    for(int tm=1; tm<=5; tm++)how_much[tm]+=arr[3][k][tm];

                                    //if(i==1&&j==2&&k==1)for(int a=1; a<=5; a++) cout << " /// "<<how_much[a];cout<<endl;
                                    for(int m=1; m<=state[4]; m++){ if(fl==1) break; ///4
                                        for(int tm=4; tm<7; tm++)how_much[tm]=0;
                                        if(m!=1)for(int tm=1; tm<=5; tm++)how_much[tm]-=arr[4][m-1][tm];
                                        for(int tm=1; tm<=5; tm++)how_much[tm]+=arr[4][m][tm];

                                        //for(int a=1; a<=5; a++) cout << " "<<how_much[a];cout<<endl;
                                        for(int o=1; o<=state[5]; o++){ if(fl==1) break; ///5
                                            for(int tm=5; tm<7; tm++)how_much[tm]=0;
                                            if(0!=1)for(int tm=1; tm<=5; tm++)how_much[tm]-=arr[5][o-1][tm];
                                            for(int tm=1; tm<=5; tm++)how_much[tm]+=arr[5][o][tm];
                                                int flfl=1;
                                                for(int ii=1; ii<=5; ii++){
                                                    //cout<</*cnt[ii]-*/how_much[ii]<<endl;
                                                    if(cnt[ii]-how_much[ii]<0) flfl=0;
                                                }
//if(i==1 && j==2 && k==1 && m==3 && o==3)for(int ii=1; ii<=5; ii++) cout<<how_much[ii]<<".."<<endl;
                                                if(flfl==1) {fl=1; break;}//system("pause");
                                        }
                                    }
                                }
                            }
                        }
                        if(fl==1) cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
            }

return 0;
}