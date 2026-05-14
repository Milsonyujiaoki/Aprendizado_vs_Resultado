/*
** test_strsplit.c — unit tests for ft_strsplit.
**
** Edge cases covered (D-03 matrix):
**   - Normal split with multiple tokens
**   - Consecutive delimiters (collapse → no empty tokens)
**   - Delimiter at start/end of string
**   - Empty string input
**   - NULL input
**   - Single-char token
**   - No delimiter found (whole string is one token)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/libft.h"

static int g_fails = 0;

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

/* free a NULL-terminated array of strings */
static void free_arr(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

/* count elements in NULL-terminated array */
static int arr_len(char **arr)
{
    int n = 0;
    if (arr == NULL) return -1;
    while (arr[n] != NULL) n++;
    return n;
}

/* ─── tests ─────────────────────────────────────────────────────────────── */

static void test_basic_split(void)
{
    char **r = ft_strsplit("a,b,c", ',');
    ASSERT(r != NULL,                         "split: result not NULL");
    ASSERT(arr_len(r) == 3,                   "split: 3 tokens");
    ASSERT(strcmp(r[0], "a") == 0,            "split: token[0] == 'a'");
    ASSERT(strcmp(r[1], "b") == 0,            "split: token[1] == 'b'");
    ASSERT(strcmp(r[2], "c") == 0,            "split: token[2] == 'c'");
    ASSERT(r[3] == NULL,                      "split: NULL-terminated");
    free_arr(r);
}

static void test_consecutive_delimiters(void)
{
    char **r = ft_strsplit("a,,b,,,c", ',');
    ASSERT(arr_len(r) == 3,                   "split: consecutive delimiters collapse");
    ASSERT(strcmp(r[0], "a") == 0,            "split: collapsed[0] == 'a'");
    ASSERT(strcmp(r[2], "c") == 0,            "split: collapsed[2] == 'c'");
    free_arr(r);
}

static void test_delimiter_at_edges(void)
{
    char **r = ft_strsplit(",hello,world,", ',');
    ASSERT(arr_len(r) == 2,                   "split: leading+trailing delimiters ignored");
    ASSERT(strcmp(r[0], "hello") == 0,        "split: edge[0] == 'hello'");
    ASSERT(strcmp(r[1], "world") == 0,        "split: edge[1] == 'world'");
    free_arr(r);
}

static void test_empty_string(void)
{
    char **r = ft_strsplit("", ',');
    ASSERT(r != NULL,                         "split: empty string returns valid array");
    ASSERT(arr_len(r) == 0,                   "split: empty string has 0 tokens");
    ASSERT(r[0] == NULL,                      "split: empty string array[0] == NULL");
    free_arr(r);
}

static void test_null_input(void)
{
    char **r = ft_strsplit(NULL, ',');
    ASSERT(r == NULL,                         "split: NULL input returns NULL");
}

static void test_no_delimiter(void)
{
    char **r = ft_strsplit("hello", ',');
    ASSERT(arr_len(r) == 1,                   "split: no delimiter → 1 token");
    ASSERT(strcmp(r[0], "hello") == 0,        "split: no delimiter token == 'hello'");
    free_arr(r);
}

static void test_single_char_tokens(void)
{
    char **r = ft_strsplit("x y z", ' ');
    ASSERT(arr_len(r) == 3,                   "split: single-char tokens count");
    ASSERT(strcmp(r[0], "x") == 0,            "split: single-char[0] == 'x'");
    free_arr(r);
}

/* ─── main ───────────────────────────────────────────────────────────────── */

int main(void)
{
    printf("\n=== test_strsplit ===\n");
    test_basic_split();
    test_consecutive_delimiters();
    test_delimiter_at_edges();
    test_empty_string();
    test_null_input();
    test_no_delimiter();
    test_single_char_tokens();
    printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
    return (g_fails != 0);
}
