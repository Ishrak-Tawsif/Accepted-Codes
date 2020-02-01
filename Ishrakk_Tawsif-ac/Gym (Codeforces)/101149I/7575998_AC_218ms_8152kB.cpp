#include<bits/stdc++.h>
using namespace std;

vector<int>v[200005] ;
int arr[200005];

int main(){

    int s,st,u,vv,min_=INT_MAX,temp=1;
        scanf("%d %d",&s,&st);

            for(int i=0;i<st; i++){
                scanf("%d %d", &u,&vv);
                v[u].push_back(vv);
                v[vv].push_back(u);
                //if(v[u].size()<min_) {min_=v[u].size();temp=u;}
                //if(v[vv].size()<min_){min_=v[vv].size();temp=vv;}
            }

            for(int i=1; i<=s; i++){
                if(v[i].size()<min_){min_=v[i].size(); temp=i;}
            }

            arr[temp]=1;
            for(int i=0; i<v[temp].size(); i++)arr[v[temp][i]]=1;

            if(arr[1]==1)printf("0");
            else printf("1");
            for(int i=2;i<=s;i++){
                if(arr[i]==1)printf(" 0");
                else printf(" 1");
            }
            printf("\n");
return 0;
}