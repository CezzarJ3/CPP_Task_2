#include "Headers/SystemElement.h"
#include "Headers/FileSystemModeling.h"
#include <bits/stdc++.h>

int main() {
    auto *fileSystemModeling = new FileSystemModeling;
    fileSystemModeling->start();
    delete fileSystemModeling;
    return 0;
}