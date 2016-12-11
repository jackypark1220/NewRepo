#include<iostream>
using namespace std;

class vector3D
{
public:
	int x, y, z;
public:
	vector3D() { }
	vector3D(int x, int y, int z) :x(x), y(y), z(z)
	{
		/*cout << x << " " << y << " " << z << endl;*/
	};

	friend ostream& operator<<(ostream& op, vector3D& p)
	{
		return op << p.x << " " << p.y << " " << p.z << " " << endl;
	}
	friend vector3D& operator+(vector3D& op, vector3D& p)
	{
		vector3D a;
		a.x = op.x + p.x; a.y = op.y + p.y; a.z = op.z + p.z;
		return a;
	}
	};
class matrix
{
private:
	vector3D a, b, c;
public:
	matrix(vector3D& a, vector3D& b, vector3D& c) :a(a), b(b), c(c) {};
	friend vector3D& operator*(matrix& p, vector3D& op)
	{
		vector3D result;
		result.x = p.a.x*op.x + p.a.y*op.y + p.a.z*op.z;
		result.y = p.b.x*op.x + p.b.y*op.y + p.b.z*op.z;
		result.z = p.c.x*op.x + p.c.y*op.y + p.c.z*op.z;

		return result;
	}

};



int main()
{
	vector3D a(10, 20, 30);
	vector3D b(30, 20, 10);
	vector3D c = a + b;
	matrix m(vector3D(1, 2, 3), vector3D(4, 5, 6), vector3D(7, 8, 9));
	vector3D n = m*a;
	cout << c << n << endl;
	return 0;
}
