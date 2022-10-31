#include <iostream>


bool checkRowForSymbols(const std::string& row)
{
    std::string permittedChars = "XO.";
    bool good_row = true;
    int found;
    for (char i : row)
    {
        found = (int) permittedChars.find(i);
        if (found == -1)
        {
            good_row = false;
            break;
        }
    }
    return good_row;
}


int countSymbolInRow(const std::string& row, char symbol)
{
    int counter = 0;
    for (char i : row)
    {
        if (i == symbol) counter++;
    }
    return counter;
}


bool checkTableAndCountXO(const std::string table[3], int &count_X, int &count_O)
{
    bool good_row;
    for (int i = 0; i < table->length(); i++)
    {
        good_row = table[i].length() == 3 && checkRowForSymbols(table[i]);
        count_X += countSymbolInRow(table[i], 'X');
        count_O += countSymbolInRow(table[i], 'O');
        if (!good_row)
        {
            std::cout << "Incorrect" << std::endl;
            break;
        }
    }
    return good_row;
}


char findWinner(std::string field)
{
    char first_sym = field[0];
    int count_sym = 0;
    for (char i : field)
    {
        if (i == first_sym) count_sym++;
    }
    if (count_sym == 3) return first_sym;
    else return '.';
}


std::string getColumn(std::string rows[3], int n_th_col)
{
    std::string column;
    for (int i = 0; i < 3; i++)
    {
        column += rows[i][n_th_col];
    }
    return column;
}


std::string getDiagonal(std::string rows[3], int n_th_diagonal)
{
    std::string diagonal;
    int j = n_th_diagonal == 0 ? 0 : 2;
    for (int i = 0; i < 3; i++)
    {
        diagonal += rows[i][j];
        n_th_diagonal == 0 ? j++ : j--;
    }
    return diagonal;
}


void countWins(
        const char columns[],
        const char rows[],
        const char diagonals[],
        int &count_won_X,
        int &count_won_O
        )
{
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
        {
            if (columns[i] == 'X' || rows[i] == 'X' || diagonals[i] == 'X') count_won_X += 1;
            else if (columns[i] == 'O' || rows[i] == 'O' || diagonals[i] == 'O') count_won_O += 1;
        }
        else
        {
            if (columns[i] == 'X' || rows[i] == 'X') count_won_X += 1;
            else if (columns[i] == 'O' || rows[i] == 'O') count_won_O += 1;
        }
    }
}


void showResultMessage(int count_won_X, int count_won_O, int count_X, int count_O)
{
    if (count_won_X == 0 && count_won_O == 0)
    {
        if (count_X >= count_O) std::cout << "Nobody" << std::endl;
        else std::cout << "Incorrect" << std::endl;
    }
    else if (count_won_X == 1 && count_won_O == 0)
    {
        if (count_X - 1 == count_O) std::cout << "Petya won" << std::endl;
        else std::cout << "Incorrect" << std::endl;
    }
    else if (count_won_X == 0 && count_won_O == 1)
    {
        if (count_X == count_O) std::cout << "Vanya won" << std::endl;
        else std::cout << "Incorrect" << std::endl;
    }
    else std::cout << "Incorrect" << std::endl;
}


int main()
{
    while (true)
    {
        std::string rows[3] = {};
        std::cout << "Enter the tic-tac-toe table:" << std::endl;
        for (std::string& row : rows)
        {
            std::getline(std::cin, row);
            if (row == "quit") break;
        }
        if (rows[0] == "quit") break;

        int count_X = 0, count_O = 0;
        bool good_table = checkTableAndCountXO(rows, count_X, count_O);

        if (good_table)
        {
            char columns[3] = {};
            for (int i = 0; i < 3; i++)
            {
                columns[i] = findWinner(getColumn(rows, i));
            }
            char diagonals[2] = {};
            for (int i = 0; i < 2; i++)
            {
                diagonals[i] = findWinner(getDiagonal(rows, i));
            }
            char row_won[3] = {};
            for (int i = 0; i < 3; i++)
            {
                row_won[i] = findWinner(rows[i]);
            }

            int count_won_X = 0, count_won_O = 0;
            countWins(columns, row_won, diagonals, count_won_X, count_won_O);
            showResultMessage(count_won_X, count_won_O, count_X, count_O);
        }
    }
}
