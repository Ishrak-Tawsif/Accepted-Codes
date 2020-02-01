///hints

/*
 we just delete equal number of equal factors as in second example we delete five
 as it repeated once in both m and n , but if both n & m contains similar factors
 but not repeated the same number of times we just take the larges occurrence of
 that factor in whatever n or m.
 n = 20 ->  2 , 2 , 5
m = 25 -> 5 , 5
we see that 25 contains two 5s and 20 contains two 2s and one 5 , thinking a little you will see that
k = 5 * 5 * 2 * 2
***************************************
n = 20 -> 2 , 2 , 5
m = 55 -> 5 , 11
here m contains one 5 and one 11  - > k = 2 * 2 * 11
*****************************************
*/

#include<bits/stdc++.h>
using namespace std;

#define mx 46700
#define ll long long int

bitset <mx> isprime;
int prime[mx],in;
map <ll, ll> n_div;
map <ll, ll> m_div;
vector <ll> nn;
vector <ll> mm;

void sieve(){
    isprime[0]=isprime[1]=1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
              in=-1;
                for(int i=0; i<mx; i++) if(!isprime[i]) prime[++in]=i;
                //cout << in << endl;
}

void div_call(int n,int type){

    int cnt;
    for(int i=0; prime[i]*prime[i]<=n && i<=in; i++)
    {

        if(n%prime[i]==0)
        {
            cnt=0;
            if(type==1) nn.push_back(prime[i]); else mm.push_back(prime[i]);
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            if(type==1) n_div[prime[i]]=cnt;
            else m_div[prime[i]]=cnt;
        }
    }
    if(n!=1)
    {
        if(type==1){n_div[n]=1; nn.push_back(n);}
        else {m_div[n]=1; mm.push_back(n);}
    }
}


int main(){

    sieve();

        int testcase,m,n;
            scanf("%d", &testcase);

                while(testcase--)
                {
                    scanf("%d %d", &n,&m);

                    n_div.clear();
                    m_div.clear();
                    nn.clear();
                    mm.clear();
                    div_call(n,1);
                    div_call(m,0);
                    long long int temp_k=1;

                            for(int i=0; i<nn.size(); i++)
                            {
                                    if(n_div[nn[i]] == m_div[nn[i]])
                                    {
                                        n_div[nn[i]] = m_div[nn[i]] = 0; //break;
                                    }
                                    else{
                                        int max_=max(n_div[nn[i]],m_div[nn[i]]);
                                        while(max_--)temp_k *= (ll)(nn[i]);
                                        n_div[nn[i]] = m_div[nn[i]] = 0;
                                    }
                            }

                            for(int i=0; i<mm.size(); i++)
                            {
                                    if(n_div[mm[i]] == m_div[mm[i]])
                                    {
                                        n_div[mm[i]] = m_div[mm[i]] = 0; //break;
                                    }
                                    else{
                                        int max_=max(n_div[mm[i]],m_div[mm[i]]);
                                        while(max_--)temp_k *= (ll) (mm[i]);
                                    }
                            }
                        cout<<temp_k<<endl;
                }
return 0;
}