#include<iostream>
using namespace std;

#include"algorithm"
#include"string"

//string的初始化
void main21()
{
	string s1="aaaaaa";
	string s2("ddddddddddd");
	string s3=s2;//通过拷贝构造函数来初始化对象s3
	string s4(10,'a');
	
	cout<<"s1"<<s1<<endl;
	cout<<"s2"<<s2<<endl;
	cout<<"s3"<<s3<<endl;
	cout<<"s4"<<s4<<endl;
}

//string的遍历
void main22()
{
	string s1="sadsfadfv";
	
	cout<<endl;
	//迭代器
	for(string::iterator it=s1.begin();it!=s1.end();it++)
	{
		cout<<*it<<"  ";
	}
	try
	{
	for(int i=0;i<s1.length()+3;i++)
	{
		cout<<s1.at(i)<<"  ";  //at()可以抛出异常
	}
	}
	catch(...)
	{
		cout<<"发生异常"<<endl;
	}

	//数组方式
	try
	{
	for(int i=0;i<s1.length()+3;i++)  //发生异常 不像外面抛出异常引起程序的中断
	{                                 //所以建议用at()，为了不发生异常
		cout<<s1[i]<<"  ";
	}
	}
	catch(...)
	{
		cout<<"数组发生异常"<<endl;
	}
}

//字符指针与字符串的转换
void main23()
{
	string s1="aaadddddddddd";
	//1 s1===>char*
	printf("s1:%s \n",s1.c_str());

	//2 char*===>string

	//3  s1的内容拷贝到buf中
	char buf[128]={0};
	s1.copy(buf,3,0);//从0号字符开始拷贝3个字符到buf中，，其中没有给你加\0
	cout<<"buf:"<<buf<<endl;
}

//连接字符串
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

//字符串的查找和替换
void main25()
{
	string s1="ni hao 11 skaj ni22 djoanijswesk 33";
	//第一次出现ni 的index
	int index=s1.find("ni",0); //位置下标从0开始
	cout<<"index:"<<index<<endl;

	//案例2：求ni 每一次出现的数组下标
	/*int offindex=s1.find("ni",0);
	while(offindex!=string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		offindex++;
		offindex=s1.find("ni",offindex);
	}*/

	//案例2：把小写换成大写
	int offindex=s1.find("ni",0);
	while(offindex!=string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		s1.replace(offindex,2,"NI");//从index位置删除字符，删除2个并用“NI”替换
		offindex++;
		offindex=s1.find("ni",offindex);
	}
	cout<<"s1替换后的结果:"<<s1<<endl;

	//案例2加强版
	string s3="aaa bbb ccc ddd ";
	s3.replace(0,3,"AAA");
	cout<<"s3替换之后的结果:"<<s3<<endl;
}

//截断（区间删除)和插入
void main26()
{
	string s1="hello1 hello2 hello3";
	string::iterator it=find(s1.begin(),s1.end(),'1');
	if(it!=s1.end())
	{
		s1.erase(it);
	}
	cout<<"s1删除1的结果:"<<s1<<endl;

	//把整个字符串都给删了
	s1.erase(s1.begin(),s1.end());
	cout<<"s1全部删除:"<<s1<<endl;
	cout<<"s1长度:"<<s1.length()<<endl;

	//插入
	string s2="bbbbbbbbbbbbbbbb";
	s2.insert(0,"AAA");
	//transform(s2.begin(),s2.end(),s2.begin(),toupper);
	cout<<"头插法插入:"<<s2<<endl;
	s2.insert(s2.length(),"CCC");
	//transform(s2.begin(),s2.end(),s2.begin(),tolower);
	cout<<"尾插法插入："<<s2<<endl;
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