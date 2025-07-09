#include <iostream>
#include "DocumentEditor.h"

int main() {
    DocumentEditor editor;

    editor.addText("Hello");
    editor.addText(" World");
    std::cout << "Content: " << editor.getContent() << std::endl;

    editor.deleteText(6);
    std::cout << "After delete: " << editor.getContent() << std::endl;

    return 0;
}
