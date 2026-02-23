#include "VersionManager.h"

int VersionManager::saveVersion(const std::string& content) {
    versions[++versionCounter] = content;
    return versionCounter;
}

std::string VersionManager::getVersion(int versionNum) const {
    auto it = versions.find(versionNum);
    if (it != versions.end())
        return it->second;
    return "";
}

bool VersionManager::versionExists(int versionNum) const {
    return versions.find(versionNum) != versions.end();
}
