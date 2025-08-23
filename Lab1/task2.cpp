#include<iostream>
using namespace std;

class Exam{
    private:
        string* StudentName;
        string* ExamDate;
        int* score;
    public:
        Exam(string n, string e, int s){
            StudentName = new string(n);
            ExamDate = new string(e);
            score = new int(s);
        }
        void setName(string name){
            *StudentName = name;
        }
        void setDate(string date){
            *ExamDate = date;
        }
        void setScore(int s){
            *score = s;
        }
        void DisplayExam(){
            cout << "Name: " << *StudentName << endl;
            cout << "Exam Date: " << *ExamDate << endl;
            cout << "Score: " << *score << endl;
        }
        ~Exam(){
            delete StudentName;
            delete ExamDate;
            delete score;
        }
};
int main(){
    Exam s1("John", "5/2/2025",85);
    cout << "-----Object1 Displayed-----" << endl;
    s1.DisplayExam();
    cout << endl;

    Exam s2 = s1;
    cout << "-----Object2 Displayed in which Object1 is copied-----" << endl;
    s2.DisplayExam();
    cout << endl;

    cout << "Changed obj1 name and score" << endl;
    cout << endl;
    s1.setName("Sam");
    s1.setScore(90);

    cout << "-----Object1 Displayed-----" << endl;
    s1.DisplayExam();
    cout << endl;

    cout << "-----Object2 Displayed-----" << endl;
    s2.DisplayExam();
}