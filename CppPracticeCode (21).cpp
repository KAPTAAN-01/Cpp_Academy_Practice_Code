#include<iostream>
using namespace std;

int main(){
    int size, block;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the number of BLOCK: ";
    cin >> block;
    for(int indxi = 0; indxi < size; indxi++){
        arr[indxi] = indxi;
    }
    cout << "COUNTING IS GIVEN BELOW" << endl;
    for(int indxj = 0; indxj < size; indxj++){
        cout << arr[indxj]<<",";
    }
    cout<<endl;
        for(int indxk = 0; indxk <= size - block; indxk++){
        int sum = 0;
        for(int indxm = 0; indxm < block; indxm++){
            sum += arr[indxk + indxm];
        }
        cout << "SUM "<< indxk <<" : " << sum<<  endl;
    }
    return 0;
}
//fully updated no mistake I check it

