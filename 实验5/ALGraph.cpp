#include <iostream>

using namespace std;

#define MVNum 100 //最大顶点数
#define OK 1
#define ERROR 0

int w = 0;  //w是v的邻接点
bool visited[MVNum] = {false};  //访问标志数组

typedef int Status;
typedef char VertexType;

typedef struct ArcNode{  //边节点
    int adjvex;    //该边所指向的顶点
    struct ArcNode* nextarc; //指向下一条边的指针
}ArcNode;

typedef struct{  //顶点信息
    VertexType data;
    ArcNode* firstarc; //指向第一条依附该顶点的边
}VNode,AdjList[MVNum];    //声明结构体数组

typedef struct{
    AdjList vertices;
    int vexnum,arcnum; //图的顶点数和边数
}ALGraph;

int LocateVex(ALGraph G, char t)
{
    for (int i=1;i<=G.vexnum;i++)
    {
        if( G.vertices[i].data == t)
            return i;
    }
    return ERROR;
}

Status CreateUDG(ALGraph &G)
{
    char v1,v2;
    int p,q;  //临时变量，用来存储顶点v1,v2在的位置,即顶点在G.vertices[]中的编号
    cout << "请输入顶点数、边数" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入顶点数据:"<< endl;
    for( int i=1;i<=G.vexnum;i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }

    cout << "请输入两个连接的顶点:"<< endl;
    for( int i=1;i<=G.arcnum;i++)
    {
        cin >> v1 >> v2;
        p=LocateVex(G,v1);q=LocateVex(G,v2);  //定位顶点v1、v2在vertices[]中的位置
        if( !p || !q)
        {
            cout << "找不到顶点 " << v1 << " 或 " << v2 << " ,请重新输入" << endl;
            i--;
            continue;
        }

        /*
        *创建邻接表采用的是头插法,每个顶点的firstarc都指向第一个指向的顶点,仍然由边节点表示,后续指向哪个顶点由边节点完成
        */
        ArcNode *p1 = new ArcNode;  //声明一个边节点
        p1->adjvex = q;      //这条边指向哪个顶点
        p1->nextarc = G.vertices[p].firstarc;  G.vertices[p].firstarc = p1; //头插法插入节点
        ArcNode *p2 = new ArcNode; //无向图对称
        p2->adjvex = p;
        p2->nextarc = G.vertices[q].firstarc;  G.vertices[q].firstarc = p2;
    }
    return OK;
}

void show(ALGraph G)
{
    for( int i=1;i<=G.vexnum;i++)
    {
        cout << i-1 << ":";
        cout << G.vertices[i].data;
        cout << " V" << "(" << i << ") -> ";
        if( !G.vertices[i].firstarc )
            cout << "NULL";
        while(G.vertices[i].firstarc != NULL)
        {
            cout << G.vertices[i].firstarc->adjvex - 1 ;
            if(G.vertices[i].firstarc->nextarc)
                cout << " -> ";
            else
                cout <<" -> NULL";
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        }
        cout << endl;
    }
}

void DFS_AL(ALGraph G,int i)
{
    cout << G.vertices[i].data << "  ";  //从第i个顶点开始
    visited[i] = true;
    ArcNode *p=G.vertices[i].firstarc;
    while( p != NULL)
    {
        w = p->adjvex;
        if(!visited[w])
            DFS_AL(G,w);
        p=p->nextarc;
    }
}

int main()
{
    char v;
    int vNum;
    ALGraph G1;
    CreateUDG(G1);
    show(G1);

    cout << "请输入进行深度优先遍历时开始的顶点" << endl;
    while(true)
    {
        cin >> v;
        vNum = LocateVex(G1,v);
        if(!vNum)
            cout << "找不到顶点 " << v << " 请重新输入" << endl;
        else
            break;
    }
    DFS_AL(G1,vNum);cout << endl;

    return 0;
}


/*
5 6

a b c d e 

a b
a d
b c
b e
c d
c e

*/ 



