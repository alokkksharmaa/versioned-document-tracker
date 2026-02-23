#include "UndoRedoManager.h"

void UndoRedoManager::saveState(const std::string& state) {
    undoStack.push(state);
    clearRedo();
}

std::string UndoRedoManager::undo(const std::string& currentState) {
    if (undoStack.empty()) return currentState;
    redoStack.push(currentState);
    std::string prev = undoStack.top();
    undoStack.pop();
    return prev;
}

std::string UndoRedoManager::redo(const std::string& currentState) {
    if (redoStack.empty()) return currentState;
    undoStack.push(currentState);
    std::string next = redoStack.top();
    redoStack.pop();
    return next;
}

void UndoRedoManager::clearRedo() {
    while (!redoStack.empty()) redoStack.pop();
}
