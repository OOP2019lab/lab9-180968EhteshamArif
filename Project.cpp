#include"Project.h"
using namespace std;
//overloaded constructor
Project::Project(char* name, int budget, int duration)
{
	this->name=new char[strlen(name)+1];
	for(int i=0;i<strlen(name)+1;i++)
	{
		this->name[i]=name[i];
	}
	this->budget=budget;
	this->duration=duration;
}
//copy constructor
Project::Project(const Project& a)
{
	this->name=new char[strlen(a.name)+1];
	for(int i=0;i<strlen(a.name)+1;i++)
	{
		this->name[i]=a.name[i];
	}
	this->budget=a.budget;
	this->duration=a.duration;
}
//overloaded ostream
ostream& operator<<(ostream& os, const Project& e)
{
	os<<"Project Name :"<<e.name<<endl;
	os<<"Budget :"<<e.budget<<endl;
	os<<"Duration :"<<e.duration<<endl;
	return os;
}
//assignment operator overloaded
const Project &   Project::operator=(const Project& other)
{
	if(name!=nullptr)
	{
		delete name;
	}
	*this=other;
	return *this;
}
//destructor
Project::~Project()
{
	if(name!=nullptr)
	{
		delete name;
	}
	
}
//set function to set budget
void Project::setBudget(int a)
{
	budget=a;
}