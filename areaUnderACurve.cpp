#include<cmath>
#include<iostream>
#include<string>
using namespace std;


/*Define functions that will be used for integrals*/
float f1(float x){
    float y = 2*(pow(x,5))+(pow(x,3))-(10*x)+2;
    return y;
}

float f2(float x){
    float y = 6*pow(x,2)-x+10;
    return y;
}

float f3(float x){
    float y = (5*x)+3;
    return y;
}

float f4(float x){
    float y=2*(pow(x,3))+120;
    return y;
}

float f5(float x){
    float y=2*(pow(x,2));
    return y;
}

/*Define functions for finding area through rectangular and trapezoidal methods.  These functions will be passed a pointer to the chosen function, the start point, the end point, and the width, and use those to find the totalarea under the function*/
float rectangleArea(float(*function)(float), float a, float b, float width){
    float fx;
    float area;
    double total;	
    for (float j = a; j<b; j+=width){
	fx = (*function)(j);
	area = fx*width;
	total = total+area;
    }
    cout<<total<<endl;
    return total;
}

float trapezoidArea(float (*function)(float), float a, float b, float width){
    float fxa;
    float fxb;
    float area;
    double total;
    for (float j = a; j<b; j+=width){
	fxa = (*function)(j);
	fxb = (*function)(j+width);
	area = ((fxa+fxb)/2)*width;
	total = total+area;
    }
    cout<<total<<endl;
    return total;
}

/*This function is passed all the same variables as well as the method of integrating that the user chose.  This is where the above functions are run, and the sum is returned*/
double methods(float(*funct)(float), float a, float b, float width, string type){
    float sum;
    if (type == "rectangular" || type == "Rectangular" || type == "rectangle" || type == "Rectangle"){
	sum = rectangleArea(funct, a, b, width);
    }
    else if (type == "trapezoid" || type == "Trapezoid" || type == "trapezoidal" || type == "Trapezoidal"){
	sum = trapezoidArea(funct, a, b, width);
    }
    else{
	cout<< "You did not enter a valid method!  Please try again"<<endl;
	sum = 0;
    }
    return sum;
}

/*Wooo, we made it!  Int main will get all the user input, then use a series of if statements to determine where pointers will point to in order to get evaluate the area under the curve*/
int main(){
    /*Initializing variables*/
    float n;
    string type;
    float a;
    float b;
    int funct;
    float width;
    string play = "Yes";
    /*While loop so that user can start over*/
    while (play == "Yes" || play == "yes"){
	cout<<"How accurate do you want your integral (the area under the curve) to be?  Please enter a number from 1-100, with 100 being the most accurate:  ";
	cin>>n; /*This will be the number of rectangles/trapezoids the area under the curve will be broken up doubleo*/
	cout<<"Would you like to use the trapezoidal method or rectangular method to find the integral (trapezoidal will be more accurate)?  ";
	cin>>type; 
	cout<<"What are the beginning and ending values of your integral?  Please enter the beginning number first, and the end number second: ";
	cout<<endl;
	cin>>a; /*Starting point*/
	cin>>b; /*Ending point*/
	width = ((b-a)/n); /*width of rectangle/trapezoids used to find area*/
	cout<<"Please select a function from those provided! Enter a \n 1 for y=(2x^5)+(x^3)-10x+2\n 2 for y=(6x^2)-x+10\n 3 for y=5x+3 \n 4 for y=(2x^3)+120\n 5 for y=2x^2  ";
	cout<<endl;
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
	cout<<"Would you like to play again? Yes/no  "<<endl;
	cin>>play;
    }	
    return 0;
}
