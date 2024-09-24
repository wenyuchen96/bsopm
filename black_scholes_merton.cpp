#include <iostream>
#include <string>
#include <cmath>
// implement Black - Scholes - Merton ("BSM") Option Pricing Model to value a european call and a put option

/*
BSM model inputs
s: stock price
k: strike price
t: time to expiration
r: risk-free rate
q: dividend yield
sigma: volatility
type: option type "call" or "put"
*/

// cumulative distribution function of a standard normal distribution
double normal_cdf(double x)
{
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double black_scholes(double s, double k, double t, double r, double q, double sigma, std::string type = "call")
{
    // define the variables
    double d1 = (log(s / k) + (r - q + pow(sigma, 2) / 2.0) * t) / (sigma * sqrt(t));
    double d2 = d1 - sigma * sqrt(t);
    double c;
    double p;

    if (type == "call")
    {
        c = s * exp(-q * t) * normal_cdf(d1) - k * exp(-r * t) * normal_cdf(d2);
        return std::round(c * 100.0) / 100.0;
    }
    else if (type == "put")
    {
        p = k * exp(-r * t) * normal_cdf(-d2) - s * exp(-q * t) * normal_cdf(-d1);
        return std::round(p * 100.0) / 100.0;
    }
    return 0.0;
}

int main()
{
    double s;
    double k;
    double t;
    double r;
    double q;
    double sigma;
    std::string type;

    std::cout << "stock price: s\n";
    std::cin >> s;

    std::cout << "strike price: k\n";
    std::cin >> k;

    std::cout << "time to expiration: t\n";
    std::cin >> t;

    std::cout << "risk-free rate: r\n";
    std::cin >> r;

    std::cout << "dividend yield: q\n";
    std::cin >> q;

    std::cout << "volatility: sigma\n";
    std::cin >> sigma;

    std::cout << "option type(call/put):\n";
    std::cin >> type;

    std::cout << "The " << type << " option valuation is " << black_scholes(s, k, t, r, q, sigma, type) << ".\n";

    return 0;
}