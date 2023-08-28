#include <iostream>
#include<string>
#include <map>
#include <iterator>
using namespace std;


struct S
{
    int PRN;
    string name;
    string dob;
    float DSA,DECO,DM,AM,OOP,HSMC;
    string email;
};

int main()
{
  struct S data[10];
  data[1].PRN=120;
  data[1].name="Aryan";
  data[1].dob="12-08-1999";
  data[1].email="aryan@gmail.com";
  data[1].DSA=88;
  data[1].DECO=96;

  data[2].PRN=121;
  data[2].name="Harsh";
  data[2].dob="25-11-2005";
  data[2].email="harsh@gmail.com";
  data[2].DSA=85;
  data[2].DECO=95;

  data[3].PRN=122;
  data[3].name="Riya";
  data[3].dob="12-02-2015";
  data[3].email="riya@gmail.com";
  data[3].DSA=78;
  data[3].DECO=86;

  int n=3;
  map<int,S > M;
  map<int,S> :: iterator i;

  M.insert(pair<int, S>(1, data[1]));
  M.insert(pair<int, S>(2, data[2]));
  M.insert(pair<int, S>(3, data[3]));

  float att[10];
  int ch;
  while(1)
    {
  cout<<"*****???????????????????? ???????????????????? ????????????*****\n";
  cout<<"1]Add new student record\n";
  cout<<"2]Display Student records\n";
  cout<<"3]Update Student attandance\n";
  cout<<"4]Search for highest Student attendance\n";
  cout<<"5]Issue Defaulter list\n";
  cout<<"6]Display individual overall Student attendance\n";
  cout<<"7]Display Subject-wise individual student attendance\n";
  cout<<"8]Overall Class attendance\n";
  cout<<"9]Delete Student Details\n";
  cout<<"10]Additional lectures for defaulter students";
  cout<<"11]Exit\n";
  cout<<"\nEnter Choice:\n";
  cin>>ch;
  switch(ch)
    {
      case 1:
        {
        //Adding new student data
        n++;
        cout<<"Enter Student Details:\n";
        cout<<"PRN No.:";
        cin>>data[n].PRN;
        cout<<"Full Name:";
        cin>>data[n].name;
        cout<<"DOB:";
        cin>>data[n].dob;
        cout<<"DSA Attendance:";
        cin>>data[n].DSA;
        cout<<"DECO Attendance:";
        cin>>data[n].DECO;
        cout<<"OOP Attendance:";
        cin>>data[n].OOP;
        cout<<"AM Attendance:";
        cin>>data[n].AM;
        cout<<"DM Attendance:";
        cin>>data[n].DM;
        cout<<"HSMC Attendance:";
        cin>>data[n].HSMC;
        cout<<"Email:";
        cin>>data[n].email;
        M.insert(pair<int, S>(n, data[n]));
        break;
      }

      case 2:
        {
        //display
        for(i=M.begin(); i!=M.end(); i++)
          {
            cout<<"SR NO.\tPRN\tName\tDOB\t\tDSA\tDECO\tOOP\tDM\tAM\tHSMC\n";
            cout<<i->first<<"\t"<<i->second.PRN<<"\t"<<i->second.name<<"\t"<<i->second.dob<<"\t"<<i->second.DSA<<"\t"<<i->second.DECO<<"\t"<<i->second.OOP<<"\t"<<i->second.DM<<"\t"<<i->second.AM<<"\t"<<i->second.HSMC<<"\t"<<i->second.email;
            cout<<"\n";
          }
        break;
      }

      case 3:
        {
          //updating attendance
        int no,j;
        cout<<"Enter PRN Number:";
        cin>>no;
        i=M.begin();
        for(j=0;i!=M.end();i++,j++)
          {
            if(i->second.PRN==no)
              break;
          }
        struct S temp;
        cout<<"Enter new details:\n";
        cout<<"Update Student Attendance:\n";
        cout<<"DSA Attendance:";
        cin>>temp.DSA;
        cout<<"DECO Attendance:";
        cin>>temp.DSA;
        cout<<"DM Attendance:";
        cin>>temp.DM;
        cout<<"AM Attendance:";
        cin>>temp.AM;
        cout<<"OOP Attendance:";
        cin>>temp.OOP;
        cout<<"HSMC Attendance:";
        cin>>temp.HSMC;
        
        M.insert(pair<int, S>(j, temp));
        break;
      }
      
      case 4:
        {
        //highest attendance
        float sum, avg, m1, m2, m3; 
        i=M.begin();
        for(int j=0;i!=M.end();i++, j++)
          {
            sum=i->second.DSA+i->second.DECO+i->second.AM+i->second.OOP+i->second.DM+i->second.HSMC;
            avg=sum/6;
            att[j]=avg;
          }
        for(int j=0;j<10;j++)
          {
            m1=att[0];
            if(att[j]>m1)
              m1=att[j];
          }
        for(int j=0;j<10;j++)
          {
            m2=att[0];
            if(att[j]==m1)
              continue;
            if(att[j]>m2)
              m2=att[j];
          }
        for(int j=0;j<10;j++)
          {
            m3=att[0];
            if(att[j]==m1||att[j]==m2)
              continue;
            if(att[j]>m3)
              m3=att[j];
          }
        cout<<"The Top Three Students with Highest Attendance are:\n";
        cout<<m1<<"\n"<<m2<<"\n"<<m3<<"\n";
        //:-/What now
        break;
          }

      case 5:
        //defaulter list
        { cout<<"Defaulter List";
          
          float sum, avg;
          i=M.begin();
        for(int j=0;i!=M.end();i++, j++)
          {
            sum=i->second.DSA+i->second.DECO+i->second.AM+i->second.OOP+i->second.DM+i->second.HSMC;
            avg=sum/6;
            if(avg<75)
              cout<<i->second.PRN<<"\t"<<i->second.name<<"\t"<<i->second.dob<<"\t"<<i->second.DSA<<"\t"<<i->second.DECO<<"\t"<<i->second.OOP<<"\t"<<i->second.DM<<"\t"<<i->second.AM<<"\t"<<i->second.HSMC<<"\t"<<i->second.email;
            cout<<"\n";              
          }
          break;
        }

      case 6:
        {
         //Display individual overall Student attendance
          int prn;
          cout<<"\nEnter student PRN: ";
          cin>>prn;
          cout<<"PRN\tName\tDOB\t\tDSA\tDECO\tOOP\tDM\tAM\tHSMC\n";
          for(int j=0;i!=M.end();i++,j++)
            {
              if(i->second.PRN==prn)
                cout<<i->second.PRN<<"\t"<<i->second.name<<"\t"<<i->second.dob<<"\t"<<i->second.DSA<<"\t"<<i->second.DECO<<"\t"<<i->second.OOP<<"\t"<<i->second.DM<<"\t"<<i->second.AM<<"\t"<<i->second.HSMC<<"\t"<<i->second.email;
              break;
            }
          break;
          }
      case 7:
        {//Display Subject-wise individual student attendance
          
            
          break;
          }
          
        
      case 11:
        {
          cout<<"Thank you!";
          exit(1);
        }

      }
    }
  
return 0;
  }       
      
