/*
*title:链栈的基本操作
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

void InitStack(LinkStack &S){     //初始化链栈
    S = NULL;
    cout<<"栈S初始化成功!"<<endl;
}

void Display(LinkStack S){
    LinkStack p = S;
    cout<<"该链栈为:"<<endl;
    cout<<"栈顶=> ";
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<" <=栈底"<<endl;
}

ElemType Pop(LinkStack &S,ElemType ee){
    if(S == NULL){
        cout<<"栈已空，无法在进行删除操作!"<<endl;
        return 0;
    }
    StackNode *p = new StackNode();
    ee = S->data;
    p = S;
    S = S->next;
    delete p;
    return ee;
}

void Push(LinkStack &S,ElemType e){     //入栈
    StackNode *p = new StackNode();
    p ->data = e;
    p ->next = S;
    S = p;
}

int main(){
    LinkStack S;

    cout<<"实验3_2-------------------链栈的基本操作"<<endl<<endl;
    cout<<"请输入对应数字选择操作："<<endl;
    cout<<"1------------------初始化链栈"<<endl;
    cout<<"2------------------入栈"<<endl;
    cout<<"3------------------出栈"<<endl;
    cout<<"4------------------打印链栈"<<endl;
    cout<<"5------------------取栈顶元素"<<endl;
    cout<<"0------------------结束程序运行"<<endl;
    int operation;
    while(cin>>operation){

        switch(operation){
        case 0 :
            cout<<"程序运行结束!"<<endl;
            return 0;
            break;
        case 1 :
            InitStack(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 2 :
            cout<<"请输入数据元素,当输入-1时结束:"<<endl;
            ElemType e;
            while(cin>>e){
                if(e == -1){
                    break;
                }
                Push(S,e);
            }
            cout<<"入栈成功!"<<endl;
            Display(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 3 :
            cout<<"请输入出栈元素的个数:"<<endl;
            int n;
            cin>>n;
            cout<<"出栈的元素依次为: ";
            for(int i=0;i<n;i++){
                ElemType ee;
                cout<<Pop(S,ee)<<" ";
            }
            cout<<endl;
            Display(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 4 :
            Display(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 5 :
            cout<<"栈顶元素为:"<<S->data<<endl;
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        default :
            cout<<"您选择的操作不存在，请重新选择:"<<endl;
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        }
    }
    return 0;
}
