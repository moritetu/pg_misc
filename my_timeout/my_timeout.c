/*-------------------------------------------------------------------------
 *
 * timeout_test.c
 *		Timeout test code
 *
 * IDENTIFICATION
 *	  contrib/timeout_test/pg_retire.c
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "fmgr.h"
#include "utils/timeout.h"


PG_MODULE_MAGIC;


static TimeoutId MyTimeoutId = USER_TIMEOUT;


static void my_timeout_handler(void);


static void my_timeout_handler(void)
{
	ereport(DEBUG3,
			(errmsg("MyTimer fired!")));
}

PG_FUNCTION_INFO_V1(my_register_timeout);
Datum
my_register_timeout(PG_FUNCTION_ARGS)
{
	if (MyTimeoutId != USER_TIMEOUT)
	{
		ereport(WARNING,
				 (errmsg("timeout is already set.")));
		PG_RETURN_INT32(-1);
	}

	MyTimeoutId = RegisterTimeout(USER_TIMEOUT, my_timeout_handler);
	PG_RETURN_INT32(MyTimeoutId);
}

PG_FUNCTION_INFO_V1(my_enable_timeout_after);
Datum
my_enable_timeout_after(PG_FUNCTION_ARGS)
{
	int timeout_after = PG_GETARG_INT32(0);

	enable_timeout_after(MyTimeoutId, timeout_after);

	PG_RETURN_BOOL(true);
}


PG_FUNCTION_INFO_V1(my_enable_timeout_at);
Datum
my_enable_timeout_at(PG_FUNCTION_ARGS)
{
	int timeout_at = PG_GETARG_INT32(0);

	enable_timeout_at(MyTimeoutId, timeout_at);

	PG_RETURN_BOOL(true);
}

PG_FUNCTION_INFO_V1(my_disable_timeout);
Datum
my_disable_timeout(PG_FUNCTION_ARGS)
{
	disable_timeout(MyTimeoutId, true);

	PG_RETURN_BOOL(true);
}


PG_FUNCTION_INFO_V1(my_get_timeout_indicator);
Datum
my_get_timeout_indicator(PG_FUNCTION_ARGS)
{
	bool indicator;

	indicator = get_timeout_indicator(MyTimeoutId, false);

	PG_RETURN_BOOL(indicator);
}

PG_FUNCTION_INFO_V1(my_get_timeout_start_time);
Datum
my_get_timeout_start_time(PG_FUNCTION_ARGS)
{
	int64 start_time;

	start_time = get_timeout_start_time(MyTimeoutId);

	PG_RETURN_INT64(start_time);
}

PG_FUNCTION_INFO_V1(my_get_timeout_finish_time);
Datum
my_get_timeout_finish_time(PG_FUNCTION_ARGS)
{
	int64 finish_time;

	finish_time = get_timeout_finish_time(MyTimeoutId);

	PG_RETURN_INT64(finish_time);
}
