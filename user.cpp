#include "user.h"

User::User() = default;
User::User(const std::string & login, const std::string & password, const std::string & name) : _login(login), _password(password), _name(name) {}
User::~User() {}

std::string User::getUserLogin() const { return _login; }
std::string User::getUserPassword() const { return _password; }
void User::setUserPassword(std::string& password) { _password = password; }
std::string User:: getUserName() const { return _name; }
void User::setUserName(std::string& name) { _name = name; }
