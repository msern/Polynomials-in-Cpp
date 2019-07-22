// Author: Mateusz Serafin
// Student number: 160272859	

// Polynomial class header file


class Polynomial
{
public:
	// constructors
	Polynomial();
	Polynomial(int array_size);
	Polynomial(float coef[], int array_size);
	Polynomial(const Polynomial& copy);

	// destructor
	~Polynomial();

	// methods
	float get_coefficient(int degree) const; // return the co-efficient of a given power of x
	float compute_value(float x) const;		// 	compute the value of the polynomial given a value for x

	// operators overloading 
	friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);
	friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);
	friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);

	friend bool operator==(const Polynomial &lhs, const Polynomial &rhs);
	friend bool operator!=(const Polynomial &lhs, const Polynomial &rhs);

	Polynomial& operator+=(const Polynomial &p);
	Polynomial& operator-=(const Polynomial &p);
	Polynomial & operator*=(const Polynomial &p);
	Polynomial & operator=(const Polynomial& q);

	friend std::ostream& operator<<(std::ostream &output, const Polynomial &p);
	friend std::istream& operator>>(std::istream &input, Polynomial &p);

private:	
	int size; // array size 
	float *coefficients; // storing coefficients 
};

