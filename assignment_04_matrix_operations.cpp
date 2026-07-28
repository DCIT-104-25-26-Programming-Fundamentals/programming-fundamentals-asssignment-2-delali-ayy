// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows, cols;

    cout << "PART A - Matrix Transpose" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix1, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, result, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(result, cols, rows);

    cout << "\nPART B - Matrix Addition" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter Matrix 1" << endl;
    readMatrix(matrix1, rows, cols);

    cout << "Enter Matrix 2" << endl;
    readMatrix(matrix2, rows, cols);

    addMatrices(matrix1, matrix2, result, rows, cols);

    cout << "\nSum of Matrices:" << endl;
    displayMatrix(result, rows, cols);

    cout << "\nPART C - Matrix Multiplication" << endl;

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for Matrix A: ";
    cin >> colsA;

    readMatrix(matrix1, rowsA, colsA);

    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Error: Matrix multiplication is not possible." << endl;
        return 0;
    }

    readMatrix(matrix2, rowsB, colsB);

    multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, colsB);

    cout << "\nProduct of Matrices:" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}

