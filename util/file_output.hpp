#ifndef FILE_OUTPUT_HPP
#define FILE_OUTPUT_HPP

#include <cstdio>

class FileOutput {
    public:
      FileOutput(const char* fileName);
      ~FileOutput();
      void fileOpen();
      void close();
      void fileWrite(int var);

    private:
      const char* FILE_NAME;
      FILE* outputFile_;
      bool canOutput_ = false;
};

#endif