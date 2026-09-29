#include "mcc2_c_helper.h"

VALUE rb_mMcc2CHelper;

static VALUE bgra_to_bgr(VALUE self, VALUE instr)
{
  char *src = StringValuePtr(instr);
  long inlen = RSTRING_LEN(instr);
  char *dst;
  VALUE outstr;

  outstr = rb_str_new2("");
  rb_str_resize(outstr, inlen / 4 * 3);
  dst = RSTRING_PTR(outstr);

  for (int i = 0; i < inlen-3; i+=4) {
    unsigned char b = src[i + 0];
    unsigned char g = src[i + 1];
    unsigned char r = src[i + 2];
    dst[0] = b;
    dst[1] = g;
    dst[2] = r;
    dst += 3;
  }
  return outstr;
}


RUBY_FUNC_EXPORTED void
Init_mcc2_c_helper(void)
{
  rb_mMcc2CHelper = rb_define_module("Mcc2CHelper");
  rb_define_singleton_method(rb_mMcc2CHelper, "bgra_to_bgr", bgra_to_bgr, 1);
}
