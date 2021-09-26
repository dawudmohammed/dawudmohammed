#include <iostream>
#include <bits/stdc++.h>

using namespace std;

float mean(float mylist[],int mytotal){
    float sum = 0;
    for(int i=0; i<mytotal;i++){
         sum+=mylist[i];
    }
    return sum/mytotal;

}

float mode(float mylist[],int mytotal){
    //sorting
    sort(mylist,mylist+mytotal);
    //find max frequency
    int max_count = 1, res=mylist[0],count=1;

    for(int i=0;i<mytotal;i++){
       if(mylist[i] == mylist[i-1]){
            count++;
       }else{
         if(count>max_count){
	   max_count = count;
	   res = mylist[i-1];
	 }
	 count=1;
       }
    }
    
    //when the last element is most frequent
    if(count>max_count){ 
       max_count = count;
       res = mylist[mytotal-1];
    }

    return res;

}

float median(float mylist[],int mytotal){
 	sort(mylist,mylist+mytotal);
	if(mytotal%2==0){
	   return (mylist[mytotal/2-1] + mylist[mytotal/2])/2;
	}
       else{
           return mylist[mytotal/2];
       }
}


int main(){
float number;
float number_list[5];
int total = 5;
  for(int i=0; i<total; i++){
    
          cout<<"Enter number "<<i+1<<endl;
          cin>>number;
	  number_list[i] = number;
  }

  cout<<"Mean: "<<mean(number_list,total)<<endl;
  cout<<"Median:"<<median(number_list,total)<<endl;
  cout<<"Mode: "<<mode(number_list,total)<<endl;
//tlc4 

}
