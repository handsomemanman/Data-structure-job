#include "sqStack.h"
/***********测试数据结构的正确性*****************/
int displayMenu() {
	printf("\n1.Createstack\n");
	printf("2.Display stack\n");
	printf("3.Delete a Element\n");
	printf("4.Insert a Element\n");
	printf("5.Display stack length\n");
	printf("6.Clear your stack\n");
	printf("0.Exit my program!\n");
	fflush(stdin);
	return getchar();
}

int main( ) {
	Sqstack L;
	char ch;
	ElemType e;

	Initstack(&L);
	while((ch=displayMenu())!='0') {
		switch(ch) {
			case '1':
				printf("Now Create a stack!\n");
				Createstack(&L);
				break;
			case '2':
				printf("Your stack is \n");
				Traversstack(&L);
				break;
			case '3':
				Pop(&L,&e);
				printf("Element %d has been Poped!\n",e);
				printf("Display stack after you has deleted!\n");
				Traversstack(&L);
				break;
			case '4':
				printf("Please Enter a Elemnet value you will Push!\n");
				scanf("%d",&e);
				Push(&L,&e);
				Traversstack(&L);
				break;
			case '5':
				printf("Length of stack is %d\n",L.top);
				break;
			case '6':
				Clearstack(&L);
				if(StackEmpty(&L))
					printf("Now,you stack has no element!!\n");
				break;
			case '0':
				printf("your program is running is over!\n");
				break;
			default:
				printf("Please Enter charactor between '0'and '8'!\n");
				break;
		}
	}
	return 0;
}
