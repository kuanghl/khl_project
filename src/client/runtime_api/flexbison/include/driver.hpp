#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>


namespace CP{
class Parser;
class Scanner;

class Driver{
public:
   Driver() = default;
   virtual ~Driver();
   void parse( const char * const filename );
   void parse( std::istream &iss );

private:
   CP::Parser  *parser  = nullptr;
   CP::Scanner *scanner = nullptr;
};

} /* end namespace  */
#endif /* END __DRIVER_HPP__ */
