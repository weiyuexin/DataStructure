/*
*title:��ջ�Ļ�������
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define ElemType int

typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S){     //��ʼ����ջ
    S = NULL;
    cout<<"ջS��ʼ���ɹ�!"<<endl;
}

void Display(LinkStack S){
    LinkStack p = S;
    cout<<"����ջΪ:"<<endl;
    cout<<"ջ��=> ";
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<" <=ջ��"<<endl;
}

ElemType Pop(LinkStack &S,ElemType ee){
    if(S == NULL){
        cout<<"ջ�ѿգ��޷��ڽ���ɾ������!"<<endl;
        return 0;
    }
    StackNode *p = new StackNode();
    ee = S->data;
    p = S;
    S = S->next;
    delete p;
    return ee;
}

void Push(LinkStack &S,ElemType e){     //��ջ
    StackNode *p = new StackNode();
    p ->data = e;
    p ->next = S;
    S = p;
}

int main(){
    LinkStack S;

    cout<<"ʵ��3_2-------------------��ջ�Ļ�������"<<endl<<endl;
    cout<<"�������Ӧ����ѡ�������"<<endl;
    cout<<"1------------------��ʼ����ջ"<<endl;
    cout<<"2------------------��ջ"<<endl;
    cout<<"3------------------��ջ"<<endl;
    cout<<"4------------------��ӡ��ջ"<<endl;
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
            InitStack(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 2 :
            cout<<"����������Ԫ��,������-1ʱ����:"<<endl;
            ElemType e;
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
            int n;
            cin>>n;
            cout<<"��ջ��Ԫ������Ϊ: ";
            for(int i=0;i<n;i++){
                ElemType ee;
                cout<<Pop(S,ee)<<" ";
            }
            cout<<endl;
            Display(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 4 :
            Display(S);
            cout<<"�������Ӧ����ѡ�������"<<endl;
            break;
        case 5 :
            cout<<"ջ��Ԫ��Ϊ:"<<S->data<<endl;
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
