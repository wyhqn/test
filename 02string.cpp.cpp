#include<iostream>
using namespace std;

#include"algorithm"
#include"string"

//string�ĳ�ʼ��
void main21()
{
	string s1="aaaaaa";
	string s2("ddddddddddd");
	string s3=s2;//ͨ���������캯������ʼ������s3
	string s4(10,'a');
	
	cout<<"s1"<<s1<<endl;
	cout<<"s2"<<s2<<endl;
	cout<<"s3"<<s3<<endl;
	cout<<"s4"<<s4<<endl;
}

//string�ı���
void main22()
{
	string s1="sadsfadfv";
	
	cout<<endl;
	//������
	for(string::iterator it=s1.begin();it!=s1.end();it++)
	{
		cout<<*it<<"  ";
	}
	try
	{
	for(int i=0;i<s1.length()+3;i++)
	{
		cout<<s1.at(i)<<"  ";  //at()�����׳��쳣
	}
	}
	catch(...)
	{
		cout<<"�����쳣"<<endl;
	}

	//���鷽ʽ
	try
	{
	for(int i=0;i<s1.length()+3;i++)  //�����쳣 ���������׳��쳣���������ж�
	{                                 //���Խ�����at()��Ϊ�˲������쳣
		cout<<s1[i]<<"  ";
	}
	}
	catch(...)
	{
		cout<<"���鷢���쳣"<<endl;
	}
}

//�ַ�ָ�����ַ�����ת��
void main23()
{
	string s1="aaadddddddddd";
	//1 s1===>char*
	printf("s1:%s \n",s1.c_str());

	//2 char*===>string

	//3  s1�����ݿ�����buf��
	char buf[128]={0};
	s1.copy(buf,3,0);//��0���ַ���ʼ����3���ַ���buf�У�������û�и����\0
	cout<<"buf:"<<buf<<endl;
}

//�����ַ���
void main24()
{
	string s1="aaaaaaaaaaa";
	string s2="xxxxxxxxx";
	s1=s1+s2;
	cout<<s1<<endl;
	string s3="33333";
	string s4="4444";
	string s5=s3+s4;
	cout<<s5<<endl;
	string s6;
	s6.append(s5);
	cout<<"s6:"<<s6<<endl;
}

//�ַ����Ĳ��Һ��滻
void main25()
{
	string s1="ni hao 11 skaj ni22 djoanijswesk 33";
	//��һ�γ���ni ��index
	int index=s1.find("ni",0); //λ���±��0��ʼ
	cout<<"index:"<<index<<endl;

	//����2����ni ÿһ�γ��ֵ������±�
	/*int offindex=s1.find("ni",0);
	while(offindex!=string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		offindex++;
		offindex=s1.find("ni",offindex);
	}*/

	//����2����Сд���ɴ�д
	int offindex=s1.find("ni",0);
	while(offindex!=string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		s1.replace(offindex,2,"NI");//��indexλ��ɾ���ַ���ɾ��2�����á�NI���滻
		offindex++;
		offindex=s1.find("ni",offindex);
	}
	cout<<"s1�滻��Ľ��:"<<s1<<endl;

	//����2��ǿ��
	string s3="aaa bbb ccc ddd ";
	s3.replace(0,3,"AAA");
	cout<<"s3�滻֮��Ľ��:"<<s3<<endl;
}

//�ضϣ�����ɾ��)�Ͳ���
void main26()
{
	string s1="hello1 hello2 hello3";
	string::iterator it=find(s1.begin(),s1.end(),'1');
	if(it!=s1.end())
	{
		s1.erase(it);
	}
	cout<<"s1ɾ��1�Ľ��:"<<s1<<endl;

	//�������ַ�������ɾ��
	s1.erase(s1.begin(),s1.end());
	cout<<"s1ȫ��ɾ��:"<<s1<<endl;
	cout<<"s1����:"<<s1.length()<<endl;

	//����
	string s2="bbbbbbbbbbbbbbbb";
	s2.insert(0,"AAA");
	//transform(s2.begin(),s2.end(),s2.begin(),toupper);
	cout<<"ͷ�巨����:"<<s2<<endl;
	s2.insert(s2.length(),"CCC");
	//transform(s2.begin(),s2.end(),s2.begin(),tolower);
	cout<<"β�巨���룺"<<s2<<endl;
}

void main27()
{
	string s1="AAAbbb";
	transform(s1.begin(),s1.end(),s1.begin(),toupper);//tolower
	cout<<s1<<endl;


}
int main()
{
	/*main21();
	main22();*/
	/*main23();
	main24();*/
	//main25();
	main26();
	//main27();
	system("pause");
	return 0;
}