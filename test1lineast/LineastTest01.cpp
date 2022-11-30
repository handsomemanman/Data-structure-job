#include "Lineast01.h"
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

/***********测试数据结构的正确性*****************/
int displayMenu() {
	printf("\n1.CreateList\n");
	printf("2.Display List\n");
	printf("3.Delete a Element\n");
	printf("4.Insert a Element\n");
	printf("5.Display List length\n");
	printf("6.Change i'st Element value\n");
	printf("7.Get i'st Element Value\n");
	printf("8.Clear your List\n");
	/*以下补充第9个操作的菜单项*/
	printf("9. reverse your List\n");

	/*补充结束*/
	printf("0.Exit my program!\n");
	fflush(stdin);
	return getchar();
}

int main() {
	SqList L;
	char ch;
	ElemType e;
	int i;

	while((ch=displayMenu())!='0') {
		switch(ch) {
			case '1':
				printf("Now Create a List!\n");
				CreateList(&L);
				break;
			case '2':
				printf("Your List is \n");
				TraversList(&L);
				break;
			case '3':
				printf("Please Enter a No. of Element you want to delete!\n");
				scanf("%d",&i);
				DeleteElem(&L,i);
				TraversList(&L);
				break;
			case '4':
				printf("Please Enter a Elemnet value and Position you will Insert!(e i)\n");
				scanf("%d%d",&e,&i);
				InsertElem(&L,i,&e);
				TraversList(&L);
				break;
			case '5':
				printf("Length of List is %d\n",GetLength(&L));
				break;
			case '6':
				printf("Please Enter a Element value and position you will Change!(e i)\n");
				scanf("%d%d",&e,&i);
				SetElem(&L,i,&e);
				TraversList(&L);
				break;
			case '7':
				printf("Get i'st Element value\nPlease Enter i:\n");
				scanf("%d",&i);
				e=-1;
				GetElem(&L,i,&e);
				printf("data[%d]=%d\n",i,e);
				break;
			case '8':
				ClearList(&L);
				if(GetLength(&L)==0)
					printf("Now,you list has no element!!\n");
				break;
				/*  以下补充对功能9的测试代码*/
			case '9':
				TraversList(Reverse(&L));
				break;

				/*  补充结束 */
			case '0':
				printf("your program is running is over!\n");
				break;
			default:
				printf("Please Enter charactor between '0'and '8'!\n");
				break;
		}
	}
}
