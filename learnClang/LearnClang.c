//
// Created by dmego on 2023/10/23.
//
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 printf 占位符
 %d 整数
 %s 字符串
 %c 字符
 %p 指针
 %f 浮点小数
 %x 十六进制整数，通常用来打印地址
 */

// 数据类型
void test_dataType() {
    char c = 'B';
    char null = '\0'; // null 字符，不表示0，而是表示没有字符
    signed int a = 1; // signed 表示一个类型会带正负号，同样长度的内存下，表示的数值大小比 unsigned 小一倍
    unsigned int b = 1; // unsigned  表示该类型不会带正负号，只能表示 0 和正整数

    short sh = 1; // 短整型，占 2 字节
    int in = 2; // 整型，占 4 字节
    long lo = 3L; // 长整型，不少于 4 字节
    long long ll = 4; // 至少占用 8 字节

    INT_MAX, INT_MIN; // int 的最小值，最大值，在 limits 头文件中

    float fl = 0.2f; // 占用 4 字节，32 位
    double db = 0.2; // 占用 8 字节，64 位
    long double ld = 0.2324;

    // 布尔类型 C 语言中，原本没有定义布尔类型，而是使用 0 表示 false, 非 0 整数表示 真
    // 在 stdbool.h 头文件中，定义了 true 和 false 这两个关键字
    bool isTrue = true;
    bool isFalse = false;

    // 字面量后缀
    int lh = 34L; // L 表示这是一个 long 类型
    int lu = 34U; // U 表示这是一个无符号整型 unsigned int

    // 溢出，每种数据类型都有数值范围，编译器不会对溢出报错
    // 为了避免溢出，最好的方法是将运算结果与数据类型的极值比较
    unsigned int ui;
    unsigned int sum;
    if (ui + sum > UINT_MAX) {
        // 错误处理方式，ui + sum 在运算时就会溢出
    }

    if (UINT_MAX - sum < ui) {
        // 正确处理方式
    }

    // 返回某个变量或者某种类型占用字节大小
    int si = sizeof(int);
    int ssi = sizeof(si);
    int sf = sizeof(3.24f);

    // 类型自动转换（Java 向上转型）
    int fi = 3.24; // fi 实际保存的是 3.24 的整数部分，取整
    float fii = 12; // fii 实际值为 12.0

    // 混合类型计算时，整数会先转为浮点型再运算
    2 + 3.14; // 2 会转为 2.0 再和 3.14 计算

    /* 函数的返回值，会自动转为定义的类型
    char tty(void) {
        int a = 12;
        return a // 这里的 a 会转为 char 类型
    }
    */
}

// 指针
void test_pointer() {
    // 指针是一个 值，表示一个 内存地址
    // 字符串 * 表示指针，跟在数据类型后面，表示该类型的指针
    char* cp;
    int* ip;
    int** ipp; // 一个指针的指向还是一个指针

    // * 作为一个运算符，取出指针变量所指向内存地址的值
    *ip += 3;
    /*
     // 在方法参数中，使用指针来传参，避免将整个变量传递到函数中，浪费空间，只需要将变量地址传递进去就行
     void test(int* p) {
        // p 表示 指针
        // *p 表示 指针所执行的值
        *p = *p + 1; // 对指针所执行的地址的值进行 + 1
     }
     */

    // & 符号用于取出一个变量的内存地址值
    int x = 1;
    &x;
    // test(&x);
    // & 与 * 互为逆运算
    if (x == *(&x)){} // 等式成立，&x 表示取 x的地址，* 表示获取该地址上的值

    // 指针变量声明之后指向的是一个随机地址，所以需要初始化
    int* p;
    p = &x; // 初始化为 x 的地址
    *p = 13; // 相当于给 x 赋值 13
    // 为了防止指针变量未初始化，可以将指针变量赋值给 null
    int* np = NULL; // NULL 表示地址为 0 的内存空间，这个地址是无法使用的
}

// https://liam.page/2017/02/05/pointer-in-C-and-Cpp/
void test_pointer_detail() {
    /*
     指针是对 对象区域的抽象，是一种复合类型
        指针存储了所指向对象的内存地址
        而与指针相复合的类型
     */
    int* ip; // 定义指针的复合类型，这是一个指向 int 类型的指针
    int val = 32;
    ip = &val; // 使用 & 来获取对象的地址，将这个地址赋值给指针变量，那么这个指针就指向了 val 的地址空间
    printf("ip store value: %d\n", *ip);

    //空指针
    int* np = NULL;

    // 空类型指针, 可以用来存放任意类型的地址
    void* vp;
    double dv = 3.24;
    int iv = 5;
    vp = &dv;
    // 空类型指针可以：做指针之间的比较、作为函数的输入或输出、赋值给另外一个空类型指针

    // 再探变量声明
    int *io, // *io 是指向 int 类型的指针
        dp; // dp 是 int 类型的变量

    // 指向指针的指针
    int va = 12;
    int *op = &va;
    /*
     **pp 是指向指针的指针
     *pp 表示 pp 是一个指针，指向 int 类型
     *(*pp) 也就是指(*pp) 也是一个指针，指向 pp 这个指针
     */
    int **pp = &op;

    // 常量与指针
    const int CI = 12;
    int *ci = &va;
    ci = &CI; // 错误❌，不允许将常量的地址赋值给 指针

    const int *CPI; // 定义一个指针，指向类型是 int 的常量
    CPI = &CI; // 正确✅，可以把一个常量地址赋值给一个常量的指针

    int *const cpi = &val; // 正确，cpi 是一个常量指针，&val 是一个变量地址，允许将变量地址赋值给一个常量的指针
    int fake = 2;
    //cpi = &fake; // 错误❌，常量一旦赋值，就不能再次被赋值。

    const int *const cipi = &val; // cipi 本身就是常量指针，通过 cipi 访问的也是常量

//    cipi = &fake; // cipi 本身是常量，不能在定义之外赋值
//    cipi = &CI;   // cipi 本身是常量，不能在定义之外赋值，即使是常量的地址也不行

    // 变量可以是常量，而指针本身也可以是常量
    int *const icp; // 指针常量
    const int *cip; // 指向常量的指针

    // 指针与数组
    int num[] = {1,2,3};
    int *p = &(num[0]);
    printf("num[0]: %d\n", *p);
    // 说明数组 num 也是一个指针，指向的是数组第一个元素的地址
    if (p == num) {
        printf("p = num, return true\n");
    }

    // 函数与指针
    // 1. 让函数返回一个数组的指针
    int arr[10]; // arr 是一个数组，元素类型是 int
    int *parr[10]; // parr 是一个 指针数组，元素类型是 int *。
    int (*pa)[10] = &arr; // pa 是一个指针，指向 arr 数组的地址
    // func 是一个函数，返回一个指针，指向长度为 10 的 int 数组
    int (*func(int a, int b))[10];

    // 2. 函数的指针
    /*
     如何确定一个函数，一个函数应该包括它的返回类型和参数列表
     */
    //bool isEqual(int, int); // 定义了 isEqual 函数
    //bool (*pFunc)(int, int) = &isEqual; // 定义了一个函数指针，指向 isEqual 函数

    //bool res1 = isEqual(1,2); // 通过原函数名调用
    //bool res2 = (*pFunc)(1, 2); // 通过函数指针，解引用掉用
    // res3 = pFunc(1, 2); // 函数指针自动转换成函数名

    // 将函数指针作为参数传入另一个函数
    //void addIfEqual(int l, int r, bool (*pFunc)(int, int)); // 显示声明第 3 个参数是一个函数指针
    //void addIfEqual2(int l, int r, bool pFunc(int, int)); // 这样写也行，会自动转换成一个函数指针参数

    //addIfEqual(1, 2, pFunc);
}

// 函数
void test_method() {

    /*
    int main() {
        // c 语言规定，return 0 表示函数执行成功，返回其他值则表示执行出了问题
        return 0;
    }
    */
}

void printt(int a) {
    printf("%d hh\n", a);
    // 函数名 就是指向函数代码的指针
    if (printt == &printt) {
        printf("printt == &printt: true\n");
    }
}
void (*print_ptr)(int) = &printt;

// 函数原型
int twice(int); // 先声明函数 int twice(int num) num 可以省略

// static 说明符
void counter(void) {
    static int num = 0; // 只初始化一次, 在 main 中调用2次，num会一直累加
    //int num = 0; // 每次进入 counter 函数都会进行初始化
    printf("num: %d\n", num);
    num++;
}

// 字符串
void test_string() {
    char str[50] = "hello, nihao";
    printf("str: %s\n", str);
    str[0] = 'c';
    char str2[] = "ssssxxx"; // 会自动计算字符串长度

    char *str3 = "wwwww, xxxx"; // 声明一个字符串指针，指向字符数组

    // str3[0] = 'c' // 指针指向的字符串，在 C 语言内部被当作常量，不能修改字符串本身

    int len2 = strlen(str2);
    printf("str2 len: %d\n", len2);
    printf("str2 sizeof: %d\n", sizeof(str2));

}

// 预处理器
#define MAX 100 // 在编译程序之前，预处理器会将 MAX 都替换成 100
#define HELLO "hello world"

// #ifdef...#endif 指令用于判断某个宏是否定义过
// 有时源码文件可能会重复加载某个库，为了避免这种情况，
// 可以在库文件里使用#define定义一个空的宏。通过这个宏，判断库文件是否被加载了

// 预定义的宏
void test_hh(){
    printf("This function: %s\n", __func__);
    printf("This file: %s\n", __FILE__);
    printf("This line: %d\n", __LINE__);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    printf("C Version: %ld\n", __STDC_VERSION__);
}

// I/O 函数
void test_io() {
    printf("test io\n"); // printf() 函数用于输出到屏幕
    int *s;
    printf("输入S:");
    scanf("%d", &s); // 读取屏幕上的一个 int, 写到 s 指向的地址
    printf("s: %d\n", s);
}

// C 语言的内存管理
void test_memory() {
    /*
     C 语言的内存管理分为两块
        系统管理：主要是函数的局部变量，存储在 stack 中，当函数调用结束后自动卸载
        用户管理：主要是程序运行整个过程中都存在的变量，存储在 heap 堆中，需要用户手动申请和释放
     */

    // void 指针，很多内存相关函数的返回值就是 void 指针
    void *vp;

    /*
      void* malloc(size_t size) 函数分配内存
      参数：size 表示要分配的内存字节数
      返回值：void* 空指针，指向分配好的内存地址

     */
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        // 内存分配失败
    }
    *p = 12;
    // malloc 最常用的地方，就是为数组和自定义的 struct 来分配内存
    free(p);

    int *arr = malloc(sizeof(int) * 10);
    if (arr == NULL) {
        printf("内存分配失败！");
    }
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    for (int i = 0; i < 10; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    // 注意，malloc()不会对所分配的内存进行初始化，
    // 里面还保存着原来的值。如果没有初始化，就使用这段内存，可能从里面读到以前的值

    // free(void* block) 函数用于释放 malloc 分配的内存
    free(arr);

    /*
     void* calloc(size_t n, size_t size); 函数
        第一个参数: 某种类型的值的数量
        第二个参数：该数据类型的单位字节长度
        注意：使用 calloc 分配的内存，内存地址内的值会全部初始化为 0
    */
    int *cp = calloc(10, sizeof(int));

    // 等同于
    int *pp = malloc(sizeof(int) * 10);
    memset(pp, 0, sizeof(int) * 10);
    free(cp);
    free(pp);
    /*
      void* realloc(void* block, size_t size)
      用于修改已经分配的内存，可以扩大或缩小
      ** 数据会自动复制过去 **
      block: 要修改的内存的地址，
      size: 扩大或缩小到的内存地址
      返回一个 空指针，指向最新分配的内存地址
     */
}

// Struct 结构
struct people { // 结构声明
    int id;
    char *name;
};

struct people p1 = {1, "hello"}; // 变量声明

// 结构声明和变量声明合并
struct book {
    char *name;
} bk;

// 为 struct 指定别名
typedef struct cell_phone {
    char *num;
} phone;

// phone 就是 cell_phone 的别名
phone ph = {"123435"};

// 指向结构体的 指针变量
phone *php = &ph; // php 是一个指针，指向 ph 这个结构体的地址

// struct 的复制
struct cat { char name[30]; short age; } a, b;

/*
 struct 指针
 如果将 struct 变量传入函数，函数内部得到的是一个原始值的副本
 在函数内部改变 副本 的值，函数外部 变量 的值不会改变

 如果需要在函数内部改变一个值后，函数外部也能生效，只需要将该值的指针传递到函数内部即可
 */
void phone_test(phone *ph) {
    // 必须要写成 (*ph).num 不能是 *ph.num
    // 因为 * 运算符优先级高，*ph.num 会 把 ph.num 看作一个指针。
    (*ph).num = "123";

    // 因为 (*ph) 这样写很麻烦，所以可以直接使用 -> 从指针上获取属性
    ph->num = "456";
}

// 嵌套 struct
typedef struct AA {
    int a;
} aa;

typedef struct BB {
    int b;
    struct AA aa;
} bb;

typedef struct CC {
    int c;
    struct AA aa;
    struct BB bb;
} cc;

// struct 结构内部自我引用
struct Node {
    int value;
    struct Node* next;
};

struct Node* head;


void test_struct() {
    p1.id = 1;
    p1.name = "hello";

    bk.name = "math book";

    strcpy(a.name, "Hula");
    a.age = 3;

    b = a; // 直接进行了复制，a, b 指向两个不同的地址
    b.name[0] = 'M';

    printf("%s\n", a.name); // Hula
    printf("%s\n", b.name); // Mula

    printf("before: %s\n", ph.num);
    phone_test(&ph);
    printf("after: %s\n", ph.num);

    head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = malloc(sizeof(struct Node));

    head->next->value = 2;
    head->next->next = malloc(sizeof(struct Node));

    head->next->next->value = 3;
    head->next->next->next = NULL;

    for (struct Node *cur = head; cur != NULL; cur = cur->next) {
        printf("Node: %d\n", cur->value);
    }

}


int main() {
    //test_pointer_detail();
    printf("HELLO: %s\n", HELLO);
    (*print_ptr)(2);
    twice(3);

    counter();
    counter();

    test_string();
    test_hh();
    //test_io();
    test_memory();
    test_struct();



    // 等价 return 0; exit(0)
    exit(EXIT_SUCCESS);
}


int twice(int a) { // 可以在 main 方法后面再实现函数
    printf("twice: %d\n", a);
}