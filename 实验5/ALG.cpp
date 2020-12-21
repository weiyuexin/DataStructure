#include<iostream>

using namespace std;

#define MVNum 100 //最大顶点数
#define OK 1
#define ERROR 0

typedef int Status;
typedef char VertexType;

typedef struct ArcNode{  //边节点
    int adjvex;    //该边所指向的顶点
    struct ArcNode* nextarc; //指向下一条边的指针
}ArcNode;

typedef struct{  //顶点信息
    VertexType data;
    ArcNode *firstarc; //指向第一条依附该顶点的边
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

Status CreateUDG(ALGraph &G)    //才用邻接表创建无向图
{
    cout<<"请输入总顶点数，总边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点的值:"<<endl;
    for(int i=0;i<G.vexnum;++i)      //输入各点，构造表头结点表
    {
        cin>>G.vertices[i].data;    //输入顶点值
        G.vertices[i].firstarc = NULL;   //初始化表头结点的指针域为NULL
    }
    cout<<"请输入各边:"<<endl;
    for(int k=0;k<G.arcnum;++k)     //输入各边，构造邻接表
    {
        VertexType v1,v2;
        cin>>v1>>v2;
        int i,j;
        i = LocateVex(G,v1);
        j = LocateVex(G,v2);
        //确定v1v2在G中的位置
        ArcNode *p1 = new ArcNode;
        p1->adjvex =j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
    return OK;
}

void show(ALGraph G)
{
    cout<<"初始化后的邻接表为:"<<endl;
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

int main()
{
    ALGraph G1;
    CreateUDG(G1);
    show(G1);


    return 0;
}
