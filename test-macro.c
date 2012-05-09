/*
 * Parse and linearize the tree for testing.
 *
 * Copyright (C) 2012 Christophre Li
 *
 */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#include "lib.h"
#include "allocate.h"
#include "token.h"
#include "parse.h"
#include "symbol.h"
#include "expression.h"

static void expand_arg(struct token *macro, struct symbol *sym, int i, struct token *orig, struct token *expanded)
{
	printf("arg%d in %s :", i, show_token(macro));
	show_tokenstream(orig);
	printf(" -> ");
	show_tokenstream(expanded);
	printf("\n");
	
}

static void expand_macro(struct token *macro, struct symbol *sym,
			 struct token **replace, struct token **replace_tail)
{
	struct symbol *parent = sym->parent;

	printf("macro %s inside", show_token(macro));
	printf(" %s\n",   show_ident(parent ? parent->ident: NULL));
	printf("expand result: ");
	show_tokenstream(*replace);
	printf("\n");
}

struct preprocess_hook test_macro_hook = {
	.expand_macro = expand_macro,
	.expand_arg = expand_arg,
};

void test_macro(char *filename)
{
	struct token *token;
	int fd;

	fd = open(filename, O_RDONLY);

	if (fd < 0)
		die("No such file: %s", filename);

	token = tokenize(filename, fd, NULL, includepath);
	show_tokenstream(token);
	printf("\n");
	token = preprocess(token);
	printf("After preprocessing\n");
	show_tokenstream(token);
}

int main(int argc, char **argv)
{
	struct string_list *filelist = NULL;
	char *file;

	preprocess_hook = &test_macro_hook;

	sparse_initialize(argc, argv, &filelist);
	FOR_EACH_PTR_NOTAG(filelist, file) {
		test_macro(file);
	} END_FOR_EACH_PTR_NOTAG(file);
	return 0;
}
