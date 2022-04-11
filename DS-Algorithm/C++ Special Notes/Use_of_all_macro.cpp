#include"bits/stdc++.h"
using namespace std;

/*
    this are if and else condition 
    which is use in macro 
    #if and #endif is use to close the condition 
    and other condition are simlar as python in c++/c macro
*/

// these statment which is begining 
// with # these names are preprocessor directives

// #line is use for start the statment from new line
// which is metion in #line _number_

#define test 100
#if test > 150
    #undef test  // undefine the macro
    #define test 25 // again define the macro
#elif test < 10
    #undef test
    #define test 3.144 //pi value
#else
    #undef test
    #define test 1
#endif

int main()
{
    cout<<test<<endl;
    cout<<"hello"<<endl;
    #line 100 // it has line_no 33 but we're reseting the line_no by 100 
    cout<<"world :"<<__LINE__<<endl;
    cout<<"I'm :"<<__LINE__<<endl;
    cout<<"Here :"<<__LINE__<<endl;
    return 0;
}
   
     