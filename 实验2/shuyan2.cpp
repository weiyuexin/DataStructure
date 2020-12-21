/*
*title:单链表的基本操作
*writer:weiyuexin
*data:2020-10-1
*/

#include<bits/stdc++.h>

using namespace std;

#define ElemType int

typedef struct LNode{
    ElemType data;    //数据域
    struct LNode *next;   //指针域
}LNode ,*LinkList;

void CreateList(LinkList &L){   //初始化单链表
    int n;
    cout<<"请输入单链表的长度："<<endl;
    cin>>n;
    L = new LNode;
    L->next = NULL;
    LinkList r = L;
    cout<<"请输入单链表的数据元素："<<endl;
    for(int i = 0;i < n; i++){
        LinkList p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void Display(LinkList &L){      //打印单链表
    cout<<"该单链表为："<<endl;
    LinkList p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void FindElem(LinkList &L,int i){    //检索元素
    LinkList p1 = L;
    LinkList p2 = L;
    int n=0;
    bool sign = false;
    while(p1){
        if(i == p1->data){
            sign = true;
            break;
        }
        p1 = p1->next;
    }
    if(sign){
        cout<<"值为"<<i<<"的元素是表中的第";
        while(p2){
            if(i == p2->data){
                cout<<n<<", ";
            }
            p2 = p2->next;
            n++;
        }
        cout<<"个元素"<<endl;
    }else{
        cout<<"单链表中不存在该元素!"<<endl;
    }
}

void GetElem(LinkList L,int i){    //定位元素
    LinkList p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i){
        cout<<"您输入的位置已超出单链表的长度!"<<endl;
        return ;
    }
    cout<<"该单链表第"<<i<<"个元素为 "<<p->data<<endl;
}

void Insert(LinkList &L,int j,ElemType e){     //插入元素
    LinkList p = L;
    int i = 0;
    //判断要插入的位置是否存在
    LinkList p1 = L->next;
    int length = 0;
    while(p1){
        length++;
        p1 = p1->next;
    }
    if(j>length){
        cout<<"要插入的位置不存在!"<<endl;
        return;
    }
    while(p && i<j - 1){
        p = p->next;
        ++i;
    }

    LNode *s = new LNode();    //生成新节点
    s->data = e;        //将数据域置为e
    s->next = p->next;
    p->next = s;

    cout<<"插入成功!"<<endl;
}

void Delete(LinkList &L,int x){     //删除指定位置的元素
    LinkList p = L;
    int i =0;
    while(p && i < x - 1){
        p = p->next;
        ++i;
    }
    if(!p->next || i>x-1){
        cout<<"删除位置不合理!"<<endl;
    }
    LNode *r = new LNode();
    r = p->next;
    p->next = r->next;
    delete r;
    cout<<"删除成功!"<<endl;
}

void DeleteElem(LinkList &L,ElemType e){    //删除指定值的元素
	LinkList p = L;
	bool sign = false;
	while(p){
		if(p->next->data == e){
            LNode *r = new LNode();
            r = p->next;
            p->next = r->next;
            delete r;
            sign = true;
		}
		p = p->next;
	}
	if(sign){
		cout<<"删除成功!"<<endl;
		Display(L);
	}else{
		cout<<"要删除的元素不存在!"<<endl;
		return;
	}
}
void Merger(){     //两个有序单链表的归并
    LinkList LA;
    LinkList LB;
    LinkList LC;

    LNode *pa = new LNode();
    LNode *pb = new LNode();
    LNode *pc = new LNode();

    cout<<"请初始化单链表PA:"<<endl;
    CreateList(LA);
    Display(LA);
    cout<<"请初始化单链表PB:"<<endl;
    CreateList(LB);
    Display(LB);

    pa = LA->next;    //pa和pb的初值分别指向两个表的第一个节点
    pb = LB->next;
    LC = LA;      //用LA的头结点作为LC的头结点
    pc = LC;      //pc的初值指向LC的头结点

    while(pa && pb){    //当LA和LB均未达到表尾时，选取最小值插入LC后
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;   //将非空表的剩余片段插入到PC之后
    delete LB;           //释放LB的头结点
    cout<<"这两个单链表归并完毕!"<<endl;
    Display(LC);
}

int main(){
    LinkList L;

    cout<<"实验2 ----- 单链表的基本操作"<<endl<<endl;
    cout<<"请输入数字选择对应的操作!!!"<<endl;
    cout<<"1---------创建单链表"<<endl;
    cout<<"2---------显示单链表"<<endl;
    cout<<"3---------检索单链表中的数据元素"<<endl;
    cout<<"4---------定位显示单链表元素"<<endl;
    cout<<"5---------插入元素"<<endl;
    cout<<"6---------删除指定位置的元素"<<endl;
    cout<<"7---------删除指定值的元素"<<endl;
    cout<<"8---------求两个有序单链表的并归"<<endl;
    cout<<"0---------结束程序"<<endl;
    cout<<"请输入你要进行的操作："<<endl;

    int operation;

    while(cin>>operation){
        switch(operation){
            case 0 :   //结束程序
                cout<<"程序运行结束!!!"<<endl;
                return 0;
            case 1 :    //创建单链表
                CreateList(L);
                Display(L);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 2 :    //显示单链表
                Display(L);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 3 :     //查找数据元素
                cout<<"请输入要检索的元素："<<endl;
                int n;
                cin>>n;
                FindElem(L,n);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 4 :      //查看指定位置的元素
                cout<<"请输入要查看的元素位置："<<endl;
                int i;
                cin>>i;
                GetElem(L,i);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 5 :      //插入元素
                cout<<"请输入要插入的位置:"<<endl;
                int j;
                cin>>j;
                cout<<"请输入要插入的元素:"<<endl;
                ElemType e;
                cin>>e;
                Insert(L,j,e);
                Display(L);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 6 :       //删除指定位置的元素
                cout<<"请输入要删除元素的位置:"<<endl;
                int x;
                cin>>x;
                Delete(L,x);
                Display(L);
                cout<<"请输入你要进行的操作："<<endl;
                break;
            case 7 :       //删除指定值的元素
            	cout<<"请输入要删除的元素:"<<endl;
            	ElemType ee;
            	cin>>ee;
            	DeleteElem(L,ee);
            	cout<<"请输入你要进行的操作："<<endl;
                break;
            case 8 :
                Merger();
                cout<<"请输入你要进行的操作："<<endl;
                break;
            default :
                cout<<"您选择的操作无效,请重新选择:"<<endl;
                break;
        }
    }
    return 0;
}
