#pragma once
class Vec3
{
	private:
		int cordX = 0;
		int cordY = 0;
		int cordZ = 0;
	public:
		// Constructor by default
		Vec3();
		// Destructor
		~Vec3();

		// Constructor w/ three values
		Vec3(int x, int y, int z);
		// Copy's Contructor
		Vec3(const Vec3 &vector);

		// METHODS
		int normalize();
		int distance_to(const Vec3& vector);
		int dot_product(const Vec3& vector);
		int cross_product(const Vec3& vector);
		float angle_between(const Vec3& vector);




};

