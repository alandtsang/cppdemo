#ifndef MYBOX_INCLUDE_FILE_H_
#define MYBOX_INCLUDE_FILE_H_

#include <string>

bool CheckDirOrFileExist(const char *path);
bool WriteFile(const char *path, const std::string &msg);
std::string ReadFile(const char *path);

#endif // MYBOX_INCLUDE_FILE_H_
