#include <iostream>
#include "VersionManager.h"

int main() {
    VersionManager vm;
    int v1 = vm.saveVersion("Hello");
    int v2 = vm.saveVersion("HelloWorld");

    std::cout << "Version " << v1 << ": " << vm.getVersion(v1) << std::endl;
    std::cout << "Version " << v2 << ": " << vm.getVersion(v2) << std::endl;

    return 0;
}
