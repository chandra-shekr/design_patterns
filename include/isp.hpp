//! Interface Segregation Principle
//! - Keep your interfaces atomic (i.e, as small as possible)

#pragma once

struct Document;

/// @brief printer interface
struct IPrinter
{
    /// @brief prints documents
    /// @param Document type
    virtual void print(Document &) = 0;
};

/// @brief scanner interface
struct IScanner
{
    /// @brief scans documents
    /// @param Document type
    virtual void scan(Document &) = 0;
};

/// @brief fax interface
struct IFax
{
    /// @brief fax documents
    /// @param Document type
    virtual void fax(Document &) = 0;
};

/// @brief A machine with just a print functionality
struct Printer : IPrinter
{

    void print(Document &) override;
};

/// @brief A machine with just a scan functionality
struct Scanner : IScanner
{

    void scan(Document &) override;
};

/// @brief A machiine with both print and scan functionality
struct IMachine : IPrinter,
                  IScanner
{
};

/// @brief Building a multi-function machine using **Decorator Pattern**
struct Machine : IMachine
{
private:
    IPrinter &printer;
    IScanner &scanner;

public:
    Machine(IPrinter &, IScanner &);

    void print(Document &) override;

    void scan(Document &) override;
};