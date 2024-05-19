#include <iostream>
#include <string>
#include <string_view>

class PasswordError
{
private:
    std::string m_message{}; 
public:
    PasswordError(const std::string_view mesg):m_message{mesg}{};
    const std::string& what() const {return m_message;};
};

class LengthError : public PasswordError
{
public:
    LengthError(const std::string_view mesg):PasswordError{mesg}{};
};
class RegisterError : public PasswordError
{
public:
    RegisterError(const std::string_view mesg):PasswordError{mesg}{};
};
class DigitError : public PasswordError
{
public:
    DigitError (const std::string_view mesg):PasswordError{mesg}{};
};
class ForbiddenLetterError : public PasswordError 
{
public:
    ForbiddenLetterError (const std::string_view mesg):PasswordError{mesg}{};
};

void lengthCheck(std::string_view);
void registerCheck(std::string_view);
void digitCheck(std::string_view);
void flCheck(std::string_view);

std::string_view get_password()
{
    std::string pass{};
    std::cin >> pass;
    lengthCheck(pass);
    registerCheck(pass);
    digitCheck(pass);
    flCheck(pass);
    return pass;
};

void lengthCheck(std::string_view pass)
{
    if (pass.size() < 9)
        throw LengthError{"your password is too short"};
};

void registerCheck(std::string_view pass)
{
    bool hasUpper{};
    bool hasLower{};
    for(auto ch : pass){
        if (ch >= 'A' && ch <= 'Z')
            hasUpper = true;
        else if (ch >= 'a' && ch <= 'z')
            hasLower = true;
        if (hasUpper && hasLower)
            return;
    }
    throw RegisterError{"all characters in your password are of the same register"};
};

void digitCheck(std::string_view pass)
{
    bool hasDigit{};
    for (auto ch : pass){
        if (ch >= '0' && ch <= '9')
            hasDigit = true;
        if (hasDigit)
            return;
    }
    throw DigitError{"your password has no digits in it"};
};

void flCheck(std::string_view pass)
{
    char confusChars[6]{'o','O','0','I','l','1'};
    for (auto ch : pass){
        for (auto cch : confusChars){
            if (ch == cch)
                throw ForbiddenLetterError{"your password contains one of the forbidden letters"};
        }
    }
};

int main(){
    try
    {
    std::string pass{get_password()};
    }
    catch(const LengthError err){std::cout << err.what() << '\n';}
    catch(const RegisterError err){std::cout << err.what() << '\n';}
    catch(const DigitError err){std::cout << err.what() << '\n';}
    catch(const ForbiddenLetterError err){std::cout << err.what() << '\n';}


    return 0;
};
