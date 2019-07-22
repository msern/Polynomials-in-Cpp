// Author: Mateusz Serafin
// Student number: 160272859	

// Quadratic class header file


class Quadratic
{
public:
	// constructors
	Quadratic();
	Quadratic(float coef0, float coef1, float coef2);			

	// destructor
	~Quadratic();

	// methods
	float get_coefficient(int degree) const;
	float compute_value(float x) const;

	// operators overloading 
	friend Quadratic operator+(const Quadratic& rhs, const Quadratic& lhs);
	friend Quadratic operator-(const Quadratic& rhs, const Quadratic& lhs);

	friend bool operator==(const Quadratic& rhs, const Quadratic& lhs);
	friend bool operator!=(const Quadratic& rhs, const Quadratic& lhs);

	Quadratic& operator+=(const Quadratic& q);
	Quadratic& operator-=(const Quadratic& q);

	friend std::ostream& operator<<(std::ostream& output, const Quadratic &q);
	friend std::istream& operator>>(std::istream &input, Quadratic &q);

private:
	float coef0, coef1, coef2;
};

