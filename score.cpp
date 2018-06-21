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
     num++;
  }
  int n=0;
  while(n<num)
  {
     cout<<student[n].name<<" "<<student[n].sex<<" "<<student[n].s<<endl;
     n++;
  }
  return 0;
}
