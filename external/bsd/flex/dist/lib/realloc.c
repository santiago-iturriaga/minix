/*	$NetBSD: realloc.c,v 1.1.1.1 2013/04/06 14:05:53 christos Exp $	*/

#include <config.h>

#include <stdlib.h>

#include <errno.h>

void * rpl_realloc (void *p, size_t n)
{
  void *result;

  if (n == 0)
    {
      n = 1;
    }

  if (p == NULL)
    {
      result = malloc (n);
    }
  else
    result = realloc (p, n);

  if (result == NULL)
    errno = ENOMEM;

  return result;
}
