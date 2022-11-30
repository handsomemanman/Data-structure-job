#include "LkStack.h"

/***********测试数据结构的正确性*****************/
int displayMenu()
{
	printf("\n1.InitStack\n");
	printf("2.Display all Element\n");
	printf("3.Pop a Element\n");
	printf("4.Push a Element\n");
	printf("5.Display length of Stack\n");
	printf("6.Destroy your stack!\n");
	printf("0.Exit my program!\n");
	fflush(stdin);
	return getchar();
}

int main( )
{
  LkStack L;
  ElemType e;
  char ch;
  
  Initstack(&L);
  while((ch=displayMenu())!='0')
  {
   switch(ch)
   {
   case '1':   Initstack(&L);
               printf("Stack L has been Initial!\n");
			   break;
   case '2':   printf("Element of Stack is as follow:\n");
               Traversstack(&L); 
               break;
   case '3':   if(Pop(&L,&e))
                 printf("Element %d is Poped just now!",e);
	           else
				 printf("Failed,Stack is empty!\n");
               Traversstack(&L);
               break;
   case '4':   printf("Please input a element you want insert!\n");
               scanf("%d",&e);
               Push(&L,&e);
			   Traversstack(&L);
               break;
   case '5':   printf("Length of Stack is %d\n",GetLength(&L));
               break;
   case '6':   Clearstack(&L);
               printf("Your Stack is destroyed!\n");
               break;
   }
 }
 Clearstack(&L);
}
