#include <iostream>
#include "isp.hpp"

void Printer::print(Document &d)
{

    std::cout << "printing document"
              << std::endl;
}

void Scanner::scan(Document &d)
{

    std::cout << "scanning document"
              << std::endl;
}

Machine::Machine(IPrinter &printer,
                 IScanner &scanner) : printer{printer},
                                      scanner{scanner}
{
}

void Machine::print(Document &d)
{

    printer.print(d);
}

void Machine::scan(Document &d)
{

    scanner.scan(d);
}