#include<iostream>
using namespace std;

class Box{
    private:
        int* num;
    public:
        Box(int j){
            num = new int(j);
        }
        void setNum(int i){
            *num = i;
        }
        int getNum(){
            return *num;
        }

        Box(Box &a){
            num = new int(*a.num);
        }
        Box& operator=(const Box& obj) {
            if(this != &obj){
                delete num;
                num = new int(*obj.num);
            }

            return *this;
        }

        ~Box(){
            delete num;
        }
};

int main(){
    Box b1(10);
    cout << "Value of Obj1: " << b1.getNum() << endl << endl;
    cout << "----Value of Obj1 copied in Obj2----" << endl;
    Box b2 = b1;
    cout << "Value of Obj2: " << b2.getNum() << endl << endl;

    cout << "----Value of Obj2 changed----" << endl;
    b2.setNum(5);
    cout << "Value of Obj2: " << b2.getNum() << endl << endl;

    cout << "----Value of Obj1 remains unchanged----" << endl;
    cout << "Value of Obj1: " << b1.getNum() << endl << endl; 

}