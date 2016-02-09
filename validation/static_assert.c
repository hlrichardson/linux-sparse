_Static_assert(1, "global ok");

struct foo {
	_Static_assert(1, "struct ok");
};

void bar(void)
{
	_Static_assert(1, " func ok");
}

_Static_assert(0, "expected assertion failure");

static int f;
_Static_assert(f, "non-constant expression");

static int *p;
_Static_assert(p, "non-integer expression");

_Static_assert(0.1, "float expression");
        
_Static_assert(!0 == 1, "non-trivial expression");
        
static char array[4];
_Static_assert(sizeof(array) == 4, "sizeof expression");
        
static const char non_literal_string[] = "non literal string";
_Static_assert(0, non_literal_string);

_Static_assert(1 / 0, "invalid expression: should not show up?");

struct s {
	char arr[16];
	_Static_assert(1, "inside struct");
};

union u {
	char c;
	int  i;
	_Static_assert(1, "inside union");
};

_Static_assert(sizeof(struct s) == 16, "sizeof assertion");

/*
 * check-name: static assertion
 *
 * check-error-start
static_assert.c:12:16: error: static assertion failed: "expected assertion failure"
static_assert.c:15:16: error: bad constant expression
static_assert.c:18:16: error: bad constant expression
static_assert.c:20:16: error: bad constant expression
static_assert.c:28:19: error: bad string literal
static_assert.c:30:18: error: bad constant expression
 * check-error-end
 */

