#include <bits/stdc++.h>

using namespace std;


#define IOS ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define forn(i,n) for(int i=0; i<int(n); i++)
#define MX 10000
bool sq[MX+5];

typedef long long int ll;

//Driver func to sort pair by second elements
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}

/*void solve()
{
   int n;
   cin>>n;
   vector<string>v(n);
   vector<pair<int,int>>p;
   forn(i,n)
   {
      cin>>v[i];
      forn(j,n)
      {
         if(v[i][j]=='*')
         {
             p.push_back({i,j});
         }
      }
   }
   p.push_back(p[0]);
   p.push_back(p[1]);
   if(p[0].first == p[1].first)
   {
       p[2].first = (p[2].first+1)%n;
       p[3].first = (p[3].first+1)%n;
   }
   if(p[0].second == p[1].second)
   {
      p[2].second = (p[2].second+1)%n;
      p[3].second = (p[3].second+1)%n;
   }
   else
   {
      swap(p[2].first,p[3].first);
   }
   v[p[2].first][p[2].second]='*';
   v[p[3].first][p[3].second]='*';

   forn(i,n)
   {
    cout<<v[i]<<endl;
   }
}*/
/*string Up2Low(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' and s[i]<='Z')
        {
            s[i]=(s[i]-'A')+'a';
        }
    }
    return s;
}*/

int lcm(int a, int b)
{
   return (a/(__gcd(a,b)))*b;
}
int main()

{
    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    int t,c=1;
    cin>>t;
    while(t--)
    {
      int n,m;
      int cnt=0;
      cin>>n>>m;
      cout<<"Case "<<c<<": ";
      std::vector<int> v(m);
      for (int i = 0; i < m; ++i)
      {
        cin>>v[i];
      }
      for(int i=1; i<(1<<m); i++)
      {
          std::vector<int> bitCount;
          for(int j=0; j<32; j++)
          {
             if(i & (1<<j))
             {
                 bitCount.push_back(v[j]);
             }
          }
          int ab=bitCount[0];
          for(auto x: bitCount)
            ab=lcm(ab,x);

          (bitCount.size()%2?cnt+=(n/ab):cnt-=(n/ab));
          bitCount.clear();
      }
      cout<<n-cnt<<endl;
      c++;
    }


    return 0;
}
