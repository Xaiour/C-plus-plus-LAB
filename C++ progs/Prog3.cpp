#include <iostream>
using namespace std;

const int MAX = 10;  
 
void readMatrix(int mat[MAX][MAX], int r, int c) {
    cout << "Enter elements (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
}

 
void printMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

 
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

 
void subMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

 
void mulMatrix(int A[MAX][MAX], int r1, int c1, int B[MAX][MAX], int r2, int c2, int C[MAX][MAX]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

 
void transposeMatrix(int A[MAX][MAX], int r, int c, int C[MAX][MAX]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;
    char choice;

    do {
        cout << "\n================ MATRIX MENU ================\n";
        cout << "(a) Addition\n";
        cout << "(b) Subtraction\n";
        cout << "(c) Multiplication\n";
        cout << "(d) Transpose\n";
        cout << "(e) Exit\n";
        cout << "Enter your choice (a-e): ";
        cin >> choice;

        switch (choice) {
            case 'a':
            case 'A': {
                cout << "Enter rows and columns for matrices: ";
                cin >> r1 >> c1;
                readMatrix(A, r1, c1);
                readMatrix(B, r1, c1);
                addMatrix(A, B, C, r1, c1);
                cout << "\nResult (Addition):\n";
                printMatrix(C, r1, c1);
                break;
            }
            case 'b':
            case 'B': {
                cout << "Enter rows and columns for matrices: ";
                cin >> r1 >> c1;
                readMatrix(A, r1, c1);
                readMatrix(B, r1, c1);
                subMatrix(A, B, C, r1, c1);
                cout << "\nResult (Subtraction):\n";
                printMatrix(C, r1, c1);
                break;
            }
            case 'c':
            case 'C': {
                cout << "Enter rows and columns for Matrix A: ";
                cin >> r1 >> c1;
                cout << "Enter rows and columns for Matrix B: ";
                cin >> r2 >> c2;
                if (c1 != r2) {
                    cout << "\nError: Multiplication not possible! Columns of A must equal rows of B.\n";
                } else {
                    readMatrix(A, r1, c1);
                    readMatrix(B, r2, c2);
                    mulMatrix(A, r1, c1, B, r2, c2, C);
                    cout << "\nResult (Multiplication):\n";
                    printMatrix(C, r1, c2);
                }
                break;
            }
            case 'd':
            case 'D': {
                cout << "Enter rows and columns for the matrix: ";
                cin >> r1 >> c1;
                readMatrix(A, r1, c1);
                transposeMatrix(A, r1, c1, C);
                cout << "\nResult (Transpose):\n";
                printMatrix(C, c1, r1); // Dimensions swap for transpose
                break;
            }
            case 'e':
            case 'E':
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please select between 'a' and 'e'.\n";
        }
    } while (choice != 'e' && choice != 'E');

    return 0;
}