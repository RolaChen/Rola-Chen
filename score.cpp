#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

struct Student
{
  string name;
  string sex;
  string score;
  double s;
};

int main()
{
  Student student[40];
  ifstream infile("score.csv",ios::in);
  string line;
  getline(infile,line);
  int num=0;
  double total=0;
  int girl=0;
  double girlaverage=0;
  while(getline(infile,line))
  {
     stringstream ss(line);
     getline(ss,student[num].name,',');
     getline(ss,student[num].sex,',');
     getline(ss,student[num].score);
     if(student[num].score[1]=='1')
     student[num].s=100;    
     else
     {
        student[num].s=(student[num].score[1]-'0')*10+student[num].score[2]-'0';
        if(student[num].score.length()==5)
        student[num].s=student[num].s+(student[num].score[4]-'0')*0.1;
     }
     if(student[num].sex[1]=='F')
     {
        girlaverage+=student[num].s;
        girl++;
     }
     total+=student[num].s;
     num++;
  }
  for(int i=0;i<num-1;i++)
  {
    for(int j=0;j<num-i-1;j++)
    {
      if(student[j].s<student[j+1].s)
      {
         Student k= student[j];
         student[j]=student[j+1];
         student[j+1]=k;
      }
      else if(student[j].s==student[j+1].s)
      {
       if(student[j].name>student[j+1].name)
       {
         Student k= student[j];
         student[j]=student[j+1];
         student[j+1]=k;
       }
      }
    }
  }
  int n=0;
  cout<<"The average of all the students: "<<total/num<<endl;
  cout<<"The average of all the girls: "<<girlaverage/girl<<endl;
  for(int i=0;i<num;i++)
  cout<<student[i].name<<student[i].sex<<student[i].score<<endl;
  return 0;
}




