// Yingge He
// 1560733
// heyingge@uw.edu
// "Copyright [2018] <Yingge He>"  [legal/copyright]

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

void DumpHex(void* pData, int byteLen);

int main(int argc, char **argv) {
  char     charVal = '0';
  int32_t  intVal = 1;
  float    floatVal = 1.0;
  double   doubleVal  = 1.0;

  typedef struct {
    char     charVal;
    int32_t  intVal;
    float    floatVal;
    double   doubleVal;
  } Ex2Struct;
  Ex2Struct structVal = { '0', 1, 1.0, 1.0 };

  DumpHex(&charVal, sizeof(char));
  DumpHex(&intVal, sizeof(int32_t));
  DumpHex(&floatVal, sizeof(float));
  DumpHex(&doubleVal, sizeof(double));
  DumpHex(&structVal, sizeof(structVal));

  return EXIT_SUCCESS;
}

void DumpHex(void* pData, int byteLen) {
  uint64_t addr = (unsigned long)pData;
  printf("The %d bytes starting at %02"PRIx64" are:", byteLen, addr);
  for (int i = 0; i < byteLen; i++) {
    uint8_t byte = *((char*)pData + i);
    printf(" %02"PRIx8, byte);
  }
  printf("\n");
}
