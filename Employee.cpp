#include"Employee.h"
using namespace std;
//overloaded constructor
Employee::Employee(char* name, const Address& a):add(a)
{
	noofproj=0;
	ar=nullptr;
	this->emp_name=new char[strlen(name)+1];
	for(int i=0;i<strlen(name)+1;i++)
	{
		emp_name[i]=name[i];
	}
}
//copy constructor
Employee::Employee(const Employee& e):add(e.add)
{
	emp_name=new char[strlen(e.emp_name)+1];
	for(int i=0;i<strlen(e.emp_name)+1;i++)
	{
		emp_name[i]=e.emp_name[i];
	}
}
//overloaded ostream
ostream& operator<<(ostream& os, const Employee& e)
{
	os<<"Employee name :"<<e.emp_name<<endl;
	cout<<e.add;
	os<<"Projects :";
	for(int i=1;i<=e.noofproj;i++)
	{
		os<<*e.ar[i]<<endl;
	}
	return os;
}
//assignment operator overloaded
const Employee &Employee::operator=(const Employee& other)
{
	if(emp_name!=nullptr)
	{
		delete emp_name;
	}
	add = other.add;
	*this=other;
	return *this;
}
//destructor
Employee::~Employee()
{
	delete emp_name;
	if(ar!=nullptr)
	{
		for(int i=1;i<=noofproj;i++)
	   {
		   if(ar[i]!=nullptr)
		   {
			    delete ar[i];
		   }
		  
	   }
	}
	delete [] ar;
}
//function to add project
void Employee::addProject(Project const * arr)
{
	bool check=false;
	for(int i=0;i<noofproj;i++)
	{
		if(ar[i]==arr)
		{
			cout<<"Exists"<<endl;
			check=true;
		}
	}
	if(check==false)
	{
		if(ar==nullptr)
		{
			ar=new Project*[2];
			ar[0]=new Project(*arr);
			noofproj++;
		}
		else if(noofproj<2)
		{
			ar[1]=new Project(*arr);
			noofproj++;
		}
	}
}
//function to remove project
void Employee::removeProject(Project const * arr)
{
	for(int i=1;i<=noofproj;i++)
	{
		if(ar[i]==arr)
		{
			delete ar[i];
			ar[i]=nullptr;
			for(int j=i;j<=noofproj-1;j++)
			{
				ar[i]=ar[i+1];
			}
			noofproj--;
		}
	}
}