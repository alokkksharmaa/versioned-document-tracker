#include <iostream>
#include "DocumentEditor.h"
#include "UndoRedoManager.h"
#include "VersionManager.h"

using namespace std;

void showMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Add Text\n";
    cout << "2. Delete Text\n";
    cout << "3. Undo\n";
    cout << "4. Redo\n";
    cout << "5. Save Version\n";
    cout << "6. Restore Version\n";
    cout << "7. Show Document\n";
    cout << "0. Exit\n";
}

int main() {
    DocumentEditor editor;
    UndoRedoManager ur;
    VersionManager vm;
    int choice;
    string input;
    int count;
    int version;

    while (true) {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                ur.saveState(editor.getContent());
                editor.addText(input);
                break;
            case 2:
                cout << "Delete how many characters? ";
                cin >> count;
                ur.saveState(editor.getContent());
                editor.deleteText(count);
                break;
            case 3:
                editor.setContent(ur.undo(editor.getContent()));
                break;
            case 4:
                editor.setContent(ur.redo(editor.getContent()));
                break;
            case 5:
                version = vm.saveVersion(editor.getContent());
                cout << "Version " << version << " saved.\n";
                break;
            case 6:
                cout << "Enter version number to restore: ";
                cin >> version;
                if (vm.versionExists(version)) {
                    ur.saveState(editor.getContent());
                    editor.setContent(vm.getVersion(version));
                    cout << "Version restored.\n";
                } else {
                    cout << "Version doesn't exist.\n";
                }
                break;
            case 7:
                cout << "Current Document:\n" << editor.getContent() << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
