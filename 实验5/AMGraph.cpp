#include<iostream>

using namespace std;

#define MaxInt 32767    //��ʾ����ֵ������
#define MAXNUM  100        //��󶥵���
#define OK 1
#define ERROR 0
typedef char VerTextType;   //���趥�����������Ϊ�ַ���
typedef int ArcType;      //����ߵ�Ȩֵ����Ϊ����

char visited[MAXNUM];

typedef struct{
	char vexs[MAXNUM];  //�����
	int arcs[MAXNUM][MAXNUM];//�ڽӾ���
	int vexnum,arcnum;     //ͼ�ĵ�ǰ�����ͱ���
}AMGraph; //�ڽӾ������������

int LocateVex(AMGraph G,char v){
	for(int i = 0; i < G.vexnum; i++){
		if(G.vexs[i] == v)return i;
	}
	return 0;
}
int CreateUNG(AMGraph &G){ //��������ͼ
	char v1,v2;
	cout<<"�����붥�����ͱ�����";
	cin>>G.vexnum>>G.arcnum;

	cout<<"���������붥�㣺";
	for(int i = 0; i < G.vexnum; i++)cin>>G.vexs[i];

	for(int j = 0; j < G.vexnum; j++)
		for(int i = 0; i < G.vexnum; i++)
			G.arcs[j][i] = 0;         //��ʼ���ڽӾ���
	cout<<"�����������ڽӱߣ�"<<endl;
	for(int k = 0; k < G.arcnum; k++){
		cin>>v1>>v2;            //�����бߵ���������
		int i = LocateVex(G,v1);     //ȷ��v1v2�������е�λ��
		int j = LocateVex(G,v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = 1;
	}
	return 1;
}

void DFS_AM(AMGraph G,int i){ //������ȱ����ڽӾ���
	cout<<G.vexs[i];
	visited[i] = 1;
	for(int j = 0; j < G.vexnum; j++){
		if(G.arcs[i][j] == 1 && !visited[j])DFS_AM(G,j);
	}
}

int main(){
	AMGraph G;
	CreateUNG(G);
	cout<<"��ʼ������ڽӾ���Ϊ:"<<endl;
	for(int j = 0; j < G.vexnum; j++){            //����ڽӾ���
		for(int i = 0; i < G.vexnum; i++)
			cout<<G.arcs[j][i]<<"  ";
		cout<<endl;
	}
	cout<<endl<<"������ȱ������Ϊ��";
	DFS_AM(G,0);	//�ڶ�����������������ȱ��������￪ʼ
}


