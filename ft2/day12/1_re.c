#include <stdio.h>
#include "1_re.h"

#if 0
// version 0 : 
// 1. empty pattern
int match_here(char *pat, char *text);

int match(char *pat, char *text)
{
	if(match_here(pat, text))
		return 1;
	return 0;
}

int match_here(char *pat, char *text)
{
	// empty pattern
	if(pat[0] == '\0')
		return 1;
	return 0;	
}
#endif

#if 0
// version 1 : 
// 1. empty pattern
// 2. exact match
int match_here(char *pat, char *text);

int match(char *pat, char *text)
{
	do
	{
		if(match_here(pat, text))
			return 1;
	} 	while(*text++ != '\0');
	return 0;
}

int match_here(char *pat, char *text)
{
	// empty pattern
	if(*pat == '\0')
		return 1;
	if(*text != '\0' && *pat == *text)
	{
		return match_here(pat + 1, text + 1);
	}	
	return 0;	
}
#endif


#if 0
// version 2 : 
// 1. empty pattern
// 2. exact match
// 3. anchor ^
int match_here(char *pat, char *text);

int match(char *pat, char *text)
{
	if(*pat == '^')
	{
		return match_here(pat + 1, text);
	}
	do
	{
		if(match_here(pat, text))
			return 1;
	} 	while(*text++ != '\0');
	return 0;
}
#endif

#if 1
// version 3 : 
// 1. empty pattern
// 2. exact match
// 3. anchor ^
// 4. anchor $
int match_here(char *pat, char *text);

int match(char *pat, char *text)
{
	if(*pat == '^')
	{
		return match_here(pat + 1, text);
	}
	do
	{
		if(match_here(pat, text))
			return 1;
	} 	while(*text++ != '\0');
	return 0;
}
int match_here(char *pat, char *text)
{
	// empty pattern
	if(*pat == '\0')
		return 1;
	if(pat[0] == '$' && pat[1] == '\0')
		return *text == '\0';	
	if(*text != '\0' && *pat == *text)
	{
		return match_here(pat + 1, text + 1);
	}	
	return 0;	
}
#endif

