#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#include "LocalFileSystem.h"
#include "Disk.h"
#include "ufs.h"

using namespace std;

//For ds3bits you'll want to implement readSuperBlock, readInodeBitmap, and readDataBitmap.
// ./ds3bits disk_testing/a.img
int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << argv[0] << ": diskImageFile" << endl;
    return 1;
  }
  string filename = argv[1];
  Disk disk(filename, 4096);

  LocalFileSystem lfs(&disk);

  super_t super;
  lfs.readSuperBlock(&super);

  unsigned char inodeBuf[4096*super.inode_bitmap_len];
  lfs.readInodeBitmap(&super, inodeBuf);

  unsigned char dataBuf[4096*super.data_bitmap_len];
  lfs.readDataBitmap(&super, dataBuf);

  printf("Super\n");
  printf("inode_region_addr %d\n", super.inode_region_addr);
  printf("data_region_addr %d\n", super.data_region_addr);
  printf("\n");
  printf("Inode bitmap\n");
  for (int i = 0; i < super.inode_bitmap_len*4096; i++){
    cout << (unsigned int) inodeBuf[i] << " ";
  }
  printf("\n");
  printf("\nData bitmap\n");
  for (int i = 0; i < super.data_bitmap_len*4096; i++){
    cout << (unsigned int) dataBuf[i] << " ";
  }
  printf("\n");

  return 0;


}
