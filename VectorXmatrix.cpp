#include<iostream>
using namespace std;
/*
Vector3D class
정의, 생성자정의, 더하기연산자 오버로딩 ostream 오버로딩,

*/


class vector3D
{
private:
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
	/*friend int operator*(vector3D& p, vector3D& op)
	{	
		int result;
		result = p.x*op.x + p.y*op.y + p.z*op.z;
		return result;
	}*/
};
class matrix 
{
private:

	vector3D a, b ,c;
public:
	matrix(vector3D& a, vector3D& b, vector3D& c) :a(a), b(b), c(c) {};
	 vector3D& operator*(/*vector3D& p,*/ vector3D& op)
	{	
		vector3D result;
		result.x = a.x*op.x + a.y*op.y + a.z*op.z;
		result.y = b.x*op.x + b.y*op.y + b.z*op.z;
		result.z = c.x*op.x + c.y*op.y + c.z*op.z;
		
		return result;
	}
	//friend vector3D& operator*(/*vector3D& p,*/ vector3D& op)
	// {
	//	
	//	 /*matrix n;
	//	 p.x = n.a.x*op.x + n.a.y*op.y + n.a.z*op.z;
	//	 p.y = n.b.x*op.x + n.b.y*op.y + n.b.z*op.z;
	//	 p.z = n.c.x*op.x + n.c.y*op.y + n.c.z*op.z;
	//	 return p;*/
	//	
	// }
};



int main()
{
	vector3D a(10, 20, 30);
	vector3D b(30, 20, 10);
	vector3D c = a + b;
	matrix m(vector3D(1,2,3),vector3D(4,5,6),vector3D(7,8,9));
	vector3D n = m*a;
	cout << c << n << endl;
	return 0;
}