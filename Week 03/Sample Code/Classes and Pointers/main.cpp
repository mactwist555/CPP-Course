#include <iostream>
using namespace std;

class Vector2D
{
	public:
	int x, y;
};

class Vector3D : public Vector2D
{
	public:
	int z;
};

int main()
{
	Vector2D vec2d;

	vec2d.x = 10;
	vec2d.y = 20;

	Vector3D vec3d;

	vec3d.x = 50;
	vec3d.y = 30;
	vec3d.z = 20;

	Vector2D* ptrVec = &vec3d;

	cout << ptrVec->x << ", " << ptrVec->y << endl;
	cout << ptrVec->z << endl;

	return 0;
}
