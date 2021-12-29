#include "header.cpp"

const int NMAX = 20;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        puts("Не заданы параметры программы.\nДля продолжения нажмите любую клавишу . . .");
        getch();
        return 1;
    }

    int N;
    int **A;
    int *X;

    if (matrixInput(argv, N, A) == 1)
        return 1;

    if (matrixOutput(argv, N, A) == 1)
    {
        matrixDelete(N, A);
        return 1;
    }

    if (countRowsWithZeroElements(N, A) <= 2)
    {
        formArray(N, A, X);    
        if (arrayOutput(argv, N, X) == 1)
        {
            matrixDelete(N, A);
            return 1;
        }

        delete [] X;
    }
    else
        messageOutput(argv);

    matrixDelete(N, A);

    puts("Для продолжения нажмите любую клавишу . . .");
    getch();

    return 0;
}