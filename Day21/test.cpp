#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    inFile.open("data2.txt");
    int temp;
    int cnt = 0;
    while(inFile>>temp){
        cout<<temp<<" ";
        cnt++;
    }cout<<"Success"<<endl;
    cout<<"Total number of items recieved = "<<cnt<<endl;
    return 0;
}
