/* File: _read_sigma_nemsiomodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Thu Aug 27 23:31:02 2020
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <string.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *_read_sigma_nemsio_error;
static PyObject *_read_sigma_nemsio_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
typedef char * string;

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
\
#define FAILNULL(p) do {                                            \
    if ((p) == NULL) {                                              \
        PyErr_SetString(PyExc_MemoryError, "NULL pointer found");   \
        goto capi_fail;                                             \
    }                                                               \
} while (0)

#define STRINGMALLOC(str,len)\
  if ((str = (string)malloc(sizeof(char)*(len+1))) == NULL) {\
    PyErr_SetString(PyExc_MemoryError, "out of memory");\
    goto capi_fail;\
  } else {\
    (str)[len] = '\0';\
  }

#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define STRINGFREE(str) do {if (!(str == NULL)) free(str);} while (0)

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif

#define STRINGCOPYN(to,from,buf_size)                           \
    do {                                                        \
        int _m = (buf_size);                                    \
        char *_to = (to);                                       \
        char *_from = (from);                                   \
        FAILNULL(_to); FAILNULL(_from);                         \
        (void)strncpy(_to, _from, sizeof(char)*_m);             \
        _to[_m-1] = '\0';                                      \
        /* Padding with spaces instead of nulls */              \
        for (_m -= 2; _m >= 0 && _to[_m] == '\0'; _m--) {      \
            _to[_m] = ' ';                                      \
        }                                                       \
    } while (0)


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int string_from_pyobj(string *str,int *len,const string inistr,PyObject *obj,const char *errmess) {
  PyArrayObject *arr = NULL;
  PyObject *tmp = NULL;
#ifdef DEBUGCFUNCS
fprintf(stderr,"string_from_pyobj(str='%s',len=%d,inistr='%s',obj=%p)\n",(char*)str,*len,(char *)inistr,obj);
#endif
  if (obj == Py_None) {
    if (*len == -1)
      *len = strlen(inistr); /* Will this cause problems? */
    STRINGMALLOC(*str,*len);
    STRINGCOPYN(*str,inistr,*len+1);
    return 1;
  }
  if (PyArray_Check(obj)) {
    if ((arr = (PyArrayObject *)obj) == NULL)
      goto capi_fail;
    if (!ISCONTIGUOUS(arr)) {
      PyErr_SetString(PyExc_ValueError,"array object is non-contiguous.");
      goto capi_fail;
    }
    if (*len == -1)
      *len = (PyArray_ITEMSIZE(arr))*PyArray_SIZE(arr);
    STRINGMALLOC(*str,*len);
    STRINGCOPYN(*str,PyArray_DATA(arr),*len+1);
    return 1;
  }
  if (PyString_Check(obj)) {
    tmp = obj;
    Py_INCREF(tmp);
  }
#if PY_VERSION_HEX >= 0x03000000
  else if (PyUnicode_Check(obj)) {
    tmp = PyUnicode_AsASCIIString(obj);
  }
  else {
    PyObject *tmp2;
    tmp2 = PyObject_Str(obj);
    if (tmp2) {
      tmp = PyUnicode_AsASCIIString(tmp2);
      Py_DECREF(tmp2);
    }
    else {
      tmp = NULL;
    }
  }
#else
  else {
    tmp = PyObject_Str(obj);
  }
#endif
  if (tmp == NULL) goto capi_fail;
  if (*len == -1)
    *len = PyString_GET_SIZE(tmp);
  STRINGMALLOC(*str,*len);
  STRINGCOPYN(*str,PyString_AS_STRING(tmp),*len+1);
  Py_DECREF(tmp);
  return 1;
capi_fail:
  Py_XDECREF(tmp);
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _read_sigma_nemsio_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = _read_sigma_nemsio_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC_US(read_nemsio_header,READ_NEMSIO_HEADER)(string,int*,int*,int*,int*,int*,size_t);
extern void F_FUNC_US(read_nemsio_coords,READ_NEMSIO_COORDS)(string,int*,int*,int*,float*,float*,float*,size_t);
extern void F_FUNC_US(read_nemsio_griddata,READ_NEMSIO_GRIDDATA)(string,int*,int*,int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,size_t);
extern void F_FUNC(onedtotwod,ONEDTOTWOD)(float*,float*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/***************************** read_nemsio_header *****************************/
static char doc_f2py_rout__read_sigma_nemsio_read_nemsio_header[] = "\
nlons,nlats,nlevs,idate,nfhour = read_nemsio_header(filename)\n\nWrapper for ``read_nemsio_header``.\
\n\nParameters\n----------\n"
"filename : input string(len=500)\n"
"\nReturns\n-------\n"
"nlons : int\n"
"nlats : int\n"
"nlevs : int\n"
"idate : rank-1 array('i') with bounds (7)\n"
"nfhour : int";
/* extern void F_FUNC_US(read_nemsio_header,READ_NEMSIO_HEADER)(string,int*,int*,int*,int*,int*,size_t); */
static PyObject *f2py_rout__read_sigma_nemsio_read_nemsio_header(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,int*,int*,int*,int*,int*,size_t)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  string filename = NULL;
  int slen(filename);
  PyObject *filename_capi = Py_None;
  int nlons = 0;
  int nlats = 0;
  int nlevs = 0;
  int *idate = NULL;
  npy_intp idate_Dims[1] = {-1};
  const int idate_Rank = 1;
  PyArrayObject *capi_idate_tmp = NULL;
  int capi_idate_intent = 0;
  int nfhour = 0;
  static char *capi_kwlist[] = {"filename",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "O:_read_sigma_nemsio.read_nemsio_header",\
    capi_kwlist,&filename_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable idate */
  idate_Dims[0]=7;
  capi_idate_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_idate_tmp = array_from_pyobj(NPY_INT,idate_Dims,idate_Rank,capi_idate_intent,Py_None);
  if (capi_idate_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `idate' of _read_sigma_nemsio.read_nemsio_header to C/Fortran array" );
  } else {
    idate = (int *)(PyArray_DATA(capi_idate_tmp));

  /* Processing variable nlats */
  /* Processing variable nfhour */
  /* Processing variable filename */
  slen(filename) = 500;
  f2py_success = string_from_pyobj(&filename,&slen(filename),"",filename_capi,"string_from_pyobj failed in converting 1st argument `filename' of _read_sigma_nemsio.read_nemsio_header to C string");
  if (f2py_success) {
  /* Processing variable nlons */
  /* Processing variable nlevs */
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(filename,&nlons,&nlats,&nlevs,idate,&nfhour,slen(filename));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("iiiNi",nlons,nlats,nlevs,capi_idate_tmp,nfhour);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  /* End of cleaning variable nlevs */
  /* End of cleaning variable nlons */
    STRINGFREE(filename);
  }  /*if (f2py_success) of filename*/
  /* End of cleaning variable filename */
  /* End of cleaning variable nfhour */
  /* End of cleaning variable nlats */
  }  /*if (capi_idate_tmp == NULL) ... else of idate*/
  /* End of cleaning variable idate */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************* end of read_nemsio_header *************************/

/***************************** read_nemsio_coords *****************************/
static char doc_f2py_rout__read_sigma_nemsio_read_nemsio_coords[] = "\
vcoord,lats,lons = read_nemsio_coords(filename,nlons,nlats,nlevs)\n\nWrapper for ``read_nemsio_coords``.\
\n\nParameters\n----------\n"
"filename : input string(len=500)\n"
"nlons : input int\n"
"nlats : input int\n"
"nlevs : input int\n"
"\nReturns\n-------\n"
"vcoord : rank-3 array('f') with bounds (nlevs + 1,3,2)\n"
"lats : rank-1 array('f') with bounds (nlats)\n"
"lons : rank-1 array('f') with bounds (nlons)";
/* extern void F_FUNC_US(read_nemsio_coords,READ_NEMSIO_COORDS)(string,int*,int*,int*,float*,float*,float*,size_t); */
static PyObject *f2py_rout__read_sigma_nemsio_read_nemsio_coords(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,int*,int*,int*,float*,float*,float*,size_t)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  string filename = NULL;
  int slen(filename);
  PyObject *filename_capi = Py_None;
  int nlons = 0;
  PyObject *nlons_capi = Py_None;
  int nlats = 0;
  PyObject *nlats_capi = Py_None;
  int nlevs = 0;
  PyObject *nlevs_capi = Py_None;
  float *vcoord = NULL;
  npy_intp vcoord_Dims[3] = {-1, -1, -1};
  const int vcoord_Rank = 3;
  PyArrayObject *capi_vcoord_tmp = NULL;
  int capi_vcoord_intent = 0;
  float *lats = NULL;
  npy_intp lats_Dims[1] = {-1};
  const int lats_Rank = 1;
  PyArrayObject *capi_lats_tmp = NULL;
  int capi_lats_intent = 0;
  float *lons = NULL;
  npy_intp lons_Dims[1] = {-1};
  const int lons_Rank = 1;
  PyArrayObject *capi_lons_tmp = NULL;
  int capi_lons_intent = 0;
  static char *capi_kwlist[] = {"filename","nlons","nlats","nlevs",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO:_read_sigma_nemsio.read_nemsio_coords",\
    capi_kwlist,&filename_capi,&nlons_capi,&nlats_capi,&nlevs_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable nlats */
    f2py_success = int_from_pyobj(&nlats,nlats_capi,"_read_sigma_nemsio.read_nemsio_coords() 3rd argument (nlats) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nlevs */
    f2py_success = int_from_pyobj(&nlevs,nlevs_capi,"_read_sigma_nemsio.read_nemsio_coords() 4th argument (nlevs) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nlons */
    f2py_success = int_from_pyobj(&nlons,nlons_capi,"_read_sigma_nemsio.read_nemsio_coords() 2nd argument (nlons) can't be converted to int");
  if (f2py_success) {
  /* Processing variable filename */
  slen(filename) = 500;
  f2py_success = string_from_pyobj(&filename,&slen(filename),"",filename_capi,"string_from_pyobj failed in converting 1st argument `filename' of _read_sigma_nemsio.read_nemsio_coords to C string");
  if (f2py_success) {
  /* Processing variable vcoord */
  vcoord_Dims[0]=nlevs + 1,vcoord_Dims[1]=3,vcoord_Dims[2]=2;
  capi_vcoord_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_vcoord_tmp = array_from_pyobj(NPY_FLOAT,vcoord_Dims,vcoord_Rank,capi_vcoord_intent,Py_None);
  if (capi_vcoord_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `vcoord' of _read_sigma_nemsio.read_nemsio_coords to C/Fortran array" );
  } else {
    vcoord = (float *)(PyArray_DATA(capi_vcoord_tmp));

  /* Processing variable lats */
  lats_Dims[0]=nlats;
  capi_lats_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_lats_tmp = array_from_pyobj(NPY_FLOAT,lats_Dims,lats_Rank,capi_lats_intent,Py_None);
  if (capi_lats_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `lats' of _read_sigma_nemsio.read_nemsio_coords to C/Fortran array" );
  } else {
    lats = (float *)(PyArray_DATA(capi_lats_tmp));

  /* Processing variable lons */
  lons_Dims[0]=nlons;
  capi_lons_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_lons_tmp = array_from_pyobj(NPY_FLOAT,lons_Dims,lons_Rank,capi_lons_intent,Py_None);
  if (capi_lons_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `lons' of _read_sigma_nemsio.read_nemsio_coords to C/Fortran array" );
  } else {
    lons = (float *)(PyArray_DATA(capi_lons_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(filename,&nlons,&nlats,&nlevs,vcoord,lats,lons,slen(filename));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NNN",capi_vcoord_tmp,capi_lats_tmp,capi_lons_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_lons_tmp == NULL) ... else of lons*/
  /* End of cleaning variable lons */
  }  /*if (capi_lats_tmp == NULL) ... else of lats*/
  /* End of cleaning variable lats */
  }  /*if (capi_vcoord_tmp == NULL) ... else of vcoord*/
  /* End of cleaning variable vcoord */
    STRINGFREE(filename);
  }  /*if (f2py_success) of filename*/
  /* End of cleaning variable filename */
  } /*if (f2py_success) of nlons*/
  /* End of cleaning variable nlons */
  } /*if (f2py_success) of nlevs*/
  /* End of cleaning variable nlevs */
  } /*if (f2py_success) of nlats*/
  /* End of cleaning variable nlats */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************* end of read_nemsio_coords *************************/

/**************************** read_nemsio_griddata ****************************/
static char doc_f2py_rout__read_sigma_nemsio_read_nemsio_griddata[] = "\
ug,vg,tempg,zsg,psg,qg,ozg,cwmrg,dpresg,presg = read_nemsio_griddata(filename,nlons,nlats,nlevs)\n\nWrapper for ``read_nemsio_griddata``.\
\n\nParameters\n----------\n"
"filename : input string(len=500)\n"
"nlons : input int\n"
"nlats : input int\n"
"nlevs : input int\n"
"\nReturns\n-------\n"
"ug : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"vg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"tempg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"zsg : rank-2 array('f') with bounds (nlons,nlats)\n"
"psg : rank-2 array('f') with bounds (nlons,nlats)\n"
"qg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"ozg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"cwmrg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"dpresg : rank-3 array('f') with bounds (nlons,nlats,nlevs)\n"
"presg : rank-3 array('f') with bounds (nlons,nlats,nlevs)";
/* extern void F_FUNC_US(read_nemsio_griddata,READ_NEMSIO_GRIDDATA)(string,int*,int*,int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,size_t); */
static PyObject *f2py_rout__read_sigma_nemsio_read_nemsio_griddata(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(string,int*,int*,int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,size_t)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  string filename = NULL;
  int slen(filename);
  PyObject *filename_capi = Py_None;
  int nlons = 0;
  PyObject *nlons_capi = Py_None;
  int nlats = 0;
  PyObject *nlats_capi = Py_None;
  int nlevs = 0;
  PyObject *nlevs_capi = Py_None;
  float *ug = NULL;
  npy_intp ug_Dims[3] = {-1, -1, -1};
  const int ug_Rank = 3;
  PyArrayObject *capi_ug_tmp = NULL;
  int capi_ug_intent = 0;
  float *vg = NULL;
  npy_intp vg_Dims[3] = {-1, -1, -1};
  const int vg_Rank = 3;
  PyArrayObject *capi_vg_tmp = NULL;
  int capi_vg_intent = 0;
  float *tempg = NULL;
  npy_intp tempg_Dims[3] = {-1, -1, -1};
  const int tempg_Rank = 3;
  PyArrayObject *capi_tempg_tmp = NULL;
  int capi_tempg_intent = 0;
  float *zsg = NULL;
  npy_intp zsg_Dims[2] = {-1, -1};
  const int zsg_Rank = 2;
  PyArrayObject *capi_zsg_tmp = NULL;
  int capi_zsg_intent = 0;
  float *psg = NULL;
  npy_intp psg_Dims[2] = {-1, -1};
  const int psg_Rank = 2;
  PyArrayObject *capi_psg_tmp = NULL;
  int capi_psg_intent = 0;
  float *qg = NULL;
  npy_intp qg_Dims[3] = {-1, -1, -1};
  const int qg_Rank = 3;
  PyArrayObject *capi_qg_tmp = NULL;
  int capi_qg_intent = 0;
  float *ozg = NULL;
  npy_intp ozg_Dims[3] = {-1, -1, -1};
  const int ozg_Rank = 3;
  PyArrayObject *capi_ozg_tmp = NULL;
  int capi_ozg_intent = 0;
  float *cwmrg = NULL;
  npy_intp cwmrg_Dims[3] = {-1, -1, -1};
  const int cwmrg_Rank = 3;
  PyArrayObject *capi_cwmrg_tmp = NULL;
  int capi_cwmrg_intent = 0;
  float *dpresg = NULL;
  npy_intp dpresg_Dims[3] = {-1, -1, -1};
  const int dpresg_Rank = 3;
  PyArrayObject *capi_dpresg_tmp = NULL;
  int capi_dpresg_intent = 0;
  float *presg = NULL;
  npy_intp presg_Dims[3] = {-1, -1, -1};
  const int presg_Rank = 3;
  PyArrayObject *capi_presg_tmp = NULL;
  int capi_presg_intent = 0;
  static char *capi_kwlist[] = {"filename","nlons","nlats","nlevs",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO:_read_sigma_nemsio.read_nemsio_griddata",\
    capi_kwlist,&filename_capi,&nlons_capi,&nlats_capi,&nlevs_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable nlevs */
    f2py_success = int_from_pyobj(&nlevs,nlevs_capi,"_read_sigma_nemsio.read_nemsio_griddata() 4th argument (nlevs) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nlats */
    f2py_success = int_from_pyobj(&nlats,nlats_capi,"_read_sigma_nemsio.read_nemsio_griddata() 3rd argument (nlats) can't be converted to int");
  if (f2py_success) {
  /* Processing variable filename */
  slen(filename) = 500;
  f2py_success = string_from_pyobj(&filename,&slen(filename),"",filename_capi,"string_from_pyobj failed in converting 1st argument `filename' of _read_sigma_nemsio.read_nemsio_griddata to C string");
  if (f2py_success) {
  /* Processing variable nlons */
    f2py_success = int_from_pyobj(&nlons,nlons_capi,"_read_sigma_nemsio.read_nemsio_griddata() 2nd argument (nlons) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ozg */
  ozg_Dims[0]=nlons,ozg_Dims[1]=nlats,ozg_Dims[2]=nlevs;
  capi_ozg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_ozg_tmp = array_from_pyobj(NPY_FLOAT,ozg_Dims,ozg_Rank,capi_ozg_intent,Py_None);
  if (capi_ozg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `ozg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    ozg = (float *)(PyArray_DATA(capi_ozg_tmp));

  /* Processing variable dpresg */
  dpresg_Dims[0]=nlons,dpresg_Dims[1]=nlats,dpresg_Dims[2]=nlevs;
  capi_dpresg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_dpresg_tmp = array_from_pyobj(NPY_FLOAT,dpresg_Dims,dpresg_Rank,capi_dpresg_intent,Py_None);
  if (capi_dpresg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `dpresg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    dpresg = (float *)(PyArray_DATA(capi_dpresg_tmp));

  /* Processing variable tempg */
  tempg_Dims[0]=nlons,tempg_Dims[1]=nlats,tempg_Dims[2]=nlevs;
  capi_tempg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_tempg_tmp = array_from_pyobj(NPY_FLOAT,tempg_Dims,tempg_Rank,capi_tempg_intent,Py_None);
  if (capi_tempg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `tempg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    tempg = (float *)(PyArray_DATA(capi_tempg_tmp));

  /* Processing variable vg */
  vg_Dims[0]=nlons,vg_Dims[1]=nlats,vg_Dims[2]=nlevs;
  capi_vg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_vg_tmp = array_from_pyobj(NPY_FLOAT,vg_Dims,vg_Rank,capi_vg_intent,Py_None);
  if (capi_vg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `vg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    vg = (float *)(PyArray_DATA(capi_vg_tmp));

  /* Processing variable cwmrg */
  cwmrg_Dims[0]=nlons,cwmrg_Dims[1]=nlats,cwmrg_Dims[2]=nlevs;
  capi_cwmrg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_cwmrg_tmp = array_from_pyobj(NPY_FLOAT,cwmrg_Dims,cwmrg_Rank,capi_cwmrg_intent,Py_None);
  if (capi_cwmrg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `cwmrg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    cwmrg = (float *)(PyArray_DATA(capi_cwmrg_tmp));

  /* Processing variable presg */
  presg_Dims[0]=nlons,presg_Dims[1]=nlats,presg_Dims[2]=nlevs;
  capi_presg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_presg_tmp = array_from_pyobj(NPY_FLOAT,presg_Dims,presg_Rank,capi_presg_intent,Py_None);
  if (capi_presg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `presg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    presg = (float *)(PyArray_DATA(capi_presg_tmp));

  /* Processing variable psg */
  psg_Dims[0]=nlons,psg_Dims[1]=nlats;
  capi_psg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_psg_tmp = array_from_pyobj(NPY_FLOAT,psg_Dims,psg_Rank,capi_psg_intent,Py_None);
  if (capi_psg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `psg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    psg = (float *)(PyArray_DATA(capi_psg_tmp));

  /* Processing variable zsg */
  zsg_Dims[0]=nlons,zsg_Dims[1]=nlats;
  capi_zsg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_zsg_tmp = array_from_pyobj(NPY_FLOAT,zsg_Dims,zsg_Rank,capi_zsg_intent,Py_None);
  if (capi_zsg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `zsg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    zsg = (float *)(PyArray_DATA(capi_zsg_tmp));

  /* Processing variable qg */
  qg_Dims[0]=nlons,qg_Dims[1]=nlats,qg_Dims[2]=nlevs;
  capi_qg_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_qg_tmp = array_from_pyobj(NPY_FLOAT,qg_Dims,qg_Rank,capi_qg_intent,Py_None);
  if (capi_qg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `qg' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    qg = (float *)(PyArray_DATA(capi_qg_tmp));

  /* Processing variable ug */
  ug_Dims[0]=nlons,ug_Dims[1]=nlats,ug_Dims[2]=nlevs;
  capi_ug_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_ug_tmp = array_from_pyobj(NPY_FLOAT,ug_Dims,ug_Rank,capi_ug_intent,Py_None);
  if (capi_ug_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `ug' of _read_sigma_nemsio.read_nemsio_griddata to C/Fortran array" );
  } else {
    ug = (float *)(PyArray_DATA(capi_ug_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(filename,&nlons,&nlats,&nlevs,ug,vg,tempg,zsg,psg,qg,ozg,cwmrg,dpresg,presg,slen(filename));
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("NNNNNNNNNN",capi_ug_tmp,capi_vg_tmp,capi_tempg_tmp,capi_zsg_tmp,capi_psg_tmp,capi_qg_tmp,capi_ozg_tmp,capi_cwmrg_tmp,capi_dpresg_tmp,capi_presg_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_ug_tmp == NULL) ... else of ug*/
  /* End of cleaning variable ug */
  }  /*if (capi_qg_tmp == NULL) ... else of qg*/
  /* End of cleaning variable qg */
  }  /*if (capi_zsg_tmp == NULL) ... else of zsg*/
  /* End of cleaning variable zsg */
  }  /*if (capi_psg_tmp == NULL) ... else of psg*/
  /* End of cleaning variable psg */
  }  /*if (capi_presg_tmp == NULL) ... else of presg*/
  /* End of cleaning variable presg */
  }  /*if (capi_cwmrg_tmp == NULL) ... else of cwmrg*/
  /* End of cleaning variable cwmrg */
  }  /*if (capi_vg_tmp == NULL) ... else of vg*/
  /* End of cleaning variable vg */
  }  /*if (capi_tempg_tmp == NULL) ... else of tempg*/
  /* End of cleaning variable tempg */
  }  /*if (capi_dpresg_tmp == NULL) ... else of dpresg*/
  /* End of cleaning variable dpresg */
  }  /*if (capi_ozg_tmp == NULL) ... else of ozg*/
  /* End of cleaning variable ozg */
  } /*if (f2py_success) of nlons*/
  /* End of cleaning variable nlons */
    STRINGFREE(filename);
  }  /*if (f2py_success) of filename*/
  /* End of cleaning variable filename */
  } /*if (f2py_success) of nlats*/
  /* End of cleaning variable nlats */
  } /*if (f2py_success) of nlevs*/
  /* End of cleaning variable nlevs */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/************************ end of read_nemsio_griddata ************************/

/********************************* onedtotwod *********************************/
static char doc_f2py_rout__read_sigma_nemsio_onedtotwod[] = "\
data2 = onedtotwod(data1,nlons,nlats)\n\nWrapper for ``onedtotwod``.\
\n\nParameters\n----------\n"
"data1 : input rank-1 array('f') with bounds (nlons*nlats)\n"
"nlons : input int\n"
"nlats : input int\n"
"\nReturns\n-------\n"
"data2 : rank-2 array('f') with bounds (nlons,nlats)";
/* extern void F_FUNC(onedtotwod,ONEDTOTWOD)(float*,float*,int*,int*); */
static PyObject *f2py_rout__read_sigma_nemsio_onedtotwod(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(float*,float*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  float *data1 = NULL;
  npy_intp data1_Dims[1] = {-1};
  const int data1_Rank = 1;
  PyArrayObject *capi_data1_tmp = NULL;
  int capi_data1_intent = 0;
  PyObject *data1_capi = Py_None;
  float *data2 = NULL;
  npy_intp data2_Dims[2] = {-1, -1};
  const int data2_Rank = 2;
  PyArrayObject *capi_data2_tmp = NULL;
  int capi_data2_intent = 0;
  int nlons = 0;
  PyObject *nlons_capi = Py_None;
  int nlats = 0;
  PyObject *nlats_capi = Py_None;
  static char *capi_kwlist[] = {"data1","nlons","nlats",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOO:_read_sigma_nemsio.onedtotwod",\
    capi_kwlist,&data1_capi,&nlons_capi,&nlats_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable nlats */
    f2py_success = int_from_pyobj(&nlats,nlats_capi,"_read_sigma_nemsio.onedtotwod() 3rd argument (nlats) can't be converted to int");
  if (f2py_success) {
  /* Processing variable nlons */
    f2py_success = int_from_pyobj(&nlons,nlons_capi,"_read_sigma_nemsio.onedtotwod() 2nd argument (nlons) can't be converted to int");
  if (f2py_success) {
  /* Processing variable data1 */
  data1_Dims[0]=nlons*nlats;
  capi_data1_intent |= F2PY_INTENT_IN;
  capi_data1_tmp = array_from_pyobj(NPY_FLOAT,data1_Dims,data1_Rank,capi_data1_intent,data1_capi);
  if (capi_data1_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting 1st argument `data1' of _read_sigma_nemsio.onedtotwod to C/Fortran array" );
  } else {
    data1 = (float *)(PyArray_DATA(capi_data1_tmp));

  /* Processing variable data2 */
  data2_Dims[0]=nlons,data2_Dims[1]=nlats;
  capi_data2_intent |= F2PY_INTENT_HIDE|F2PY_INTENT_OUT;
  capi_data2_tmp = array_from_pyobj(NPY_FLOAT,data2_Dims,data2_Rank,capi_data2_intent,Py_None);
  if (capi_data2_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_read_sigma_nemsio_error,"failed in converting hidden `data2' of _read_sigma_nemsio.onedtotwod to C/Fortran array" );
  } else {
    data2 = (float *)(PyArray_DATA(capi_data2_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(data1,data2,&nlons,&nlats);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_data2_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_data2_tmp == NULL) ... else of data2*/
  /* End of cleaning variable data2 */
  if((PyObject *)capi_data1_tmp!=data1_capi) {
    Py_XDECREF(capi_data1_tmp); }
  }  /*if (capi_data1_tmp == NULL) ... else of data1*/
  /* End of cleaning variable data1 */
  } /*if (f2py_success) of nlons*/
  /* End of cleaning variable nlons */
  } /*if (f2py_success) of nlats*/
  /* End of cleaning variable nlats */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/***************************** end of onedtotwod *****************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"read_nemsio_header",-1,{{-1}},0,(char *)F_FUNC_US(read_nemsio_header,READ_NEMSIO_HEADER),(f2py_init_func)f2py_rout__read_sigma_nemsio_read_nemsio_header,doc_f2py_rout__read_sigma_nemsio_read_nemsio_header},
  {"read_nemsio_coords",-1,{{-1}},0,(char *)F_FUNC_US(read_nemsio_coords,READ_NEMSIO_COORDS),(f2py_init_func)f2py_rout__read_sigma_nemsio_read_nemsio_coords,doc_f2py_rout__read_sigma_nemsio_read_nemsio_coords},
  {"read_nemsio_griddata",-1,{{-1}},0,(char *)F_FUNC_US(read_nemsio_griddata,READ_NEMSIO_GRIDDATA),(f2py_init_func)f2py_rout__read_sigma_nemsio_read_nemsio_griddata,doc_f2py_rout__read_sigma_nemsio_read_nemsio_griddata},
  {"onedtotwod",-1,{{-1}},0,(char *)F_FUNC(onedtotwod,ONEDTOTWOD),(f2py_init_func)f2py_rout__read_sigma_nemsio_onedtotwod,doc_f2py_rout__read_sigma_nemsio_onedtotwod},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_read_sigma_nemsio",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit__read_sigma_nemsio(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_read_sigma_nemsio(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _read_sigma_nemsio_module = PyModule_Create(&moduledef);
#else
  m = _read_sigma_nemsio_module = Py_InitModule("_read_sigma_nemsio", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _read_sigma_nemsio (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_read_sigma_nemsio' is auto-generated with f2py (version:2).\nFunctions:\n"
"  nlons,nlats,nlevs,idate,nfhour = read_nemsio_header(filename)\n"
"  vcoord,lats,lons = read_nemsio_coords(filename,nlons,nlats,nlevs)\n"
"  ug,vg,tempg,zsg,psg,qg,ozg,cwmrg,dpresg,presg = read_nemsio_griddata(filename,nlons,nlats,nlevs)\n"
"  data2 = onedtotwod(data1,nlons,nlats)\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _read_sigma_nemsio_error = PyErr_NewException ("_read_sigma_nemsio.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));




/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_read_sigma_nemsio");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
