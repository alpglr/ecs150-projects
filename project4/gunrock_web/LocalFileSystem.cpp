#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <cstring>
#include "LocalFileSystem.h"
#include "ufs.h"

#define UFS_BLOCK_SIZE (4096)

using namespace std;

// implement stat and read to implement ds3ls and ds3cat (remember, the root directory is always inode 0 in our file system). 
// For ds3bits you'll want to implement readSuperBlock, readInodeBitmap, and readDataBitmap.

LocalFileSystem::LocalFileSystem(Disk *disk) {
  this->disk = disk;
}

void LocalFileSystem::readSuperBlock(super_t *super) {
  //read the first disk block
  super_t buffer[4096];
  disk->readBlock(0, buffer);
  memcpy(super, buffer, sizeof(super_t));

}

void LocalFileSystem::readInodeBitmap(super_t *super, unsigned char *inodeBitmap){
  for (int i = 0; i < super->inode_bitmap_len; i++){ //might need to make i increment by blocksize
    disk->readBlock(super->inode_bitmap_addr+i, inodeBitmap);
  }
  
}
void LocalFileSystem::readDataBitmap(super_t *super, unsigned char *dataBitmap){
  for (int i = 0; i < super->data_bitmap_len; i++){ //might need to make i increment by blocksize
      disk->readBlock(super->data_bitmap_addr+i, dataBitmap);
  }
}

int LocalFileSystem::lookup(int parentInodeNumber, string name) {
  return 0;
}

int LocalFileSystem::stat(int inodeNumber, inode_t *inode) {
  return 0;
}

int LocalFileSystem::read(int inodeNumber, void *buffer, int size) { //read contents of a file or dir
  return 0;
}

int LocalFileSystem::create(int parentInodeNumber, int type, string name) {
  return 0;
}

int LocalFileSystem::write(int inodeNumber, const void *buffer, int size) {
  return 0;
}

int LocalFileSystem::unlink(int parentInodeNumber, string name) {
  return 0;
}
