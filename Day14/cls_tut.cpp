#include<iostream>
using namespace std;

class Emp{
private:
    int a, b, c; // only functions of Emp can access this 

public:
    int d, e, f; 
    //void setData(int, int, int); //Declaration
    void getData(){
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;
        cout<<"The value of d is "<<d<<endl;
        cout<<"The value of e is "<<e<<endl;
        cout<<"The value of f is "<<f<<endl;
    }
    void setData(int, int, int); //Declaration
};

void Emp :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Emp harsh;
    harsh.setData(1, 2, 3);
    harsh.getData();
    return 0;
}
