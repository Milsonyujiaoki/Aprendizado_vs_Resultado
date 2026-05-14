/*
** test_printf.c — unit tests for ft_printf.
**
** Strategy: capture output via pipe, compare with expected string.
** Edge cases covered (D-03, D-04):
**   - All 7 specifiers: %c %s %d %i %u %x %%
**   - Width (right-align, left-align with '-')
**   - Precision for %s and %d
**   - Zero-padding with '0' flag
**   - NULL string → "(null)"
**   - Zero and negative integers
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../../include/libft.h"

static int g_fails = 0;

/* ─── capture helper ─────────────────────────────────────────────────────── */

/*
** capture_printf: redirect stdout to a pipe, call ft_printf with a format
** and ONE argument (variadic for simplicity), restore stdout, return bytes.
** Writes output into buf[bufsz].  Returns chars written by ft_printf, or -1.
**
** Note: we build a simple per-specifier capture rather than a generic
** variadic forwarder to avoid complexity. Each specifier has a dedicated
** helper below.
*/

static int	capture_s(const char *fmt, const char *arg, char *buf, int bufsz)
{
	int	pipefd[2];
	int	saved;
	int	n;
	int	ret;

	if (pipe(pipefd) < 0) return (-1);
	saved = dup(1);
	dup2(pipefd[1], 1);
	ret = ft_printf(fmt, arg);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	n = (int)read(pipefd[0], buf, bufsz - 1);
	buf[n < 0 ? 0 : n] = '\0';
	close(pipefd[0]);
	return (ret);
}

static int	capture_d(const char *fmt, int arg, char *buf, int bufsz)
{
	int	pipefd[2];
	int	saved;
	int	n;
	int	ret;

	if (pipe(pipefd) < 0) return (-1);
	saved = dup(1);
	dup2(pipefd[1], 1);
	ret = ft_printf(fmt, arg);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	n = (int)read(pipefd[0], buf, bufsz - 1);
	buf[n < 0 ? 0 : n] = '\0';
	close(pipefd[0]);
	return (ret);
}

static int	capture_c(const char *fmt, char arg, char *buf, int bufsz)
{
	int	pipefd[2];
	int	saved;
	int	n;
	int	ret;

	if (pipe(pipefd) < 0) return (-1);
	saved = dup(1);
	dup2(pipefd[1], 1);
	ret = ft_printf(fmt, arg);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	n = (int)read(pipefd[0], buf, bufsz - 1);
	buf[n < 0 ? 0 : n] = '\0';
	close(pipefd[0]);
	return (ret);
}

static int	capture_no_arg(const char *fmt, char *buf, int bufsz)
{
	int	pipefd[2];
	int	saved;
	int	n;
	int	ret;

	if (pipe(pipefd) < 0) return (-1);
	saved = dup(1);
	dup2(pipefd[1], 1);
	ret = ft_printf(fmt);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	n = (int)read(pipefd[0], buf, bufsz - 1);
	buf[n < 0 ? 0 : n] = '\0';
	close(pipefd[0]);
	return (ret);
}

#define ASSERT(cond, label) \
    do { \
        if (cond) { printf("[PASS] %s\n", label); } \
        else       { printf("[FAIL] %s\n", label); g_fails++; } \
    } while (0)

/* ─── tests ─────────────────────────────────────────────────────────────── */

static void test_specifiers(void)
{
	char buf[128];

	capture_s("%s", "hello", buf, sizeof(buf));
	ASSERT(strcmp(buf, "hello") == 0, "printf: %%s nominal");

	capture_d("%d", 42, buf, sizeof(buf));
	ASSERT(strcmp(buf, "42") == 0, "printf: %%d positive");

	capture_d("%d", -7, buf, sizeof(buf));
	ASSERT(strcmp(buf, "-7") == 0, "printf: %%d negative");

	capture_d("%d", 0, buf, sizeof(buf));
	ASSERT(strcmp(buf, "0") == 0, "printf: %%d zero");

	capture_d("%i", 99, buf, sizeof(buf));
	ASSERT(strcmp(buf, "99") == 0, "printf: %%i");

	capture_d("%u", 255, buf, sizeof(buf));
	ASSERT(strcmp(buf, "255") == 0, "printf: %%u");

	capture_d("%x", 255, buf, sizeof(buf));
	ASSERT(strcmp(buf, "ff") == 0, "printf: %%x lowercase");

	capture_c("%c", 'A', buf, sizeof(buf));
	ASSERT(strcmp(buf, "A") == 0, "printf: %%c");

	capture_no_arg("%%", buf, sizeof(buf));
	ASSERT(strcmp(buf, "%") == 0, "printf: %%%%");
}

static void test_width(void)
{
	char buf[128];

	capture_d("%5d", 42, buf, sizeof(buf));
	ASSERT(strcmp(buf, "   42") == 0, "printf: width right-align");

	capture_d("%-5d", 42, buf, sizeof(buf));
	ASSERT(strcmp(buf, "42   ") == 0, "printf: width left-align");

	capture_d("%05d", 42, buf, sizeof(buf));
	ASSERT(strcmp(buf, "00042") == 0, "printf: zero-pad width");

	capture_s("%8s", "hi", buf, sizeof(buf));
	ASSERT(strcmp(buf, "      hi") == 0, "printf: width %%s right-align");

	capture_s("%-8s", "hi", buf, sizeof(buf));
	ASSERT(strcmp(buf, "hi      ") == 0, "printf: width %%s left-align");
}

static void test_precision(void)
{
	char buf[128];

	capture_s("%.3s", "hello", buf, sizeof(buf));
	ASSERT(strcmp(buf, "hel") == 0, "printf: precision truncates %%s");

	capture_d("%.5d", 42, buf, sizeof(buf));
	ASSERT(strcmp(buf, "00042") == 0, "printf: precision pads %%d");

	capture_s("%8.3s", "hello", buf, sizeof(buf));
	ASSERT(strcmp(buf, "     hel") == 0, "printf: width+precision %%s");
}

static void test_null_string(void)
{
	char buf[128];

	capture_s("%s", NULL, buf, sizeof(buf));
	ASSERT(strcmp(buf, "(null)") == 0, "printf: NULL string → (null)");
}

/* ─── main ───────────────────────────────────────────────────────────────── */

int main(void)
{
	printf("\n=== test_printf ===\n");
	test_specifiers();
	test_width();
	test_precision();
	test_null_string();
	printf("\n%s — %d failure(s)\n", g_fails == 0 ? "ALL PASS" : "SOME FAIL", g_fails);
	return (g_fails != 0);
}
