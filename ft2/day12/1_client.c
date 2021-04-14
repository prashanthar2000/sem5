#include <stdio.h>
#include "1_re.h"
#include <assert.h>
// support :
//	empty pattern match
//	exact match
//	anchor ^
//	anchor $
//	char matcher .
//	closure *
#if 0
// version 0
// 1. empty pattern
int main()
{
	assert(match("", "abc"));
	assert(match("", ""));
}
#endif

#if 0
// version 1
// 1. empty pattern
// 2. exact match
int main()
{
	assert(match("", "abc"));
	assert(match("", ""));

	assert(match("abc", "abc"));
	assert(match("abc", "abcy"));
	assert(match("abc", "abxc") == 0);
	assert(match("abc", "xabc"));
	assert(match("abc", "xabcy"));

	assert(match("abc", "abd") == 0);
	assert(match("abc", "") == 0);
}
#endif


#if 0
// version 2
// 1. empty pattern
// 2. exact match
// 3. anchor ^
int main()
{
	assert(match("", "abc"));
	assert(match("", ""));

	assert(match("abc", "abc"));
	assert(match("abc", "abcy"));
	assert(match("abc", "abxc") == 0);
	assert(match("abc", "xabc"));
	assert(match("abc", "xabcy"));

	assert(match("abc", "abd") == 0);
	assert(match("abc", "") == 0);

	assert(match("^abc", "abc"));
	assert(match("^abc", "abcy"));
	assert(match("^abc", "xabc") == 0);
	assert(match("^abc", "abxabc") == 0);
	assert(match("^^abc", "^abc"));
	assert(match("^^abc", "^^abc") == 0);
	
	
}
#endif

#if 1
// version 3
// 1. empty pattern
// 2. exact match
// 3. anchor ^
// 4. anchor $
int main()
{
	assert(match("", "abc"));
	assert(match("", ""));

	assert(match("abc", "abc"));
	assert(match("abc", "abcy"));
	assert(match("abc", "abxc") == 0);
	assert(match("abc", "xabc"));
	assert(match("abc", "xabcy"));

	assert(match("abc", "abd") == 0);
	assert(match("abc", "") == 0);

	assert(match("^abc", "abc"));
	assert(match("^abc", "abcy"));
	assert(match("^abc", "xabc") == 0);
	assert(match("^abc", "abxabc") == 0);
	assert(match("^^abc", "^abc"));
	assert(match("^^abc", "^^abc") == 0);
	
	assert(match("abc$", "abc"));
	assert(match("abc$", "abcy") == 0);
	assert(match("abc$", "xabc"));
	assert(match("^abc$", "abc"));
	assert(match("abc$", "abcxabc"));
	assert(match("^abc$", "abcxabc") == 0);

}
#endif


