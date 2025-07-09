#include <iostream>
#include "../editor/DocumentEditor.h"
#include "../undo_redo/UndoRedoManager.h"
#include "../versioning/VersionManager.h"

int main() {
    DocumentEditor editor;
    UndoRedoManager undoRedo;
    VersionManager versioner;

    editor.addText("Alok");
    undoRedo.saveState(editor.getContent());

    editor.addText(" Sharma");
    undoRedo.saveState(editor.getContent());

    int v1 = versioner.saveVersion(editor.getContent());
    std::cout << "Saved Version: " << v1 << " => " << editor.getContent() << std::endl;

    editor.setContent(undoRedo.undo(editor.getContent()));
    std::cout << "After Undo: " << editor.getContent() << std::endl;

    editor.setContent(undoRedo.redo(editor.getContent()));
    std::cout << "After Redo: " << editor.getContent() << std::endl;

    return 0;
}
