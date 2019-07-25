// Ejemplo de diferenciación Automatica
// 

#include "AutomaticDiff.h"


int main()
{
    double y_;

    std::vector<double> x_{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    unsigned int n{ x_.size() };

    sum_cuadrado(n, x_, y_);
    std::cout << "y: " << y_ << "\n";

    // Metodo de las tangentes
    std::vector<double> x_tng(10);
    double y_tng;

    // Cada una de las derivadas parciales.
    for (unsigned int i = 0; i < n; i++)
    {
        x_tng.at(i) = 1;
        sum_cuadrado_tng(n, x_, y_, x_tng, y_tng);
        x_tng.at(i) = 0;
        std::cout << "y_tng: " << y_tng << "\n";
    }

    // Adjoints
    std::vector<double> x_adj(10);
    double y_adj{ 1.0 };

    sum_cuadrado_adj(n, x_, y_, x_adj, y_adj);

    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << "y_adj: " << x_adj[i] << "\n";
    }

    // Adjoints
    mult_todas_adj(n, x_, y_, x_adj, y_adj);

    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << "y_adj_mult: " << x_adj[i] << "\n";
    }


    getchar();

    return 0;
}
