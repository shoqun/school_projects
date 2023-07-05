#include "s21_test.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      // 15 functions
      test_memchr(), test_memcmp(), test_memcpy(), test_memset(),
      test_strncat(), test_strchr(), test_strncmp(), test_strncpy(),
      test_strcspn(), test_strerror(), test_strlen(), test_strpbrk(),
      test_strrchr(), test_strstr(), test_strtok(),

      // sprintf
      test_sprintf_e(), test_sprintf_f(), test_sprintf_g(), test_sprintf_n(),
      test_sprintf_c(), test_sprintf_octal(), test_sprintf_percent(),
      test_sprintf_string(), test_sprintf_unsigned(), test_sprintf_HEX(),
      test_sprintf_hex(), test_sprintf_pointer(), test_sprintf_signed(),
      test_sprintf_signed_i(), suite_s21_sscanf_c(), suite_s21_sscanf_d(),
      suite_s21_sscanf_f(), suite_s21_sscanf_i(), suite_s21_sscanf_mix(),
      suite_s21_sscanf_n(), suite_s21_sscanf_o(), suite_s21_sscanf_p(),
      suite_s21_sscanf_s(), suite_s21_sscanf_u(), suite_s21_sscanf_x(),
      test_to_upper(), test_to_lower(), test_insert(), test_trim(),

      NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
