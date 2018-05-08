#include "file_output.hpp"

FileOutput::FileOutput(const char* fileName):FILE_NAME(fileName) {
    fileOpen();
}

void FileOutput::fileOpen() {
    outputFile_ = fopen(FILE_NAME, "w");
    canOutput_ = outputFile_ == NULL ? false : true;
}

void FileOutput::fileWrite(int var) {
    if (canOutput_) {
        fprintf(outputFile_, "%d\n", var);
    }
}

void FileOutput::close() {
    canOutput_ = false;
    if (outputFile_ != NULL) {
        fclose(outputFile_);
    }
}

FileOutput::~FileOutput() {
    close();
}
