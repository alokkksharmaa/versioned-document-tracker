# Versioned Document Tracker (C++)

A modular C++ project simulating a text editor with:
- Undo/Redo
- Version Saving
- File Save/Load
- Clean modular architecture

### Run
```bash
g++ ui/main.cpp editor/DocumentEditor.cpp undo_redo/UndoRedoManager.cpp versioning/VersionManager.cpp -o tracker
./tracker
