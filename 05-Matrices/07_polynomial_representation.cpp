/*
Program Name: Special Matrices - Polynomial Representation & Addition


1. MATHEMATICAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A polynomial P(x) = a_n*x^n + a_(n-1)*x^(n-1) + ... + a_0
   - Represented dynamically as an array of 'n' Terms, where each Term contains:
     * `coeff`: Coefficient value
     * `exp`  : Exponent/Power value

2. ADDITION ALGORITHM (Two-Pointer Technique):
----------------------------------------------------------------------------------------------------
   - Traverse terms of both polynomials using pointers `i` and `j`.
   - If exp1 > exp2 -> Copy term 1 to sum polynomial.
   - If exp2 > exp1 -> Copy term 2 to sum polynomial.
   - If exp1 == exp2 -> Add coefficients (coeff1 + coeff2) and keep common exponent!

3. TIME & SPACE COMPLEXITY:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n1 + n2) linear time.
   - Space Complexity: O(n1 + n2) for storing sum terms.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Term Structure holding coefficient and exponent
struct Term {
    int coeff;
    int exp;
};

class Polynomial {
private:
    int n;          // Number of non-zero terms
    Term *terms;    // Dynamic array of terms

public:
    // Constructor
    Polynomial(int n) {
        this->n = n;
        terms = new Term[this->n];
    }

    // Set specific term at index
    void SetTerm(int index, int coeff, int exp) {
        if (index >= 0 && index < n) {
            terms[index].coeff = coeff;
            terms[index].exp = exp;
        }
    }

    // Display Polynomial in standard mathematical form: 3x^4 + 2x^2 + 5
    void Display() {
        for (int i = 0; i < n; i++) {
            cout << terms[i].coeff << "x^" << terms[i].exp;
            if (i < n - 1) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    // Add two Polynomials
    Polynomial Add(const Polynomial &p) {
        int i = 0, j = 0, k = 0;

        // Maximum possible terms in result
        Polynomial *sum = new Polynomial(n + p.n);

        while (i < n && j < p.n) {
            if (terms[i].exp > p.terms[j].exp) {
                sum->terms[k++] = terms[i++];
            } else if (terms[i].exp < p.terms[j].exp) {
                sum->terms[k++] = p.terms[j++];
            } else {
                // Same exponent -> Add coefficients
                sum->terms[k].exp = terms[i].exp;
                sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
            }
        }

        // Copy remaining terms of first polynomial
        for (; i < n; i++) sum->terms[k++] = terms[i];

        // Copy remaining terms of second polynomial
        for (; j < p.n; j++) sum->terms[k++] = p.terms[j];

        sum->n = k; // Actual terms in sum
        return *sum;
    }

    // Destructor
    ~Polynomial() {
        delete[] terms;
    }
};

int main() {
    cout << "--- Polynomial Representation & Addition ---" << endl;

    // Polynomial 1: 3x^4 + 2x^2 + 5x^0
    Polynomial p1(3);
    p1.SetTerm(0, 3, 4);
    p1.SetTerm(1, 2, 2);
    p1.SetTerm(2, 5, 0);

    // Polynomial 2: 5x^4 + 3x^3 + 1x^2 + 7x^0
    Polynomial p2(4);
    p2.SetTerm(0, 5, 4);
    p2.SetTerm(1, 3, 3);
    p2.SetTerm(2, 1, 2);
    p2.SetTerm(3, 7, 0);

    cout << "\nPolynomial 1: "; p1.Display();
    cout << "Polynomial 2: "; p2.Display();

    // Addition
    Polynomial sum = p1.Add(p2);

    cout << "\nSum Polynomial (P1 + P2): ";
    sum.Display();

    return 0;
}