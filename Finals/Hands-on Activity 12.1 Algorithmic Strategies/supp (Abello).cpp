#include <iostream>

int countPaths(int matrix[][4], int row, int col, int cost)
{
    if (cost < 0)
    {
        return 0;
    }

    if (row == 0 && col == 0)
    {
        return (cost == matrix[0][0]) ? 1 : 0;
    }

    if (row == 0)
    {
        return countPaths(
            matrix,
            0,
            col - 1,
            cost - matrix[row][col]
        );
    }

    if (col == 0)
    {
        return countPaths(
            matrix,
            row - 1,
            0,
            cost - matrix[row][col]
        );
    }

    return countPaths(
        matrix,
        row - 1,
        col,
        cost - matrix[row][col]
    )
    +
    countPaths(
        matrix,
        row,
        col - 1,
        cost - matrix[row][col]
    );
}

int main()
{
    int matrix[4][4] =
    {
        {4, 7, 1, 6},
        {5, 7, 3, 9},
        {3, 2, 1, 2},
        {7, 1, 6, 3}
    };

    int cost = 22;

    std::cout << "Target Cost: "
              << cost << std::endl;

    std::cout << "Number of Paths: "
              << countPaths(matrix, 3, 3, cost)
              << std::endl;

    return 0;
}