//Quadratic Operations
#include<iostream>
#include<cmath>
using namespace std;
class quadratic
{
    int a,b,c;
public:
    quadratic() //constructor sets quadratic to 0x2+0x+0
    {
        a=b=c=0;
    }
    friend istream &operator >>(istream &ob, quadratic &obj); //input quadratic expression
    friend ostream &operator <<(ostream &ob, quadratic &obj); //output quadratic expression
    void compute() //solve for value of x
    {
        float x1,x2,discriminant,realPart, imaginaryPart;
        cout<<"The solution of the given quadratic expression for 0 is:";
        discriminant = b*b - 4*a*c; //calculate discriminant
        if (discriminant > 0) //select discriminant type
        {
            x1 = (-b + sqrt(discriminant)) / (2*a);
            x2 = (-b - sqrt(discriminant)) / (2*a);
            cout << "\nRoots are real and different." << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
        else if (discriminant == 0)
        {
            cout << "\nRoots are real and same." << endl;
            x1 = (-b + sqrt(discriminant)) / (2*a);
            cout << "x1 = x2 =" << x1 << endl;
        }
        else
        {
            realPart = -b/(2*a);
            imaginaryPart =sqrt(-discriminant)/(2*a);
            cout << "\nRoots are complex and different."  << endl;
            cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
        }
    }
    float eval(float xval) //evaluates value of polynomial for given value of x
    {
        float result;
        result=((a*pow(xval,2))+(b*xval)+c);
        return result;
    }
    quadratic operator+(quadratic &ob) //overloaded + to add two quadratic expressions
    {
        quadratic temp;
        temp.a=a+ob.a;
        temp.b=b+ob.b;
        temp.c=c+ob.c;
        return temp;
    }
};

ostream &operator<<(ostream &ob, quadratic &obj) //display quadratic expression
{
    ob<<"("<<obj.a<<")x^2 + ("<<obj.b<<")x + ("<<obj.c<<")"<<endl;
}

istream &operator>>(istream &ob, quadratic &obj) //take terms of quadratic from user
{
    ob>>obj.a>>obj.b>>obj.c;
}

int main()
{
    float val;
    int n;
    quadratic q1,q2,q3;
    cout<<"Quadratic Expression Form\n ax^2 + bx + c\n\n";
    cout<<"Enter a, b, c for a quadratic expression: "; //take first quadratic from user
    cin>>q1;
    cout<<"Operations available:\n1.Add Quadratic Expressions\n2.Evaluate for a given value of x\n3.Solve for value of x\n";
    cout<<"Select Operation: ";
    cin>>n;
    switch(n)
    {
    case 1:
        cout<<"Enter second quadratic expression: "; //take second quadratic from user
        cin>>q2;
        q3=q1+q2; //add quadratic expressions
        cout<<q3; //display addition
        break;
    case 2:
        cout<<"Enter value of x: "; //take value of x from user
        cin>>val;
        cout<<"Value of polynomial for given value of x is "<<q1.eval(val)<<endl; //calculate and display value of polynomial
        break;
    case 3:
        q1.compute(); //calculate value of x
        break;
    default: //default case
        cout<<"Wrong Operation Code\n";
    }
    return 0;
}
