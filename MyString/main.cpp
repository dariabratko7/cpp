#include <iostream>
#include "TemplateArray.h"
#include "Product.h"
using namespace std;

int main() {
    Array<Product> products;

    products.AddLast(Product("Milk", 25.5));
    products.AddLast(Product("Bread", 15.2));
    products.Add(1, Product("Eggs", 30.0));

    cout << "Products list:" << endl;
    products.Output();

    products.Dell(1); // видалити Eggs
    cout << "\nAfter deletion:" << endl;
    products.Output();

    return 0;
}