#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* name;
  name = disemvowel((char*) "");
  ASSERT_STREQ("", name);
  free(name);
}

TEST(Disemvowel, HandleNoVowels) {
    char* name = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", name);
  free(name);
}

TEST(Disemvowel, HandleOnlyVowels) {
char*name = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", name);
  free(name);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
char input[] = "Morris, Minnesota";
char* name = disemvowel(input);
  ASSERT_STREQ("Mrrs, Mnnst", name);
    free(name);
}

TEST(Disemvowel, HandlePunctuation) {
char* name = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", name);
  free(name);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;
  char *name;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  name = disemvowel(str);
  
  ASSERT_STREQ("xyz", name);

  free(str);
  free(name);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
