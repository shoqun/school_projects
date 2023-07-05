#include <check.h>

#include "s21_smartCalc.h"

START_TEST(calc_test_1) {
  char arr[73][100] = {
      ")5+7(", "(", "()", "()*()*()", "(()*())", "))", "((", "(()", "(()())()",
      "(()()()", "(1)(+)(2)", "((+10-)*(10))", "(1)*((-)2)*(3)", "aoa", ".",
      ",", "--5", ".5.5.", "....", "..", "5.5.5", "5.5 5.5",
      // "5   5",
      "a(10)", "co sin", "co s(x)", "as(x)", "sin(*8)", "l(x)", "ll(x)", "",
      "(*5)", "(/5)", "(^5)", "(mod5)", "()",
      "(555+)",  // √ solved
      "(555-)",  // √ solved
      "(555*)", "(5555/)", "(555mod)", "(555()",

      "*3+3",  //√ solved
      "())", "lod(33)",
      "2*+6",  //√ solved
  };

  double result = 0;
  int NumElements = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < NumElements; i++) {
    result = 0;
    int CODE = s21_smartCalc_v1_0(arr[i], &result);

    ck_assert_double_eq(result, 0);
    if (CODE != 0) {
      ck_assert_int_eq(CODE, CODE);

    } else {
      ck_assert_int_eq(CODE, 0);
    }
  }
}
END_TEST

START_TEST(calc_test_2) {
  double x = 20;
  char arr[73][100] = {
      //   "cos( 32 + 23 / 3 ) - 255 ln(32)",
      //    "cos( 32 + 23 / 3 ) - 255log(32)",
      //    "cos( 32 + 23 / 3 ) - log(32)255", // √
      "(1)(2)(3)",
      "(1)*(-2)*(3)",
      "log(20)ln(20)",
      "5*5. * 5",
      ".0",
      ".575",
      "(.5)",
      "(555.)",
      "7(+3)",
      "20 mod (-4)",
      "20 ^ (-4)",
      "255*20*(-255)",
      "-2+5",
      "-sqrt(100)",
      "(20*(-2))",

      "3+(-sqrt(100))",
      "-(-(-2))",
      "sin(-2)",
      "-2^2",
      "-(-(-log(100000)))",
      "22-(-2^3)",
      "sin(-2+3)",
      "-2+3+3",
      "2-(-(-(-(4*log(100)*3/3+100))))",
      "22*1",
      "5",
      "5.5",
      "5.5 * 5",
      "45",
      "(20)",
      "((1)*(55))*(3)",
      "ln(10)",
      "ln(1)",
      "cos(20) * sin(20) *tan(20)",
      "(acos(1))* asin(1)",
      "sqrt(20)",
      "ln(20)",
      "20 mod 20",
      "20 mod 5",
      "sin( 20 + 2 / 3) / (4 mod 5) ",
      "sin( 20 + ln(2) ^ 3 ) / (4*5)",
      "255*20*(-255)",
      "2+5",
      "sqrt(100)",
      "(20*(2))",
      "3*sqrt(25)",
      "sqrt((24*1)+1)",
      "3+(sqrt(100))",
      "(2)",
      "sin(2)",
      "2^2",
      "(((log(100000))))",
      "22-(2^3)",
      "atan(0.5)",
      "+1000mod994",
      "2-cos(3)",
      "sin(2+3)",
      "2+3+3",
      "2-((((4*log(100)*3/3+100))))",
      "tan(asin(1))",
      "ln(acos(0))",
      "2+2.4",
      "2/(1+2)",
      "1000mod994",
      "2^3^4",
      "2^(3^4)",
      "(2^3)^4",
      "2*3mod4",
      "33-5*20",
      "5",
  };
  double ResultNumbers[73] = {
      // cos( 32 + 23 / 3 ) - 255*log(32),
      // cos( 32 + 23 / 3 ) - 255*log10(32),
      // cos( 32 + 23 / 3 ) - log10(32)*255,
      (1) * (2) * (3),
      (1) * (-2) * (3),
      log10(20) * log(20),
      5 * 5. * 5,
      .0,
      .575,
      (.5),
      (555.),
      7 * (+3),
      fmod(x, -4),
      pow(x, -4),
      255 * x * (-255),
      -2 + 5,
      -sqrt(100),
      (20 * (-2)),
      3 + (-sqrt(100)),
      -(-(-2)),
      sin(-2),
      pow(-2, 2),
      -(-(-log10(100000))),
      22 - (-8),
      sin(-2 + 3),
      -2 + 3 + 3,
      2 - (-(-(-(4 * log10(100) * 3 / 3 + 100)))),
      22 * 1,
      5,
      5.5,
      5.5 * 5,
      45,
      (x),
      ((1) * (55)) * (3),
      log(10),
      log(1),
      cos(x) * sin(x) * tan(x),
      (acos(1)) * asin(1),
      sqrt(x),
      log(x),
      fmod(x, x),
      fmod(x, 5),
      sin(x + 2. / 3.) / (fmod(4, 5)),
      sin(x + pow(log(2), 3)) / (4 * 5),
      255 * x * (-255),
      2 + 5,
      sqrt(100),
      (20 * (2)),
      3 * sqrt(25),
      sqrt((24 * 1) + 1),
      3 + (sqrt(100)),
      (2),
      sin(2),
      2 * 2,
      (((log10(100000)))),
      22 - (2 * 2 * 2),
      atan(0.5),
      fmod(+1000, 994),
      2 - cos(3),
      sin(2 + 3),
      2 + 3 + 3,
      2 - ((((4. * log10(100) * 3. / 3. + 100.)))),
      tan(asin(1)),
      log(acos(0)),
      2 + 2.4,
      (2. / 3.),
      fmod(1000, 994),
      pow(8, 4),
      pow(2, pow(3, 4)),
      pow(8, 4),
      fmod(2 * 3, 4),
      33 - 5 * x,
      5,
  };
  int NumElements = sizeof(arr) / sizeof(arr[0]);
  double result = 0;
  for (int i = 0; i < NumElements; i++) {
    result = 0;
    int CODE = s21_smartCalc_v1_0(arr[i], &result);
    ck_assert_int_eq(CODE, 0);
    ck_assert_double_eq_tol(result, ResultNumbers[i], 1e-7);
  }
}
END_TEST

START_TEST(calc_test_3) {
  {
    char arr[2][30] = {"cos(3) * sin(3) *tan(3) *(-acos(3))* asin(3)",
                       "ln(-1)"};
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    double result = 0;

    int CODE = s21_smartCalc_v1_0(arr[0], &result);
    ck_assert_int_eq(CODE, 1);
    ck_assert_double_eq(result, 0);  // nan

    CODE = s21_smartCalc_v1_0(arr[1], &result);
    ck_assert_int_eq(CODE, 0);
    ck_assert_double_nan(result);  // nan
  };
}
END_TEST

START_TEST(calc_test_4) {
  {
    char arr[2][10] = {
        "2/0",
        "2/(2-2)",
    };
    int NumElements = sizeof(arr) / sizeof(arr[0]);
    double result = 0;
    for (int i = 0; i < NumElements; i++) {
      int CODE = s21_smartCalc_v1_0(arr[i], &result);
      ck_assert_int_eq(CODE, 5);
      ck_assert_double_eq(result, 0);
    }
  };
}
END_TEST

START_TEST(calc_test_5) {
  char arr[2][10] = {
      "2/2",
      "2/(3-1)",
  };
  int NumElements = 2;
  double result = 0;
  for (int i = 0; i < NumElements; i++) {
    int CODE = s21_smartCalc_v1_0(arr[i], &result);
    ck_assert_int_eq(CODE, 0);
    ck_assert_double_eq(result, 1);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Calculation test");
  TCase *tc1_1 = tcase_create("Calculation test");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_2);
  tcase_add_test(tc1_1, calc_test_3);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);

  srunner_run_all(sr, CK_ENV);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

/*

double x = 20;
    char arr1[73][100] = {
      "cos( 32 + 23 / 3 ) - 255 ln(32)",
       "cos( 32 + 23 / 3 ) - 255log(32)",
       "cos( 32 + 23 / 3 ) - log(32)255", // √
        "(1)(2)(3)",
        "(1)*(-2)*(3)",
        "log(20)ln(20)",
        "5*5. * 5",
        ".0",
        ".575",
         "(.5)",
         "(555.)",
        "7(+3)",
        "20 mod (-4)",
        "20 ^ (-4)",
        "255*20*(-255)",
        "-2+5",
        "-sqrt(100)",
        "(20*(-2))",

        "3+(-sqrt(100))",
        "-(-(-2))",
        "sin(-2)",
        "-2^2",
        "-(-(-log(100000)))",
        "22-(-2^3)",
        "sin(-2+3)",
        "-2+3+3",
        "2-(-(-(-(4*log(100)*3/3+100))))",
        "22*1",
        "5",
        "5.5",
        "5.5 * 5",
        "45",
        "(20)",
        "((1)*(55))*(3)",
        "ln(10)",
        "ln(1)",
        "cos(20) * sin(20) *tan(20)",
        "(acos(1))* asin(1)",
        "sqrt(20)",
        "ln(20)",
        "20 mod 20",
        "20 mod 5",
        "sin( 20 + 2 / 3) / (4 mod 5) ",
        "sin( 20 + ln(2) ^ 3 ) / (4*5)",
        "255*20*(-255)",
        "2+5",
        "sqrt(100)",
        "(20*(2))",
        "3*sqrt(25)",
        "sqrt((24*1)+1)",
        "3+(sqrt(100))",
        "(2)",
        "sin(2)",
        "2^2",
        "(((log(100000))))",
        "22-(2^3)",
        "atan(0.5)",
        "+1000mod994",
        "2-cos(3)",
        "sin(2+3)",
        "2+3+3",
        "2-((((4*log(100)*3/3+100))))",
        "tan(asin(1))",
        "ln(acos(0))",
        "2+2.4",
        "2/(1+2)",
        "1000mod994",
        "2^3^4",
        "2^(3^4)",
        "(2^3)^4",
        "2*3mod4",
        "33-5*20",
        "5",
    };
     double x = 20;

  double ResultNumbers[73] = {
        cos( 32 + 23 / 3 ) - 255*log(32),
        cos( 32 + 23 / 3 ) - 255*log10(32),
        cos( 32 + 23 / 3 ) - log10(32)*255,
        (1)*(2)*(3),
        (1)*(-2)*(3),
        log10(20)*log(20),
        5*5. * 5,
        .0,
        .575,
        (.5),
        (555.),
        7*(+3),
        fmod(x, -4),
        pow(x, -4),
        255 * x * (-255),
        -2 + 5,
        -sqrt(100),
        (20 * (-2)),
        3 + (-sqrt(100)),
        -(-(-2)),
        sin(-2),
        pow(-2, 2),
        -(-(-log10(100000))),
        22 - (-8),
        sin(-2 + 3),
        -2 + 3 + 3,
        2 - (-(-(-(4 * log10(100) * 3 / 3 + 100)))),
        22 * 1,
        5,
        5.5,
        5.5 * 5,
        45,
        (x),
        ((1) * (55)) * (3),
        log(10),
        log(1),
        cos(x) * sin(x) * tan(x),
        (acos(1)) * asin(1),
        sqrt(x),
        log(x),
        fmod(x, x),
        fmod(x, 5),
        sin(x + 2. / 3.) / (fmod(4, 5)),
        sin(x + pow(log(2), 3)) / (4 * 5),
        255 * x * (-255),
        2 + 5,
        sqrt(100),
        (20 * (2)),
        3 * sqrt(25),
        sqrt((24 * 1) + 1),
        3 + (sqrt(100)),
        (2),
        sin(2),
        2 * 2,
        (((log10(100000)))),
        22 - (2 * 2 * 2),
        atan(0.5),
        fmod(+1000, 994),
        2 - cos(3),
        sin(2 + 3),
        2 + 3 + 3,
        2 - ((((4. * log10(100) * 3. / 3. + 100.)))),
        tan(asin(1)),
        log(acos(0)),
        2 + 2.4,
        (2. / 3.),
        fmod(1000, 994),
        pow(8, 4),
        pow(2, pow(3, 4)),
        pow(8, 4),
        fmod(2 * 3, 4),
        33 - 5 * x,
        5,
    };


    for (int i = 0; i < 73; i++) {


        printf("[%d] RESULT = %lf\n", i, ResultNumbers[i]);
    }

    }*/