/*
*title:顺序栈的基本操作
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define SElemType int

typedef struct{
    SElemType *base;    //定义栈底指针
    SElemType *top;     //定义栈顶指针
    int stacksize;
}SqStack;

void InitStack(SqStack &S,int maxsize){    //初始化栈
    S.base = new SElemType[maxsize];
    if(!S.base){
        cout<<"创建栈失败!"<<endl;
    }
    S.top = S.base;     //top初始化为base,是空栈
    S.stacksize = maxsize;
    cout<<"成功创建了一个最大容量为"<<S.stacksize<<"的顺序栈!"<<endl;
}

void Display(SqStack S){     //打印顺序栈
    cout<<"该顺序栈为:"<<endl;
    cout<<"栈底=>";
    for(int i=0;i<S.stacksize;i++){
        cout<<*S.base++<<" ";
        if(!*S.base || S.top == S.base){
            break;
        }
    }
    cout<<"<=栈顶"<<endl;
}

void Push(SqStack &S,SElemType e){    //入栈
    if(S.top - S.base == S.stacksize){
        cout<<"栈已满，无法插入!"<<endl;
        return;
    }
    *S.top++=e;
}

SElemType Pop(SqStack &S){    //出栈
    if(S.top == S.base){
        cout<<"栈空!"<<endl;
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
    cout<<"实验3_1-------------------顺序栈的基本操作"<<endl<<endl;
    cout<<"请输入对应数字选择操作："<<endl;
    cout<<"1------------------建栈"<<endl;
    cout<<"2------------------入栈"<<endl;
    cout<<"3------------------出栈"<<endl;
    cout<<"4------------------打印顺序栈"<<endl;
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
            cout<<"请输入栈的最大容量:"<<endl;
            cin>>maxsize;
            InitStack(S,maxsize);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 2 :
            cout<<"请输入数据元素,当输入-1时结束:"<<endl;
            int e;
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
            int m;
            cin>>m;
            cout<<"出栈的元素为:"<<endl;
            for(int i= 0;i<m;i++){
                Pop(S);
            }
            cout<<"(先出->后出)"<<endl;
            Display(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 4 :
            Display(S);
            cout<<"请输入对应数字选择操作："<<endl;
            break;
        case 5 :
            cout<<"栈顶元素为: "<<GetTop(S)<<endl;
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
