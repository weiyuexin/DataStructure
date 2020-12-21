#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int map[110][110];//这就是map数组，存储图
int dis[10010];//dis数组，存储估计值
int book[10010];//book[i]代表这个点有没有被当做源点去搜索过，1为有，0为没有。这样就不会重复搜索了。
int n,m;
void dijkstra(int u)//主函数，参数是源点编号
{
memset(dis,88,sizeof(dis));//把dis数组附最大值
    int start=u;//先从源点搜索
    book[start]=1;//标记源点已经搜索过
    for(int i=1;i<=n;i++)
    {
        dis[i]=min(dis[i],map[start][i]);//先更新一遍
    }
    for(int i=1;i<=n-1;i++)
    {
        int minn=9999999;
            if(book[i]==0 && minn>dis[i])
            {
                minn=dis[i];
                start=i;//找到离源点最近的点，然后把编号记录下来，用于搜索。
            }
        book[start]=1;
        for(int j=1;j<=n;j++)
            dis[j]=min(dis[j],dis[start]+map[start][j]);//以新的点来更新dis。
    }
}
int main()
{
    cin>>n>>m;
    memset(map,88,sizeof(map));
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        map[a][b]=c;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                map[i][j]=0;
                
    dijkstra(1);//以1为源点。
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
}
