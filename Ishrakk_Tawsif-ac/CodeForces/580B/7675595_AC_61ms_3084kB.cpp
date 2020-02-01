#include<bits/stdc++.h>
using namespace std;

#define mx 100005



struct s{

    long long mon,fac;

        bool operator < (const s&x)const{
            return mon<x.mon;
        }
};

vector <s> v;

int main(){

    int n,d;
    s get;

        while(scanf("%d %d", &n, &d) == 2){
            for(int i=0; i<n; i++) {scanf("%lld %lld", &get.mon, &get.fac); v.push_back(get);};
            sort(v.begin(), v.end());

                int j=0;
                long long max_=LONG_LONG_MIN,temp=0;

                //for(int i=0; i<n; i++)cout<<v[i].mon<<endl;
                for(int i=0; i<n;){ /// two pointer

                        while(v[i].mon-v[j].mon < d && i<n){
                            temp += v[i].fac;//cout << i << " " << j <<endl;
                            i++;
                        }
                    max_=max(temp,max_);//cout<<max_<<endl;
                    temp-=v[j].fac;
                    j++;
                }
                cout << max_ <<endl;
        }
return 0;
}