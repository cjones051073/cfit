#ifndef __VARIABLE_HH__
#define __VARIABLE_HH__

#include <string>

class Parameter;
class ParameterExpr;
class Function;


class Variable
{
private:
  std::string _name;
  double      _value;
  double      _error;

public:
  Variable() {}

  Variable( std::string name, double value = 0., double error = 0. )
    : _name( name ), _value( value ), _error( error )
  {}

  void set( double value, double error = -1. )
  {
    _value = value;
    if ( error >= 0. )
      _error = error;
  }
  void setValue( double value ) { _value = value; }
  void setError( double error ) { _error = error; }

  // Getters.
  std::string name()  const { return _name;  }
  double      value() const { return _value; }
  double      error() const { return _error; }


  // Binary operations that need access to this class.
  friend const Function pow( const Variable& left, const double& right );

  // Operations with variables with themselves.
  friend const Function operator+( const Variable&      left, const Variable&      right );
  friend const Function operator-( const Variable&      left, const Variable&      right );
  friend const Function operator*( const Variable&      left, const Variable&      right );
  friend const Function operator/( const Variable&      left, const Variable&      right );

  // Operations with variables as the left operand.
  friend const Function operator+( const Variable&      left, const double&        right );
  friend const Function operator-( const Variable&      left, const double&        right );
  friend const Function operator*( const Variable&      left, const double&        right );
  friend const Function operator/( const Variable&      left, const double&        right );

  friend const Function operator+( const Variable&      left, const Parameter&     right );
  friend const Function operator-( const Variable&      left, const Parameter&     right );
  friend const Function operator*( const Variable&      left, const Parameter&     right );
  friend const Function operator/( const Variable&      left, const Parameter&     right );

  friend const Function operator+( const Variable&      left, const ParameterExpr& right );
  friend const Function operator-( const Variable&      left, const ParameterExpr& right );
  friend const Function operator*( const Variable&      left, const ParameterExpr& right );
  friend const Function operator/( const Variable&      left, const ParameterExpr& right );

  // Operations with variables as the right operand.
  friend const Function operator+( const double&        left, const Variable&      right );
  friend const Function operator-( const double&        left, const Variable&      right );
  friend const Function operator*( const double&        left, const Variable&      right );
  friend const Function operator/( const double&        left, const Variable&      right );

  friend const Function operator+( const Parameter&     left, const Variable&      right );
  friend const Function operator-( const Parameter&     left, const Variable&      right );
  friend const Function operator*( const Parameter&     left, const Variable&      right );
  friend const Function operator/( const Parameter&     left, const Variable&      right );

  friend const Function operator+( const ParameterExpr& left, const Variable&      right );
  friend const Function operator-( const ParameterExpr& left, const Variable&      right );
  friend const Function operator*( const ParameterExpr& left, const Variable&      right );
  friend const Function operator/( const ParameterExpr& left, const Variable&      right );

  // Operations with functions as the left operand.
  friend const Function operator+( const Function&      left, const Variable&      right );
  friend const Function operator-( const Function&      left, const Variable&      right );
  friend const Function operator*( const Function&      left, const Variable&      right );
  friend const Function operator/( const Function&      left, const Variable&      right );

  // Operations with functions as the right operand.
  friend const Function operator+( const Variable&      left, const Function&      right );
  friend const Function operator-( const Variable&      left, const Function&      right );
  friend const Function operator*( const Variable&      left, const Function&      right );
  friend const Function operator/( const Variable&      left, const Function&      right );
};


#endif
