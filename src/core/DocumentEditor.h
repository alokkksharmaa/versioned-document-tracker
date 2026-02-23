#ifndef DOCUMENT_EDITOR_H
#define DOCUMENT_EDITOR_H

#include <string>

class DocumentEditor {
private:
    std::string content;

public:
    void addText(const std::string& text);
    void deleteText(int count);
    std::string getContent() const;
    void setContent(const std::string& newContent);
};

#endif
