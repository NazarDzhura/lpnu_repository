#include <iostream>
#include <cmath>
using namespace std;

double pi = 3.14159265359;
double convert(double degree);

class GeometricFigures {																		
protected:
	double area = 0;

public:
	virtual const double getArea() = 0;

};

class FlatFigures : public GeometricFigures {
public:
	virtual const double getArea() = 0;
};

class VolumetricFigures : public GeometricFigures {
protected:
	double volume = 0;

public:
	virtual const double getVolume() = 0;
};

class Circle : public FlatFigures {
private:
	double r = 0;
public:
	virtual const double getArea() {
		area = pi * (r * r);
		return area;
	}

	void printArea() {
		cout << "Area of circle: " << getArea() << endl << "\n============================================================\n" << endl;
	}

	friend istream& operator >> (istream& is, Circle& a);

	Circle(double new_r) {
		r = new_r;
	};
	~Circle() {};
};

istream& operator >> (istream& is, Circle& a) {
	cout << "Enter radius of circle: " << endl;
	is >> a.r;
	return is;
}

class Triangle : public FlatFigures {
private:
	double side1 = 0;
	double angle1 = 0, angle2 = 0, angle3 = 0;

public:
	virtual const double getArea() {
		angle3 = 180 - (angle1 + angle2);
		area = 0.5 * side1 * side1 * sin(convert(angle1)) * sin(convert(angle2)) / sin(convert(angle3));
		return area;
	}
	void printArea() {
		cout << "Area of triangle: " << getArea() << endl << "\n============================================================\n" << endl;
	}

	friend istream& operator >> (istream& is, Triangle& a);

	Triangle(double new_side1, double new_angle1, double new_angle2) {
		side1 = new_side1;
		angle1 = new_angle1;
		angle2 = new_angle2;
	};
	~Triangle() {};
};

istream& operator >> (istream& is, Triangle& a) {
	cout << "Enter side, angle 1 and angle 2 of your triangle: " << endl;
	is >> a.side1;
	is >> a.angle1;
	is >> a.angle2;
	return is;
}


class Cylinder : public VolumetricFigures {
private:
	double r = 0;
	double h = 0;

public:
	virtual const double getArea() {
		area = 2 * pi * r * h + 2 * pi * (r * r);
		return area;
	}
	virtual const double getVolume() {
		volume = pi * (r * r) * h;
		return volume;
	}
	void printArea() {
		cout << "Area of cylinder: " << getArea() << endl;
	}
	void printVolume() {
		cout << "Volume of cylinder: " << getVolume() << endl << "\n============================================================\n" << endl;
	}

	friend istream& operator >> (istream& is, Cylinder& a);

	Cylinder(double new_r, double new_h) {
		r = new_r;
		h = new_h;
	}
	~Cylinder() {};
};

istream& operator >> (istream& is, Cylinder& a) {
	cout << "Enter radius and height of cylinder: " << endl;
	is >> a.r;
	is >> a.h;
	return is;
}

class Cone : public VolumetricFigures {
private:
	double r = 0;
	double h = 0;

public:
	virtual const double getArea() {
		double l = sqrt((h * h) + (r * r));
		area = pi * r * l + pi * (r * r);
		return area;
	}
	virtual const double getVolume() {
		volume = 1 / 3 * pi * (r * r) * h;
		return volume;
	}
	void printArea() {
		cout << "Area of cone: " << getArea() << endl;
	}
	void printVolume() {
		cout << "Volume of cone: " << getVolume() << endl << "\n============================================================\n" << endl;
	}

	friend istream& operator >> (istream& is, Cone& a);

	Cone(double new_r, double new_h) {
		r = new_r;
		h = new_h;
	}
	~Cone() {};
};

istream& operator >> (istream& is, Cone& a) {
	cout << "Enter radius and height of cone: " << endl;
	is >> a.r;
	is >> a.h;
	return is;
}

class Sphere : public VolumetricFigures {
private:
	double r = 0;

public:
	virtual const double getArea() {
		area = 4 * pi * (r * r);
		return area;
	}
	virtual const double getVolume() {
		volume = 4 / 3 * pi * (r * r * r);
		return volume;
	}
	void printArea() {
		cout << "Area of sphere: " << getArea() << endl;
	}
	void printVolume() {
		cout << "Volume of sphere: " << getVolume() << endl << "\n============================================================\n" << endl;
	}

	friend istream& operator >> (istream& is, Sphere& a);

	Sphere(double new_r) {
		r = new_r;
	}
	~Sphere() {};
};

istream& operator >> (istream& is, Sphere& a) {
	cout << "Enter radius of sphere: " << endl;
	is >> a.r;
	return is;
}

int main() {
	Circle circle1(0);
	cin >> circle1;
	circle1.printArea();

	Triangle triangle1(0, 0, 0);
	cin >> triangle1;
	triangle1.printArea();

	Cylinder cylinder1(0, 0);
	cin >> cylinder1;
	cylinder1.printArea();
	cylinder1.printVolume();

	Cone cone1(0, 0);
	cin >> cone1;
	cone1.printArea();
	cone1.printVolume();

	Sphere sphere1(0);
	cin >> sphere1;
	sphere1.printArea();
	sphere1.printVolume();
}

double convert(double degree)
{
	return (degree * (pi / 180));
}