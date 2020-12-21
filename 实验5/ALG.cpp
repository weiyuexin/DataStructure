#include<iostream>

using namespace std;

#define MVNum 100 //��󶥵���
#define OK 1
#define ERROR 0

typedef int Status;
typedef char VertexType;

typedef struct ArcNode{  //�߽ڵ�
    int adjvex;    //�ñ���ָ��Ķ���
    struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
}ArcNode;

typedef struct{  //������Ϣ
    VertexType data;
    ArcNode *firstarc; //ָ���һ�������ö���ı�
}VNode,AdjList[MVNum];    //�����ṹ������

typedef struct{
    AdjList vertices;
    int vexnum,arcnum; //ͼ�Ķ������ͱ���
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

Status CreateUDG(ALGraph &G)    //�����ڽӱ�������ͼ
{
    cout<<"�������ܶ��������ܱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"�����붥���ֵ:"<<endl;
    for(int i=0;i<G.vexnum;++i)      //������㣬�����ͷ����
    {
        cin>>G.vertices[i].data;    //���붥��ֵ
        G.vertices[i].firstarc = NULL;   //��ʼ����ͷ����ָ����ΪNULL
    }
    cout<<"���������:"<<endl;
    for(int k=0;k<G.arcnum;++k)     //������ߣ������ڽӱ�
    {
        VertexType v1,v2;
        cin>>v1>>v2;
        int i,j;
        i = LocateVex(G,v1);
        j = LocateVex(G,v2);
        //ȷ��v1v2��G�е�λ��
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
    cout<<"��ʼ������ڽӱ�Ϊ:"<<endl;
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
