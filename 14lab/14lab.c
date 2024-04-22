#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *source_file = fopen("input.txt", "r");
  if (source_file == NULL) {
    printf("Ошибка открытия исходного файла.\n");
    return 1;
  }
  FILE *target_file = fopen("output.txt", "w");
  if (target_file == NULL) {
    printf("Ошибка открытия нового файла.\n");
    fclose(source_file);
    return 1;
  }

  int c;
  while ((c = fgetc(source_file)) != EOF) {
    c = toupper(c);
    fputc(c, target_file);
  }

  fclose(source_file);
  fclose(target_file);

  return 0;
}
