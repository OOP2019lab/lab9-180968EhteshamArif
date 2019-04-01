#include"Address.h"
using namespace std;
//overloaded constructor
Address::Address(char* House_Number, char* Street_Name, char * City,char* County)
{
	this->city=new char[strlen(City)+1];
	this->house_Number=new char[strlen(House_Number)+1];
	this->county=new char[strlen(County)+1];
	this->street_Name=new char[strlen(Street_Name)+1];
	for(int i=0;i<strlen(City)+1;i++)
	{
		this->city[i]=City[i];
	}
	for(int i=0;i<strlen(County)+1;i++)
	{
		this->county[i]=County[i];
	}
	for(int i=0;i<strlen(House_Number)+1;i++)
	{
		this->house_Number[i]=House_Number[i];
	}
	for(int i=0;i<strlen(Street_Name)+1;i++)
	{
		this->street_Name[i]=Street_Name[i];
	}
}
//copy constructor
Address::Address(const Address& a)
{
	this->city=new char[strlen(a.city)+1];
	this->house_Number=new char[strlen(a.house_Number)+1];
	this->county=new char[strlen(a.county)+1];
	this->street_Name=new char[strlen(a.street_Name)+1];
	for(int i=0;i<strlen(a.city)+1;i++)
	{
		city[i]=a.city[i];
	}
	for(int i=0;i<strlen(a.county)+1;i++)
	{
		county[i]=a.county[i];
	}
	for(int i=0;i<strlen(a.house_Number)+1;i++)
	{
		house_Number[i]=a.house_Number[i];
	}
	for(int i=0;i<strlen(a.street_Name)+1;i++)
	{
		street_Name[i]=a.street_Name[i];
	}
}
//ostream overloaded
ostream& operator<<(ostream& os, const Address& a)
{
	os<<"City :"<<a.city<<endl;
	os<<"Country :"<<a.county<<endl;
	os<<"House Number :"<<a.house_Number<<endl;
	os<<"Street Name :"<<a.street_Name<<endl;
	return os;
}
//Assignment operator overloading
const Address &   Address::operator=(const Address& other)
{
	if(house_Number!=nullptr||street_Name!=nullptr||county!=nullptr||city!=nullptr)
	{
		delete city;
		delete street_Name;
		delete county;
		delete house_Number;
	}
	Address::Address(other);
	return *this;
}
//destructor
Address::~Address()
{
	if(house_Number!=nullptr)
	{
		delete house_Number;
	}
	if(city!=nullptr)
	{
		delete city;
	}
	if(street_Name!=nullptr)
	{
		delete street_Name;
	}
	if(county!=nullptr)
	{
		delete county;
	}
}