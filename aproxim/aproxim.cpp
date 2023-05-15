#include <iostream>
#include <vector>
#include <cmath>

void regression(const std::vector<double>& x, const std::vector<double>& y, double& a, double& b)
{
    double sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_xy = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    double denom = n * sum_x2 - sum_x * sum_x;
    if (denom == 0) {
        a = INFINITY;
        b = INFINITY;
    }
    else {
        a = (n * sum_xy - sum_x * sum_y) / denom;
        b = (sum_y - a * sum_x) / n;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество данных" << std::endl;
    int size;
    std::cin >> size;
    std::vector<double> x, y;

    std::cout << "Введите данные" << std::endl;
    for (int i = 0; i < size; i++) {
        double a;
        std::cout << "Введите x" << i + 1 << " ";
        std::cin >> a;
        x.push_back(a);
        std::cout << "Введите у" << i + 1 << " ";
        std::cin >> a;
        y.push_back(a);
    }

    double a, b;
    regression(x, y, a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;
}


