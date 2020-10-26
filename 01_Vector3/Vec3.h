#ifndef VECTOR_3
#define VECTOR_3

#include <math.h>

template <typename E>
class Vec3
{
	public:
		// Attributes
		E x;
		E y;
		E z;

		// Constructor by default
		Vec3() : x(0), y(0), z(0) {}

		// Destructor -> NOT NECESSARY
		// ~Vec3() {}

		// Constructor w/ three values
		Vec3(E cordX, E cordY, E cordZ): x(cordX), y(cordY), z(cordZ) {}

		// Copy's Contructor
		Vec3(const Vec3& vector) {
			this->x = vector.x;
			this->y = vector.y;
			this->z = vector.z;
		}

		// METHODS 

		// Operator + -
		inline Vec3<E> operator+ (const Vec3<E>& vector) const{
			return Vec3<E>(this->x + vector.x, this->y + vector.y, this->z + vector.z);
		}

		inline Vec3<E> operator- (const Vec3<E>& vector) const {
			return Vec3<E>(this->x - vector.x, this->y - vector.y, this->z - vector.z);
		}

		// Functions
		inline Vec3<E> normalize() {
			const E length = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
			return Vec3<E>(this->x / length, this->y / length, this->z / length);
		}

		inline E distance_to(const Vec3<E>& vector) {
			return sqrt((this->x * vector.x) * (this->x * vector.x) +
						(this->y * vector.y) * (this->y * vector.y) +
						(this->z * vector.z) * (this->z * vector.z));
		}

		inline E dot_product(const Vec3<E>& vector) {
			return (this->x * vector.x) + (this->y * vector.y) + (this->z * vector.z);
		}

		// CROSS PRODUCT -> (a,b,c) x (d,e,f) = (bf-ce, cd-af, ae-bd)
		inline Vec3<E> cross_product(const Vec3<E>& vector) {
			return Vec3<E> (this->y * vector.z - this->z * vector.y,
				this->z * vector.x - this->x * vector.z,
				this->x * vector.y - this->y * vector.x);
		}
		inline E angle_between(const Vec3& vector) {
			return acos((this->x * vector.x + this->y * vector.y + this->z * z)/(this->dot_product(vector)));
		}
};

template <typename E>
inline std::ostream& operator<< (std::ostream& os, const Vec3<E> vector) {
	os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
	return os;
}

#endif // !VECTOR_3
