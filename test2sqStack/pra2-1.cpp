#include "sqStack.h"
#include"SqStack.cpp"
#include "string.h"

/*把10进制转换成对应的N进制,转换结构存入到S中*/
int Convert(long D,char N,Sqstack *S) {
	int bit;
	if(N<2||N>36) return 0;
	/*以下填写正确的程序段*/
	Initstack(S);
	while(D!=0) {
		bit= D % N;
		D /= N;
		Push(S,&bit);
	}
	/*填写结束*/
	return 1;
}

/*括号匹配程序,正确匹配,返回1,不能正确匹配,返回0*/
int Bracket(char *str) {
	/*以下填写正确的程序段*/
	Sqstack S;
	Initstack(&S);
	int e=1;
	int i = 0;
	while(str[i]!=0) {
		if(str[i] == '(')
			Push(&S,&e);
		else if(str[i] == ')') {
			if(StackEmpty(&S))
				return 0;
			else
				Pop(&S,&e);
		}
		i++;
	}
	if(StackEmpty(&S))
		return 1;
	else
		return 0;
	/*填写结束*/
}

/*以下为Bracket1函数,可以处理三种括号匹配,请补充完整程序*/
int Bracket1(char *str ) {
	Sqstack S;
	Initstack(&S);
	int e;
	int e1=1,e2=2,e3=3;
	int i = 0;
	while(str[i]!=0) {
		if(str[i] == '(')
			Push(&S,&e1);
		else if(str[i] == ')') {
			if(StackEmpty(&S))
				return 0;
			else
				Pop(&S,&e);
			if(e!=1)
				return 0;
		}
		if(str[i] == '[')
			Push(&S,&e2);
		else if(str[i] == ']') {
			if(StackEmpty(&S))
				return 0;
			else
				Pop(&S,&e);
			if(e!=2)
				return 0;
		}
		if(str[i] == '{')
			Push(&S,&e3);
		else if(str[i] == '}') {
			if(StackEmpty(&S))
				return 0;
			else
				Pop(&S,&e);
			if(e!=3)
				return 0;
		}
		i++;
	}
	if(StackEmpty(&S))
		return 1;
	else
		return 0;

}

/*以下为对Convert的自动化测试函数,请补充完整程序*/
void ConvertTest(Sqstack *S) {


}


/*菜单*/
char Displaymenu( ) {
	printf("\n1.Test Convert Decimal to N\n");
	printf("2.Test bracket matching problem\n");
	printf("0.Exit program!\n");
	char a;
	cin>>a;
	return a;
}

int main() {
	Sqstack S;
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
				/*以下程序输出Convert的转换结果，请补充完整*/
				while(!StackEmpty(&S)) {
					Pop(&S,&e);
					if(e<10)
						printf("%d",e);
					else {
						printf("%c",e/10+'A');
					}
				}
				/*补充结束*/
			}
		} else if(ch=='2') {
			printf("Please Enter a string:\n");
			fflush(stdin);
			fgets(str,256,stdin);
			/*请把下面空格中的 1 改为正确的关表表达式*/
			if( Bracket1(str)==1 )   {
				printf("String \" ");
				printf("%s\" is right matching!\n",str);
			}   else
				printf("String \"%s\" is not matching!\n",str);
		}
		printf("\n");
	}
	return 1;
}
