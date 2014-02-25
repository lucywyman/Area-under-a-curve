/********************************************************************
*Program filename: areaUnderACurve.cpp
*Author: Lucy Wyman
*Date: February 9, 2014
*Description: Calculate the area under a chosen curve between two user-inputted points
*Input: Beginning and ending points, number of rectangles or trapezoids used, method of Riemann sum, and equation to be used
*Output: Area under a curve between two points
*********************************************************************/

#include<cmath>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


/*Define functions that will be used for integrals*/
/*********************************************************************
**Function: f1, f2, f3, f4, f5
** Description: Given functions which can be chosen to find the area under.  y=mx+b format.
** Parameters: Float x
** Pre-Conditions: X must be a double
** Post-Conditions: Return value of y for given x.
********************************************************************/ 
double f1(double x){
    double y = 2*(pow(x,5))+(pow(x,3))-(10*x)+2;
    return y;}

double f2(double x){
    double y = 6*pow(x,2)-x+10;
    return y;}

double f3(double x){
    double y = (5*x)+3;
    return y;}

double f4(double x){
    double y=2*(pow(x,3))+120;
    return y;}

double f5(double x){
    double y=2*(pow(x,2));
    return y;}

/*Define functions for finding area through rectangular and trapezoidal methods.  These functions will be passed a pointer to the chosen function, the start point, the end point, and the width, and use those to find the totalarea under the function*/

/*********************************************************************
**Function: Rectangle Area and Trapezoid Area
** Description: Use either trapezoids or rectangles to find the area under a curve using Riemann sums. 
** Parameters: Function being used, starting point, ending point, and width of each rectangle/trapezoid
** Pre-Conditions: All parameters are doubles and need a value
** Post-Conditions: Return double total, also cout it to terminal
*********************************************************************/ 
double rectangleArea(double(*function)(double), double a, double b, double width){
    double fx;
    double area;
    double total;	
    for (double j = a; j<b; j+=width){
	fx = (*function)(j);
	area = fx*width;
	total = total+area;}
    cout<<total<<endl;
    return total;}

double trapezoidArea(double (*function)(double), double a, double b, double width){
    double fxa;
    double fxb;
    double area;
    double total;
	for (double j = a; j<b; j+=width){
	    fxa = (*function)(j);
	    fxb = (*function)(j+width);
	    area = ((fxa+fxb)/2)*width;
	    total = total+area;}
    cout<<total<<endl;
    return total;}

/*This function is passed all the same variables as well as the method of integrating that the user chose.  This is where the above functions are run, and the sum is returned*/

/*********************************************************************
**Function:  Run rectangle, trapezoid, or both functions with inputed variables 
** Description: Legitimately just passing all variables to the right functions according to user input
** Parameters: Function, start point, end point, width of rectangle/trapezoid, and which method user wants to use
** Pre-Conditions: All parameters must be doubles except for type which is a string.
** Post-Conditions: return double sum
*********************************************************************/ 
double methods(double(*funct)(double), double a, double b, double width, string type){
    double sum;
    double sum1;
    if (type == "rectangular" || type == "Rectangular" || type == "rectangle" || type == "Rectangle"){
	sum = rectangleArea(funct, a, b, width);}
    else if (type == "trapezoid" || type == "Trapezoid" || type == "trapezoidal" || type == "Trapezoidal"){
	sum = trapezoidArea(funct, a, b, width);}
    else if (type =="both" || type=="Both"){
    	sum = rectangleArea(funct, a, b, width);
	sum1 = trapezoidArea(funct, a, b, width);}
    else{
	cout<< "\033[1;31mYou did not enter a valid method!  Please try again\33[0m"<<endl;
	sum = 0;}
    return sum;}


/*Check inputs*/
void checkInput(){
	cin.clear();
	cin.ignore(1000, '\n');}

/*Wooo, we made it!  Int main will get all the user input, then use a series of if statements to determine where pointers will point to in order to get evaluate the area under the curve*/

/*********************************************************************
*Function: Main!  Calling all functions and asking for user input.
** Description: Get user input, check to make sure it's valid, and pass parameters to functions.
** Parameters: Nada
** Pre-Conditions: None
** Post-Conditions: Woo.
*********************************************************************/ 
int main(){
    string play = "yes";
    /*Nested while loop so user can start over"*/
    while (play == "yes" || play == "Yes"){
	while(1){
	    /*Initializing variables*/
	    double n;
	    string type;
	    double a;
	    double b;
	    int funct;
	    double width;
	    cout<<"\033[1;34mHow accurate do you want your integral (the area under the curve) to be?  Please enter a number from 1-1000, with 1000 being the most accurate:\33[0m ";
	    cin>>n;
	    if (n>1000 || n<0 || cin.fail()){
		checkInput();
		cout<<endl<<"\033[1;31mSorry! You did not input a number between 1 and 1000.  Please try again!\033[0m\n"<<endl;
		break;
	    }	/*This will be the number of rectangles/trapezoids the area under the curve will be broken up doubleo*/
	    cout<<"\033[1;34mWould you like to use the trapezoidal method, rectangular method, or both to find the integral? (trapezoidal will be more accurate)\33[0m ";
	    cin>>type;
	    if (cin.fail()){
	    	checkInput();
		cout<<endl<<"\033[1;31Sorry! You did not input a valid method.  Please try again!\33[0m"<<endl;
		break;
	    }
	    cout<<"\033[1;34mWhat are the beginning and ending values of your integral?  Please enter the beginning number first, and the end number second:\33[0m ";
	    cout<<endl;
	    cin>>a; /*Starting point*/
	    cin>>b; /*Ending point*/
	    if (a>1000 || b>1001 || cin.fail()){
		checkInput();
		cout<<"\033[1;31mSorry! The number you input is too high or too low.  Please select a number between 0 and 4000\033[0m"<<endl;
		break;
	    }
	    width = ((b-a)/n); /*width of rectangle/trapezoids used to find area*/
	    cout<<"\033[1;34mPlease select a function from those provided! Enter a\33[0m\n \033[1;35m1 for y=(2x^5)+(x^3)-10x+2\n 2 for y=(6x^2)-x+10\n 3 for y=5x+3 \n 4 for y=(2x^3)+120\n 5 for y=2x^2\33[0m\n ";
	    cin>>funct;
	    /*All the if statements*/
	    if (funct == 1){
		double answer = methods(&f1, a, b, width, type);
	    }	
	    if (funct == 2){
		double answer = methods(&f2, a, b, width, type);
	    }
	    if (funct == 3){
		double answer = methods(&f3, a, b, width, type);
	    }
	    if (funct == 4){
		double answer = methods(&f4, a, b, width, type);
	    }
	    if (funct == 5){
		double answer = methods(&f5, a, b, width, type);
	    }
	    cout<<"FUNCT"<<&f1<<endl;
	    cout<<"\033[1;34mWould you like to play again? Yes/no\33[0m  "<<endl;
	    cin>>play;
	    if (play != "yes" && play !="Yes"){
	    	break;
	    }
	}	
    }
    return 0;
}
