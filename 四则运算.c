#include<iostream.h>
#include<stdlib.h>//atof函数的头文件
#include<stdio.h>//sprintf函数的头文件
#define MAX 255//宏定义常量
#include<string.h>
double cmjia(char x[],char y[]);//声明函数
double cmjian(char x[],char y[]);
double cmcheng(char x[],char y[]);
double cmchu(char x[],char y[]);
double compute(char pstr[]);
double xsd(char x[]);
//主函数
void main()
{
	do
    {
	double t;//存储运算结果
	char a[]="0";
	char linshi[MAX];//计算临时用的
    char biaodashi[MAX];//用来存放表达式
    for(;;)//输入表达式 
	{
		cout<<"请输入一个正确的数学表达式，形如7+8*6，按回车结束"<<endl;//输入表达式 
		cin>>biaodashi;
	    if(biaodashi[0]=='*'||biaodashi[0]=='/') 
			cout<<"您输入的表达式有误，请重新输入"<<endl;//判断首字符是否为*/，如果是提示错误别返回重新输入
		else break;
	}
	if(biaodashi[0]=='-'||biaodashi[0]=='+')//判断首字符是否为+-，如果是给字符前加字符0
	{   
		strcat(a,biaodashi);
		strcpy(biaodashi,a);
	}
	strcpy(linshi,biaodashi);
    t=compute(linshi);//计算
	cout<<"运算结果是："<<biaodashi<<'='<<t<<endl;//输出结果
	}while(1);//计算完返回，接着输入
    
	
}
//自定义函数
double xsd(char x[])//判断是否有小数点，并把字符型转化为浮点型
{
	for(int i=0;i<strlen(x);i++)
		if(x[i]=='.')
		{
            double num = 0.0;
            sscanf(x, "%f", &num);//
			return num;
		}
        else
	    return atof(x);
}
double cmjia(char x[],char y[])//计算两字符加法，并返回double型值
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a+b;
	return c;
}
double cmjian(char x[],char y[])//计算两字符减法，并返回double型值
{
	double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a-b;
	return c;
}
double cmcheng(char x[],char y[])//计算两字符乘法，并返回double型值
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a*b;
	return c;
}
double cmchu(char x[],char y[])//计算两字符除法，并返回double型值
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a/b;
	return c;
}
double compute(char pstr[])//
{
	char strleft[MAX],strright[MAX],coml[MAX],comr[MAX],com[MAX],ysf;//ysf代表运算符
	double comzhi,zhi;//comzhi代表中途计算的值，com代表comzhi所对应的字符型
    int n=0;
	//先算乘除
	for(int i=0;i<strlen(pstr);i++)
	{
		if(pstr[i]=='*'||pstr[i]=='/')
		{
			ysf=pstr[i]; 
			//　获取左边要计算的数据coml和该数据前的字符串strleft
            for(int j=i-1;j>=0;j--)
			{
				if(pstr[j]=='-'||pstr[j]=='+')
				{
					for(int k=0;k<=j;k++) strleft[k]=pstr[k];
					strleft[k]='\0';//获取左边要计算数据前的字符串strleft
				    for(k=j+1,n=0;k<i;k++,n++) coml[n]=pstr[k];
					coml[n]='\0';//获取左边要计算的数据coml
					break;
				}
				else
				for(int k=0;k<i;k++) 
				{
					coml[k]=pstr[k]; 
					strleft[0]='\0';
				}
			}
			//获取右边要计算的数据comr和该数据后的字符串 strright
			for(j=i+1;j<=strlen(pstr);j++)
		    {
				if(pstr[j]=='-'||pstr[j]=='+'||pstr[j]=='*'||pstr[j]=='/'||pstr[j]=='\0')
				{
					for(int k=0,n=j;k<strlen(pstr)-i-1;k++,n++) strright[k]=pstr[n];
					strright[k]='\0';
				    for(k=i+1,n=0;k<j;k++,n++) comr[n]=pstr[k];
					comr[n]='\0';
					break;
				 }
			 }
			 if(ysf=='*')//如果是*
			 {
				 comzhi=cmcheng(coml,comr);
				 sprintf(com,"%.3f",comzhi);
			}
			else//如果是/
			{
				comzhi=cmchu(coml,comr);
				sprintf(com,"%.3f",comzhi);
			}
			strcat(strleft,com);//把数据前的字符和运算后的字符连接
			strcat(strleft,strright);//把数据后的字符和运算后的字符连接
	        strcpy(pstr,strleft);//替换pstr
		}//重新找操作符
	}
	//再找加减
	for(i=0;i<strlen(pstr);i++)
	{
		if(pstr[i]=='+'||pstr[i]=='-')
		{
			ysf=pstr[i];
		 //　获取左边要计算的数据coml
			for(int k=0;k<i;k++) coml[k]=pstr[k];
			coml[k]='\0';
			//获取右边要计算的数据和该数据后的字符串 strright
			    
		    for(int j=i+1;j<=strlen(pstr);j++)
			{
			    if(pstr[j]=='-'||pstr[j]=='+'||pstr[j]=='\0')
				{
					for(int k=0,n=j;k<=strlen(pstr)-j;k++,n++) strright[k]=pstr[n];
			 	    strright[k]='\0';
				    for(k=i+1,n=0;k<j;k++,n++) comr[n]=pstr[k];
				    comr[n]='\0';
				    break;
				}
			}
		    if(ysf=='+')
			{
				comzhi=cmjia(coml,comr);
			    sprintf(com,"%.3f",comzhi);
			}
	        else
			{
				comzhi=cmjian(coml,comr);
			    sprintf(com,"%.3f",comzhi);
			}
			strcat(com,strright);
            strcpy(pstr,com);
		}
	}
	
	//没找到，说明全部+-都计算完了
	zhi=atof(pstr);
	return zhi;
}式