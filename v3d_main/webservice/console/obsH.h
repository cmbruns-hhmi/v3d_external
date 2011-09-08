/* obsH.h
   Generated by gSOAP 2.8.3 from obsModHeader.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef obsH_H
#define obsH_H
#include "obsStub.h"

namespace obs {
#ifndef WITH_NOIDREF
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 void * SOAP_FMAC4 obs_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 obs_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

SOAP_FMAC3 void* SOAP_FMAC4 soap_container_id_forward(struct soap*, const char*, void*, size_t, int, int, size_t, unsigned int);

SOAP_FMAC3 void SOAP_FMAC4 obs_container_insert(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_byte
#define SOAP_TYPE_obs_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_begin_send(soap) || obs::soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef SOAP_TYPE_obs_int
#define SOAP_TYPE_obs_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_begin_send(soap) || obs::soap_put_int(soap, data, "int", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef SOAP_TYPE_obs_LONG64
#define SOAP_TYPE_obs_LONG64 (9)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_LONG64(struct soap*, LONG64 *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_LONG64(struct soap*, const char*, int, const LONG64 *, const char*);
SOAP_FMAC3 LONG64 * SOAP_FMAC4 soap_in_LONG64(struct soap*, const char*, LONG64 *, const char*);

#ifndef soap_write_LONG64
#define soap_write_LONG64(soap, data) ( soap_begin_send(soap) || obs::soap_put_LONG64(soap, data, "long", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_LONG64(struct soap*, const LONG64 *, const char*, const char*);

#ifndef soap_read_LONG64
#define soap_read_LONG64(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_LONG64(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 LONG64 * SOAP_FMAC4 soap_get_LONG64(struct soap*, LONG64 *, const char*, const char*);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_SOAP_ENV__Fault
#define SOAP_TYPE_obs_SOAP_ENV__Fault (36)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_SOAP_ENV__Fault(soap, data), 0) || obs::soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#define soap_new_SOAP_ENV__Fault(soap, n) soap_instantiate_SOAP_ENV__Fault(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Fault(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_SOAP_ENV__Reason
#define SOAP_TYPE_obs_SOAP_ENV__Reason (35)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_SOAP_ENV__Reason(soap, data), 0) || obs::soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#define soap_new_SOAP_ENV__Reason(soap, n) soap_instantiate_SOAP_ENV__Reason(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Reason(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_SOAP_ENV__Detail
#define SOAP_TYPE_obs_SOAP_ENV__Detail (32)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_SOAP_ENV__Detail(soap, data), 0) || obs::soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#define soap_new_SOAP_ENV__Detail(soap, n) soap_instantiate_SOAP_ENV__Detail(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Detail(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_SOAP_ENV__Code
#define SOAP_TYPE_obs_SOAP_ENV__Code (30)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_SOAP_ENV__Code(soap, data), 0) || obs::soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#define soap_new_SOAP_ENV__Code(soap, n) soap_instantiate_SOAP_ENV__Code(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Code(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_SOAP_ENV__Header
#define SOAP_TYPE_obs_SOAP_ENV__Header (29)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_SOAP_ENV__Header(soap, data), 0) || obs::soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#define soap_new_SOAP_ENV__Header(soap, n) soap_instantiate_SOAP_ENV__Header(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Header(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE_obs_fw__annotationsChanged
#define SOAP_TYPE_obs_fw__annotationsChanged (28)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__annotationsChanged(struct soap*, struct fw__annotationsChanged *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__annotationsChanged(struct soap*, const struct fw__annotationsChanged *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__annotationsChanged(struct soap*, const char*, int, const struct fw__annotationsChanged *, const char*);
SOAP_FMAC3 struct fw__annotationsChanged * SOAP_FMAC4 soap_in_fw__annotationsChanged(struct soap*, const char*, struct fw__annotationsChanged *, const char*);

#ifndef soap_write_fw__annotationsChanged
#define soap_write_fw__annotationsChanged(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__annotationsChanged(soap, data), 0) || obs::soap_put_fw__annotationsChanged(soap, data, "fw:annotationsChanged", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__annotationsChanged(struct soap*, const struct fw__annotationsChanged *, const char*, const char*);

#ifndef soap_read_fw__annotationsChanged
#define soap_read_fw__annotationsChanged(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__annotationsChanged(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__annotationsChanged * SOAP_FMAC4 soap_get_fw__annotationsChanged(struct soap*, struct fw__annotationsChanged *, const char*, const char*);

#define soap_new_fw__annotationsChanged(soap, n) soap_instantiate_fw__annotationsChanged(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__annotationsChanged(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__annotationsChanged * SOAP_FMAC2 soap_instantiate_fw__annotationsChanged(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__annotationsChanged(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__annotationsChangedResponse
#define SOAP_TYPE_obs_fw__annotationsChangedResponse (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__annotationsChangedResponse(struct soap*, struct fw__annotationsChangedResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__annotationsChangedResponse(struct soap*, const struct fw__annotationsChangedResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__annotationsChangedResponse(struct soap*, const char*, int, const struct fw__annotationsChangedResponse *, const char*);
SOAP_FMAC3 struct fw__annotationsChangedResponse * SOAP_FMAC4 soap_in_fw__annotationsChangedResponse(struct soap*, const char*, struct fw__annotationsChangedResponse *, const char*);

#ifndef soap_write_fw__annotationsChangedResponse
#define soap_write_fw__annotationsChangedResponse(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__annotationsChangedResponse(soap, data), 0) || obs::soap_put_fw__annotationsChangedResponse(soap, data, "fw:annotationsChangedResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__annotationsChangedResponse(struct soap*, const struct fw__annotationsChangedResponse *, const char*, const char*);

#ifndef soap_read_fw__annotationsChangedResponse
#define soap_read_fw__annotationsChangedResponse(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__annotationsChangedResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__annotationsChangedResponse * SOAP_FMAC4 soap_get_fw__annotationsChangedResponse(struct soap*, struct fw__annotationsChangedResponse *, const char*, const char*);

#define soap_new_fw__annotationsChangedResponse(soap, n) soap_instantiate_fw__annotationsChangedResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__annotationsChangedResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__annotationsChangedResponse * SOAP_FMAC2 soap_instantiate_fw__annotationsChangedResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__annotationsChangedResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__entityViewRequested
#define SOAP_TYPE_obs_fw__entityViewRequested (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__entityViewRequested(struct soap*, struct fw__entityViewRequested *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__entityViewRequested(struct soap*, const struct fw__entityViewRequested *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__entityViewRequested(struct soap*, const char*, int, const struct fw__entityViewRequested *, const char*);
SOAP_FMAC3 struct fw__entityViewRequested * SOAP_FMAC4 soap_in_fw__entityViewRequested(struct soap*, const char*, struct fw__entityViewRequested *, const char*);

#ifndef soap_write_fw__entityViewRequested
#define soap_write_fw__entityViewRequested(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__entityViewRequested(soap, data), 0) || obs::soap_put_fw__entityViewRequested(soap, data, "fw:entityViewRequested", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__entityViewRequested(struct soap*, const struct fw__entityViewRequested *, const char*, const char*);

#ifndef soap_read_fw__entityViewRequested
#define soap_read_fw__entityViewRequested(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__entityViewRequested(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__entityViewRequested * SOAP_FMAC4 soap_get_fw__entityViewRequested(struct soap*, struct fw__entityViewRequested *, const char*, const char*);

#define soap_new_fw__entityViewRequested(soap, n) soap_instantiate_fw__entityViewRequested(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__entityViewRequested(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__entityViewRequested * SOAP_FMAC2 soap_instantiate_fw__entityViewRequested(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__entityViewRequested(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__entityViewRequestedResponse
#define SOAP_TYPE_obs_fw__entityViewRequestedResponse (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__entityViewRequestedResponse(struct soap*, struct fw__entityViewRequestedResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__entityViewRequestedResponse(struct soap*, const struct fw__entityViewRequestedResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__entityViewRequestedResponse(struct soap*, const char*, int, const struct fw__entityViewRequestedResponse *, const char*);
SOAP_FMAC3 struct fw__entityViewRequestedResponse * SOAP_FMAC4 soap_in_fw__entityViewRequestedResponse(struct soap*, const char*, struct fw__entityViewRequestedResponse *, const char*);

#ifndef soap_write_fw__entityViewRequestedResponse
#define soap_write_fw__entityViewRequestedResponse(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__entityViewRequestedResponse(soap, data), 0) || obs::soap_put_fw__entityViewRequestedResponse(soap, data, "fw:entityViewRequestedResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__entityViewRequestedResponse(struct soap*, const struct fw__entityViewRequestedResponse *, const char*, const char*);

#ifndef soap_read_fw__entityViewRequestedResponse
#define soap_read_fw__entityViewRequestedResponse(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__entityViewRequestedResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__entityViewRequestedResponse * SOAP_FMAC4 soap_get_fw__entityViewRequestedResponse(struct soap*, struct fw__entityViewRequestedResponse *, const char*, const char*);

#define soap_new_fw__entityViewRequestedResponse(soap, n) soap_instantiate_fw__entityViewRequestedResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__entityViewRequestedResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__entityViewRequestedResponse * SOAP_FMAC2 soap_instantiate_fw__entityViewRequestedResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__entityViewRequestedResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__entitySelected
#define SOAP_TYPE_obs_fw__entitySelected (20)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__entitySelected(struct soap*, struct fw__entitySelected *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__entitySelected(struct soap*, const struct fw__entitySelected *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__entitySelected(struct soap*, const char*, int, const struct fw__entitySelected *, const char*);
SOAP_FMAC3 struct fw__entitySelected * SOAP_FMAC4 soap_in_fw__entitySelected(struct soap*, const char*, struct fw__entitySelected *, const char*);

#ifndef soap_write_fw__entitySelected
#define soap_write_fw__entitySelected(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__entitySelected(soap, data), 0) || obs::soap_put_fw__entitySelected(soap, data, "fw:entitySelected", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__entitySelected(struct soap*, const struct fw__entitySelected *, const char*, const char*);

#ifndef soap_read_fw__entitySelected
#define soap_read_fw__entitySelected(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__entitySelected(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__entitySelected * SOAP_FMAC4 soap_get_fw__entitySelected(struct soap*, struct fw__entitySelected *, const char*, const char*);

#define soap_new_fw__entitySelected(soap, n) soap_instantiate_fw__entitySelected(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__entitySelected(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__entitySelected * SOAP_FMAC2 soap_instantiate_fw__entitySelected(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__entitySelected(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__entitySelectedResponse
#define SOAP_TYPE_obs_fw__entitySelectedResponse (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__entitySelectedResponse(struct soap*, struct fw__entitySelectedResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__entitySelectedResponse(struct soap*, const struct fw__entitySelectedResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__entitySelectedResponse(struct soap*, const char*, int, const struct fw__entitySelectedResponse *, const char*);
SOAP_FMAC3 struct fw__entitySelectedResponse * SOAP_FMAC4 soap_in_fw__entitySelectedResponse(struct soap*, const char*, struct fw__entitySelectedResponse *, const char*);

#ifndef soap_write_fw__entitySelectedResponse
#define soap_write_fw__entitySelectedResponse(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__entitySelectedResponse(soap, data), 0) || obs::soap_put_fw__entitySelectedResponse(soap, data, "fw:entitySelectedResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__entitySelectedResponse(struct soap*, const struct fw__entitySelectedResponse *, const char*, const char*);

#ifndef soap_read_fw__entitySelectedResponse
#define soap_read_fw__entitySelectedResponse(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__entitySelectedResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__entitySelectedResponse * SOAP_FMAC4 soap_get_fw__entitySelectedResponse(struct soap*, struct fw__entitySelectedResponse *, const char*, const char*);

#define soap_new_fw__entitySelectedResponse(soap, n) soap_instantiate_fw__entitySelectedResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__entitySelectedResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__entitySelectedResponse * SOAP_FMAC2 soap_instantiate_fw__entitySelectedResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__entitySelectedResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__ontologyChanged
#define SOAP_TYPE_obs_fw__ontologyChanged (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__ontologyChanged(struct soap*, struct fw__ontologyChanged *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__ontologyChanged(struct soap*, const struct fw__ontologyChanged *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__ontologyChanged(struct soap*, const char*, int, const struct fw__ontologyChanged *, const char*);
SOAP_FMAC3 struct fw__ontologyChanged * SOAP_FMAC4 soap_in_fw__ontologyChanged(struct soap*, const char*, struct fw__ontologyChanged *, const char*);

#ifndef soap_write_fw__ontologyChanged
#define soap_write_fw__ontologyChanged(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__ontologyChanged(soap, data), 0) || obs::soap_put_fw__ontologyChanged(soap, data, "fw:ontologyChanged", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__ontologyChanged(struct soap*, const struct fw__ontologyChanged *, const char*, const char*);

#ifndef soap_read_fw__ontologyChanged
#define soap_read_fw__ontologyChanged(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__ontologyChanged(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__ontologyChanged * SOAP_FMAC4 soap_get_fw__ontologyChanged(struct soap*, struct fw__ontologyChanged *, const char*, const char*);

#define soap_new_fw__ontologyChanged(soap, n) soap_instantiate_fw__ontologyChanged(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__ontologyChanged(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__ontologyChanged * SOAP_FMAC2 soap_instantiate_fw__ontologyChanged(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__ontologyChanged(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__ontologyChangedResponse
#define SOAP_TYPE_obs_fw__ontologyChangedResponse (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__ontologyChangedResponse(struct soap*, struct fw__ontologyChangedResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__ontologyChangedResponse(struct soap*, const struct fw__ontologyChangedResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__ontologyChangedResponse(struct soap*, const char*, int, const struct fw__ontologyChangedResponse *, const char*);
SOAP_FMAC3 struct fw__ontologyChangedResponse * SOAP_FMAC4 soap_in_fw__ontologyChangedResponse(struct soap*, const char*, struct fw__ontologyChangedResponse *, const char*);

#ifndef soap_write_fw__ontologyChangedResponse
#define soap_write_fw__ontologyChangedResponse(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__ontologyChangedResponse(soap, data), 0) || obs::soap_put_fw__ontologyChangedResponse(soap, data, "fw:ontologyChangedResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__ontologyChangedResponse(struct soap*, const struct fw__ontologyChangedResponse *, const char*, const char*);

#ifndef soap_read_fw__ontologyChangedResponse
#define soap_read_fw__ontologyChangedResponse(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__ontologyChangedResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__ontologyChangedResponse * SOAP_FMAC4 soap_get_fw__ontologyChangedResponse(struct soap*, struct fw__ontologyChangedResponse *, const char*, const char*);

#define soap_new_fw__ontologyChangedResponse(soap, n) soap_instantiate_fw__ontologyChangedResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__ontologyChangedResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__ontologyChangedResponse * SOAP_FMAC2 soap_instantiate_fw__ontologyChangedResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__ontologyChangedResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__ontologySelected
#define SOAP_TYPE_obs_fw__ontologySelected (12)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__ontologySelected(struct soap*, struct fw__ontologySelected *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__ontologySelected(struct soap*, const struct fw__ontologySelected *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__ontologySelected(struct soap*, const char*, int, const struct fw__ontologySelected *, const char*);
SOAP_FMAC3 struct fw__ontologySelected * SOAP_FMAC4 soap_in_fw__ontologySelected(struct soap*, const char*, struct fw__ontologySelected *, const char*);

#ifndef soap_write_fw__ontologySelected
#define soap_write_fw__ontologySelected(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__ontologySelected(soap, data), 0) || obs::soap_put_fw__ontologySelected(soap, data, "fw:ontologySelected", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__ontologySelected(struct soap*, const struct fw__ontologySelected *, const char*, const char*);

#ifndef soap_read_fw__ontologySelected
#define soap_read_fw__ontologySelected(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__ontologySelected(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__ontologySelected * SOAP_FMAC4 soap_get_fw__ontologySelected(struct soap*, struct fw__ontologySelected *, const char*, const char*);

#define soap_new_fw__ontologySelected(soap, n) soap_instantiate_fw__ontologySelected(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__ontologySelected(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__ontologySelected * SOAP_FMAC2 soap_instantiate_fw__ontologySelected(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__ontologySelected(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_obs_fw__ontologySelectedResponse
#define SOAP_TYPE_obs_fw__ontologySelectedResponse (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_fw__ontologySelectedResponse(struct soap*, struct fw__ontologySelectedResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_fw__ontologySelectedResponse(struct soap*, const struct fw__ontologySelectedResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_fw__ontologySelectedResponse(struct soap*, const char*, int, const struct fw__ontologySelectedResponse *, const char*);
SOAP_FMAC3 struct fw__ontologySelectedResponse * SOAP_FMAC4 soap_in_fw__ontologySelectedResponse(struct soap*, const char*, struct fw__ontologySelectedResponse *, const char*);

#ifndef soap_write_fw__ontologySelectedResponse
#define soap_write_fw__ontologySelectedResponse(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_fw__ontologySelectedResponse(soap, data), 0) || obs::soap_put_fw__ontologySelectedResponse(soap, data, "fw:ontologySelectedResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_fw__ontologySelectedResponse(struct soap*, const struct fw__ontologySelectedResponse *, const char*, const char*);

#ifndef soap_read_fw__ontologySelectedResponse
#define soap_read_fw__ontologySelectedResponse(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_fw__ontologySelectedResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct fw__ontologySelectedResponse * SOAP_FMAC4 soap_get_fw__ontologySelectedResponse(struct soap*, struct fw__ontologySelectedResponse *, const char*, const char*);

#define soap_new_fw__ontologySelectedResponse(soap, n) soap_instantiate_fw__ontologySelectedResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_fw__ontologySelectedResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct fw__ontologySelectedResponse * SOAP_FMAC2 soap_instantiate_fw__ontologySelectedResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_fw__ontologySelectedResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_obs_PointerToSOAP_ENV__Reason (38)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_PointerToSOAP_ENV__Reason(soap, data), 0) || obs::soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_obs_PointerToSOAP_ENV__Detail (37)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_PointerToSOAP_ENV__Detail(soap, data), 0) || obs::soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_obs_PointerToSOAP_ENV__Code
#define SOAP_TYPE_obs_PointerToSOAP_ENV__Code (31)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_PointerToSOAP_ENV__Code(soap, data), 0) || obs::soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#endif

#ifndef SOAP_TYPE_obs__QName
#define SOAP_TYPE_obs__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)


#define soap_serialize__QName(soap, a) soap_serialize_string(soap, a)

SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize__QName(soap, data), 0) || obs::soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !obs::soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef SOAP_TYPE_obs_string
#define SOAP_TYPE_obs_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_begin_send(soap) || (obs::soap_serialize_string(soap, data), 0) || obs::soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !obs::soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

} // namespace obs


#endif

/* End of obsH.h */
