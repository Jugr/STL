#include<iostream>
using namespace std;


class Complex
{
public:
	Complex(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void printComplex(){
		cout << "(" << this->a << "+" << this->b << "i)" << endl;
	}
	friend Complex complexAdd(Complex& c1, Complex& c2);
	
	//法二
	Complex complexAdd(Complex& another) {
		Complex tmp(this->a + another.a, this->b + another.b);
		return tmp;
	}

	//法三
	//friend Complex operator+ (Complex& c1, Complex& c2);

	//法四 同理法二
	Complex operator+ (Complex& another) {
		Complex tmp(this->a + another.a, this->b + another.b);
		return tmp;
	}

private:
	int a; //实数
	int b;//叙述
};

//法一
Complex complexAdd(Complex& c1, Complex& c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}


#if 0
//法三
//操作符重载写在全局
Complex operator+ (Complex& c1, Complex& c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}
#endif

int main() {

	Complex c1(1, 2);
	Complex c2(3, 4);

	c1.printComplex();
	c2.printComplex();

	//法一
	//Complex c3 = complexAdd(c1, c2);
	//c3.printComplex();

	//法二
	//Complex c3 = c2.complexAdd(c1);
	//c3.printComplex();

	//法三
	Complex c3 = c1 + c2;//
	//Complex c3 = operator+(c1, c2);
	c3.printComplex();

	//法四
	Complex c3 = c1 + c2;//
	//Complex c3 = c1.operator+(c2);
	c3.printComplex();


	return 0;
}