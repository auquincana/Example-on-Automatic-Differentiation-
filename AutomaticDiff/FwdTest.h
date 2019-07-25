#pragma once


class FwdTest
{
    public:
    FwdTest(double _nominal, double _spot, double _discFuerte, double _discDebil);

    ~FwdTest();

    double ForwardPrice() const;

    double Value(double strike) const;

    double Derivative(double strike) const;  

    double nominal = 1;
    //double strike = 0;
    double spot = 0;
    double discFuerte = 1;
    double discDebil = 1;
    double fwdPrice = 0;
    
};

