#ifndef STRING
#define STRING

#include <iostream>

template <typename E>
class Str {
public:
	char* array;

	// Constructor
	Str() : {
		array = ["aa"];
	}

	// Constructor with variables 
	Str(const char* string) : {

	}

	// Destructor
	~Str() {

	}

	// Copy Constructor
	Str(const char* string) {
		array = string;
	}

	// METHODS 

	// Operator + ==
	inline Str operator+ (const Str& string) const {
		return Str(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	}

	inline bool operator== (const String& vector) {
		return true;
	}


	// Function
	inline int length() {
		return 0;
	}

	// Function
	inline void clear() {
		~Str();
	}

	inline static String GetMeAString() {
		return std::out <<
	}

private:
};


#endif // !STRING
