#include<bits/stdc++.h>
using namespace std;

struct d{
    long int s,k;

        bool operator < (const d&x) const{
           int t=s-k;
           int tt=x.s-x.k;
           return t>tt;
        }
};

vector <d> v;

int main(){
    d get;
    int n;
        scanf("%d", &n);

            for(int i=0; i<n; i++){
                scanf("%ld %ld", &get.s, &get.k);
                v.push_back(get);
            }

            sort(v.begin(),v.end());
            long long ext=v[0].s-v[0].k,tot=v[0].s;
            for(int i=1; i<n; i++){
                    //cout<<v[i].s << " " << v[i].k << endl;
                    if(ext>v[i].s){
                        ext -= v[i].k;
                        //ext += v[i].s-v[i].k;
                    }
                    else {
                        tot += v[i].s-ext;
                        ext=v[i].s-v[i].k;
                    }//cout<<ext<<endl;ll
            }
            printf("%lld\n",tot);
  return 0;
}