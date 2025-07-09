#ifndef UNDO_REDO_MANAGER_H
#define UNDO_REDO_MANAGER_H

#include <stack>
#include <string>

class UndoRedoManager {
private:
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;

public:
    void saveState(const std::string& state);
    std::string undo(const std::string& currentState);
    std::string redo(const std::string& currentState);
    void clearRedo();
};

#endif
