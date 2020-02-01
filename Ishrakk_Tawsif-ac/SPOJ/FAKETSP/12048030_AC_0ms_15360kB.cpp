#include<bits/stdc++.h>
#include <string>
#include <stdlib.h>     /* atof */
using namespace std;

map <string,int>mpp;

double todob(string ss)
{
    double res = 0,nn=0;
    int i=0,cnt=0;//cout<<ss<<".."<<endl;
    while(i<ss.length() && ss[i]!='.')
    {
        if(ss[i] == '-') {nn=1;i++;continue;}
        double temp = (ss[i]-'0') * 1.0;
        res *= 10;
        res += temp;
        i++;
    }
    while(i<ss.length())
    {
        if(ss[i] == '.'){i++;continue;}
        double temp = (ss[i]-'0') * 1.0;
        res *= 10;
        res += temp;
        i++;
        cnt++;
    }
    double koyta = 1;
    while(cnt--) koyta *= 10;

    if(nn) res *= -1.0;
    if(koyta != 0.0) res/=koyta;
    return res;
}

double calcdis(double x,double y,double xx,double yy)
{
    x -= xx;
    y -= yy;

    return sqrt((x*x) + (y*y));
}

void init()
{
    mpp.clear();
    mpp["started"]= 0; mpp["I"] = 0; mpp["out"] =0; mpp["at"] = 0;
    mpp["finished"]=0; mpp["journey"]=0; mpp["my"]=0; mpp["in"]=0; mpp["I"]=0;
}

int main()
{
    string str;

    int start,fini,fl=0;
    double res = 0.0,prex=0.0,prey=0.0;
    while(getline(cin,str))
    {
        //stringstream ss (str);
        string sstr;
        start=0,fini=0;
        /*while(ss>> sstr)
        {
            //mpp[sstr] = 1;
            if(sstr == "started") start = 1;
            if(sstr == "finished") fini = 1;
        }*/

        string fs = "";
        string sn = "";
        int comma = 0;


        int i=0;

        while(1)
        {
            if(str[i] == '(') {i++;break;}
            i++;
        }

        while(1)
        {
            if(str[i] == ')') break;
            if(str[i] == ',') {i++;comma=1; continue;}
            if(str[i] == ' '){i++; continue;}
            if(!comma) fs += str[i];
            else sn += str[i];
            i++;
        }
//cout<<fs<<" "<<sn<<endl;

        double curx = todob(fs);
        double cury = todob(sn);

        char ch[205],ch2[205];

        //for(int i=0; i<205; i++) ch[i] = '0';
        //for(int i=0; i<205; i++) ch2[i] = '0';

        //for(int i=0; i<fs.length(); i++) ch[i] = fs[i];
        //for(int i=0; i<sn.length(); i++) ch2[i] = sn[i];

        //double curx = atof(ch);
        //double cury = atof(ch2);

//cout<<curx<<" "<<cury<<endl;
        if(!fl)
        {
            fl=1;
            prex = curx;
            prey = cury;
            continue;
        }

        double curdis = calcdis(prex,prey,curx,cury);
        res += curdis;
        printf("The salesman has traveled a total of %.3f kilometers.\n",res);
        prex = curx;
        prey = cury;
        if(fini)
        {
            break;
        }
    }

    return 0;
}