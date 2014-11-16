
static void *non_pure1(void)
{
	return (void *)0;
}

static __attribute__((__pure__)) void *pure1(void)
{
	void *i = (void *)0;
	return i;
}

static void*(*f1_ok)(void) = pure1;
static __attribute__((__pure__)) void*(*f2_ok)(void) = pure1;
static __attribute__((__pure__)) void*(*f3_error)(void) = non_pure1;

static __attribute__((__pure__)) int pure2(void)
{
	int i = 0;
	return i;
}

static int non_pure2(void)
{
	return 0;
}

static int (*f4)(void) = pure2;
static __attribute__((__pure__)) int(*f5)(void) = pure2;
static __attribute__((__pure__)) int(*f6_error)(void) = non_pure2;


/*
 * check-name: Pure function attribute
 *
 * check-error-start
 * check-error-end
 */
