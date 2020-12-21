
#include <stdio.h>
#include <malloc.h>
#define  MaxVertices 100
#define maxSize 100
typedef int VertexType;

/***********边表**********/
typedef struct EdgeNode
{
	int adjvex;      //该边所指向结点的位置
	struct EdgeNode *next;   //该边所指向下一个结点的指针
}EdgeNode;

/*********顶点表*********/
typedef struct
{
	int vertex;     //顶点的信息
	EdgeNode *edgenext;  //指向第一条边的指针
}VertexNode,AdjList[MaxVertices];

/*********图结构********/
typedef struct
{
	AdjList adjlist;
	int nodeNum;  //顶点数
	int edgeNum;  //边数
}ALGraph;

/*********创建图********/
void create_Graph(ALGraph *G)
{
	int i, j;
	int vi, vj;     //相连接的两个顶点序号
	EdgeNode *s;    //边表结点

	printf("请输入顶点数和边数(以空格隔开)");
	scanf_s("%d%d", &G->nodeNum, &G->edgeNum);

	printf("建立顶点表:\n");
	for (i = 0; i < G->nodeNum; i++)
	{
		//getchar();
		printf("请输入第%d个顶点的信息:", i + 1);
		scanf_s("%d", &G->adjlist[i].vertex);
		G->adjlist[i].edgenext = NULL;
	}

	printf("\n打印顶点下标及顶点数据:\n");
	for (i = 0; i < G->nodeNum; i++)
		printf("顶点下标：%d  顶点数据:%d\n ", i,G->adjlist[i]);

	printf("\n建立边表:\n");
	for (i = 0; i < G->edgeNum; i++)
	{
		printf("请输入相连接的两个顶点下标:");
		scanf_s("%d%d",&vi,&vj );
		s = malloc(sizeof(EdgeNode));
		s->adjvex = vj;    //边所指向结点的位置
		s->next = G->adjlist[vi].edgenext;
		G->adjlist[vi].edgenext = s;

		//输入(0 1)在1中也把0编入
		s = malloc(sizeof(EdgeNode));
		s->adjvex = vi;    //边所指向结点的位置
		s->next = G->adjlist[vj].edgenext;
		G->adjlist[vj].edgenext = s;
	}
}

/***********打印边表*********/
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

/**************深度优先遍历**************/
int visit[maxSize];
void DFS(ALGraph G,int v)
{
	EdgeNode *p;
	if (v<0 || v>=G.nodeNum)
		return;
	else
	{
		visit[v] = 1;     //已经访问标记
		printf("%d ", G.adjlist[v].vertex);
		p = G.adjlist[v].edgenext;   //p指向顶点v的第一条边
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
	printf("深度优先遍历顺序为：");
	for (v = 0; v < G.nodeNum; v++)
		visit[v] = 0;
	for (v = 0; v < G.nodeNum; v++)
	{
		if (!visit[v])
			DFS(G, v);
	}
}

/***************广度优先遍历*************/
int visitBFS[maxSize];
void BFS(ALGraph G,int v)
{
	EdgeNode *p;
	int que[maxSize], front = 0, rear = 0;   //队列定义的简单写法
	int j;
	printf("%d ", G.adjlist[v].vertex);
	visitBFS[v] = 1;
	rear = (rear + 1) % maxSize;     //当前顶点v进入队列
	que[rear] = v;
	while (front!=rear)     //队空时遍历完成
	{
		front = (front + 1) % maxSize;     //顶点出队
		j = que[front];
		p = G.adjlist[j].edgenext;    //p指向出队顶点j的第一条边
		while (p != NULL)
		{
			if (visitBFS[p->adjvex] == 0)
			{
				printf("%d", p->adjvex);
				visitBFS[p->adjvex] = 1;
				rear = (rear + 1) % maxSize;   //该顶点进队
				que[rear] = p->adjvex;
			}
			p = p->next;
		}
	}
}

void BFSTravel(ALGraph G)
{
	int i;
	printf("\n广度优先遍历顺序为：");
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
