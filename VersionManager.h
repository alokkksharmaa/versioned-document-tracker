#ifndef VERSION_MANAGER_H
#define VERSION_MANAGER_H

#include <map>
#include <string>

class VersionManager {
private:
    std::map<int, std::string> versions;
    int versionCounter = 0;

public:
    int saveVersion(const std::string& content);
    std::string getVersion(int versionNum) const;
    bool versionExists(int versionNum) const;
};

#endif
