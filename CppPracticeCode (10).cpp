#include<iostream>
using namespace std;
int main(){
int sum,b,x,i,n,m;
cout<<"Enter the number of counting"<<endl;
cin>>m;
for( i=0;i<=m;i++){

    cout<<i<<endl;
}

cout<<"HOW MANY DIGITS YOU WANT TO ADD";

cin>>n;
for( b=0;b<=10;b++){
   for(x=0;x<=n; x++){
    sum=b+x;
   } 
}
return 0;
}