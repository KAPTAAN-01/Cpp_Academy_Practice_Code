#include<iostream>
using namespace std;
int main(){
    cout<<"ENTER THE STARTING RANGE : "<<endl;
    int sr;
    cin>>sr;  
    int* sr1 = &sr;
    cout<<"ENTER THE ENDING RANGE : "<<endl;
    int er;
    cin>>er; 
    int* er1 = &er;
    cout<<"PRIME NUMBERS BETWEEN"<<sr<<"&"<<er<<" : ";
    int i;
    int* i1 = &i;
    for( *i1=*sr1;*i1<*er1;i++){
        int j;
        int*j1 = &j;
        for(*j1 =2;*j1<*i1;j++){
            if(*i1%*j1==0){
                break;
            }  
        }
        if(*j1==*i1){
            cout<<*j1<<" ";
        } 
    } 
  return 0;  
}


