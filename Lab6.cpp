#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double convert(double degree);

class Triangle {
protected:
	double side1 = 0;
	double side2 = 0;
	double side3 = 0;
	double h = 0;
	double angle1 = 0;
	double angle2 = 0;
	double area = 0;
	double perimeter = 0;

public:

	//bool operator == (Triangle t) {
	//	if (area == t.area) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}

	double getSide1() { return side1; }
	double getArea() { return area; }
	double getPerimeter() { return perimeter; }
	double getAngle1() { return angle1; }
	double getAngle2() { return angle2; }

	void setSide1(double new_side1) {
		side1 = new_side1;
	}
	void setAngle1(double new_angle1) {
		angle1 = new_angle1;
	}
	void setAngle2(double new_angle2) {
		angle2 = new_angle2;
	}
	void setH(double new_h) {
		h = new_h;
	}
	

	Triangle() {};
	~Triangle() {};
};

class EquilateralTriangle : public Triangle {
public:
	double areaOfEquilateral() {
		area = pow(side1, 2) * sqrt(3) / 4;
		return area;
	}
	double perimeterOfEquilateral() {
		perimeter = side1 * 3;
		return perimeter;
	}
	bool operator == (EquilateralTriangle e) {
		if (side1 == e.side1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator > (EquilateralTriangle e) {
		if (side1 > e.side1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator < (EquilateralTriangle e) {
		if (side1 < e.side1) {
			return true;
		}
		else {
			return false;
		}
	}

	friend ostream& operator << (ostream& os, const EquilateralTriangle& e);
	friend istream& operator >> (istream& is, EquilateralTriangle& e);

	EquilateralTriangle(double new_side1) {
		side1 = new_side1;
	};
	~EquilateralTriangle() {};
};

ostream& operator << (ostream& os, const EquilateralTriangle& e) {
	os << "Side: " << e.side1 << "\nTotal area: " << e.area << "\nTotal perimeter: " << e.perimeter << endl;
	return os;
}
istream& operator >> (istream& is, EquilateralTriangle& e) {
	is >> e.side1;
	return is;
}
	class RightTriangle : public Triangle {
	public:
		double areaOfRight() {
			area = side1 * h / 2;
			return area;
		}
		double perimeterOfRight() {
			perimeter = (2 * sqrt(areaOfRight())) + side1;
			return perimeter;
		}

		bool operator == (RightTriangle r) {
			if (side1 == r.side1 && h == r.h && areaOfRight() == r.areaOfRight()) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator > (RightTriangle r) {
			if (areaOfRight() > r.areaOfRight()) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator < (RightTriangle r) {
			if (areaOfRight() < r.areaOfRight()) {
				return true;
			}
			else {
				return false;
			}
		}

		friend ostream& operator << (ostream& os, const RightTriangle& r);
		friend istream& operator >> (istream& is, RightTriangle& r);

		RightTriangle(double new_side1, double new_h) {
			side1 = new_side1;
			h = new_h;
		};
		~RightTriangle() {};
	};

	ostream& operator << (ostream & os, const RightTriangle & r) {
		os << "Main side: " << r.side1 << "\nHeight: " << r.h << "\nTotal area: " << r.area << "\nTotal perimeter: " << r.perimeter << endl;
		return os;
	}
	istream& operator >> (istream& is, RightTriangle& r) {
		is >> r.side1;
		is >> r.h;
		return is;
	}


class ArbitraryTriangle : public Triangle {
private:
	double angle3 = 180 - (angle1 + angle2);



public:
	double areaOfArbitary() {
		angle3 = 180 - (angle1 + angle2);
		area = 0.5 * side1 * side1 * sin(convert(angle1)) * sin(convert(angle2)) / sin(convert(angle3));
		return area;
	}
	double perimeterOfArbitary() {
		side2 = side1 * sin(convert(angle1)) / sin(convert(angle2));
		side3 = side1 * sin(convert(angle3)) / sin(convert(angle2));
		perimeter = side1 + side2 + side3;
		return perimeter;
	}
	bool operator == (ArbitraryTriangle a) {
		if (side1 == a.side1 && angle1 == a.angle1 && angle2 == a.angle2) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator > (ArbitraryTriangle a) {
		if (areaOfArbitary() > a.areaOfArbitary()) {
			return true; 
		}
		else {
			return false;
		}
	}
	bool operator < (ArbitraryTriangle a) {
		if (areaOfArbitary() < a.areaOfArbitary()) {
			return true; 
		}
		else {
			return false;
		}
	}

	friend ostream& operator << (ostream& os, const ArbitraryTriangle& a);
	friend istream& operator >> (istream& is, ArbitraryTriangle& a);

	ArbitraryTriangle(double new_side1, double new_angle1, double new_angle2) {
		side1 = new_side1;
		angle1 = new_angle1;
		angle2 = new_angle2;
	};
	~ArbitraryTriangle() {};
};

ostream& operator << (ostream& os, const ArbitraryTriangle& a) {
	os << "Main side: " << a.side1 << "\nAngle 1: " << a.angle1 << "\nAngle 2: " << a.angle2 << "\nAngle 3: " << a.angle3 << "\nTotal area: " << a.area << "\nTotal perimeter: " << a.perimeter << endl;
	return os;
}
istream& operator >> (istream& is, ArbitraryTriangle& a) {
	is >> a.side1;
	is >> a.angle1;
	is >> a.angle2;
	return is;
}

int main() {
	RightTriangle right1(10, 5);
	cout << right1.areaOfRight() << endl;
	cout << right1.perimeterOfRight() << endl;

	RightTriangle right2(10, 5);
	cout << right2.areaOfRight() << endl;
	cout << right2.perimeterOfRight() << endl;

	if (right1 == right2) {
		cout << "Rigth triangulars are equal." << endl; 
	}
	else {
		cout << "Right triangulars aren’t equal." << endl;
	}

	if (right1 > right2) {
		cout << "Right triangular #1 is bigger than #2." << endl;
	}
	else {
		cout << "Right triangular #1 is smaller than #2." << endl;
	}

	EquilateralTriangle equilateral1(10);
	cout << equilateral1.areaOfEquilateral() << endl;
	cout << equilateral1.perimeterOfEquilateral() << endl;

	ArbitraryTriangle arbitrary1(10, 25, 60);
	cout << arbitrary1.areaOfArbitary() << endl;
	cout << arbitrary1.perimeterOfArbitary() << endl;
	
	cout << "\nEnther side, angle 1 and angle 2 of arbitrary triangle: " << endl;
	cin >> arbitrary1;
	cout << "Total area: " << arbitrary1.areaOfArbitary() << endl;
	cout << "Total perimeter: " << arbitrary1.perimeterOfArbitary() << endl;
	
	cout << "\nEnther hypotenuse and height of right triangle: " << endl;
	cin >> right1;
	cout << "Total area: " << right1.areaOfRight() << endl;
	cout << "Total perimeter: " <<right1.perimeterOfRight() << endl;

	cout << "\nEnter side of equilateral triangle: " << endl;
	cin >> equilateral1;
	cout << "Total area: " << equilateral1.areaOfEquilateral() << endl;
	cout << "Total perimeter: " << equilateral1.perimeterOfEquilateral() << endl;

	cout << "\nArbitrary Triangle:" << endl;
	cout << arbitrary1;
	cout << "\nRight Triangle:" << endl;
	cout << right1;
	cout << "\nEquilateral Triangle:" << endl;
	cout << equilateral1;
}

double convert(double degree)
{
	double pi = 3.14159265359;
	return (degree * (pi / 180));
}
