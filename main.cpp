#include <iostream>
#include "Headers/File.h"
#include "Headers/SystemElement.h"
#include "Headers/Dir.h"
#include "Headers/SymbolicLink.h"
#include "Headers/FileSystemModeling.h"
#include <bits/stdc++.h>

void test() {
    string name = "file1";
    string ext = "txt";
    File *file1 = new File(name, ext, 10);
    _sleep(1000);
    name = "file2";
    File *file2 = new File(name, ext, 10);
    name = "file3";
    File *file3 = new File(name, ext, 10);
    _sleep(1000);
    name = "dir1";
    Dir *dir1 = new Dir(name);
    _sleep(1000);
    name = "dir2";
    Dir *dir2 = new Dir(name);

    name = "dir3";
    Dir *dir3 = new Dir(name);
    dir3->addElement(file3);

    dir1->addElement(file1);
//    dir2->addElement(file2);
    dir2->addElement(dir3);
    dir1->addElement(file2);
    dir1->addElement(dir2);

    dir1->getPrintedInfo(0);
}

int main() {
//    string name = "file";
//    string ext = "txt";
//    File *file = new File(name, ext, 10);
//    file->getPrintedInfo();
//
//    _sleep(1000);
//    file->edit();
//    file->getPrintedInfo();
//
//    _sleep(1000);
//    name = "newfile";
//    file->rename(name);
//    file->getPrintedInfo();
//    delete file;
//
//    Dir *dir = new Dir(name, true);
//    dir->deleteDir();
//
//    cout << "\n";
//    string name1 = "filename";
//    string ext1 = " txt";
//    File *file1 = new File(name1, ext1, 11);
//    dir->addElement(file1);
//
//
//    name = "myfile";
//    ext = "gif";
//    File *file2 = new File(name, ext, 15);
//    dir->addElement(file2);
//    dir->getPrintedInfo();
//
//    name1 = "newDir";
//    Dir *dir1 = new Dir(name1);
//    dir1->addElement(dir);
//    dir1->getPrintedInfo();

//    test();
//    string name = "/";
//    string ext = "txt";
//    Dir *dir1 = new Dir(name);
//    string name1 = "mylink";
//    auto *hardLink = new HardLink(name1, dir1);
//    delete hardLink;
//    hardLink->getPrintedInfo(0);
//
//    hardLink->getLink()->getPrintedInfo(0);
//
//    name1 = "newNameHard";
//    hardLink->rename(name1);
//    hardLink->getPrintedInfo(0);
//    delete hardLink;

//    name1 = "softLink";
//    auto *symbolicLink = new SymbolicLink(name1, dir1);
//    dir1->deleteDir();
//    symbolicLink->deleteLinkedElement();
//    symbolicLink->getLink()->getPrintedInfo(0);

    auto *fileSystemModeling = new FileSystemModeling;
    fileSystemModeling->start();

//    string name = "file";
//    string ext = "txt";
//    File *file = new File(name, ext, 10);
//
//    vector<File *> vec;
//    vec.push_back(file);
//
//    auto it = std::find(vec.begin(), vec.end(), file);
//
//    vec.erase(it);
//
//    delete file;
//    cout << "end";
    return 0;
}