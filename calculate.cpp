#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

void replace_comma(){
	ifstream in;
	in.open("total.csv");
	string line;
	ofstream out;
	out.open("final.txt");
	while(!in.eof()){
		getline(in,line);
		replace(line.begin(),line.end(),',',' ');
		out<<line<<endl;
	}
	in.close();
	out.close();
}

int main(){
	float price;
	string buyer;// 1 for Jimmy 2 for Sam 3 for Common
	string type;//1 for 8.1% 2 for 1.8% 3 for no tax
	float Jimmy_total = 0;
	float Sam_total = 0;
	replace_comma();
	ifstream input;
	input.open("final.txt");
	while(input>>price){
		if(price!=0){
			input>>buyer;
			input>>type;
			if(buyer=="Jimmy"){
				if(type=="8.10%"){
					Jimmy_total+=price*1.081;
				}
				else if(type=="1.80%"){
					Jimmy_total+=price*1.018;
				}
				else{
					Jimmy_total+=price;
				}
			}
			else if (buyer=="Sam"){
				if(type=="8.10%"){
					Sam_total+=price*1.081;
				}
				else if(type=="1.80%"){
					Sam_total+=price*1.018;
				}
				else{
					Sam_total+=price;
				}
			}
			else{
				if(type=="8.10%"){
					float temp = price*1.081;
					temp/=2;
					Sam_total+=temp;
					Jimmy_total+=temp;
				}
				else if(type=="1.80%"){
					float temp = price*1.018;
					temp/=2;
					Sam_total+=temp;
					Jimmy_total+=temp;
				}
				else{
					float temp = price;
					temp/=2;
					Sam_total+=temp;
					Jimmy_total+=temp;
				}
			}
		}
		else break;
	}
	input.close();
	cout<<"Jimmy's total:"<<Jimmy_total<<endl;
	cout<<"Sam's total:"<<Sam_total<<endl;
	return 0;
	
}
