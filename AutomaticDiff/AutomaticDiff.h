
#include <vector>
#include <iostream>
#include <stack>

void sum_cuadrado(unsigned int n, const std::vector<double>& x, double& y);

void sum_cuadrado_tng(unsigned int n, const std::vector<double>& x, double& y, const std::vector<double>& x_tng, double& y_tng);

void sum_cuadrado_adj(unsigned int n, const std::vector<double>& x, double& y, std::vector<double>& x_adj, double& y_adj);

void mult_todas_adj(unsigned int n, const std::vector<double>& x, double& y, std::vector<double>& x_adj, double& y_adj);