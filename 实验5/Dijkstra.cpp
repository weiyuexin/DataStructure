#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int map[110][110];//�����map���飬�洢ͼ
int dis[10010];//dis���飬�洢����ֵ
int book[10010];//book[i]�����������û�б�����Դ��ȥ��������1Ϊ�У�0Ϊû�С������Ͳ����ظ������ˡ�
int n,m;
void dijkstra(int u)//��������������Դ����
{
memset(dis,88,sizeof(dis));//��dis���鸽���ֵ
    int start=u;//�ȴ�Դ������
    book[start]=1;//���Դ���Ѿ�������
    for(int i=1;i<=n;i++)
    {
        dis[i]=min(dis[i],map[start][i]);//�ȸ���һ��
    }
    for(int i=1;i<=n-1;i++)
    {
        int minn=9999999;
            if(book[i]==0 && minn>dis[i])
            {
                minn=dis[i];
                start=i;//�ҵ���Դ������ĵ㣬Ȼ��ѱ�ż�¼����������������
            }
        book[start]=1;
        for(int j=1;j<=n;j++)
            dis[j]=min(dis[j],dis[start]+map[start][j]);//���µĵ�������dis��
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
                
    dijkstra(1);//��1ΪԴ�㡣
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";
}
