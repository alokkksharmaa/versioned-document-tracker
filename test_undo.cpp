#include <iostream>
#include "UndoRedoManager.h"

int main() {
    UndoRedoManager manager;
    std::string content = "Hello";

    manager.saveState(content);
    content += " World";
    manager.saveState(content);

    content = manager.undo(content);
    std::cout << "Undo: " << content << std::endl;

    content = manager.redo(content);
    std::cout << "Redo: " << content << std::endl;

    return 0;
}
