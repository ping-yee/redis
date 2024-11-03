#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "listpack.h"

// 測試函數
void test_listpack_operations(void)
{
    printf("\n\n== Listpack Test ==\n\n");
    unsigned char *lp = lpNew(50);
    printf("Listpack created. Total bytes: %lu, Number of elements: %lu\n", lpBytes(lp), lpLength(lp));

    unsigned char *field1 = (unsigned char *)"field1";
    unsigned char *value1 = (unsigned char *)"value1";
    lp = lpAppend(lp, field1, strlen((char *)field1));
    lp = lpAppend(lp, value1, strlen((char *)value1));
    printf("After inserting field1 and value1:\n");
    printf("Total bytes: %lu, Number of elements: %lu\n", lpBytes(lp), lpLength(lp));

    long long int_val = 42;
    lp = lpAppendInteger(lp, int_val);
    printf("After inserting integer 42:\n");
    printf("Total bytes: %lu, Number of elements: %lu\n", lpBytes(lp), lpLength(lp));

    unsigned char *p = lpFirst(lp);
    unsigned int slen;
    long long lval;
    while (p != NULL)
    {
        unsigned char *val = lpGetValue(p, &slen, &lval);
        if (val)
        {
            printf("String element: %.*s\n", slen, val);
        }
        else
        {
            printf("Integer element: %lld\n", lval);
        }
        p = lpNext(lp, p);
    }

    p = lpFirst(lp);
    lp = lpDelete(lp, p, NULL);
    printf("After deleting first element (field1):\n");
    printf("Total bytes: %lu, Number of elements: %lu\n", lpBytes(lp), lpLength(lp));

    lpFree(lp);
    printf("\n\n== Listpack freed ==\n\n");
}
