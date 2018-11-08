#ifndef MYBOX_INCLUDE_BASE64_H_
#define MYBOX_INCLUDE_BASE64_H_

#include <string>

std::string base64_encode(const char *, unsigned int len);
std::string base64_decode(std::string const &s);

#endif // MYBOX_INCLUDE_BASE64_H_
