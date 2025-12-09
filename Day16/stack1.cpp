#include<iostream>
#include<vector>

class Stack{
    private:
        int max_Elements;
        // We have two options for arr : arr[MX] where MX is static or we can use vector
        std::vector<int> arr;
    public:
        Stack(int max_Element);
        bool isEmpty();
        bool isFull();
        int peek();
        void push(int x);
        int pop();
};

Stack::Stack(int max_Element){
    max_Elements = max_Element;
}
bool Stack::isEmpty(){
    return (arr.size() == 0);
}
bool Stack::isFull(){
    return (arr.size() >= max_Elements);
}
int Stack::peek(){
    if(!(*this).isEmpty()){
        return (((*this).arr).back());
    }
    else throw std::runtime_error("cannot peek in empty stack");
}
void Stack::push(int x){
    if(!(*this).isFull()){
        (*this).arr.push_back(x);
    }
    else{
        throw std::runtime_error("Stack OverFlow");
    }
}
int Stack::pop(){
    if(!(*this).isEmpty()){
        int ret = (*this).arr.back();
        (*this).arr.pop_back();
        return ret;
    }
    else throw std::runtime_error("Stack UnderFlow");
}

int main(){
    Stack mystack{3};
    for(int i = 0; i < 3; i++) mystack.push(i);
    int val = mystack.pop();
    std::cout<<"1st pop "<<val<<std::endl;
    val = mystack.pop();
    std::cout<<"2nd pop "<<val<<std::endl;
    val = mystack.pop();
    std::cout<<"3rd pop "<<val<<std::endl;
    mystack.pop();
    return 0;
}

