/*
*title:˳��ջ�Ļ�������
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define SElemType int

typedef struct{
    SElemType *base;    //����ջ��ָ��
    SElemType *top;     //����ջ��ָ��
    int stacksize;
}SqStack;

void InitStack(SqStack &S,int maxsize){    //��ʼ��ջ
    S.base = new SElemType[maxsize];
    if(!S.base){
        cout<<"����ջʧ��!"<<endl;
    }
    S.top = S.base;     //top��ʼ��Ϊbase,�ǿ�ջ
    S.stacksize = maxsize;
    cout<<"�ɹ�������һ���������Ϊ"<<S.stacksize<<"��˳��ջ!"<<endl;
}

void Display(SqStack S){     //��ӡ˳��ջ
    cout<<"��˳��ջΪ:"<<endl;
    cout<<"ջ��=>";
    for(int i=0;i<S.stacksize;i++){
        cout<<*S.base++<<" ";
        if(!*S.base || S.top == S.base){
            break;
        }
    }
    cout<<"<=ջ��"<<endl;
}

void Push(SqStack &S,SElemType e){    //��ջ
    if(S.top - S.base == S.stacksize){
        cout<<"ջ�������޷�����!"<<endl;
        return;
    }
    *S.top++=e;
}

SElemType Pop(SqStack &S){    //��ջ
    if(S.top == S.base){
        cout<<"ջ��!"<<endl;
    }
    SElemType e;
    e = *--S.top;
    cout<<e<<" ";
}

SElemType GetTop(SqStack S){
    if(S.top != S.base){
        return *(S.top-1);
    }
}

int main(){
    SqStack S;
    int maxsize;
    cout<<"ʵ��3_1-------------------˳��ջ�Ļ�������"<<endl<<endl;
    cout<<"�������Ӧ����ѡ�������"<<endl;
    cout<<"1------------------��ջ"<<endl;
    cout<<"2------------------��ջ"<<endl;
    cout<<"3------------------��ջ"<<endl;
    cout<<"4------------------��ӡ˳��ջ"<<endl;
    cout<<"5------------------ȡջ��Ԫ��"<<endl;
    cout<<"0------------------������������"<<endl;
    int operation;
    while(cin>>operation){

        switch(operation){
        case 0 :
            cout<<"�������н���!"<<endl;
            return 0;
            break;
        case 1 :
            cout<<"������ջ���������:"<<endl;
            cin>>maxsize;
            InitStack(S,maxsize);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 2 :
            cout<<"����������Ԫ��,������-1ʱ����:"<<endl;
            int e;
            while(cin>>e){
                if(e == -1){
                    break;
                }
                Push(S,e);
            }
            cout<<"��ջ�ɹ�!"<<endl;
            Display(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 3 :
            cout<<"�������ջԪ�صĸ���:"<<endl;
            int m;
            cin>>m;
            cout<<"��ջ��Ԫ��Ϊ:"<<endl;
            for(int i= 0;i<m;i++){
                Pop(S);
            }
            cout<<"(�ȳ�->���)"<<endl;
            Display(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 4 :
            Display(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 5 :
            cout<<"ջ��Ԫ��Ϊ: "<<GetTop(S)<<endl;
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        default :
            cout<<"��ѡ��Ĳ��������ڣ�������ѡ��:"<<endl;
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        }
    }
    return 0;
}
