#pragma once
class Vector3
{
public:
	Vector3(float _x,float _y, float _z);
	~Vector3();
	struct position
	{
		float x;
		float y;
		float z;
	};
	struct size
	{
		float x = 1;
		float y = 1;
		float z = 1;
	};
	struct rotation {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	position pos;
	size size;
	rotation rot;
};

