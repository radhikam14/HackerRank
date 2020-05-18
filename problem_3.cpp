#include<bits/stdc++.h>
using namespace std;
int ham(int h,int *b, int p)
{   
    while(p>0)
    {
        if(*b >= (p*2))
        {
            *b=*b - (p*2);
             break;
        }
        else
            p--;
    }
    return h*p;
}

int chicken(int c,int *b, int f)
{  
    while(f>0)
    {
        if(*b >= (f*2))
        {
            *b= *b - (f*2);
             break;
        }
        else
            f--;
    }
    return c*f;
}

int main() {
    int t;
    cin>>t;
    while(t>0)
    {   int b=0,p=0,f=0;
        int h=0,c=0;
        cin>>b>>p>>f;
        cin>>h>>c;
        
        int profit=0;
        if(b>1)
        {
        if(h>c)
        {
            profit=ham( h,  &b, p);
            if(b>0)
            profit=profit + chicken( c, &b,f);
        }
        else
        {
            profit=chicken( c, &b, f);
            if(b>0)
            profit=profit+ham( h,  &b, p);
        }
        }
        cout<<profit<<"\n"; 
        t--;
    }
    return 0;
}
