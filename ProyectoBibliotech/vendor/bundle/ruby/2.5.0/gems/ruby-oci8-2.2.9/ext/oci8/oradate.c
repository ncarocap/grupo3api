/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/*
 *  oradate.c
 *
 * Copyright (C) 2002-2015 Kubo Takehiro <kubo@jiubao.org>
 *
 * date and time between 4712 B.C. and 9999 A.D.
 */
#include "oci8.h"
#include <time.h>

static VALUE cOraDate;

/*
 * Document-class: OraDate
 *
 * OraDate is the ruby class compatible with Oracle <tt>DATE</tt> data type.
 * The range is between 4712 B.C. and 9999 A.D.
 */
struct ora_date {
    unsigned char century;
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
};
typedef struct ora_date ora_date_t;

#define Set_year(od, y) (od)->century = y / 100 + 100, (od)->year = y % 100 + 100
#define Set_month(od, m) (od)->month = m
#define Set_day(od, d)   (od)->day = d
#define Set_hour(od, h)  (od)->hour = h + 1
#define Set_minute(od, m) (od)->minute = m + 1
#define Set_second(od, s) (od)->second = s + 1

#define Get_year(od) (((od)->century - 100) * 100 + ((od)->year - 100))
#define Get_month(od) ((od)->month)
#define Get_day(od) ((od)->day)
#define Get_hour(od) ((od)->hour - 1)
#define Get_minute(od) ((od)->minute - 1)
#define Get_second(od) ((od)->second - 1)

#define Check_year(year) \
    if (year < -4712 || 9999 < year) \
        rb_raise(rb_eRangeError, "Out of range for year %d (expect -4712 .. 9999)", year)
#define Check_month(month) \
    if (month < 1 || 12 < month) \
        rb_raise(rb_eRangeError, "Out of range for month %d (expect 1 .. 12)", month)
#define Check_day(day) \
    if (day < 1 || 31 < day) \
        rb_raise(rb_eRangeError, "Out of range for day %d (expect 1 .. 31)", day)
#define Check_hour(hour) \
    if (hour < 0 || 23 < hour) \
        rb_raise(rb_eRangeError, "Out of range for hour %d (expect 0 .. 24)", hour)
#define Check_minute(min) \
    if (min < 0 || 59 < min) \
        rb_raise(rb_eRangeError, "Out of range for minute %d (expect 0 .. 59)", min)
#define Check_second(sec) \
    if (sec < 0 || 59 < sec) \
        rb_raise(rb_eRangeError, "Out of range for second %d (expect 0 .. 59)", sec)

#ifdef HAVE_RB_DATA_TYPE_T_FUNCTION
#define check_oradate(obj) ((ora_date_t*)Check_TypedStruct((obj), &odate_data_type))
#else
static ora_date_t *check_oradate(VALUE obj)
{
    if (!rb_obj_is_kind_of(obj, cOraDate)) {
        rb_raise(rb_eTypeError, "wrong argument type %s (expected %s)",
                 rb_obj_classname(obj), rb_class2name(cOraDate));
    }
    return DATA_PTR(obj);
}
#endif

static size_t odate_memsize(const void *ptr)
{
    return sizeof(ora_date_t);
}

static const rb_data_type_t odate_data_type = {
    "OraDate",
    {NULL, RUBY_DEFAULT_FREE, odate_memsize,},
#ifdef RUBY_TYPED_FREE_IMMEDIATELY
    NULL, NULL, RUBY_TYPED_FREE_IMMEDIATELY
#endif
#ifdef RUBY_TYPED_WB_PROTECTED
    | RUBY_TYPED_WB_PROTECTED
#endif
};

static void oci8_set_ora_date(ora_date_t *od, int year, int month, int day, int hour, int minute, int second)
{
    Set_year(od, year);
    Set_month(od, month);
    Set_day(od, day);
    Set_hour(od, hour);
    Set_minute(od, minute);
    Set_second(od, second);
}

static VALUE ora_date_s_allocate(VALUE klass)
{
    ora_date_t *od;
    return TypedData_Make_Struct(klass, ora_date_t, &odate_data_type, od);
}

/*
 * @overload initialize(year = 1, month = 1, day = 1, hour = 0, min = 0, sec = 0)
 *
 *  Returns an <code>OraDate</code> object initialized to the specified date and time.
 *
 *  @example
 *    OraDate.new              # => 0001-01-01 00:00:00
 *    OraDate.new(2012)        # => 2012-01-01 00:00:00
 *    OraDate.new(2012, 3, 4)  # => 2012-03-04 00:00:00
 *
 *  @param [Integer] year year
 *  @param [Integer] month month
 *  @param [Integer] day  day of month
 *  @param [Integer] hour hour
 *  @param [Integer] min  minute
 *  @param [Integer] sec  second
 */
static VALUE ora_date_initialize(int argc, VALUE *argv, VALUE self)
{
    VALUE vyear, vmonth, vday, vhour, vmin, vsec;
    ora_date_t *od = check_oradate(self);
    int year, month, day, hour, min, sec;

    rb_scan_args(argc, argv, "06", &vyear, &vmonth, &vday, &vhour, &vmin, &vsec);
    /* set year */
    if (argc > 0) {
        year = NUM2INT(vyear);
        Check_year(year);
    } else {
        year = 1;
    }
    /* set month */
    if (argc > 1) {
        month = NUM2INT(vmonth);
        Check_month(month);
    } else {
        month = 1;
    }
    /* set day */
    if (argc > 2) {
        day = NUM2INT(vday);
        Check_day(day);
    } else {
        day = 1;
    }
    /* set hour */
    if (argc > 3) {
        hour = NUM2INT(vhour);
        Check_hour(hour);
    } else {
        hour = 0;
    }
    /* set minute */
    if (argc > 4) {
        min = NUM2INT(vmin);
        Check_minute(min);
    } else {
        min = 0;
    }
    /* set second */
    if (argc > 5) {
        sec = NUM2INT(vsec);
        Check_second(sec);
    } else {
        sec = 0;
    }

    oci8_set_ora_date(od, year, month, day, hour, min, sec);
    return Qnil;
}

/*
 *  @private
 */
static VALUE ora_date_initialize_copy(VALUE lhs, VALUE rhs)
{
    ora_date_t *l = check_oradate(lhs);
    ora_date_t *r = check_oradate(rhs);

    rb_call_super(1, &rhs);
    memcpy(l, r, sizeof(ora_date_t));
    return lhs;
}

/*
 * @overload now
 *
 *  Returns an <code>OraDate</code> object initialized to the
 *  current local time.
 *
 *  @return [OraDate]
 */
static VALUE ora_date_s_now(VALUE klass)
{
    VALUE obj = ora_date_s_allocate(klass);
    ora_date_t *od = check_oradate(obj);
    time_t tm = time(0);
    int year, month, day, hour, min, sec;
#ifdef HAVE_LOCALTIME_R
    struct tm t;
    localtime_r(&tm, &t);
#define tp (&t)
#else
    struct tm *tp;
    tp = localtime(&tm);
#endif
    year = tp->tm_year + 1900;
    month = tp->tm_mon + 1;
    day = tp->tm_mday;
    hour = tp->tm_hour;
    min = tp->tm_min;
    sec = tp->tm_sec;

    oci8_set_ora_date(od, year, month, day, hour, min, sec);
    return obj;
}

/*
 * @overload to_s
 *
 *  Returns a string representing <i>self</i>.
 *  The string format is 'yyyy/mm/dd hh:mi:ss'.
 *
 *  @return [OraDate]
 */
static VALUE ora_date_to_s(VALUE self)
{
    ora_date_t *od = check_oradate(self);
    char buf[30];

    sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d", Get_year(od), Get_month(od),
            Get_day(od), Get_hour(od), Get_minute(od), Get_second(od));
    return rb_usascii_str_new_cstr(buf);
}

/*
 * @overload to_a
 *
 *  Returns a 6-element <i>array</i> of year, month, day, hour, minute and second.
 *
 *  @return [Array]
 */
static VALUE ora_date_to_a(VALUE self)
{
    ora_date_t *od = check_oradate(self);
    VALUE ary[6];

    ary[0] = INT2FIX(Get_year(od));
    ary[1] = INT2FIX(Get_month(od));
    ary[2] = INT2FIX(Get_day(od));
    ary[3] = INT2FIX(Get_hour(od));
    ary[4] = INT2FIX(Get_minute(od));
    ary[5] = INT2FIX(Get_second(od));
    return rb_ary_new4(6, ary);
}

/*
 * @overload year
 *
 *  Returns the year field of <i>self</i>.
 *
 *  @return [Integer]
 */
static VALUE ora_date_year(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_year(od));
}

/*
 * @overload year=num
 *
 *  Assigns <i>num</i> to the year field of <i>self</i>.
 *
 *  @param [Integer] num number between -4712 and 9999
 */
static VALUE ora_date_set_year(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v = NUM2INT(val);

    Check_year(v);
    Set_year(od, v);
    return self;
}

/*
 * @overload month
 *
 *  Returns the month field of <i>self</i>.
 *  The month starts with one.
 *
 *  @return [Integer]
 */
static VALUE ora_date_month(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_month(od));
}

/*
 * @overload month=num
 *
 *  Assigns <i>num</i> to the month field of <i>self</i>.
 *  The month starts with one.
 *
 *  @param [Integer] num number between 1 and 12
 */
static VALUE ora_date_set_month(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v = NUM2INT(val);

    Check_month(v);
    Set_month(od, v);
    return self;
}

/*
 * @overload day
 *
 *  Returns the day of month field of <i>self</i>.
 *
 *  @return [Integer]
 */
static VALUE ora_date_day(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_day(od));
}

/*
 * @overload day=num
 *
 *  Assigns <i>num</i> to the day of month field of <i>self</i>.
 *
 *  @param [Integer] num number between 1 and 31
 */
static VALUE ora_date_set_day(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v = NUM2INT(val);

    Check_day(v);
    Set_day(od, v);
    return self;
}

/*
 * @overload hour
 *
 *  Returns the hour field of <i>self</i>.
 *
 *  @return [Integer]
 */
static VALUE ora_date_hour(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_hour(od));
}

/*
 * @overload hour=num
 *
 *  Assigns <i>num</i> to the hour field of <i>self</i>.
 *
 *  @param [Integer] num number between 0 and 23
 */
static VALUE ora_date_set_hour(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v = NUM2INT(val);

    Check_hour(v);
    Set_hour(od, v);
    return self;
}

/*
 * @overload minute
 *
 *  Returns the minute field of <i>self</i>.
 *
 *  @return [Integer]
 */
static VALUE ora_date_minute(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_minute(od));
}

/*
 * @overload minute=num
 *
 *  Assigns <i>num</i> to the minute field of <i>self</i>.
 *
 *  @param [Integer] num number between 0 and 59
 */
static VALUE ora_date_set_minute(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v = NUM2INT(val);

    Check_minute(v);
    Set_minute(od, v);
    return self;
}

/*
 * @overload second
 *
 *  Returns the second field of <i>self</i>.
 *
 *  @return [Integer]
 */
static VALUE ora_date_second(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return INT2FIX(Get_second(od));
}

/*
 * @overload second=num
 *
 *  Assigns <i>num</i> to the second field of <i>self</i>.
 *
 *  @param [Integer] num number between 0 and 59
 */
static VALUE ora_date_set_second(VALUE self, VALUE val)
{
    ora_date_t *od = check_oradate(self);
    int v;

    v = NUM2INT(val);
    Check_second(v);
    Set_second(od, v);
    return self;
}

/*
 * @overload trunc
 *
 *  Truncates hour, minute and second fields to zero.
 *
 *  @example
 *    oradate = OraDate.now  # => 2008/07/17 11:07:30
 *    oradate.trunc          # => 2008/07/17 00:00:00
 *
 *  @return [OraDate]
 */
static VALUE ora_date_trunc(VALUE self)
{
    ora_date_t *od = check_oradate(self);

    od->hour = 1;
    od->minute = 1;
    od->second = 1;
    return self;
}

/*
 * @overload <=>(other)
 *
 *  Returns -1, 0, or +1 depending on whether <i>self</i> is less than,
 *  equal to, or greater than <i>other</i>.
 *
 *  @return [-1, 0, +1]
 */
static VALUE ora_date_cmp(VALUE self, VALUE val)
{
    ora_date_t *od1 = check_oradate(self);
    ora_date_t *od2 = check_oradate(val);

    if (od1->century < od2->century) return INT2FIX(-1);
    if (od1->century > od2->century) return INT2FIX(1);
    if (od1->year < od2->year) return INT2FIX(-1);
    if (od1->year > od2->year) return INT2FIX(1);
    if (od1->month < od2->month) return INT2FIX(-1);
    if (od1->month > od2->month) return INT2FIX(1);
    if (od1->day < od2->day) return INT2FIX(-1);
    if (od1->day > od2->day) return INT2FIX(1);
    if (od1->hour < od2->hour) return INT2FIX(-1);
    if (od1->hour > od2->hour) return INT2FIX(1);
    if (od1->minute < od2->minute) return INT2FIX(-1);
    if (od1->minute > od2->minute) return INT2FIX(1);
    if (od1->second < od2->second) return INT2FIX(-1);
    if (od1->second > od2->second) return INT2FIX(1);
    return INT2FIX(0);
}

/*
 *  @private
 */
static VALUE ora_date_hash(VALUE self)
{
    ora_date_t *od = check_oradate(self);
    unsigned int v;

    v = (od->century <<  8)
        + (od->year    << 15)
        + (od->month   << 22)
        + (od->day     << 26)
        + (od->hour    << 12)
        + (od->minute  <<  6)
        + (od->second  <<  0);
    return INT2FIX(v);
}

/*
 * @overload _dump
 *
 *  Serializes <i>self</i>.
 *  This method is called by Marshal.dump().
 *
 *  @return [String] a byte stream
 *  @see OraDate._load
 */
static VALUE ora_date_dump(int argc, VALUE *argv, VALUE self)
{
    ora_date_t *od = check_oradate(self);

    return rb_str_new((const char*)od, sizeof(ora_date_t)); /* ASCII-8BIT */
}

/*
 * @overload _load(bytes)
 *
 *  Restores a byte stream serialized by {OraDate#_dump}.
 *  This method is called by Marshal.load() to deserialize a byte stream
 *  created by Marshal.dump().
 *
 *  @param [String] bytes a byte stream
 *  @return [OraDate] an deserialized object
 */
static VALUE ora_date_s_load(VALUE klass, VALUE str)
{
    ora_date_t *od;
    VALUE obj;

    Check_Type(str, T_STRING);
    if (RSTRING_LEN(str) != sizeof(ora_date_t)) {
        rb_raise(rb_eTypeError, "marshaled OraDate format differ");
    }
    obj = TypedData_Make_Struct(cOraDate, ora_date_t, &odate_data_type, od);
    memcpy(od, RSTRING_PTR(str), sizeof(ora_date_t));
    return obj;
}

/*
 *  Document-class: OCI8::BindType::OraDate
 *
 *  This is a helper class to bind OraDate as Oracle's <tt>DATE</tt> datatype.
 *
 */
static VALUE bind_oradate_get(oci8_bind_t *obind, void *data, void *null_struct)
{
    ora_date_t *od;

    VALUE obj = TypedData_Make_Struct(cOraDate, ora_date_t, &odate_data_type, od);
    memcpy(od, data, sizeof(ora_date_t));
    return obj;
}

static void bind_oradate_set(oci8_bind_t *obind, void *data, void **null_structp, VALUE val)
{
    ora_date_t *od = check_oradate(val);

    memcpy(data, od, sizeof(ora_date_t));
}

static void bind_oradate_init(oci8_bind_t *obind, VALUE svc, VALUE val, VALUE length)
{
    obind->value_sz = sizeof(ora_date_t);
    obind->alloc_sz = sizeof(ora_date_t);
}

static void bind_oradate_init_elem(oci8_bind_t *obind, VALUE svc)
{
    static const ora_date_t julian_day_0 = {100-47, 100-12, 1, 1, 1, 1, 1};
    ub4 idx = 0;
    do {
        memcpy((ora_date_t*)obind->valuep + idx, &julian_day_0, sizeof(ora_date_t));
    } while (++idx < obind->maxar_sz);
}

static const oci8_bind_data_type_t bind_oradate_data_type = {
    {
        {
            "OCI8::BindType::OraDate",
            {
                NULL,
                oci8_handle_cleanup,
                oci8_handle_size,
            },
            &oci8_bind_data_type.rb_data_type, NULL,
#ifdef RUBY_TYPED_WB_PROTECTED
            RUBY_TYPED_WB_PROTECTED,
#endif
        },
        oci8_bind_free,
        sizeof(oci8_bind_t)
    },
    bind_oradate_get,
    bind_oradate_set,
    bind_oradate_init,
    bind_oradate_init_elem,
    NULL,
    SQLT_DAT,
};

static VALUE bind_oradate_alloc(VALUE klass)
{
    return oci8_allocate_typeddata(klass, &bind_oradate_data_type.base);
}

void Init_ora_date(void)
{
    cOraDate = rb_define_class("OraDate", rb_cObject);

    rb_define_alloc_func(cOraDate, ora_date_s_allocate);
    rb_define_method(cOraDate, "initialize", ora_date_initialize, -1);
    rb_define_method(cOraDate, "initialize_copy", ora_date_initialize_copy, 1);
    rb_define_singleton_method(cOraDate, "now", ora_date_s_now, 0);
    rb_define_method(cOraDate, "to_s", ora_date_to_s, 0);
    rb_define_method(cOraDate, "to_a", ora_date_to_a, 0);

    rb_define_method(cOraDate, "year", ora_date_year, 0);
    rb_define_method(cOraDate, "year=", ora_date_set_year, 1);

    rb_define_method(cOraDate, "month", ora_date_month, 0);
    rb_define_method(cOraDate, "month=", ora_date_set_month, 1);

    rb_define_method(cOraDate, "day", ora_date_day, 0);
    rb_define_method(cOraDate, "day=", ora_date_set_day, 1);

    rb_define_method(cOraDate, "hour", ora_date_hour, 0);
    rb_define_method(cOraDate, "hour=", ora_date_set_hour, 1);

    rb_define_method(cOraDate, "minute", ora_date_minute, 0);
    rb_define_method(cOraDate, "minute=", ora_date_set_minute, 1);

    rb_define_method(cOraDate, "second", ora_date_second, 0);
    rb_define_method(cOraDate, "second=", ora_date_set_second, 1);

    rb_define_method(cOraDate, "trunc", ora_date_trunc, 0);

    rb_define_method(cOraDate, "<=>", ora_date_cmp, 1);
    rb_include_module(cOraDate, rb_mComparable);

    rb_define_method(cOraDate, "hash", ora_date_hash, 0);

    rb_define_method(cOraDate, "_dump", ora_date_dump, -1);
    rb_define_singleton_method(cOraDate, "_load", ora_date_s_load, 1);

    oci8_define_bind_class("OraDate", &bind_oradate_data_type, bind_oradate_alloc);
}
