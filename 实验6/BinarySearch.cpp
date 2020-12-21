#include<iostream>

using namespace std;

#define KeyType int
#define InfoType int
typedef struct{
    KeyType key;           //�ؼ�����
    InfoType otherinfo;   //������
}ElemType;

typedef struct{
   ElemType *R;       //�洢�ռ����ַ
   int length;         //����
}SSTable;

void Create(SSTable &ST)
{
    int n;
    cout<<"�������ĳ��ȣ�"<<endl;
    cin>>n;
    cout<<"������"<<n<<"��Ԫ��"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ST.R[i].key;
    }
    ST.length = n;
    cout<<"��ʼ���ɹ�!"<<endl;
}

void Display(SSTable ST)
{
    for(int i=0;i<ST.length;i++)
    {
        cout<<ST.R[i].key<<" ";
    }
    cout<<endl;
}

int Search_Bin(SSTable ST,KeyType key,int &num){      //�۰����
    int low=1,high=ST.length;     //�ò��������ֵ
    num=0;
    while(low<=high)
    {
        num++;
        int mid=(low+high)/2;
        if(key == ST.R[mid].key)      //�ҵ�����Ԫ��
        {
            //cout<<"������"<<num<<"��"<<endl;
            return mid;
        }
        else if(key<ST.R[mid].key)
            high = mid-1;    //����ǰһ���ӱ���в���
        else
            low=mid+1;       //������һ���ӱ���в���
    }
    //cout<<"������"<<num<<"��"<<endl;
    return 0;
}

int main(){
    SSTable ST;
    cout<<"ʵ��6---------------�۰����"<<endl;
    Create(ST);
    cout<<"��ʼ���������Ϊ��"<<endl;
    Display(ST);
    int key;    //���ҹؼ���
    cout<<"���������Ԫ��:"<<endl;
    while(cin>>key){
        int num;
        if(Search_Bin(ST,key,num)==0)
        {
            cout<<key<<"�������ڸñ�"<<endl;
            cout<<"��������"<<num<<"��"<<endl;
        }else{
            cout<<key<<"�Ǹñ��еĵ�"<<Search_Bin(ST,key,num)+1<<"��Ԫ��"<<endl;
            cout<<"��������"<<num<<"��"<<endl;
        }
        cout<<"���������Ԫ��:"<<endl;
    }
    return 0;
}
