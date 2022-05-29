#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
	const int n = 20;
	double d[n][n];
	double pomd;
	double h = 0.251327;

	fstream plik;
	fstream pochX;
	fstream pochY;
	fstream monoX;
	fstream monoY;
	plik.open("135207.dat", ios::in);
	pochX.open("pochX.txt", ios::out);
	pochY.open("pochY.txt", ios::out);
	monoX.open("monoX.txt", ios::out);
	monoY.open("monoY.txt", ios::out);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik >> pomd >> pomd >> d[i][j];
		}
	}

	double Px[20][20];
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			Px[i][j] = (d[i + 1][j] - d[i - 1][j]) / (2 * h);
			pochX << i * h << '\t' << j * h << '\t' << Px[i][j] << "\n";

			if (Px[i][j] < 0)
			{
				monoX << i * h << '\t' << j * h << '\t' << -1 << "\n";
			}
			if (Px[i][j] > 0)
			{
				monoX << i * h << '\t' << j * h << '\t' << 1 << "\n";
			}
		}
	}

	double Py[n][n];
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			Py[i][j] = (d[i][j + 1] - d[i][j - 1]) / (2 * h);

			if (Py[i][j] > 0)
			{
				Py[i][j] = Py[i][j];
			}
			else
			{
				Px[i][j] = -Px[i][j];
			}
			pochY << i * h << '\t' << j * h << '\t' << Py[i][j] << "\n";

			if (Py[i][j] < 0)
			{
				monoY << i * h << '\t' << j * h << '\t' << -1 << "\n";
			}

			if (Py[i][j] > 0)
			{
				monoY << i * h << '\t' << j * h << '\t' << 1 << "\n";
			}
		}
	}
	plik.close();
	monoX.close();
	monoY.close();
	pochX.close();
	pochY.close();
	return 0;
}