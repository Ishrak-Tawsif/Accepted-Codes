#include<bits/stdc++.h>
using namespace std;


struct d{

    long int l,u;

        bool operator <(const d&x) const
        {
            if(l==x.l) return u>x.u;
            return l>x.l;
        }
}st[200001];

int main(){

    int n;
        scanf("%d", &n);
            for(int i=0; i<n; i++) scanf("%ld %ld", &st[i].l, &st[i].u);
            sort(st, st+n);
//for(int i=0; i<n; i++) cout<<st[i].l<<" "<<st[i].u<<endl;
                long int mx=st[0].l,cnt=1;
                    for(int i=1; i<n; i++) {
                        if(mx<=st[i].u)cnt++;//cout<<st[i].u<<endl;
                    }
                    printf("%ld\n", cnt);
return 0;
}