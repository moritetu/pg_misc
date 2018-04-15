my_timeout
==========

my_timeout is sample program for studying timeout feature of PostgreSQL.


Installation
------------

```bash
$ cd my_timeout
$ make install
```

Usage
-----

```sql
postgres=# CREATE EXTENSION my_timeout;
CREATE EXTENSION
postgres=# SELECT my_register_timeout(); -- Register my timer.
 my_register_timeout 
---------------------
                   9
(1 row)

postgres=# SELECT my_enable_timeout_after(5000); -- A timer will be fired after 5 seconds.
 my_enable_timeout_after 
-------------------------
 t
(1 row)

postgres=# SELECT my_get_timeout_indicator(); -- Check whether timer fired.
 my_get_timeout_indicator 
--------------------------
 t
(1 row)

postgres=# SELECT my_get_timeout_start_time(); -- Show start-time of the timer.
   my_get_timeout_start_time   
-------------------------------
 2018-04-16 00:17:37.234418+09
(1 row)

postgres=# SELECT my_get_timeout_finish_time(); -- Show finish-time of the timer.
  my_get_timeout_finish_time   
-------------------------------
 2018-04-16 00:17:42.234418+09
(1 row)

postgres=# DROP EXTENSION my_timeout;
DEBUG:  drop auto-cascades to function my_register_timeout()
DEBUG:  drop auto-cascades to function my_enable_timeout_after(integer)
DEBUG:  drop auto-cascades to function my_enable_timeout_at(integer)
DEBUG:  drop auto-cascades to function my_disable_timeout()
DEBUG:  drop auto-cascades to function my_get_timeout_indicator()
DEBUG:  drop auto-cascades to function my_get_timeout_start_time()
DEBUG:  drop auto-cascades to function my_get_timeout_finish_time()
DROP EXTENSION
```

