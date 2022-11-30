#include "sqStack.h"
#include"SqStack.cpp"
#include "string.h"

/*��10����ת���ɶ�Ӧ��N����,ת���ṹ���뵽S��*/
int Convert(long D,char N,Sqstack *S) {
	int bit;
	if(N<2||N>36) return 0;
	/*������д��ȷ�ĳ����*/
	Initstack(S);
	while(D>=N) {
		bit= D % N;
		D /= N;
		Push(S,&bit);
	}
	bit=D;
	Push(S,&bit);
	/*��д����*/
	return 1;
}

/*����ƥ�����,��ȷƥ��,����1,������ȷƥ��,����0*/
int Bracket(char *str) {
	/*������д��ȷ�ĳ����*/
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
	/*��д����*/
}

/*����ΪBracket1����,���Դ�����������ƥ��,�벹����������*/
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

/*����Ϊ��Convert���Զ������Ժ���,�벹����������*/
void ConvertTest(Sqstack *S) {


}


/*�˵�*/
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
				/*���³������Convert��ת��������벹������*/
				while(!StackEmpty(&S)) {
					Pop(&S,&e);
					printf("%d",e);
				}
				/*�������*/
			}
		} else if(ch=='2') {
			printf("Please Enter a string:\n");
			fflush(stdin);
			fgets(str,256,stdin);
			/*�������ո��е� 1 ��Ϊ��ȷ�Ĺر���ʽ*/
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
