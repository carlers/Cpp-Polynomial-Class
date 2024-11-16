// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#ifndef POLYNOMIALHEADERDEF
#define POLYNOMIALHEADERDEF

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Polynomial
{
  private:
    vector<double> coefficients;

  public:
    Polynomial();
    Polynomial(const vector<double>& coeffs);
    Polynomial setCoeffs(const vector<double>& coeffs);

    Polynomial &operator=(const Polynomial &p);
    Polynomial operator+(const Polynomial &p) const;
    Polynomial operator-(const Polynomial &p) const;
    Polynomial operator*(const Polynomial &p) const;
    pair<Polynomial, Polynomial> operator/(const Polynomial& divisor) const;

    friend ostream& operator<<(ostream &output,
                         const Polynomial &p);
    int degree() const;

};

bool process_input(string &input, char &poly, string &fileName);

#endif