#include<iostream>
#include<algorithm>
using namespace std;
     void matrix(){
              int arry[3][3];
                  // work to get prince
         double a00 = arry[0][0]/arry[0][0];
         double a01 = arry[0][1]/arry[0][0];
         double a02 = arry[0][2]/arry[0][0];
         
         //passing values to row 1
         arry[0][0] = a00;
         arry[0][1] = a01;
         arry[0][2] = a02;
         
         // BASICALLY WORK ON R2 TO GET 0 ON ARRY[1][0]
         
         // work to get 0 on index [1][0]
         double a10 = arry[1][0]*arry[0][0];
         double A10 = arry[1][0]-a10;
         
         //work on index [1][1]
         double a11 = arry[1][1]-a10;
         //work on index [1][2]
         double a12 = arry[1][2]-a10;
         
         //BASICALLY WORK ON R3 TO GET 0 ON ARRY[2][0]
         
         // work to get 0 on index [2][0]
         double a20 = arry[2][0]*arry[0][0];
         double A20 = arry[2][0]-a20;
         // work on index [2][1]
         double a21 = arry[2][1]-a20;
         // work on index [2][2]
         double a22 = arry[2][2]-a20;
         
         //WORK ON R2 TO GET PRINCE ON  ARRY[1][1]
         double A11 = a11/a11;
         double A12 = a12/a11;
         //work to get 0 on arry[2][1]
         double A21 = a21*A11;
         double b21 = a21-A21;
         //work on [2][2]
         double A22 = a22-A21;
          
         // work to get prince on index[2][2]
         double B22 = A22/A22;
         
         //PASSING VALUES TO ARRY
         arry[1][0] = A10;
         arry[1][1] = A11;
         arry[1][2] = A12;
         
          arry[2][0] = A20;
          arry[2][1] = b21;
          arry[2][2] = B22;
         // display ECHILON FORM
         
            cout<<"MATRIX ECHILON FORM: "<<endl;
    for(int l=0;l<3;l++){
        for(int m=0;m<3;m++){   
            cout<<arry[l][m]<<" ";
        }
        cout<<endl;
    }
}
 

int main(){
       void matrix();
            int arry[3][3];
    
    //loops for getting values of array
    cout<<"ENTER THE VALUES OF A 3 X 3 MATRIX "<<endl;
    for(int i=0;i<3;i++){   
        for(int j=0;j<3;j++){       
            cin>>arry[i][j];
        }
    }
    // matrix cout
    cout<<"MATRIX ENTERED BY YOU IS : "<<endl;
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){   
            cout<<arry[a][b]<<" ";
        }
        cout<<endl;
    }
          if(arry[0][0] == 0){
              
              int x[3] = {arry[0][0],arry[0][1],arry[0][2]};
              int y[3] = {arry[1][0],arry[1][1],arry[1][2]};
              int z[3] = {arry[2][0],arry[2][1],arry[2][2]};
              
              swap (x,y);
             matrix();
          }
              
          else{
              matrix();
           
          }
   return 0;
}

