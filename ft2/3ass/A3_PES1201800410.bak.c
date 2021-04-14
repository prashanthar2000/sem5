#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 5000
#define MAX_REGEX_LEN 2000
#define MAX_CHAR_CLASS_LEN 100

#define DEBUG 0

enum
{
    UNUSED,
    DOT,
    BEGIN,
    END,
    QUESTIONMARK,
    STAR,
    PLUS,
    CHAR,
    CHAR_CLASS,
    DIGIT,
    WORD
};

typedef struct regex_t
{
    char type;
    union
    {
        char ch;     //Char
        char *ch_cl; //char_class
    };
} regex_t;
// typedef struct regex_t regex_t;

typedef struct span
{
    int match;
    int start;
    int end;

} span_t;

#if DEBUG
void disp_reg(regex_t *reg)
{
    int i = 0;
    while (reg[i].type != UNUSED)
    {

        if (reg[i].type == CHAR_CLASS)
        {
            printf("%d , %s", reg[i].type, reg[i].ch_cl);
        }
        else
            printf("%d , %c", reg[i].type, reg[i].ch);
        ++i;
        printf("\n");
    }
}
#endif

//function declarations
static int match_here(regex_t *pattern, const char *text, int *matchlength);
static int match_question(regex_t p, regex_t *pattern, const char *text, int *matchlength);
static int match_ch_cl(char c, const char *str);
static int match_star(regex_t p, regex_t *pattern, const char *text, int *matchlength);
static int match_plus(regex_t p, regex_t *pattern, const char *text, int *matchlength);
static int matchone(regex_t p, char c);
static int match_digit(char c);
static int match_alpha(char c);
static int match_range(char c, char start, char end);

regex_t *re_compile(const char *pattern)
{

    regex_t *re_compiled = (regex_t *)malloc(sizeof(regex_t) * MAX_REGEX_LEN);
    char c;    // current  char of pattern
    int i = 0; // index of pattern
    int j = 0; // index of re_compiled

    while (pattern[i] != '\0')
    {

        c = pattern[i];
        // printf("%c\n" , c);
        switch (c)
        {
        case '^':
        {
            re_compiled[j].type = BEGIN;
        }
        break;
        case '$':
        {
            re_compiled[j].type = END;
        }
        break;
        case '*':
        {
            re_compiled[j].type = STAR;
        }
        break;
        case '+':
        {
            re_compiled[j].type = PLUS;
        }
        break;
        case '?':
        {
            re_compiled[j].type = QUESTIONMARK;
        }
        break;

        case '\\':
        {
            if (pattern[i + 1] != '\0')
            {
                i += 1;
                //check for d or w
                switch (pattern[i])
                {
                case 'd':
                {
                    re_compiled[j].type = DIGIT;
                }
                break;
                case 'w':
                {
                    re_compiled[j].type = WORD;
                }
                break;

                default:
                {
                    re_compiled[j].type = CHAR;
                    re_compiled[j].ch = pattern[i];
                }
                break;
                }
            }
        }
        break;

        case '[':
        {
            /* Remember where the char-buffer starts. */
            int buf_idx = 0;
            char *ch_cl_buf = (char *)malloc(sizeof(char) * MAX_CHAR_CLASS_LEN);

            re_compiled[j].type = CHAR_CLASS;

            //copy regex to ch_cl_buf
            while ((pattern[++i] != ']') && (pattern[i] != '\0')) /* Missing ] */
            {
                if (pattern[i] == '\\')
                {

                    if (pattern[i + 1] == 0) /* incomplete pattern, missing non-zero char after '\\' */
                    {
                        return 0;
                    }
                    ch_cl_buf[buf_idx++] = pattern[i++];
                }

                ch_cl_buf[buf_idx++] = pattern[i];
            }

            /* Null-terminate string end */
            ch_cl_buf[buf_idx++] = 0;
            re_compiled[j].ch_cl = ch_cl_buf;
        }
        break;

        default:
        {
            re_compiled[j].type = CHAR;
            re_compiled[j].ch = c;
        }
        break;
            // }
        }
        ++j;
        ++i;
    }
    re_compiled[j].type = UNUSED;
    return re_compiled;
}

static int match_range(char c, char start, char end)
{
    return ((c >= start) && (c <= end));
}
static int match_digit(char c)
{
    return match_range(c, '0', '9');
}
static int match_alpha(char c)
{
    return ((match_range(c, 'a', 'z')) || (match_range(c, 'A', 'Z')));
}
static int match_alphanum(char c)
{
    return ((c == '_') || match_alpha(c) || match_digit(c));
}
static int matchone(regex_t p, char c)
{
    switch (p.type)
    {
    case CHAR_CLASS:
        return match_ch_cl(c, (const char *)p.ch_cl);
    case DIGIT:
        return match_digit(c);
    case WORD:
        return match_alphanum(c);
    default:
        return (p.ch == c);
    }
}
static int match_question(regex_t p, regex_t *pattern, const char *text, int *matchlength)
{

    // if (p.type == UNUSED)
    //     return 1;
    if (match_here(pattern, text, matchlength))
        return 1;
    if (*text && matchone(p, *text++))
    {
        if (match_here(pattern, text, matchlength))
        {
            (*matchlength)++;
            return 1;
        }
    }
    return 0;
}

static int match_ch_cl(char c, const char *str)
{
    do
    {
        if (str[1] == '-' && str[2] != '\0')
        {
            if (match_range(c, str[0], str[2]))
                return 1;
            str = str + 2;
        }
        else if (c == str[0])
        {
            return 1;
        }
    } while (*str++ != '\0');

    return 0;
}

static int match_star(regex_t p, regex_t *pattern, const char *text, int *matchlength)
{
    int greedy = 1;
#if DEBUG
    printf("type %d %s\n", pattern[0].type, text);
#endif
    if (pattern[0].type == QUESTIONMARK)
    {
        greedy = 0;
    }
    int prelen = *matchlength;
    const char *prepoint = text;
    if (greedy)
    {
        // printf("greedy \n");
        while ((text[0] != '\0') && matchone(p, *text))
        {
            text++;
            (*matchlength)++;
        }
    }
    else //non greedy
    {
        // printf("non greedy\n");
        while ((text[0] != '\0') && matchone(p, *text))
        {
            if (match_here(pattern + 1, text, matchlength))
            {
                // printf("found match\n");
                return 1;
            }
            // printf("%d %c \t" , pattern[1].type , *text );
            text++;
            (*matchlength)++;
        }
    }
    while (text >= prepoint)
    {
        if (match_here(pattern, text--, matchlength))
            return 1;
        (*matchlength)--;
    }

    *matchlength = prelen;
    //* always return 1 , bcz * can match ""
    return 0;
}

static int match_plus(regex_t p, regex_t *pattern, const char *text, int *matchlength)
{
    const char *prepoint = text;
    while ((text[0] != '\0') && matchone(p, *text))
    {
        text++;
        (*matchlength)++;
    }
    while (text > prepoint)
    {
        if (match_here(pattern, text--, matchlength))
            return 1;
        (*matchlength)--;
    }

    return 0;
}

static int match_here(regex_t *pattern, const char *text, int *matchlength)
{
    int pre = *matchlength;
    do
    {
        if ((pattern[0].type == UNUSED)
        {
            return 1
        } 
        if (pattern[1].type == QUESTIONMARK)
        {
            return match_question(pattern[0], &pattern[2], text, matchlength);
        }
        else if (pattern[1].type == STAR)
        {
            return match_star(pattern[0], &pattern[2], text, matchlength);
        }
        else if (pattern[1].type == PLUS)
        {
            return match_plus(pattern[0], &pattern[2], text, matchlength);
        }
        else if ((pattern[0].type == END) && pattern[1].type == UNUSED)
        {
            return (text[0] == '\0');
        }

        (*matchlength)++;
    } while ((text[0] != '\0') && matchone(*pattern++, *text++));

    *matchlength = pre;
    return 0;
}

span_t *re_search(regex_t *pattern, char *text)
{
    span_t *span = (span_t *)malloc(sizeof(span_t));
    span->end = span->start = -1;
    span->match = 0;
    int *matchlength = &span->end;
    *matchlength = 0;
    if (pattern != 0)
    {
        if (pattern[0].type == BEGIN)
        {
            // return ((match_here(&pattern[1], text, matchlength)) ? 0 : -1);
            match_here(&pattern[1], text, matchlength);
            return span;
        }
        else
        {
            int idx = -1;

            do
            {
                idx += 1;
                // printf("");
                if (match_here(pattern, text, matchlength))
                {
                    printf("idx=%d , matchlenght=%d \n", idx ,*matchlength);
                    if (text[0] == '\0')
                    {
                        // span->match = 0;
                        return span;
                    }
                    if (*matchlength > 0)
                    {
                        span->match = 1;
                        span->start = idx;
                        span->end = idx + *matchlength - 1;
                        return span;
                    }
                    if (idx != 0 && *matchlength == 0)
                    {
                        return span;
                    }
                    span->match = 1;
                    span->start = idx;
                    span->end = idx + *matchlength;
                    if (idx == 0 && *matchlength == 0)
                    {
                        return span;
                    }

                    // return idx;
                }
            } while (*text++ != '\0');
        }
    }

    return span;
    // return -1;
}

int main()
{

    char *text = (char *)malloc(sizeof(char) * MAX_TEXT_LEN);
    fgets(text, MAX_TEXT_LEN, stdin);
    text[strlen(text) - 1] = 0;
    // printf("%s\n", text);

    //get M
    char *temp = (char *)malloc(sizeof(char) * 5);
    temp = fgets(temp, 5, stdin);
    // printf("%s", temp);
    int M = atoi(temp);
    // printf("%d\n" , M );

    char *pattern = (char *)malloc(sizeof(char) * MAX_REGEX_LEN);
    for (int i = 0; i < M; ++i)
    {
        pattern = fgets(pattern, MAX_REGEX_LEN, stdin);
        // printf("\n%s" , pattern);
        pattern[strlen(pattern) - 1] = 0;
#if DEBUG
        disp_reg(re_compile(pattern));
#endif
        regex_t *pat = re_compile(pattern);
        span_t *span = re_search(pat, text);
        if (span->match)
        {
            printf("%d %d %d\n", span->match, span->start, span->end);
        }
        else
        {
            printf("0\n");
        }
        free(span);
        free(pat);
    }

    // if i get idx != 0 and matchlenth = 0 ; then its not a match

    // span_t *span = re_search(re_compile("ab*") , "acbbbc");
    // printf("%d %d %d\n", span->match , span->start , span->end);

    // span = re_search(re_compile("b\\w*?aba"), "bbbabbbaba");

    // printf("%d %d %d\n", span->match , span->start , span->end);
}