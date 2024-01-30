// 1. Write a program to print the series 4,6,12,18,30,42,60,72
// 2. Write a program to find all the Palindrome dates that come between the year 01-01-2001 till 31-12-2021. eg. 10-02-2001
// Submit your assignment to techjobs@uexcelerate.com by 31st Jan along with your resume.


// For this assignment i am using C++ Language to solve given problems.

#include <bits/stdc++.h>
using namespace std;

class ass{

    public: 
        void print (vector<int>v, int n){
            cout << "Printed array is ";
            cout << "[";
            cout << v[0];
            for (int i=1;i<n;i++){
                cout <<", " <<v[i]; 
            }
            cout << "]"<< endl;
            cout << endl;
        }

        void printDefault(){
            vector<int>v={4,6,12,18,30,42,60,72};
            cout<< "defalut array is printed \n";
            print(v, 8);
        }

        void printWithInput(){
            int n;
            cout << "Input the length of array ";
            cin>> n;
            cout << "Input the value of array \n"<< "For example: \n For n = 3 \n 4 5 2 \n ";
            vector<int>v(n);
            for (int i=0;i<n;i++){
                cin>>v[i];
            }
            print(v, n);
        }
        bool isLeapYear(int year){
            return (((year % 4 == 0) and (year % 100 != 0))or (year % 400 == 0));
}
        bool isvalidDate(int d, int m, int y, int y1, int y2){
            if (y>y2 or y<y1) return false;
            if (m<1 or m>12) return false;
            if (d<1 or d>31) return false;
            if (m==2){
                if (isLeapYear(y)) return (d<=29);
                else return (d<=28);
            }
            if (m==4 or m==6 or m==9 or m==11) return (d<=30);
            return true;

        }

        void printPalindromeDates(int y1, int y2){
            
            for (int y=y1; y<=y2; y++){
                string str = to_string(y);
                string rev = str;
                reverse(rev.begin(), rev.end());
                int d = stoi(rev.substr(0,2));
                int m = stoi(rev.substr(2,2));
                if (isvalidDate(d, m, y, y1, y2)){
                    cout << d << "-"<< m << "-"<< y << endl;
                }
            }
            cout << endl;
        }
        void printPalindromeDatesdefalt(){
            int y1 = 2001;
            int y2 = 2021;
            cout<< "Palindrome Date from " << y1 << " to " << y2 << endl;
            printPalindromeDates(y1, y2);
        }
        void printPalindromeDatesInput(){
            cout << "input the year \nFor example: \n starting year 2001 \n ending year 2021 \n";
            cout << "Starting year ";
            int y1;
            cin >>y1;
            cout << endl;
            cout << "ending year ";
            int y2;
            cin >>y2;
            cout << endl;
            cout<< "Palindrome Date from " << y1 << " to " << y2 << endl;
            if (y1 < 1000){
                y1 = 1000;
            }
            if (y2>9999){
                y2 = 9999;
            }
            printPalindromeDates(y1, y2);
        }
    
};

int main(){

    int choose;
    cout << "Hello there! I'm Nikhil, the developer behind this piece of code."<< endl;
    cout << "This code is designed to solve two familiar problems, and I'm giving you the flexibility to choose how it operates. If you input '1', the code will run for a predefined value provided in the problems. Alternatively, if you input '2', the code will prompt you for input.\n ";
    cout << endl;

    cout << "Please input either 1 or 2 : ";
    cin >> choose;

    if (choose !=1 and choose !=2){
        cout<< "Error: Invalid Input\nMessage: Choose either 1 or 2";
    }


    ass first_pro;
    ass second_pro;
    switch(choose){
        case 1:
            // Run the code with defalt value that are give in question:
            first_pro.printDefault();
            second_pro.printPalindromeDatesdefalt();
            cout<< "Happy Coding!!!"<< endl;
            break;
        case 2:
            // Run the code with user's Input value
            first_pro.printWithInput();
            second_pro.printPalindromeDatesInput();
            cout<< "Happy Coding!!!"<< endl;
            break;
    }
    return 0;

}