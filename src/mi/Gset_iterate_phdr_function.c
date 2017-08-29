#include "libunwind_i.h"

//! Set a alternative function to use in place of dl_iterate_phdr.
/*! Suggested use is to specify an async-signal safe implementation.
 *  If not set (or set to NULL) a the system dl_iterate_phdr will
 *  be used. */
void
unw_set_iterate_phdr_function (unw_addr_space_t as, unw_iterate_phdr_func_t function)
{
  if (!tdep_init_done)
    tdep_init ();

  if (function)
    as->iterate_phdr_function = function;
  else
    as->iterate_phdr_function = dl_iterate_phdr;
}
