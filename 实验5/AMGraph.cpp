#include<iostream>

using namespace std;

#define MaxInt 32767    //表示极大值，即∞
#define MAXNUM  100        //最大顶点数
#define OK 1
#define ERROR 0
typedef char VerTextType;   //假设顶点的数据类型为字符型
typedef int ArcType;      //假设边的权值类型为整型

char visited[MAXNUM];

typedef struct{
	char vexs[MAXNUM];  //顶点表
	int arcs[MAXNUM][MAXNUM];//邻接矩阵
	int vexnum,arcnum;     //图的当前点数和边数
}AMGraph; //邻接矩阵的数据类型

int LocateVex(AMGraph G,char v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i] == v)return i;
	}
	return 0;
}
int CreateUNG(AMGraph &G){ //创建无向图
	char v1,v2;
	cout<<"请输入顶点数和边数：";
	cin>>G.vexnum>>G.arcnum;

	cout<<"请依次输入顶点：";
	for(int i = 0; i < G.vexnum; i++)cin>>G.vexs[i];

	for(int j = 0; j < G.vexnum; j++)
		for(int i = 0; i < G.vexnum; i++)
			G.arcs[j][i] = 0;         //初始化邻接矩阵
	cout<<"请依次输入邻接边："<<endl;
	for(int k = 0; k < G.arcnum; k++){
		cin>>v1>>v2;            //输入有边的两个顶点
		int i = LocateVex(G,v1);     //确定v1v2在数组中的位置
		int j = LocateVex(G,v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
	}
	return 1;
}

void DFS_AM(AMGraph G,int i){ //深度优先遍历邻接矩阵
	cout<<G.vexs[i];
	visited[i] = 1;
	for(int j = 0; j < G.vexnum; j++){
		if(G.arcs[i][j] == 1 && !visited[j])DFS_AM(G,j);
	}
}

int main(){
	AMGraph G;
	CreateUNG(G);
	cout<<"初始化后的邻接矩阵为:"<<endl;
	for(int j = 0; j < G.vexnum; j++){            //输出邻接矩阵
		for(int i = 0; i < G.vexnum; i++)
			cout<<G.arcs[j][i]<<"  ";
		cout<<endl;
	}
	cout<<endl<<"深度优先遍历输出为：";
	DFS_AM(G,0);	//第二个参数决定深度优先遍历从哪里开始
}


