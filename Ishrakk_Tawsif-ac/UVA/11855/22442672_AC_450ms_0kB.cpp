#include <bits/stdc++.h>
using namespace std;

#define mx      1003
#define base    10000001
#define mod     1000000007
#define ll      long long int

string inch,ch;
int sz;
ll pow_[mx],HP[mx],HS[mx];

int getCharVal(char c){
    int now = (c - 'A') + 1;
    return now;
}

void init(){
    pow_[0] = 1;
    for(int i=1; i<mx; i++)
    {
        pow_[i] = (pow_[i-1]%mod * base%mod)%mod;
        pow_[i] = pow_[i] % mod;
    }
}

void computeHashPre(){

    HP[0] = getCharVal(ch[0]);//printf("%lld\n", HP[0]);
    for(int i=1; i<=sz; i++){
        //if(ch[i] == ' ') continue;//printf("%c", ch[i]);
        int now = getCharVal(ch[i]);
        HP[i] = (((HP[i-1] * base)%mod) + now) % mod;//printf("%lld\n", HP[i]);
    }//printf("\n");
}

ll getHashPre(int l,int r){

    if(!l) return HP[r];

    ll res = (HP[r] - ((HP[l-1]%mod * pow_[r-l+1]%mod))%mod)%mod;
    res = (res + mod) % mod;

    return res%mod;
}

map <ll,int> cnt;
//map<char,int> cnt2;

int main(){

    //freopen("out.txt","w",stdout);

    init();
    //cin.ignore();
    while(getline(cin,inch) && inch.size()){

        /*for(int i=0; inch[i]!='\0'; i++){
            if(inch[i] == ' ') continue;
            cnt2[inch[i]] ++;
            printf("%c %d\n",inch[i],cnt2[inch[i]]);
        }*/
        //cnt.clear();
//cout<<inch<<endl;
        ch = "";
        for(int i=0,j=0; i<inch.size(); i++){
            if(inch[i] == ' ') continue;
            ch += inch[i];
            //ch[j] = '\0';
        }

        sz = ch.size();

        sz --;//printf("sz: %d\n", sz);
        computeHashPre();

        int j = 1,fl = 0;
        int res[1003];

        while(j<=sz){
            int maxi = 0;

            //if((j*2)>(sz+1)) break;

            for(int i=0; (i+j-1)<=sz; i++){
                ll curHashVal = getHashPre(i,i+j-1);
                cnt[curHashVal] ++;
                maxi = max(maxi,cnt[curHashVal]);
                //if(j == 2) printf("%c%c %lld\n",ch[i],ch[i+j-1],curHashVal);
            }
            //res[j] = maxi;
            //printf("%d %d\n", j,maxi);
            j++;
            if(maxi>1) printf("%d\n",maxi);
            else {printf("\n");fl = 1; break;}
            //cnt.clear();
        }
        if(!fl) printf("\n");
        cnt.clear();
    }

    return 0;
}