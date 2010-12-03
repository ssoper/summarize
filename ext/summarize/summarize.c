#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <glib-object.h>
#include <ruby.h>

#include "libots.h"
#include "summarize.h"


void Init_summarize() {
 VALUE rb_mOts = rb_define_module("Summarize");
 rb_define_module_function(rb_mOts, "summarize", summarize, 3);
}

static VALUE summarize(const VALUE self, volatile VALUE rb_str, volatile VALUE rb_dict_file, const VALUE rb_ratio) {
  long int length = RSTRING_LEN(rb_str);
  char *text = StringValuePtr(rb_str);
  char *dictionary_file = StringValuePtr(rb_dict_file);
  int ratio = NUM2INT(rb_ratio);
  unsigned char *result;
  size_t result_len;
  OtsArticle *doc = ots_new_article();

  if (!ots_load_xml_dictionary(doc, dictionary_file)) {
    ots_free_article(doc);
    rb_raise(rb_eRuntimeError, "Cannot load dictionary file");
    return Qnil;
  }

  ots_parse_stream(text, length, doc);
  ots_grade_doc(doc);
  ots_highlight_doc(doc, ratio);

  result = ots_get_doc_text(doc, &result_len);

  ots_free_article(doc);

  return rb_str_new2(result);
}
