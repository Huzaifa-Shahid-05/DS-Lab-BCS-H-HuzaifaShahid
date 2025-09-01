#include<iostream>
using namespace std;

class SafePointer{
    private: 
        int* ptr;
    public:
        void setValue(int val){
            ptr = new int(val);
        }
        int getValue(){
            return *ptr;
        }

        void release(){
            delete ptr;
            ptr = nullptr;
        }

        ~SafePointer(){
            delete ptr;
        }
};

int main(){
    SafePointer a,b,c,d,e;
    a.setValue(90);
    b.setValue(80);
    c.setValue(75);
    d.setValue(96);
    e.setValue(88);

    cout << "A value: " << a.getValue() << endl;
    cout << "B value: " << b.getValue() << endl;
    cout << "C value: " << c.getValue() << endl;
    cout << "D value: " << d.getValue() << endl;
    cout << "E value: " << e.getValue() << endl;

    a.release();
    b.release();
    c.release();
    d.release();
    e.release();
}