#ifndef MOTURGATEWAY_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP
#define MOTURGATEWAY_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP

#include <exception>
#include <string>

namespace exceptions
{
    class InitializationException : public std::exception
    {
    public:
        explicit InitializationException(const char* what);
        const char* what() const noexcept override;
    private:
        const char* m_what;
    };
} // namespace exceptions

#endif // MOTURGATEWAY_EXCEPTIONS_INITIALIZATIONEXCEPTION_HPP
