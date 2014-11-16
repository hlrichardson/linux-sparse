
static __attribute__((__pure__)) void *pure1(void)
{
	void *i = (void *)0;
	return i;
}

static void*(*f1_err)(void) = pure1;
static __attribute__((__pure__)) void*(*f1_ok)(void) = pure1;

static __attribute__((__pure__)) int pure2(void)
{
	int i = 0;
	return i;
}

static int (*f2_err)(void) = pure2;
static __attribute__((__pure__)) int(*f2_ok)(void) = pure2;


/*
 * check-name: Pure function attribute
 *
 * check-error-start
pure-function.c:8:31: warning: incorrect type in initializer (different modifiers)
pure-function.c:8:31:    expected void *( *static [toplevel] f1_err )( ... )
pure-function.c:8:31:    got void [pure] *( static [toplevel] *<noident> )( ... )
pure-function.c:17:30: warning: incorrect type in initializer (different modifiers)
pure-function.c:17:30:    expected int [signed] ( *static [toplevel] f2_err )( ... )
pure-function.c:17:30:    got int [signed] [pure] ( static [toplevel] *<noident> )( ... )
 * check-error-end
 */
