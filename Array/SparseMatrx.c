#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100
struct Element {
    int row, col, value;
};
struct SparseMatrix {
    int rows, cols, numElements;
    struct Element data[MAX_ROWS * MAX_COLS];
};
void initializeSparseMatrix(struct SparseMatrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->numElements = 0;
}
void insertElement(struct SparseMatrix *matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid row or column index. Insertion failed.\n");
        return;
    }
    matrix->data[matrix->numElements].row = row;
    matrix->data[matrix->numElements].col = col;
    matrix->data[matrix->numElements].value = value;
    matrix->numElements++;
}
int searchElement(struct SparseMatrix *matrix, int row, int col) {
    for (int i = 0; i < matrix->numElements; i++) {
        if (matrix->data[i].row == row && matrix->data[i].col == col) {
            return matrix->data[i].value;
        }
    }
    return 0; 
}
int main() {
    struct SparseMatrix matrix;
    int rows, cols;
    printf("Enter the number of rows and columns for the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    initializeSparseMatrix(&matrix, rows, cols);
    int row, col, value;
    printf("Enter elements in the format <row column value>. Enter -1 -1 -1 to stop.\n");
    while (1) {
        scanf("%d %d %d", &row, &col, &value);
        if (row == -1 && col == -1 && value == -1) {
            break;
        }
        insertElement(&matrix, row, col, value);
    }
    printf("Enter the row and column to search for an element: ");
    scanf("%d %d", &row, &col);
    int result = searchElement(&matrix, row, col);
    if (result != 0) {
        printf("Element found at (%d, %d): %d\n", row, col, result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}
