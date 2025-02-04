#include <iostream>
#include <string>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **matrix;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols]();
        }
    }

    

    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    int set(int r, int c, int data)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            matrix[r][c] = data;
            return 1;
        }
        return 0;
    }

    int add(Matrix m)
    {
        if (m.cols != cols || m.rows != rows)
        {
            cout << "Matrices cannot be added." << endl;
            return 0;
        }

        // Dynamically allocate memory for the result matrix
        int **n = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            n[i] = new int[cols]();
        }

        // Perform the addition
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                n[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }

        // Print the result
        cout << "Addition answer:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << n[i][j] << " ";
            }
            cout << endl;
        }

        // Cleanup result matrix
        for (int i = 0; i < rows; i++)
        {
            delete[] n[i];
        }
        delete[] n;

        return 1;
    }

    int multiply(Matrix *m)
    {
        if (cols != m->rows)
        {
            cout << "Cannot be multiplied." << endl;
            return 0;
        }

        int **n = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            n[i] = new int[m->cols];
        }

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < m->cols; j++)
            {
                n[i][j] = 0;
                for (int p = 0; p < cols; p++)
                {
                    n[i][j] += matrix[i][p] * m->matrix[p][j];
		    
                }
            }
        }

        cout << "Multiplication answer:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m->cols; j++)
            {
                cout << n[i][j] << " ";
            }
            cout << endl;
        }

        // Cleanup result matrix
        for (int i = 0; i < rows; i++)
        {
            delete[] n[i];
        }
        delete[] n;

        return 1;
    }
};

int main(int argc, char const *argv[])
{
    Matrix m1(3, 2), m2(2, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            m1.set(i, j, i + j + 2); // Example values
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m2.set(i, j, i + j + 1); // Example values
        }
    }

    // Perform addition
    m1.add(m2);

    // Perform multiplication
    m1.multiply(&m2);

    return 0;
}
