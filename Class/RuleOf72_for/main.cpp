/* 
 * File:   main.cpp
 * Author: Christian Sandoval
 * Purpose: To Illustrate the rule of 72 by the way of a for loop
 * Created on March 28, 2016, 7:54 AM
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv)
{
    //Declare variables
    float pv = 100.0f;//Present value
    float iRate = 0.05f;//Interest rate
    float nComp;//Number of compounding periods by the rule of 72
    int nYears = 0;//Comparison of calculations to the rule of 72
    float fv = pv;//Future value
    
    //Calculate the approximate number of years to double by the rule of 72
    nComp = static_cast<int>(0.72f / iRate);
    
    //Output initial conditions and set up the table
    cout << "Present Value = $" << pv << endl;
    cout << "Interest rate = " << iRate*100 << "%" << endl;  
    cout << "\nYears    Future Value " << endl;
    cout << fixed << setprecision(2) << showpoint;
    cout << setw(3) <<nYears << setw(10) << " $" << fv << endl;
    
    //Loop each year until the future value is 2x the present value
    for(nYears = 1; fv < 2 * pv; nYears++)
    {
        fv *= (1 + iRate);
        cout << setw(3) <<nYears << setw(10) << " $" << fv << endl;
    }
        
    //OutPut Results
    cout << "\nBy the rule of 72 it will take " << nComp << " years to double." << endl;
    cout << "The Future Value = $" << fv << endl;
    cout << "The number of years to more than double = " <<nYears << endl;
    
    return 0;
}

//FV Future Value
//PV present value
//(1+i) = year + Interest, 
//Formula: FV = PV *(1+i)*(1+i)
//Formula: FV = PV *(1+i)pow(N)
//Formula: FV = PV *(1+i)*(1+i)