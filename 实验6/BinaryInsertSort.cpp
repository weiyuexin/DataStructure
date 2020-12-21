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

void BInsertSort(SqList &L)     //�۰��������
{
    for(int i=2;i<=L.length;++i)
    {
        L.r[0]=L.r[i];     //��������ļ�¼�ݴ浽������
        int low=1,high=i-1;     //��������ĳ���
        while(low<=high)
        {
            int m=(low+high)/2;     //�۰�
            if(L.r[0].key<L.r[m].key)
                high=m-1;               //�������ǰһ���ӱ�
            else
                low=m+1;             //������ں�һ���ӱ�
        }
         for(int j=i-1;j>=high+1;--j)   //��¼����
            L.r[j+1]=L.r[j];
         L.r[high+1] = L.r[0];
    }
}

int main()
{
    cout<<"ʵ��6------�۰��������"<<endl;
    SqList L;
    insertList(L);
    cout<<"��ʼ�����˳���Ϊ:"<<endl;
    Display(L);
    BInsertSort(L);
    cout<<"�۰��������������Ϊ:"<<endl;
    Display(L);
    return 0;
}
