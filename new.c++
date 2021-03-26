#include <iostream>
#include  <string>
#include  <vector>
#include  <fstream>
#include <time.h> 
#include <unistd.h>
#include <pthread.h>

using namespace std;

typedef vector<int> vecI;
void merge(vector<int> first,vector<int> second,vector<int> &out){
	int countF = 0;
	int countS = 0;
	while( countF <first.size()&& countS < second.size()){	
	  if( first.at(countF) <= second.at(countS)){

	  	out.push_back(first.at(countF));
	  	countF=countF +1;
	  }  //if()
	  else{
	  	out.push_back(second.at(countS));
	  	countS=countS +1;
	  } //else()
	} //while()
	
	if(countF<first.size()){ 
	  while(countF<first.size()){
	  	out.push_back(first.at(countF));
	  	countF=countF +1;
	  } //while
	  	
	} //if()
	else if(countS < second.size()){
	  while(countS < second.size()){
	    out.push_back(second.at(countS));
	  	countS=countS +1;
	  } //while
	} // else if()
	else{
		;//done
	} //else
	
	
}


void bubbleSort(vector<int> &input){
	int temp = 0;
	for(int i =1; i<input.size() ;i++){
		for(int j=0;j<input.size() -i;j++){
			if( input.at(j) >input.at(j+1)){
				temp = input.at(j);
				input.at(j) = input.at(j+1);
				input.at(j+1) = temp;
			} // if()
			
		} //for()
	} // for()
	
} // bubbleSort




int main() {
	vector<int> input;
	ifstream rFile ;
	ofstream oFile;
    rFile.open("input1.txt");
    int piece;
	int inputF;
	while(rFile>>inputF)
	{
		input.push_back(inputF);
		
	}
	rFile.close();
	cout << "how you want to cut (please input int\n";
	cin >> piece;
	pid_t pid[piece];
	if( pid ==0){
		int i = 0;
		while(pid[i]==0&&i<piece)
		pid[i]=fork();
	}
	else if( pid >0){
		;
	}
	for(int i = 1;i<= piece;i++){
		int breakPoint = (input.size()/piece)*i;
		
		int lastBreakPoint = (input.size()/piece)*(i - 1);
		vector<int> separate;
		separate.clear();
		if(piece == i ){
			for(int j = lastBreakPoint ;j< input.size();j++){
			  separate.push_back(input.at(j));
			  //separateInput.push_back(separate);
		    } //for
		} //if()
		else {
			for(int j = lastBreakPoint ;j< breakPoint;j++){
			  separate.push_back(input.at(j));
		    } //for
		} // else 
		
	} //for()
	bubbleSort(input);
	vector<int> check;
	check.clear();
//	bubbleSort(separateInput.at(0));
//	bubbleSort(separateInput.at(1));
//	merge(separateInput.at(0),separateInput.at(1),check);
	
	for(int i = 0;i <check.size();i++){
		cout << check.at(i)<<",";
	}
	  

	time_t start, end,result;
	start= time(NULL);
	end = time(NULL);
	result = end -start;
	printf("time%f", result);



}
