#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int

vector <int> graph[mx];
vector <int> topsort;
int vis[mx],n,domino;

int arr[105],sum[105];


int main()
{
   string s1,s2,s3;
        while(cin>> s1)
        {
            cin>> s2;
            if(s1.size() != s2.size()) pf("WRONG_ANSWER\n");
            else{
            int arr[17],ans[17],in=-1;
                for(int i=s1.length()-1; i>=0; i--){
                    arr[++in]=s1[i]-'0';
                    //cout<<arr[in];
                }
                sort(arr,arr+in+1);
                int i=0,inn=-1;//cout<<arr[in]<<endl;
                while(arr[i]==0 && i<in) i++;
                ans[++inn]=arr[i]; arr[i]=-1;//cout<<i<<endl;
                for(int i=0; i<=in; i++) if(arr[i]!=-1){ans[++inn]=arr[i];}
                //for(int i=0; i<=in; i++)cout<<ans[i];
                int fl=0;
                for(int i=0; i<=inn; i++){
                    int temp = s2[i]-'0';
                    if(temp != ans[i]) {fl=1; break;}
                }
                if(fl==0) pf("OK\n");
                else pf("WRONG_ANSWER\n");
            }
        }
   return 0;
}