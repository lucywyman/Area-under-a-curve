/********************************************************************
 *Program filename: doubleegralCalculatorCLI.cpp
 *Author: Lucy Wyman
 *Date: February 9, 2014
 *Description: Calculate the area under a chosen curve between two user-inputted podoubles
 *Input: Beginning and ending podoubles, number of rectangles or trapezoids used, method of Riemann sum, and equation to be used
 *Output: Area under a curve between two podoubles
 *********************************************************************/

#include<cmath>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


/*Define functions that will be used for doubleegrals*/
/*********************************************************************
 **Function: f1, f2, f3, f4, f5
 ** Description: Given functions which can be chosen to find the area under.  y=mx+b format.
 ** Parameters: Float x
 ** Pre-Conditions: X must be a double
 ** Post-Conditions: Return value of y for given x.
 ********************************************************************/ 
double f1(double x){
    double y = 2*(pow(x,5))+(pow(x,3))-(10*x)+2;
    return y;
}

double f2(double x){
    double y = 6*pow(x,2)-x+10;
    return y;
}

double f3(double x){
    double y = (5*x)+3;
    return y;
}

double f4(double x){
    double y=2*(pow(x,3))+120;
    return y;
}

double f5(double x){
    double y=2*(pow(x,2));
    return y;
}

/*Define functions for finding area through rectangular and trapezoidal methods.  These functions will be passed a podoubleer to the chosen function, the start podouble, the end podouble, and the width, and use those to find the totalarea under the function*/

/*********************************************************************
 **Function: Rectangle Area and Trapezoid Area
 ** Description: Use either trapezoids or rectangles to find the area under a curve using Riemann sums. 
 ** Parameters: Function being used, starting podouble, ending podouble, and width of each rectangle/trapezoid
 ** Pre-Conditions: All parameters are doubles and need a value
 ** Post-Conditions: Return double total, also cout it to terminal
 *********************************************************************/ 
double rectangleArea(double(*function)(double), double a, double b, double width){
    double fx = 0;
    double area;
    double total;
    for (double j=a; j<b; j= j+width){
	fx = (*function)(j);
	area = fx*width;
	total = total+area;
    }
    return total;
}

double trapezoidArea(double(*function)(double), double a, double b, double width){
    double fxa;
    double fxb;
    double area;
    double total;
    for (double j = a; j<b; j+=width){
	fxa = (*function)(j);
	fxb = (*function)(j+width);
	area = ((fxa+fxb)/2)*width;
	total = total+area;
    }
    return total;
}

/*This function is passed all the same variables as well as the method of doubleegrating that the user chose.  This is where the above functions are run, and the sum is returned*/

/*********************************************************************
 **Function:  Run rectangle, trapezoid, or both functions with inputed variables 
 ** Description: Legitimately just passing all variables to the right functions according to user input
 ** Parameters: Function, start podouble, end podouble, width of rectangle/trapezoid, and which method user wants to use
 ** Pre-Conditions: All parameters must be doubles except for type which is a string.
 ** Post-Conditions: return double sum
 *********************************************************************/ 
double methods(double(*funct)(double), double a, double b, double width, char type){
    double sum = 0;
    double sum1 = 0;
    if (type == 'r'){
	sum = rectangleArea(*funct, a, b, width);
    }
    else if (type == 't'){	
	sum = trapezoidArea(funct, a, b, width);
	}
    else if (type =='b'){
	sum = rectangleArea(funct, a, b, width);
	sum1 = trapezoidArea(funct, a, b, width);
	cout<<sum1<<endl;
    }
    return sum;
}

/****************************************************
**Function: argParse
**Description: Parse arguments that are input by the user.
**Parameters:  Function chose by user, start point (a), end point (b), width of rectangles used in riemann sum, and method of riemann sum (rectangular or trapezoidal).
**Pre-conditions: All arguments have been input in the correct format.
**Post-conditions: Double answer is returned
******************************************************/
double argParse(double funct, double a, double b, double width, char type){
    double answer = 0;
    if (funct == 1){
	answer = methods(&f1, a, b, width, type);
    }
    else if (funct == 2){
	answer = methods(&f2, a, b, width, type);
    }
    else if(funct==3){
	answer = methods(&f3, a, b, width, type);
    }
    else if (funct == 4){
	answer = methods(&f4, a, b, width, type);
    }
    else if (funct == 5){
	answer = methods(&f5, a, b, width, type);
    }
    else{
    cout<<"You done goofed"<<endl;}
    return answer;
}    

/*Wooo, we made it!  Int main will get all the user input, then use a series of if statements to determine where podoubleers will podouble to in order to get evaluate the area under the curve*/

/*********************************************************************
 *Function: Main!  Calling all functions and asking for user input.
 ** Description: Get user input, check to make sure it's valid, and pass parameters to functions.
 ** Parameters: Nada
 ** Pre-Conditions: None
 ** Post-Conditions: Woo.
 *********************************************************************/ 
int main(int argc, char *argv[]){
    /*Initializing variables*/
double n;
    char type;
    double a;
    double b;
    double funct;
    double width;
    if(argc!= 11){
	cout<<"You did not enter the right number of arguments!  Please enter five arguments, -f for function (1-5), -m for method (r or t), -a for starting podouble, -b for ending podouble, and -n for the number of rectangles to be used"<<endl;
	exit(1);}
    for (int i = 1; i<11; i+=2){
	if (argv[i][0] == '-' && argv[i][1] == 'f'){
	    funct = atoi(argv[i+1]);
	}
	else if (argv[i][0] == '-' && argv[i][1] =='m'){
	    type = *argv[i+1];
	} 
	else if (argv[i][0] == '-' && argv[i][1] == 'a'){
	    a = atoi(argv[i+1]);
	}
	else if (argv[i][0] == '-' && argv[i][1] == 'b'){
	    b = atoi(argv[i+1]);
	}
	else if (argv[i][0] == '-' && argv[i][1] == 'n'){
	    n = atoi (argv[i+1]);
	}
	else{
	    cout<<"Oops!  You seem to have entered something incorrectly.  Please try again!"<<endl;
	    exit(1);
	}
    }
    width = (b-a)/n;
	double answer = argParse(funct, a, b, width, type);
	cout<<"The area under the curve from "<<a<<" to "<<b<<" is "<<answer<<endl;
	return 0;	
}
