#include "cansat_sd.hpp"

Cansat_sd sd = Cansat_sd();

void setup() {
  
    sd.listDir(SD, "/", 0);
    sd.createDir(SD, "/mydir");
    sd.listDir(SD, "/", 0);
    sd.removeDir(SD, "/mydir");
    sd.listDir(SD, "/", 2);
    sd.writeFile(SD, "/hello.txt", "Hello ");
    sd.appendFile(SD, "/hello.txt", "World!\n");
    sd.readFile(SD, "/hello.txt");
    sd.deleteFile(SD, "/foo.txt");
    sd.renameFile(SD, "/hello.txt", "/foo.txt");
    sd.readFile(SD, "/foo.txt");
    sd.testFileIO(SD, "/test.txt");
    Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
    Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));

}

void loop() {

}
