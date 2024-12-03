#include "imports.hpp"

#include "./medium"


int main(void)
{
    // tests here
    Store newCase;

    newCase.InsertItem(1);

    newCase.InsertItem(69);

    newCase.RemoveItem(69);

    cout << newCase.getRandomValue() << endl;

    return 0;
}