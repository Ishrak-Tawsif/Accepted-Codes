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

map <string,int> fruits;
vector<int>vv;


int main()
{
   int n,m;
    //cout<<fruits["abs"]+1;
        while(sf(n) == 1)
        {
            vv.clear();
            fruits.clear();

            sf(m);

            int arr[n+1];
                    for(int i=0; i<n; i++) sf(arr[i]);
                    sort(arr, arr+n);
                    string temp;
                        loop(m){
                            cin>> temp;
                            fruits[temp]++;
                            //cout<<temp << " " << fruits[temp]<<endl;
                        }
    typedef std::map<string,int>::iterator it_type;
    for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++) {
     //cout<<iterator->first << endl;
        vv.pb(iterator->second);
    }
    sort(vv.begin(),vv.end());
        int min_=0,max_=0,in=n,inn=-1;
        for(int i=vv.size()-1,j=0; i>=0; i--,j++){
            max_ +=  vv[i] * arr[--in];//cout<< vv[i] << " " << arr[in]<<endl;
            min_ +=  vv[i] * arr[++inn];//cout<< vv[j] << " " << arr[in]<<endl;
        }
        pf("%d %d\n",min_,max_);
    }
   return 0;
}