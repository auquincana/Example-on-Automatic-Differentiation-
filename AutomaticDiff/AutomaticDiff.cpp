// AutomaticDiff.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <stack>

// Input: x_0.....x_n-1
// Output: (suma x_i_cuadrado)_cuadrado

void sum_cuadrado(unsigned int n, const std::vector<double>& x, double& y)
{
	y = 0.0;
	for (unsigned int i = 0; i < n; i++)
	{
		y = y + x[i] * x[i];
	}
	y = y * y;
}

void sum_cuadrado_tng(unsigned int n, const std::vector<double>& x, double& y, const std::vector<double>& x_tng, double& y_tng)
{
	y_tng = 0.0;
	y = 0.0;
	for (unsigned int i = 0; i < n; i++)
	{
		y_tng = y_tng + 2 * x[i] * x_tng[i];
		y = y + x[i] * x[i];
	}

	y_tng = 2 * y * y_tng;
	y = y * y;
}

            
void sum_cuadrado_adj(unsigned int n, const std::vector<double>& x, double& y, std::vector<double>& x_adj, double& y_adj)
{
	std::stack<double> required_double;
	std::stack<double> result_double;

	y = 0.0;
	for (unsigned int i = 0; i < n; i++)
	{
		y = y + x[i] * x[i];
	}

	// Insertamos el resultado parcial de y en required_double, este nos sirve para las derivadas
	required_double.push(y);
	y = y * y;
	// Insertamos el resultado en result_double
	result_double.push(y);

	y = required_double.top();
	required_double.pop();
	y_adj = 2 * y * y_adj;

	for (int i = n-1; i >= 0; i--)
	{

		x_adj.at(i) = 2 * x[i] * y_adj;
	}

	y = result_double.top();
	result_double.pop();
}

           
void mult_todas_adj(unsigned int n, const std::vector<double>& x, double& y, std::vector<double>& x_adj, double& y_adj)
{
	
	std::stack<double> required_v; // Resultado Parcial, tiene n-1 datos
	std::stack<double> result_double;

	y = 1.0;
	for (unsigned int i = 1; i < n; i++)
	{
		y = y * x[i - 1];
		// Insertamos el resultado parcial de y en required_double
		required_v.push(y); 
	}

	// Derivadas intermedias
	x_adj.at(n - 1) = y_adj;
	for (int i = n - 2; i >= 0; i--)
	{
		x_adj.at(i) = x[i+1] * x_adj[i+1];
	}

	for (int i = n - 1; i > 0; i--)
	{
		y_adj = required_v.top();
		x_adj.at(i) = x_adj[i] * y_adj;
		required_v.pop();
	}

}


