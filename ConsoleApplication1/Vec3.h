#ifndef VECTOR_3
#define VECTOR_3

template <typename E>
class Vec3
{

	public:
		// Constructor by default
		Vec3() : x(0), y(0), z(0) {}
		// Destructor -> NO NECESSARY
		// ~Vec3() {}

		// Constructor w/ three values
		Vec3(E x, E y, E z) {}
		// Copy's Contructor
		Vec3(const Vec3& vector) {}

		// METHODS
		int normalize() {}
		int distance_to(const Vec3& vector) {}
		int dot_product(const Vec3& vector) {}
		int cross_product(const Vec3& vector) {}
		float angle_between(const Vec3& vector) {}

	private:
		E x;
		E y;
		E z;
};

#endif // !VECTOR_3
