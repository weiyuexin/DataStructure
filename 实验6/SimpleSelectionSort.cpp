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

void SelectSort(SqList &L)     //��ѡ������
{
    for(int i=1;i<L.length;++i)
    {
        int k=i;
        for(int j=i+1;j<=L.length;++j)
        {
            if(L.r[j].key<L.r[k].key)
            {
                k=j;           //kָ����������йؼ�����С�ļ�¼
            }
        }
        if(k!=i)
        {
            RedType t=L.r[i];
            L.r[i]=L.r[k];
            L.r[k]=t;
        }
    }
}

int main()
{
    cout<<"ʵ��6------��ѡ������"<<endl;
    SqList L;
    insertList(L);
    cout<<"��ʼ�����˳���Ϊ:"<<endl;
    Display(L);
    SelectSort(L);
    cout<<"��ѡ������������Ϊ:"<<endl;
    Display(L);
    return 0;
}
