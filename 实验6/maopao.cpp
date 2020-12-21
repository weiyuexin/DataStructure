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

void BubbleSort(SqList &L)
{
    int m = L.length-1;
    int flag = 1;      //flag �������ĳһ�������Ƿ�������

    //while((m>0) && (flag == 1))
    for(int i=0;i<m;i++)
    {
        flag =0;            //flag ��Ϊ0����û�з����������򲻻ᷢ����һ������
        for(int j=0;j<=m-i;j++)
        {
            if(L.r[j].key>L.r[j+1].key)
            {
                flag =1;    //����������flag��Ϊ1
                RedType t =L.r[j];    //����ǰ��������¼
                L.r[j]=L.r[j+1];
                L.r[j+1]=t;
            }
        }
        if(flag == 0)
            break;
    }
}

int main()
{
    cout<<"ʵ��6------ð������"<<endl;
    SqList L;
    insertList(L);
    cout<<"��ʼ�����˳���Ϊ:"<<endl;
    Display(L);
    BubbleSort(L);
    cout<<"ð������������Ϊ:"<<endl;
    Display(L);
    return 0;
}
