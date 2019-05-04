/*****************************************************************************
 * Copyright (c) 2010, 2011 Rowley Associates Limited.                       *
 *                                                                           *
 * This file may be distributed under the terms of the License Agreement     *
 * provided with this software.                                              *
 *                                                                           *
 * THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, INCLUDING THE   *
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. *
 *****************************************************************************/

#include <libmem.h>
#include <libmem_loader.h>

#define RAM_SIZE (8 * 1024)

extern unsigned char __RAM_segment_start__[];
extern unsigned char __RAM_segment_used_end__[];

int
kinetis_register_libmem_driver(libmem_driver_handle_t *h);
 
int
main(unsigned long param0)
{ 
  libmem_driver_handle_t h;    
  int res = kinetis_register_libmem_driver(&h);
  if (res != LIBMEM_STATUS_SUCCESS)
    libmem_rpc_loader_exit(LIBMEM_STATUS_ERROR, "Unsupported device");  
   
  res = libmem_rpc_loader_start(__RAM_segment_used_end__, __RAM_segment_start__ + RAM_SIZE - 1); 
  libmem_rpc_loader_exit(res, 0);
  return 0;
}
