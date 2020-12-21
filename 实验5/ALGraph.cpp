#include <iostream>

using namespace std;

#define MVNum 100 //��󶥵���
#define OK 1
#define ERROR 0

int w = 0;  //w��v���ڽӵ�
bool visited[MVNum] = {false};  //���ʱ�־����

typedef int Status;
typedef char VertexType;

typedef struct ArcNode{  //�߽ڵ�
    int adjvex;    //�ñ���ָ��Ķ���
    struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
}ArcNode;

typedef struct{  //������Ϣ
    VertexType data;
    ArcNode* firstarc; //ָ���һ�������ö���ı�
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

Status CreateUDG(ALGraph &G)
{
    char v1,v2;
    int p,q;  //��ʱ�����������洢����v1,v2�ڵ�λ��,��������G.vertices[]�еı��
    cout << "�����붥����������" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "�����붥������:"<< endl;
    for( int i=1;i<=G.vexnum;i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }

    cout << "�������������ӵĶ���:"<< endl;
    for( int i=1;i<=G.arcnum;i++)
    {
        cin >> v1 >> v2;
        p=LocateVex(G,v1);q=LocateVex(G,v2);  //��λ����v1��v2��vertices[]�е�λ��
        if( !p || !q)
        {
            cout << "�Ҳ������� " << v1 << " �� " << v2 << " ,����������" << endl;
            i--;
            continue;
        }

        /*
        *�����ڽӱ���õ���ͷ�巨,ÿ�������firstarc��ָ���һ��ָ��Ķ���,��Ȼ�ɱ߽ڵ��ʾ,����ָ���ĸ������ɱ߽ڵ����
        */
        ArcNode *p1 = new ArcNode;  //����һ���߽ڵ�
        p1->adjvex = q;      //������ָ���ĸ�����
        p1->nextarc = G.vertices[p].firstarc;  G.vertices[p].firstarc = p1; //ͷ�巨����ڵ�
        ArcNode *p2 = new ArcNode; //����ͼ�Գ�
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
    cout << G.vertices[i].data << "  ";  //�ӵ�i�����㿪ʼ
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

    cout << "���������������ȱ���ʱ��ʼ�Ķ���" << endl;
    while(true)
    {
        cin >> v;
        vNum = LocateVex(G1,v);
        if(!vNum)
            cout << "�Ҳ������� " << v << " ����������" << endl;
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



