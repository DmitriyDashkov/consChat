#include "Message.h"

Message::Message() = default;
Message::Message(const std::string& from, const std::string& to, const std::string& message) : _from(from), _to(to), _message(message) {}
Message::~Message() {}

