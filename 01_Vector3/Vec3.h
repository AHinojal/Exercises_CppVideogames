#ifndef VECTOR_3
#define VECTOR_3

template <typename E>
class Vec3
{
	public:
		// Constructor by default
		Vec3() : x(0), y(0), z(0) {}
		// Destructor -> NOT NECESSARY
		// ~Vec3() {}
		// Constructor w/ three values
		Vec3(E cordX, E cordY, E cordZ): x(cordX), y(cordY), z(cordZ) {}
		// Copy's Contructor
		Vec3(const Vec3& vector) {
			this.x = vector.x;
			this.y = vector.y;
			this.z = vector.z;
		}

		// Operatior +


		// METHODS
		inline E normalize() {
			return 
		}
		inline E distance_to(const Vec3& vector) {
			return
		}
		inline E dot_product(const Vec3& vector) {
			return
		}
		inline E cross_product(const Vec3& vector) {
			return
		}
		inline E angle_between(const Vec3& vector) {
		
		}

	private:
		E x;
		E y;
		E z;
};

#endif // !VECTOR_3
