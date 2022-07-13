#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addStudent(string filename, int *student_count, int *in_state_fees, int *out_of_state_fees){
std::cout<<endl<<"Press any key to add Students details";
getchar();
ofstream file(filename.c_str(), ios::app);
char name[50];
std::cout<<endl<<"\n Enter Student Name: ";
fgets(name, 50, stdin);

file<<endl<<name;

int state=-1;
cout<<endl<<"\n Press 1 for In-State or 2 for Out-Of-State : ";
cin>>state;

if(state==1)
file<<" | In-State";
else if(state==2)
file<<" | Out-Of-State";
else
file<<" | NA";

int college_tuition;
cout<<endl<<"Enter Tution: ";
cin>>college_tuition;

char health_lan_status;
cout<<endl<<"Do you wish to enroll in a Health Plan? y/n : ";
cin>>health_plan_status;

int healthPlan = 0;

if(health_plan_status=='Y' || health_plan_status=='y'){
char plan;
cout<<endl<<"# Choose Your Health Plan #";
cout<<endl<<"E -> $50";
cout<<endl<<"S -> $100";
cout<<endl<<"C -> $150";
cout<<endl<<"F -> $200";

cout<<endl<<"Select any letter (A, B, C, D): ";
cin>>plan;

switch(plan){     	
case 'A':
case 'a': healthPlan = 40;   break;
case 'B':
case 'b': healthPlan = 160; break;
case 'C':
case 'c': healthPlan =  120; break;
case 'D':
case 'd' : healthPlan =  200; break;
default: cout<<endl<<"Invalid Choice..";
}

if(healthPlan!=0)
file<<" | Health Plan : "<<plan;
else
file<<" | Health Plan : None"<<plan;

file<<" | "<<college_tuition;

if(state==1){
*in_state_fees = *in_state_fees + college_tuition + healthPlan;
}
else if(state==2){
*out_of_state_fees = *out_of_state_fees + college_tuition + healthPlan;
}

}
*student_count = *student_count++;
file.close();
}

void generateReport(const string filename, const int *student_count, const int *in_state_fees, const int *out_of_state_fees){
if(*student_count==0){
cout<<endl<<"Error: There should be atleast one record to generate report.";
}
else{
ofstream file(filename.c_str(), ios::app);
file<<endl<<"Total Tuition Paid for all In-State Students : "<<*in_state_fees;
file<<endl<<"Total Tuition Paid for all Out-of-State Students : "<<*out_of_state_fees;
file.close();
cout<<endl<<"Success: "<<filename<<" generated ";		
}
	
}

int main(int argc, char** argv) {
	
int health_plan_status = 0;
string fileName = "tuition_report.txt";
int student_count = 0;
int in_state_fees = 0;
int out_of_state_fees = 0;


ofstream file(fileName.c_str(), ios::out);
file.close();

while(health_plan_status!=-1){
cout<<endl<<"## (College Student Tuition) ##"<<endl;
cout<<endl<<"1 Add Student Details";
cout<<endl<<"2 Generate Report";
cout<<endl<<"-1 Exit";
cout<<"\n\n Enter your choice : ";
cin>>health_plan_status;

switch(health_plan_status){
case 1: addStudent(fileName, &student_count, &in_state_fees, &out_of_state_fees);
	break;
case 2: generateReport(fileName, &student_count, &in_state_fees, &out_of_state_fees);
	break;
case -1: cout<<endl<<"Thank you";
	break;
default: cout<<endl<<"Invalid Choice"; getchar();
	
}	
}

return 0;
}
