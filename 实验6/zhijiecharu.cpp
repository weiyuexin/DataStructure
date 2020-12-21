/*
*author��weiyuexin 
*date: 2020/12/18
*/ 

#include<iostream>

using namespace std;

#define MAXSIZE 100

typedef int KeyType;    //����ؼ�������Ϊ����
typedef int InfoType;
typedef struct{      //��¼����
    KeyType key;         //�ؼ�����
    InfoType otherinfo;     //����������
}RedType;
typedef struct{
    RedType r[MAXSIZE+1];       //r[0]���û������ڱ���Ԫ
    int length;       //˳�����
}SqList;

void insertList(SqList &L)
{
    cout<<"������Ԫ�ظ���:"<<endl;
    int n;
    cin>>n;
    cout<<"������"<<n<<"��Ԫ��(�Կո����):"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>L.r[i].key;
    }
    L.length=n;
    cout<<n<<"��Ԫ�ز��뵽˳���ɹ�!"<<endl;
}

void Display(SqList L)
{
    for(int i=1;i<=L.length;i++)
    {
        cout<<L.r[i].key<<" ";
    }
    cout<<endl;
}

void InsertSort(SqList &L)     //ֱ�Ӳ�������
{
    for(int i=2;i<=L.length;++i)
    {
        int j;
        if(L.r[i].key<L.r[i-1].key)
        {
            L.r[0] = L.r[i];     //��������ļ�¼�ݴ浽������
            L.r[i] = L.r[i-1];    //r[i-1]����
            for(j=i-2;L.r[0].key<L.r[j].key;--j)
                L.r[j+1] = L.r[j];
            L.r[j+1] = L.r[0];
        }
    }
}

int main()
{
    cout<<"ʵ��6------ֱ�Ӳ�������"<<endl;
    SqList L;
    insertList(L);
    cout<<"��ʼ�����˳���Ϊ:"<<endl;
    Display(L);
    InsertSort(L);
    cout<<"ֱ�Ӳ�������������Ϊ:"<<endl;
    Display(L);
    return 0;
}
