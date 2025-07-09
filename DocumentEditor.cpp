#include "DocumentEditor.h"

void DocumentEditor::addText(const std::string& text) {
    content += text;
}

void DocumentEditor::deleteText(int count) {
    if (count > content.size()) count = content.size();
    content.erase(content.size() - count, count);
}

std::string DocumentEditor::getContent() const {
    return content;
}

void DocumentEditor::setContent(const std::string& newContent) {
    content = newContent;
}
