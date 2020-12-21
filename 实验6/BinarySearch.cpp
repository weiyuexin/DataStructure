#include<iostream>

using namespace std;

#define KeyType int
#define InfoType int
typedef struct{
    KeyType key;           //关键字域
    InfoType otherinfo;   //其他域
}ElemType;

typedef struct{
   ElemType *R;       //存储空间基地址
   int length;         //长度
}SSTable;

void Create(SSTable &ST)
{
    int n;
    cout<<"请输入表的长度；"<<endl;
    cin>>n;
    cout<<"请输入"<<n<<"个元素"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ST.R[i].key;
    }
    ST.length = n;
    cout<<"初始化成功!"<<endl;
}

void Display(SSTable ST)
{
    for(int i=0;i<ST.length;i++)
    {
        cout<<ST.R[i].key<<" ";
    }
    cout<<endl;
}

int Search_Bin(SSTable ST,KeyType key,int &num){      //折半查找
    int low=1,high=ST.length;     //置查找区间初值
    num=0;
    while(low<=high)
    {
        num++;
        int mid=(low+high)/2;
        if(key == ST.R[mid].key)      //找到待查元素
        {
            //cout<<"共查找"<<num<<"次"<<endl;
            return mid;
        }
        else if(key<ST.R[mid].key)
            high = mid-1;    //继续前一个子表进行查找
        else
            low=mid+1;       //继续后一个子表进行查找
    }
    //cout<<"共查找"<<num<<"次"<<endl;
    return 0;
}

int main(){
    SSTable ST;
    cout<<"实验6---------------折半查找"<<endl;
    Create(ST);
    cout<<"初始化后的序列为："<<endl;
    Display(ST);
    int key;    //查找关键字
    cout<<"请输入待查元素:"<<endl;
    while(cin>>key){
        int num;
        if(Search_Bin(ST,key,num)==0)
        {
            cout<<key<<"不存在于该表"<<endl;
            cout<<"共查找了"<<num<<"次"<<endl;
        }else{
            cout<<key<<"是该表中的第"<<Search_Bin(ST,key,num)+1<<"个元素"<<endl;
            cout<<"共查找了"<<num<<"次"<<endl;
        }
        cout<<"请输入待查元素:"<<endl;
    }
    return 0;
}
