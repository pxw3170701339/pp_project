#include<iostream.h>
#include<stdlib.h>//atof������ͷ�ļ�
#include<stdio.h>//sprintf������ͷ�ļ�
#define MAX 255//�궨�峣��
#include<string.h>
double cmjia(char x[],char y[]);//��������
double cmjian(char x[],char y[]);
double cmcheng(char x[],char y[]);
double cmchu(char x[],char y[]);
double compute(char pstr[]);
double xsd(char x[]);
//������
void main()
{
	do
    {
	double t;//�洢������
	char a[]="0";
	char linshi[MAX];//������ʱ�õ�
    char biaodashi[MAX];//������ű��ʽ
    for(;;)//������ʽ 
	{
		cout<<"������һ����ȷ����ѧ���ʽ������7+8*6�����س�����"<<endl;//������ʽ 
		cin>>biaodashi;
	    if(biaodashi[0]=='*'||biaodashi[0]=='/') 
			cout<<"������ı��ʽ��������������"<<endl;//�ж����ַ��Ƿ�Ϊ*/���������ʾ����𷵻���������
		else break;
	}
	if(biaodashi[0]=='-'||biaodashi[0]=='+')//�ж����ַ��Ƿ�Ϊ+-������Ǹ��ַ�ǰ���ַ�0
	{   
		strcat(a,biaodashi);
		strcpy(biaodashi,a);
	}
	strcpy(linshi,biaodashi);
    t=compute(linshi);//����
	cout<<"�������ǣ�"<<biaodashi<<'='<<t<<endl;//������
	}while(1);//�����귵�أ���������
    
	
}
//�Զ��庯��
double xsd(char x[])//�ж��Ƿ���С���㣬�����ַ���ת��Ϊ������
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
double cmjia(char x[],char y[])//�������ַ��ӷ���������double��ֵ
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a+b;
	return c;
}
double cmjian(char x[],char y[])//�������ַ�������������double��ֵ
{
	double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a-b;
	return c;
}
double cmcheng(char x[],char y[])//�������ַ��˷���������double��ֵ
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a*b;
	return c;
}
double cmchu(char x[],char y[])//�������ַ�������������double��ֵ
{
    double a,b;
	a=xsd(x);
	b=xsd(y);
	double c=a/b;
	return c;
}
double compute(char pstr[])//
{
	char strleft[MAX],strright[MAX],coml[MAX],comr[MAX],com[MAX],ysf;//ysf���������
	double comzhi,zhi;//comzhi������;�����ֵ��com����comzhi����Ӧ���ַ���
    int n=0;
	//����˳�
	for(int i=0;i<strlen(pstr);i++)
	{
		if(pstr[i]=='*'||pstr[i]=='/')
		{
			ysf=pstr[i]; 
			//����ȡ���Ҫ���������coml�͸�����ǰ���ַ���strleft
            for(int j=i-1;j>=0;j--)
			{
				if(pstr[j]=='-'||pstr[j]=='+')
				{
					for(int k=0;k<=j;k++) strleft[k]=pstr[k];
					strleft[k]='\0';//��ȡ���Ҫ��������ǰ���ַ���strleft
				    for(k=j+1,n=0;k<i;k++,n++) coml[n]=pstr[k];
					coml[n]='\0';//��ȡ���Ҫ���������coml
					break;
				}
				else
				for(int k=0;k<i;k++) 
				{
					coml[k]=pstr[k]; 
					strleft[0]='\0';
				}
			}
			//��ȡ�ұ�Ҫ���������comr�͸����ݺ���ַ��� strright
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
			 if(ysf=='*')//�����*
			 {
				 comzhi=cmcheng(coml,comr);
				 sprintf(com,"%.3f",comzhi);
			}
			else//�����/
			{
				comzhi=cmchu(coml,comr);
				sprintf(com,"%.3f",comzhi);
			}
			strcat(strleft,com);//������ǰ���ַ����������ַ�����
			strcat(strleft,strright);//�����ݺ���ַ����������ַ�����
	        strcpy(pstr,strleft);//�滻pstr
		}//�����Ҳ�����
	}
	//���ҼӼ�
	for(i=0;i<strlen(pstr);i++)
	{
		if(pstr[i]=='+'||pstr[i]=='-')
		{
			ysf=pstr[i];
		 //����ȡ���Ҫ���������coml
			for(int k=0;k<i;k++) coml[k]=pstr[k];
			coml[k]='\0';
			//��ȡ�ұ�Ҫ��������ݺ͸����ݺ���ַ��� strright
			    
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
	
	//û�ҵ���˵��ȫ��+-����������
	zhi=atof(pstr);
	return zhi;
}ʽ