#include "LKStack.h"
#include "LKStack.cpp"
#include "string.h"
using namespace std;

/*把10进制转换成对应的 N 进制,转换结构存入到S中*/
int Convert(long D,char N,LkStack *S) {
	/*以下填写正确的程序段*/
	long d = D;
	int *e;
	while(d>=N) {
		*e = d % N;
		Push(S, e);
		d /= N;
	}
	*e=d;
	Push(S, e);

	/*填写结束*/
	return 1;
}

/*括号匹配程序,正确匹配,返回1,不能正确匹配,返回0*/
int Bracket(char *str) {
	/*以下填写正确的程序段*/
	LkStack S;
	
	int *e;
	*e = 1;
	int i = 0;
	while(str[i]!=0) {
		if(str[i] == '(')
			Push(&S,e);
		else if(str[i] == ')') {
			if(StackEmpty(&S))
				return 0;
			else
				Pop(&S,e);
		}
		i++;
	}
	if(StackEmpty(&S))
		return 1;
	else
		return 0;

	/*填写结束*/
}

/*菜单*/
char Displaymenu( ) {
	printf("\n1.Test Convert Decimal to N\n");
	printf("2.Test bracket matching problem\n");
	printf("0.Exit program!\n");
	return getchar();
}

int main( ) {
	LkStack S;
	int N,e;
	char ch;
	int x;
	char str[256]= {0};

	while((ch=Displaymenu())!='0') {
		if(ch=='1') {
			printf("Please Enter a long number:\n");
			scanf("%ld",&x);
			printf("Please Enter a Decimal N(2<N<36):\n");
			scanf("%d",&N);
			if(Convert(x,N,&S)) {
				printf("Result of convert:\n");
				while(!StackEmpty(&S)) {
					Pop(&S,&e);
					printf("%d",e);
				}
			}
		} else if(ch=='2') {
			printf("Please Enter a string:\n");
			fflush(stdin);
			fgets(str,256,stdin);
			if(Bracket(str)==1)
				printf("String \" %s \" is right matching!\n",str);
			else
				printf("String \" %s \" is not matching!\n",str);
		}
		printf("\n");
		fflush(stdin);
	}
	return 1;
}
