#include<bits/stdc++.h>
using namespace std;
int main(){

        vector<pair<int,int> >v;
        vector<pair<int,char> >v2;
        int in[11],c[11];
        int diff,isleaked,n,temp,testcase;
        char ans;

            while(scanf("%d", &testcase) == 1){

                while(testcase --){
                    scanf("%d", &n);

                    memset(in,0,sizeof(in));
                    memset(c,0,sizeof(c));

                    for(int i=0; i<n; i++){
                            scanf("%d %d %c", &diff, &isleaked, &ans);
                            //cout << diff <<isleaked<<ans;

                                if(isleaked == 0 && ans == 'i') in[diff]++;
                                else if(isleaked == 1 && ans == 'c') c[diff]++;
                            //v.push_back(make_pair(diff,isleaked));
                            //v2.push_back(make_pair(diff,ans));
                    }
                    //for(int i=0; i<9; i++)cout << i << " " << in[i] << " " << c[i] << endl;
                    //sort(v.begin(),v.end());
                    //sort(v2.begin(),v2.end());


                        /*for(int i=0; i<n; i++){
                            //cout<<v[i].first << " " << v[i].second << endl;
                            //cout<<v2[i].first << " " << v2[i].second << endl;
                            if(v[i].second == 0 && v2[i].second == 'i'){
                                temp=i;
                                    while(temp<n){
                                        if(v[temp].second == 1 && v2[temp].second == 'c') count++;

                                        temp++;
                                    }
                            }
                        }*/

                        int count=0,sum=0;
                        for(int i=1; i<=10; i++){
                            count=0;
                            if(in[i] != 0){
                                for(int j=i+1; j<=10; j++){
                                    if(c[j] != 0) count += in[i]*c[j];
                                }
                            }
                            sum += count;
                        }
                        cout << sum << endl;
                        //v.clear();
                        //v2.clear();
                }
            }
            
return 0;
}
