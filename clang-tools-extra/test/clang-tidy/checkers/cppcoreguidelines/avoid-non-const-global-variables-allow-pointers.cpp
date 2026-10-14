// RUN: %check_clang_tidy %s cppcoreguidelines-avoid-non-const-global-variables %t -- \
// RUN: -config="{CheckOptions: {cppcoreguidelines-avoid-non-const-global-variables.AllowPointers : 'true'}}"

struct struct_t {
  int member;
};

static struct_t *p_struct = nullptr;

struct_t *p_global = nullptr;

int nonConstInt = 0;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: variable 'nonConstInt' is non-const and globally accessible, consider making it const [cppcoreguidelines-avoid-non-const-global-variables]
int *pointerToNonConstInt = &nonConstInt;

typedef int (*functionPointer)();
functionPointer fp = nullptr;

int nonConstGlobal = 0;
// CHECK-MESSAGES: :[[@LINE-1]]:5: warning: variable 'nonConstGlobal' is non-const and globally accessible, consider making it const [cppcoreguidelines-avoid-non-const-global-variables]

int &referenceToNonConstInt = nonConstInt;
// CHECK-MESSAGES: :[[@LINE-1]]:6: warning: variable 'referenceToNonConstInt' provides global access to a non-const object; consider making the referenced data 'const' [cppcoreguidelines-avoid-non-const-global-variables]
