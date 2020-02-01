#include<bits/stdc++.h>
using namespace std;
//.
#define mx 46700
#define ll long long int

bitset <mx> isprime;
int prime[mx],in;
map <ll, ll> n_div;
map <ll, ll> m_div;
vector <ll> nn;
vector <ll> mm;
//int arr_n[mx+1],arr_m[mx+1];

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
//m_div[1000]=2; cout<<m_div[1000]<<endl;
        int testcase,m,n;
            scanf("%d", &testcase);

                while(testcase--)
                {
                    scanf("%d %d", &n,&m);
                    //memset(arr_m,0,sizeof(arr_m));
                    //memset(arr_n,0,sizeof(arr_n));
                    n_div.clear();
                    m_div.clear();
                    nn.clear();
                    mm.clear();
                    div_call(n,1);
                    div_call(m,0);
                    long long int temp_k=1;
                        //for(int i=0; i<n_div.size(); i++) cout<<n_div[i] <<" ";
                        //cout<<endl;
                        //for(int i=0; i<m_div.size(); i++) cout<<m_div[i] <<" ";
                        //cout<<endl;
                       //vector<int>uncommon; int fl;
                        /*for(int i=0; i<n_div.size();i++){
                                if(arr_n[n_div[i]]>arr_m[n_div[i]])
                                {
                                    temp_k *= n_div[i] * (arr_n[n_div[i]]-arr_m[n_div[i]]);
                                }
                                //cout<< n_div[i]<<" .. "<<arr_n[n_div[i]] <<" " << arr_m[n_div[i]]<<endl;
                        }//cout<<temp_k<<endl;
                        for(int i=0; i<m_div.size();i++){
                            if(arr_m[m_div[i]]>arr_n[m_div[i]])
                                {
                                    temp_k *= m_div[i] * (arr_m[m_div[i]]-arr_n[m_div[i]]);
                                }
                                //cout<< m_div[i]<<" "<<arr_n[n_div[i]] <<" " << arr_m[n_div[i]]<<endl;
                        }*/
                        //cout<<endl;

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
                                        //cout<< max_ << " " << nn[i] <<endl;
                                    }
                                //cout<< nn[i] << " " << n_div[nn[i]] << " " << m_div[nn[i]]<<endl;
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
                                         //cout<< max_ << " " << mm[i] <<endl;
                                    }
                              //cout<< mm[i] << " " << n_div[mm[i]] << " " << m_div[mm[i]]<<endl;
                            }
                        cout<<temp_k<<endl;
                }
return 0;
}