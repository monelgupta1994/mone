#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100];
map<pair<int,int>,int>maps;
     int weight[100],visit[100],n;


 int findmin()
 {
    int i,j,k,l,min=10001,pos;

         for(i=0;i<n;i++)
     {
         if(min> weight[i] && !visit[i] )
         {
             min=weight[i];
             pos=i;
         }
     }
    return pos;

 }


 void dijkstra(int x)
 {
    // int weight[100];
    int i,j,k,l,min=10001,pos;

     for(i=0;i<100;i++)
        weight[i]=10000;
     weight[x]=0;

//     dij();

    /* for(i=0;i<n-1;i++)
     {
         if(min> weight[i])
         {
             min=weight[i];
             pos=i;
         }
     }*/
    for(k=0;k<n-1;k++)
    {



     pos=findmin();
     visit[pos]=1;

     for(i=0;i<vec[pos].size();i++)
     { j=vec[pos][i];
        pair<int,int>foo;
       foo=make_pair(pos,j);
        if(!visit[j] && weight[j]>weight[pos]+maps[foo]  )
            weight[j]=weight[pos]+maps[foo];
     }
    }

 }



int main()
{

    int i,j,k,l,m;
   cin>>n>>m;
   while(m--)
   {
       cin>>i>>j>>k;
       vec[i].push_back(j);
       vec[j].push_back(i);
       pair<int,int>foo,doo;
       foo=make_pair(i,j);
       maps[foo]=k;
       doo=make_pair(j,i);
       maps[doo]=k;


   }
   dijkstra(0);

   for(i=0;i<n;i++)
   {
       cout<<weight[i]<<endl;
   }



    return 0;
}
