// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
  coefficients.push_back(0.0);
}

Polynomial::Polynomial(const vector<double> &coeffs)
{
  coefficients = coeffs;
}

Polynomial Polynomial::setCoeffs(const vector<double>& coeffs)
{
  coefficients = coeffs;
  return *this;
}

int Polynomial::degree() const
{
  return coefficients.size() - 1;
}

// Operator overload for assignment
Polynomial &Polynomial::operator=(const Polynomial &p)
{
  coefficients = p.coefficients;
  return *this;
}

// Operator overload for addition
Polynomial Polynomial::operator+(const Polynomial &other) const
{
  int maxDegree = max(degree(), other.degree());
  vector<double> resultCoeffs(maxDegree + 1, 0.0);

  for (int i = 0; i <= maxDegree; i++)
  {
    if (i <= degree())
    {
      resultCoeffs[i] += coefficients[i];
    }
    if (i <= other.degree())
    {
      resultCoeffs[i] += other.coefficients[i];
    }
  }
  return Polynomial(resultCoeffs);
}

// Operator overload for subtraction
Polynomial Polynomial::operator-(const Polynomial &other) const
{
  int maxDegree = max(degree(), other.degree());
  vector<double> resultCoeffs(maxDegree + 1, 0.0);

  for (int i = 0; i <= maxDegree; i++)
  {
    if (i <= degree())
    {
      resultCoeffs[i] += coefficients[i];
    }
    if (i <= other.degree())
    {
      resultCoeffs[i] -= other.coefficients[i];
    }
  }
  return Polynomial(resultCoeffs);
}

// Operator overload for multiplication
Polynomial Polynomial::operator*(const Polynomial &other) const
{
  // The degree of the result is the sum of the degrees
  vector<double> resultCoeffs(degree() + other.degree() + 1, 0.0);

  // Multiply each term of this polynomial by each term of the other polynomial
  // for loop will go over each degree twice
  for (int i = 0; i <= degree(); ++i)
  {
    for (int j = 0; j <= other.degree(); ++j)
    {
       // Add product to the correct degree
      resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
    }
  }
  return Polynomial(resultCoeffs);
}

// Operator overload for division, returning a pair (quotient, remainder)
pair<Polynomial, Polynomial> Polynomial::operator/(const Polynomial &divisor) const
{
  vector<double> quotientCoeffs(degree() - divisor.degree() + 1, 0);
  // Start with dividend as remainder
  vector<double> remainderCoeffs = coefficients; 

  int divisorDegree = divisor.degree();
  // Leading coefficient of the divisor
  int divisorLeadingCoeff = divisor.coefficients.back(); 

  // polynomial long division
  while (remainderCoeffs.size() > divisor.coefficients.size() - 1)
  {
    int remainderDegree = remainderCoeffs.size() - 1;
    // Step 1: divide leading coefficients of divident and divisor
    int coeffQuotient = remainderCoeffs.back() / divisorLeadingCoeff;

    // Determine the position for the coefficient in the quotient
    int quotientPos = remainderDegree - divisorDegree;
    quotientCoeffs[quotientPos] = coeffQuotient;

    // Step 2: subtract (divisor*coeffQuotient) from leading terms of dividend
    // the difference is the new dividend for the next step
    for (int i = 0; i <= divisorDegree; i++)
    {
      remainderCoeffs[quotientPos + i] -= divisor.coefficients[i] * coeffQuotient;
    }

    // Step 3: repeat division process with new dividend
    // Remove the highest degree term from the remainder
    remainderCoeffs.pop_back();
  }

  // Create quotient and remainder polynomials
  Polynomial quotient(quotientCoeffs);
  Polynomial remainder(remainderCoeffs);

  return {quotient, remainder}; // Return as pair
}

// Operator overload for insertion
ostream& operator<<(ostream &output, const Polynomial &p)
{
  string poly;
  for(int i = 0; i <= p.degree(); i++)
  {
    if (p.degree() == 0)
    {
      poly += to_string(p.coefficients[i]);
    }
    else 
      if (p.degree() == 1)
      {
        poly += to_string(p.coefficients[i]) + 'x' + ' ' + '+' + ' ';
      }
      else 
      {
        poly += to_string(p.coefficients[i]) + 'x' + '^' + to_string(p.degree() - i) + ' ' + '+' + ' ';
      }
  }
  output << poly;
  return output;
}

bool process_input(string &input, char &poly, string &fileName)
{
  bool valid;
  return valid;
}
