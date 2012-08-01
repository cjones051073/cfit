
#include <cfit/models/exponential.hh>
#include <cfit/math.hh>


Exponential::Exponential( const Variable& x, const Parameter& gamma )
  : _hasLower( false ), _hasUpper( false ), _lower( 0.0 ), _upper( 0.0 )
{
  push( x );

  push( gamma );

  cache();
}


Exponential* Exponential::copy() const
{
  return new Exponential( *this );
}


double Exponential::gamma()  const
{
  return getPar( 0 ).value();
}


void Exponential::setLowerLimit( const double& lower )
{
  _hasLower = true;
  _lower    = lower;

  cache();
}


void Exponential::setUpperLimit( const double& upper )
{
  _hasUpper = true;
  _upper    = upper;

  cache();
}


void Exponential::setLimits( const double& lower, const double& upper )
{
  _hasLower = true;
  _hasUpper = true;
  _lower    = lower;
  _upper    = upper;

  cache();
}


void Exponential::unsetLowerLimit()
{
  _hasLower = false;

  cache();
}


void Exponential::unsetUpperLimit()
{
  _hasUpper = false;

  cache();
}


void Exponential::unsetLimits()
{
  _hasLower = false;
  _hasUpper = false;

  cache();
}


void Exponential::cache()
{
  // Compute the norm as ( exp( - gamma x_min ) - exp( - gamma x_max ) ) / gamma.
  // Within the standard range ( 0, +infinity ), the norm is 1/gamma.
  const double& vgamma = gamma();

  double expmin = 1.0;
  if ( _hasLower )
    expmin = std::exp( - vgamma * _lower );

  double expmax = 0.0;
  if ( _hasUpper )
    expmax = std::exp( - vgamma * _upper );

  _norm = ( expmin - expmax ) / vgamma;
}


double Exponential::evaluate( double x ) const throw( PdfException )
{
  // Return 0 if x is outside the upper or lower limits.
  if ( _hasLower )
  {
    if ( x < _lower )
      return 0.0;
  }
  else
    if ( x < 0.0 )
      return 0.0;

  if ( _hasUpper && ( x > _upper ) )
    return 0.0;

  return std::exp( - gamma() * x ) / _norm;
}


double Exponential::evaluate() const throw( PdfException )
{
  return evaluate( getVar( 0 ).value() );
}


double Exponential::evaluate( const std::vector< double >& vars ) const throw( PdfException )
{
  return evaluate( vars[ 0 ] );
}