NAME = s21_smartCalc_v1.0

CC = gcc

FLAGS =  -Wall -Wextra -pedantic -std=c11

TST_LIBS = -lcheck
ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit -lm
endif

LIB_NAME = s21_smartCalc

SRCS=$(wildcard s21_*.c)
OBJS=$(SRCS:.c=.o)

BUILD_DIR = ../build

.PHONY: all clean rebuild format check test gcov_report $(LIB_NAME).a

# All:
# 	gcc -Wall -Wextra s21_preprocess.c s21_evaluate.c s21_infixToPolish.c s21_smartCalc.c #functions.c

all:


install:
	[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	
	cd $(BUILD_DIR) && cmake ../src/smartCalc_v1_0 && make
	
	#ln -s $(BUILD_DIR)/smartCalc_v1_0 ${HOME}/Desktop/smartCalc_v1_0

uninstall: clean
	rm -rf ../build/

dvi:
	open README.md


dist:
	tar -cf SmartCalc.tar ../build

rebuild: clean all
check:
	clang-format -n -style=Google *.c *.h smartCalc_v1_0/*.cpp smartCalc_v1_0/*.h

#style_apply:
format:
	clang-format -i -style=Google *.c *.h smartCalc_v1_0/*.cpp smartCalc_v1_0/*.h


clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov \
	*.html *.css *.info report   test.dSYM \
	tests/*.o s21_smart_calc.tar.gz SmartCalc.tar

s21_smartCalc.a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o

test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) -g utest_smartCalc.c $(LIB_NAME).a $(TST_LIBS) -o test #-g -fsanitize=address -fsanitize=undefined
	./test


add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test
	./test
	lcov -t “gcov_test” -o test.info --rc lcov_branch_coverage=1 --no-external -c -d .
	genhtml -o report/ test.info --rc lcov_branch_coverage=1
	open ./report/index.html

valgrind:
	make test
	$(CC) -g tests/*.c s21_smartCalc.a -o test -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
	valgrind --leak-check=full --show-leak-kinds=all -s ./test
