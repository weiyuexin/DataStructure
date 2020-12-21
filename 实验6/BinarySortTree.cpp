#include<iostream>

using namespace std;

#define KeyType int
#define InfoType int

typedef struct{
    KeyType key;   //�ؼ���
    InfoType otherinfo;   //����������
}ElemType;

typedef struct BSTNode{
    ElemType data;        //ÿ���ڵ������������ؼ����������������
    struct BSTNode *lchild,*rchild;    //���Һ���
}BSTNode,*BSTree;

void InsertBST(BSTree &T,ElemType e)     //�����������Ĳ���
{
    //������������T�в����ڹؼ���e.key������Ԫ��ʱ��������Ԫ��
    if(!T)
    {         //�ҵ�����λ�ã��ݹ����
        BSTNode* S = new BSTNode;   //�����½ڵ�*S
        S->data = e;     //�½ڵ����������Ϊe
        S->lchild = S->rchild =NULL;    //�½ڵ���ΪҶ�ӽڵ�
        T=S;     //���½ڵ�*S���ӵ����ҵ��Ĳ���λ��
    }else if(e.key<T->data.key)
    {
        InsertBST(T->lchild,e);     //��*S���뵽������
    }else{
        InsertBST(T->rchild,e);    //��*S���뵽������
    }
}

void CreateBST(BSTree &T)      //��������������
{
    //���ζ���һ���ػ���Ϊkey�Ľڵ㣬���˽ڵ���������������
    T=NULL;    //������������ʼ��Ϊ��
    ElemType e;

    cout<<"�����������Ԫ��(-1����):"<<endl;
    cin>>e.key;
    while(e.key!=-1)
    {
        InsertBST(T,e);
        cin>>e.key;
    }
    cout<<"���������������ɹ�!"<<endl;
}

BSTree SearchBST(BSTree T,KeyType key,int &num)    //�����������ĵݹ����
{
    num++;
    if((!T) || key==T->data.key)
        return T;
    else if(key<T->data.key)
        return SearchBST(T->lchild,key,num);
    else
        return SearchBST(T->rchild,key,num);
}

void InOrderTraverse(BSTree T){    //�������������
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data.key<<" ";
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    cout<<"ʵ����-------------------����������"<<endl;
    BSTree T;
    CreateBST(T);        //��������������
    cout<<"��ʼ����Ķ����������������������Ϊ:"<<endl;
    InOrderTraverse(T);   //�����������������
    cout<<endl;
    cout<<"������Ҫ���ҵĹؼ��֣�"<<endl;
    KeyType key;   //Ҫ���ҵĹؼ���
    while(cin>>key){
        int num=0;    //���Ҵ���
        if(SearchBST(T,key,num) == NULL)
        {
            cout<<"�����������в����ڸ�Ԫ��!"<<endl;
            cout<<"��������"<<num<<"��"<<endl;
        }else{
            cout<<"���ҳɹ���"<<endl;
            cout<<"��������"<<num<<"��"<<endl;
        }
        cout<<"������Ҫ���ҵĹؼ��֣�"<<endl;
    }
    return 0;
}
