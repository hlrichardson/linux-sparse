extern void __attribute__((cdecl)) f1(void);
extern void __attribute__((__cdecl__)) f2(void);
extern void __attribute__((stdcall)) f3(void);
extern void __attribute__((__stdcall__)) f4(void);

typedef void (__attribute__((__stdcall__)) *f5)(void);
typedef f5 f5ptr;