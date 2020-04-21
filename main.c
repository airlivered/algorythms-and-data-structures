#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

int IsInt(int input)
{
    int temp, status;
    status = scanf("%d", &input);
    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("������� ��������� ���, ��������� �� ���: ");
        status = scanf("%d", &input);
}
    return input;
    }
//array functions
void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
     printf("\n");
}

void random_array(int* array, int size)
{
    for (int i = 0; i < size; i++){
        array[i] = rand() % 30 - 10;
    }
}

void input_array(int* array, int size)
{
    for (int i = 0; i < size; i++){
        printf("array[%d] = ", i);
        array[i] = IsInt(array[i]);
    }
}

void input_matrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            printf("matrix[%d][%d] = ", i + 1, j + 1);
            matrix[i][j] = IsInt(matrix[i][j]);
        }
    }
}

void random_matrix(int** matrix, int rows) {
	for (int row = 0; row < rows; row++) {
		for (int collum = 0; collum < rows; collum++) {
			matrix[row][collum] = rand() % 27;
		}
	}
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int print_matrix(int** matrix, int rows)
{
for(int i = 0; i < rows;i++) {
    for(int j = 0; j < rows;j++) {
        printf("%d ", matrix[i][j]);
        }
        printf("\n");
        }
return 0;
}

int main()
{
    int rows = 0, matrix1_flag = 1, array_flag = 0, key = 0, m_flag = 0;
    setlocale(LC_CTYPE, "ukr");
    printf("������������� ������\n����������� ������ �6\n�������� ���'���\n");
    do{
    printf("������ ����� ������� � ��������� �������:");
    rows = IsInt(rows);
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(rows * sizeof(int));
    }
    if (!matrix) {
    printf("\n����������� ���'��'\n");
    exit(1);
    }

    int *array = (int *)malloc(rows * sizeof(int));
    if (!array) {
    printf("\n����������� ���'��'\n");
    exit(1);
    }
    printf("�� �������� �������? ������ 0, ���� ���������, ��� 1, ���� ���������: ");

    do{
    matrix1_flag = IsInt(matrix1_flag);
    if (matrix1_flag == 0) {
       random_matrix(matrix, rows);
       key = 1;
    }
    else if (matrix1_flag == 1) {
        input_matrix(matrix, rows);
        key = 1;
    }
    else {
        printf("������� ��������� ���, ��������� �� ���: ");
    }
    } while (key != 1);
    printf("���� �������:\n");
    print_matrix(matrix, rows);
    printf("\n");
    key = 0;

    printf("�� �������� ������? ������ 0, ���� ���������, ��� 1, ���� ���������: ");
    do{
    array_flag = IsInt(array_flag);
    if (array_flag == 0) {
       random_array(array, rows);
       key = 1;
    }
    else if (array_flag == 1) {
        input_array(array, rows);
        key = 1;
    }
    else {
        printf("������� ��������� ���, ��������� �� ���: ");
    }
    } while (key != 1);

    printf("���� ������:\n");
    print_array(array, rows);
    printf("\n");

    for (int i = 0; i < rows; i++){
        swap(&matrix[i][i], &array[i]);
    }

    printf("ϳ��� ����� ���� �������:\n");
    print_matrix(matrix, rows);
    printf("������: \n");
    print_array(array, rows);
    free(matrix);
    free(array);

    printf("��������� ��������? ������ 0, ���� �, ��� 1, ���� ���: ");
    for(;;){
        m_flag = IsInt(m_flag);
        if (m_flag == 0||m_flag == 1){
            break;
        }
        printf("������� ��������� ���, ��������� �� ���: ");
    }
    } while (m_flag == 1);
}
