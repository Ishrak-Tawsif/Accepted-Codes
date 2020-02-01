#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 1000000


int swi[mx],dp[mx],n;

/*int call(int pos)
{
    if(pos==0 || pos>n) return 0;

        int ans=INT_MIN;

            if(pos != 1)
            {
                ans = max(call(i));
            }
}*/
string str;
int main()
{
    sf(n);
    //string str;
    int bla,gol;
    double aa=0.0,bb=0.0,cc=0.0;
    cin.ignore();
        loop1(tt,n)
        {//cout<<tt<<endl;

            getline(cin,str);

                //cin>> str;
                bla=0,gol=0;
//cout<<str<<endl;
                    int temp=str.find("blue");
                    int temp2=str.find("black");


                        if(temp != str.npos && temp2 != str.npos) bla=1;

                    if(!bla)
                    {
                        int temp=str.find("white");
                        int temp2=str.find("gold");


                        if(temp != str.npos && temp2 != str.npos) gol=1;
                    }
                    if(bla == 1) aa = aa+1.0;
                    else if(gol == 1) bb = bb+1.0;
                    else cc = cc+1.0;//cout<<aa << " " << bb << " " << cc<< endl;
                }

        double sum = aa+bb+cc;
        pf("%.10f\n%.10f\n%.10f\n",aa/sum*100,bb/sum*100,cc/sum*100);

    return 0;
}