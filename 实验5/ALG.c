
#include <stdio.h>
#include <malloc.h>
#define  MaxVertices 100
#define maxSize 100
typedef int VertexType;

/***********�߱�**********/
typedef struct EdgeNode
{
	int adjvex;      //�ñ���ָ�����λ��
	struct EdgeNode *next;   //�ñ���ָ����һ������ָ��
}EdgeNode;

/*********�����*********/
typedef struct
{
	int vertex;     //�������Ϣ
	EdgeNode *edgenext;  //ָ���һ���ߵ�ָ��
}VertexNode,AdjList[MaxVertices];

/*********ͼ�ṹ********/
typedef struct
{
	AdjList adjlist;
	int nodeNum;  //������
	int edgeNum;  //����
}ALGraph;

/*********����ͼ********/
void create_Graph(ALGraph *G)
{
	int i, j;
	int vi, vj;     //�����ӵ������������
	EdgeNode *s;    //�߱���

	printf("�����붥�����ͱ���(�Կո����)");
	scanf_s("%d%d", &G->nodeNum, &G->edgeNum);

	printf("���������:\n");
	for (i = 0; i < G->nodeNum; i++)
	{
		//getchar();
		printf("�������%d���������Ϣ:", i + 1);
		scanf_s("%d", &G->adjlist[i].vertex);
		G->adjlist[i].edgenext = NULL;
	}

	printf("\n��ӡ�����±꼰��������:\n");
	for (i = 0; i < G->nodeNum; i++)
		printf("�����±꣺%d  ��������:%d\n ", i,G->adjlist[i]);

	printf("\n�����߱�:\n");
	for (i = 0; i < G->edgeNum; i++)
	{
		printf("�����������ӵ����������±�:");
		scanf_s("%d%d",&vi,&vj );
		s = malloc(sizeof(EdgeNode));
		s->adjvex = vj;    //����ָ�����λ��
		s->next = G->adjlist[vi].edgenext;
		G->adjlist[vi].edgenext = s;

		//����(0 1)��1��Ҳ��0����
		s = malloc(sizeof(EdgeNode));
		s->adjvex = vi;    //����ָ�����λ��
		s->next = G->adjlist[vj].edgenext;
		G->adjlist[vj].edgenext = s;
	}
}

/***********��ӡ�߱�*********/
void print_Graph(ALGraph *G)
{
	int i, j;
	for (i = 0; i < G->nodeNum; i++)
	{
		printf("%d->",i);
		while (1)
		{
			if (G->adjlist[i].edgenext == NULL)
			{
				printf("^");
				break;
			}
			printf("%d->", G->adjlist[i].edgenext->adjvex);
			G->adjlist[i].edgenext = G->adjlist[i].edgenext->next;
		}
		printf("\n");

	}
}

/**************������ȱ���**************/
int visit[maxSize];
void DFS(ALGraph G,int v)
{
	EdgeNode *p;
	if (v<0 || v>=G.nodeNum)
		return;
	else
	{
		visit[v] = 1;     //�Ѿ����ʱ��
		printf("%d ", G.adjlist[v].vertex);
		p = G.adjlist[v].edgenext;   //pָ�򶥵�v�ĵ�һ����
		while (p != NULL)
		{
			if (visit[p->adjvex] != 1)
				DFS(G,p->adjvex);
			p = p->next;
		}
	}
}
void DFSTravel(ALGraph G)
{
	int v;
	printf("������ȱ���˳��Ϊ��");
	for (v = 0; v < G.nodeNum; v++)
		visit[v] = 0;
	for (v = 0; v < G.nodeNum; v++)
	{
		if (!visit[v])
			DFS(G, v);
	}
}

/***************������ȱ���*************/
int visitBFS[maxSize];
void BFS(ALGraph G,int v)
{
	EdgeNode *p;
	int que[maxSize], front = 0, rear = 0;   //���ж���ļ�д��
	int j;
	printf("%d ", G.adjlist[v].vertex);
	visitBFS[v] = 1;
	rear = (rear + 1) % maxSize;     //��ǰ����v�������
	que[rear] = v;
	while (front!=rear)     //�ӿ�ʱ�������
	{
		front = (front + 1) % maxSize;     //�������
		j = que[front];
		p = G.adjlist[j].edgenext;    //pָ����Ӷ���j�ĵ�һ����
		while (p != NULL)
		{
			if (visitBFS[p->adjvex] == 0)
			{
				printf("%d", p->adjvex);
				visitBFS[p->adjvex] = 1;
				rear = (rear + 1) % maxSize;   //�ö������
				que[rear] = p->adjvex;
			}
			p = p->next;
		}
	}
}

void BFSTravel(ALGraph G)
{
	int i;
	printf("\n������ȱ���˳��Ϊ��");
	for (i = 0; i < G.nodeNum; i++)
	{
		if (visitBFS[i] == 0)
			BFS(G, i);
	}
}

void main()
{
	ALGraph *G = malloc(sizeof(ALGraph));
	create_Graph(G);
	print_Graph(G);
        DFSTravel(G);
	system("pause");
}
