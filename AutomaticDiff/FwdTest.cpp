#include "stdafx.h"
#include "FwdTest.h"


FwdTest::FwdTest(double _nominal, double _spot, double _discFuerte, double _discDebil) : nominal(_nominal), spot(_spot), discFuerte(_discFuerte), discDebil(_discDebil)
{
    fwdPrice = spot * discFuerte / discDebil;
}


FwdTest::~FwdTest()
{
}

double FwdTest::ForwardPrice() const
{
    return fwdPrice;
}

double FwdTest::Value(double strike) const
{
    double value = nominal * (fwdPrice - strike);
    
    return value;
}

double FwdTest::Derivative(double strike)  const
{
    double Dvalue = - nominal;

    return Dvalue;
}
