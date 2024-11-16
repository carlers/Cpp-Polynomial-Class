// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <string>
#include "Polynomial.h"

using namespace std;

int main()
{
  string input, fileName;
  char poly;
  Polynomial p;
  Polynomial q;

  Polynomial sum;
  Polynomial difference;
  Polynomial product = p * q;
  pair<Polynomial, Polynomial> division;
  Polynomial quotient;
  Polynomial remainder;

  while (1)
  {
    cout << "\n==================== Polynomial Calculator ====================\n";
    cout << "\n    p = " << p << endl;
    cout << "    q = " << q << endl;

    sum = p + q;
    cout << "p + q = " << sum << endl;

    difference = p - q;
    cout << "p - q = " << difference << endl;

    cout << "p * q = " << product << endl;

    division = p / q;
    quotient = division.first;
    remainder = division.second;
    cout << "p / q = " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
    cout << "\n===============================================================\n";

    /* do
    {
      cout << '\n'
           << "\nEnter 'q' to exit the program." << '\n'
           << "Enter a command. Format: *variable* *filename* (ex. p poly1.txt): ";
      getline(cin, input);
    } while (!process_input(input, poly, fileName));
    // process_input(input) returns false if invalid input */

    cout << "Enter a command. Format: *variable* *filename* (ex. p poly1.txt): ";
    cin >> poly;
    cin >> fileName;

    // open file
    fstream file(fileName, ios::in);
    string line, degree;
    vector<double> coeffs;
    if (file.is_open())
    {
      getline(file, line);   // POLYNOMIAL
      getline(file, degree); // degree ex. 5
      for (int i = 0; i < stoi(degree); i++)
      {
        getline(file, line);
        coeffs.push_back(stod(line));
      }
      file.close();
    }

    if (poly == 'p')
    {
      p.setCoeffs(coeffs);
    }
    else
    {
      q.setCoeffs(coeffs);
    }
  }
}
