#include <arpa/inet.h>

#include <stdint.h>
#include <cstdlib>
#include <string>

bool HexToBin(const std::string& str_hex, std::string* str_bin) {
  if (str_hex.size() % 2 != 0) {
    return false;
  }

  str_bin->resize(str_hex.size() / 2);
  for (size_t i = 0; i < str_bin->size(); i++) {
    uint8_t cTemp = 0;
    for (size_t j = 0; j < 2; j++) {
      char cCur = str_hex[2 * i + j];
      if (cCur >= '0' && cCur <= '9') {
        cTemp = (cTemp << 4) + (cCur - '0');
      } else if (cCur >= 'a' && cCur <= 'f') {
        cTemp = (cTemp << 4) + (cCur - 'a' + 10);
      } else if (cCur >= 'A' && cCur <= 'F') {
        cTemp = (cTemp << 4) + (cCur - 'A' + 10);
      } else {
        return false;
      }
    }
    (*str_bin)[i] = cTemp;
  }

  return true;
}

bool BinToHex(const std::string& str_bin, std::string* str_hex) {
  str_hex->resize(str_bin.size() * 2);
  for (size_t i = 0; i < str_bin.size(); i++) {
    uint8_t cTemp = str_bin[i];
    for (size_t j = 0; j < 2; j++) {
      uint8_t cCur = (cTemp & 0x0f);
      if (cCur < 10) {
        cCur += '0';
      } else {
        cCur += ('a' - 10);
      }
      (*str_hex)[2 * i + 1 - j] = cCur;
      cTemp >>= 4;
    }
  }

  return true;
}
