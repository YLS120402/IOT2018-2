
#include <iostream>

#include <string.h>

#include <windows.h>



using namespace std;



typedef long DataType; //可以是其他数据类型



//定义学生单链表结构体

typedef struct node

{

	DataType data;//学生学号

	char   name[20];//学生姓名

	double   score;//学生成绩分数

	struct node* Next;//指向下一个学生的指针

}LinkList,*PLinkList;



/* ****************创建空单链表***********************/

PLinkList Create_Linklist()

{

	PLinkList PLinkListPoint;

	PLinkListPoint=new LinkList;//为PLinkList分配一个LinkList的空间

	if(!PLinkListPoint)

	{

		cout<<"分配内存失败！"<<endl;

		return (NULL);

	}

	else

	{

		PLinkListPoint->Next=NULL;

		return (PLinkListPoint);//返回创建节点信息

	}

}

/* ****************头插法创建并填充链表****************/

PLinkList Create_ReverseLinkList()

{

	PLinkList H,preview;

	int NodeCount=0;

	H=new LinkList;

	if(!H)

	{

		cout<<"分配内存失败！"<<endl;

		return (NULL);

	}

	else

	{

		H->Next=NULL; 

	}

	cout<<"\t请输入你想创建链表结点总数：";

	cin>>NodeCount;

	cout<<"\t\t请输入各结点数据\n\t（注：头插法创建，链表存储数据将与实际数据相反）";



	for(int i=1;i<=NodeCount;i++)

	{	

        cout<<endl;

		preview=new LinkList;

		cout<<"输入学号: "; 

		cin>>preview->data; 

		cout<<"输入姓名: "; 

		cin>>preview->name;

		cout<<"输入分数: "; 

		cin>>preview->score;

		preview->Next=H->Next; 

		H->Next=preview; 

	}

	return (H);

}

// ****************尾插法创建并填充链表****************/

PLinkList Create_SeqLinkList()

{  

	PLinkList H,preview,current; 

	int NodeCount=0; 

	H=new LinkList;//申请一个LinkList的头结点

	if(!H)

	{

		cout<<"分配内存失败！"<<endl;

		return (NULL);

	}

	else

    	H->Next=NULL; 

	cout<<"\t请输入你想创建链表结点总数：";

	cin>>NodeCount;

	cout<<"\t\t请输入各结点数据\n\t（注：尾插法创建,链表顺序与实际数据相同)";

	preview=H;            //将H赋给preview

	for(int i=1;i<=NodeCount;i++)

	{

        cout<<endl; 

		current=new LinkList;

		if(!current)

		{

			cout<<"分配空间失败！"<<endl;

			return (NULL);

		}

		preview->Next=current; 

		cout<<"输入学号:"; 

		cin>>current->data; 

		cout<<"输入姓名:"; 

		cin>>current->name;

		cout<<"输入分数:";

		cin>>current->score;

		current->Next=NULL; //尾为节点指向空

		preview=current; 

	}

	return (H);

}



// ****************销毁链表操作****************************/

int  Destory_LinkList(PLinkList* PLinkListPoint)

{

	if(!*PLinkListPoint)

	{

		cout<<"表不存在！"<<endl;

		return (0);

	}

	PLinkList p=*PLinkListPoint,q;

	while(p)

	{

		q=p;

		p=p->Next;

		delete q;

	}

	return (1);

}

/*******************更新单链表*******************************/

int alter_LinkList(PLinkList PLinkListPoint, DataType DataX,float Grade)

{

	PLinkList p=PLinkListPoint;

	if(!PLinkListPoint)

	{

		cout<<"表不存在！"<<endl;

		return (-1);

	}

	if(p)

	{

		while(p && p->data!=DataX)

			p=p->Next;

		if(!p)

		{

			cout<<"\n\n\n\n\t\t此表中，没有该数据！"<<endl;

			return (NULL);

		}

		p->score=Grade;//将grade赋值给相应学号的成绩

		return 1;

	}

	else

	{

		cout<<"表不存在!"<<endl;

		return (0);

	}

}

/**************删除指定值的学生的信息********************/   

int Del_LinkList(PLinkList PLinkListPoint, DataType DataX)

{  

 //返回值：-1表不存在，1成功

	PLinkList p=PLinkListPoint->Next;

	PLinkList q,r;

	r=PLinkListPoint;

	if(!PLinkListPoint)

	{

		cout<<"表不存在！"<<endl;

		return (-1);

	}

	if(p)

	{

		while(p && p->data!=DataX)

		{

			p=p->Next;

			r=r->Next;//用于找到值相等的上一个节点

		}

		if(!p)

		{

			cout<<"\n\n\n\n\t\t此表中，没有该数据！"<<endl;

			return (NULL);

		}

		q=p;

		r->Next=q->Next;

		delete q;

		return (NULL);

		

	}

	else

	{

		cout<<"表不存在!"<<endl;

		return (0);

	}



}

/************************按元素检索操作**********************/

PLinkList Locate_LinkList(PLinkList PLinkListPoint ,DataType DataX)

{

	PLinkList p=PLinkListPoint;

	if(p)

	{

		while(p && p->data!=DataX)

        p=p->Next;

		if(p)

		return(p);

		else

		{

			cout<<"\n\n\n\n\t\t此表中，没有该数据！"<<endl;

			return (NULL);

		}

             

	}

	else

	{

		cout<<"表不存在!"<<endl;

		return (NULL);

	}

}

/********************逆置操作****************************/

PLinkList Reverse_LinkList(PLinkList PLinkListPoint)

{

	if(!PLinkListPoint)

	{

		return (NULL);

	}

	PLinkList p,q;

	p=PLinkListPoint->Next;

	PLinkListPoint->Next=NULL;

	while(p)

	{

		q=p;

		p=p->Next;

		q->Next=PLinkListPoint->Next;

		PLinkListPoint->Next=q;

	}

	return (PLinkListPoint);

}

/*******************检查单链表是否为空******************/

int CheckEmpty_LinkList(PLinkList PLinkListPoint)

{

	if(!PLinkListPoint)

		return (-1);

	if(!PLinkListPoint->Next)

		return (1);

	else

		return (0);

}

/******************** 输出链表操作******************/

void Print_LinkListData(PLinkList H)

{

	if(!H)

	{

		cout<<"链表不存在！"<<endl;

	}

	PLinkList current=H;

	cout<<"操作后的单链表为:"<<endl; 

	cout<<"学 号\t\t姓 名\t\t成 绩 "<<endl;

	cout<<endl;

	current=current->Next;

	while(current)

	{

		cout<<current->data<<"\t\t"<<current->name<<"\t\t"<<current->score<<endl;;

		cout<<endl; 

		current=current->Next;

	}

	cout<<endl;

	system("pause");

}



int main()

{

	int i=-1,j=-1,choice;

	long data=0,number;

    float grade;

	PLinkList PLinkListPoint1,PLinkListPoint2;

	PLinkListPoint1=Create_Linklist();

	while(1)

	{

		system("cls");

        cout<<" **单链表操作及其实现(注意必须先选择操作 1 或者 2 建立单链表)**"<<endl;

        cout<<"\t┏———————-—M  E  N  U————————-┓ \n";	

		cout<<"\t│                                            │"<<endl;

        cout<<"\t│      1.头插法创建并填充链表                │"<<endl;

        cout<<"\t│      2.尾插法创建并填充链表                │"<<endl;

        cout<<"\t│      3.按元素检索操作                      │"<<endl;

        cout<<"\t│      4.按学号删除结点操作                  │"<<endl;

        cout<<"\t│      5.修改指定学号学生的成绩              │"<<endl;

        cout<<"\t│      6.逆置链表操作                        │"<<endl;

        cout<<"\t│      7.销毁链表操作                        │"<<endl;

        cout<<"\t│      0.退出程序                            │"<<endl;

        cout<<"\t│                                            │"<<endl;

        cout<<"\t┗—————-请输入你想要实现的操作:-————-┛"<<endl;

		cout<<"\t\t\t\t";

        //cout<<"请输入你想要实现的操作: ";

		cin>>choice;

        system("cls");

		switch(choice)

		{

		case 1:

		case 2:

			if(choice==1)

			{

                cout<<"\n\n\t\t\t1.头插法创建并填充链表"<<endl<<endl;

				PLinkListPoint1=Create_ReverseLinkList();

				Print_LinkListData(PLinkListPoint1);

				break;

			}

			else

			{

                cout<<"\n\n\t\t\t2.尾插法创建并填充链表"<<endl<<endl;

				PLinkListPoint1=Create_SeqLinkList();

				Print_LinkListData(PLinkListPoint1);

				break;

			}  

		case 3:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t链表为空，请选择操作1、2建立单链表"<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t3.按元素检索操作"<<endl<<endl;

			cout<<"请输入你要查找学生的学号:  ";

			cin>>j;

			PLinkListPoint2=Locate_LinkList(PLinkListPoint1,j);

			if(PLinkListPoint2)

			{

				cout<<"要查找的元素为: "<<PLinkListPoint2->data<<"\t";

				cout<<PLinkListPoint2->name<<"\t";

				cout<<PLinkListPoint2->score<<endl;

			}

			j=-1;

			system("pause");

			break;

		case 4:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t链表为空，请选择操作1、2建立单链表"<<endl<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t4.按位置删除结点操作"<<endl<<endl;

			cout<<"请输入你想删除学生的学号：";

			cin>>i;

			if(Del_LinkList(PLinkListPoint1 , i)==1)

			{

				cout<<"删除成功！"<<endl;

			}

			i=-1;

			Print_LinkListData(PLinkListPoint1);

			//system("pause");

			break;

		case 5:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t链表为空，请选择操作1、2建立单链表"<<endl;

				system("pause");

				break;

			}

             cout<<"\n\n\t\t\t5.修改指定学号学生的成绩"<<endl<<endl;

             cout<<"请输入要修改的学生的学号和成绩:  ";

             cin>>number>>grade;

             alter_LinkList(PLinkListPoint1,number,grade);

             Print_LinkListData(PLinkListPoint1);

			 //system("pause");

             break;

		case 6:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t链表为空，请选择操作1、2建立单链表"<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t6.逆置链表操作"<<endl<<endl;

			Reverse_LinkList(PLinkListPoint1);

			cout<<"\t\t\t逆置链表成功 ！"<<endl;

			Print_LinkListData(PLinkListPoint1);

			//system("pause");

			break;

		case 7:

			if(CheckEmpty_LinkList(PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t链表为空，请选择操作1、2建立单链表"<<endl<<endl;

				system("pause");

				break;

			}

            cout<<"\n\n\t\t\t7.销毁链表操作"<<endl<<endl; 

			if(Destory_LinkList(&PLinkListPoint1))

			{

				cout<<"\n\n\t\t\t销毁单链表成功！"<<endl;

			}

			system("pause");

			break;

			//退出程序

		case 0:

			exit(0);

			break;

		default:

			cout<<"\n\n\t\t\t输入参数错误！"<<endl;

			system("pause");

			break;

   }

 }

 return 0;

}